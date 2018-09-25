#ifndef TESTUNIT_INTERNAL_H
#define TESTUNIT_INTERNAL_H

char *get_test_name(Test test);
void run_test(Test test, Group group);
Test make_test(char* test_name, void (*testFn)(void *));

#endif