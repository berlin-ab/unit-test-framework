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
 
char* get_group_name(Group group) {
	return group->name;
}

void run_test(Test test, Group group) {
	test->test(group);
}

void run_group(Group group) {
	run_test(group->test, group);
	printf("Running %s.\n", get_test_name(group->test));
}

Group make_group(char *name) {
	Group group = malloc(sizeof(Group));
	group->name = name;
	return group;
}

char *get_test_name(Test test) {
	return test->name;
}

void add_to_group(Group group, void (*testFn)(void *)) {
	printf("Adding test to group.\n");
	Test test = malloc(sizeof(Test));
	test->name = "some test name";
	test->test = testFn;
	group->test = test;
}
