typedef struct TestData *Test;
typedef struct GroupData *Group;
typedef struct SuiteData *Suite;

Suite make_suite();

void run_suite(Suite suite);
void add_group_to_suite(Suite suite, Group group);

Group make_group();
char* get_group_name(Group group);

void *equals();
void assert_equal(void *actual, void *expected);
void add_to_group(Group group, void (*f)(void *group));