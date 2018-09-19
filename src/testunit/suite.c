#include "../testunit.h"
#include <stdlib.h>
#include <stdio.h>

struct SuiteData {
	Group group;
	int number_of_failed_tests;
	int number_of_successful_tests;
};

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

	if (suite->group) {
		run_group(suite->group);
	}

	printf("Ran %d tests. %d succeeded. %d failed.\n",
	       suite->number_of_failed_tests+suite->number_of_successful_tests,
	       suite->number_of_successful_tests,
	       suite->number_of_failed_tests);
}

static void success() {
	current_suite->number_of_successful_tests++;
}

static void failed() {
	current_suite->number_of_failed_tests++;
}

void add_group_to_suite(Suite suite, Group group) {
	printf("Adding a group to the suite.\n");
	suite->group = group;
}


void assert_equal(void *actual, void *expected) {
	if (actual == expected) {
		success();
	}	else {
		failed();
	}
}
