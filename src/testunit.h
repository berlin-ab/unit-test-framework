#ifndef TESTUNIT_H
#define TESTUNIT_H
#include <stdio.h>
#include <stdlib.h>

typedef struct TestData *Test;
typedef struct GroupData *Group;
typedef struct SuiteData *Suite;

Suite make_suite();

void run_suite(Suite suite);
void add_group_to_suite(Suite suite, Group group);
/*
 * Groups
 */
void add_to_group(Group group, void (*test_function)(void *));
Group make_group(char *name);
char* get_group_name(Group group);
void run_group(Group group);

/*
 * Assertions
 */
void *equals();
void assert_equal(void *actual, void *expected);



/*
 * Tests
 */
char *get_test_name(Test test);
void run_test(Test test, Group group);
Test make_test(char* test_name, void (*testFn)(void *));



#endif