#include <stdio.h>
#include <stdlib.h>
#include "testunit.h"

void it_has_a_title_for_the_group(void *group) {
	assert_equal(get_group_name(group), "Adding a group");
}

void it_can_have_multiple_tests(void *group) {
	assert_equal("true", "true");
}

Group test_suites() {
	Group group;
	
	group = make_group("Adding a group");
	add_to_group(group, it_has_a_title_for_the_group);
	add_to_group(group, it_can_have_multiple_tests);
	return group;
}

int main(int argc, const char* argv[]) {
	Suite suite = make_suite();
	add_group_to_suite(
		suite,
		test_suites()
	);
	run_suite(suite);
}