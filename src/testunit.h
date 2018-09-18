typedef struct {
	char* name;
	void (*test)(void *);
} Test;

typedef struct {
	char *name;
	Test *test;
} Group;

typedef struct {
	Group *group;
	int number_of_failed_tests;
	int number_of_successful_tests;
} Suite;

Suite *make_suite();

void run_suite(Suite *suite);
void add_group_to_suite(Suite *suite, Group *group);

Group *make_group();

void *equals();
void assert_equal(void *actual, void *expected);
void add_to_group(Group *group, void (*f)(void *group));