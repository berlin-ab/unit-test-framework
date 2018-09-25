#ifndef TESTUNIT_H
#define TESTUNIT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TestData *Test;
typedef struct GroupData *Group;
typedef struct SuiteData *Suite;

/*
 * Assertions
 */
void *equals();
void assert_equal(void *actual, void *expected);

/*
 * Groups
 */
void add_to_group(Group group, void (*test_function)(void *));
Group make_group(char *name);

/*
 * Suites
 */
Suite make_suite();
void run_suite(Suite suite);
void add_group_to_suite(Suite suite, Group group);

#endif