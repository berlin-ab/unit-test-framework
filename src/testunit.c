#include <stdio.h>
#include <stdlib.h>
#include "testunit.h"

struct TestData {
	char* name;
	void (*test)(void *);
};

struct GroupData {
	char *name;
	Test test;
};
 
struct SuiteData {
	Group group;
	int number_of_failed_tests;
	int number_of_successful_tests;
};

char* get_group_name(Group group) {
	return group->name;
}

Suite make_suite() {
	Suite suite;
	suite = (Suite) malloc(sizeof(Suite));
	suite->number_of_failed_tests = 0;
	suite->number_of_successful_tests = 0;
	return suite;
}

static Suite current_suite;

void run_suite(Suite suite) {
	current_suite = suite;
	printf("Running suite.\n");

	if (suite->group && suite->group->test) {
		Test test = suite->group->test;
		
		test->test(suite->group);
		
		printf("Running %s.\n", test->name);
	}

	printf("Ran %d tests. %d succeeded. %d failed.",
		suite->number_of_failed_tests+suite->number_of_successful_tests,
		suite->number_of_successful_tests, 
		suite->number_of_failed_tests);
}

void add_group_to_suite(Suite suite, Group group) {
	printf("Adding a group to the suite.\n");
	suite->group = group;
}

Group make_group() {
	return malloc(sizeof(Group));
}

static void success() {
	current_suite->number_of_successful_tests++;
}

static void failed() {
	current_suite->number_of_failed_tests++;
}


void assert_equal(void *actual, void *expected) {
	if (actual == expected) {
		success();
	}	else {
		failed();
	}
}

void add_to_group(Group group, void (*testFn)(void *)) {
	printf("Adding test to group.\n");
	Test test = malloc(sizeof(Test));
	test->name = "some test name";
	test->test = testFn;
	group->test = test;
}
