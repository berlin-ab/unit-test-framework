#include "../testunit.h"

struct GroupData {
	char *name;
	Test test;
};

Group make_group(char *name) {
	Group group = malloc(sizeof(Group));
	group->name = name;
	return group;
}

void add_to_group(Group group, void (*testFn)(void *)) {
	printf("Adding test to group.\n");
	Test test = make_test("some test name", testFn);
	group->test = test;
}

void run_group(Group group) {
	run_test(group->test, group);
	printf("Running %s.\n", get_test_name(group->test));
}

char* get_group_name(Group group) {
	return group->name;
}

