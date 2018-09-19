#include "../testunit.h"

struct TestData {
	char* name;
	void (*test)(void *);
};

void run_test(Test test, Group group) {
	test->test(group);
}

Test make_test(char* test_name, void (*testFn)(void *)) {
	Test test = malloc(sizeof(Test));
	test->name = test_name;
	test->test = testFn;
	return test;
}

char *get_test_name(Test test) {
	return test->name;
}