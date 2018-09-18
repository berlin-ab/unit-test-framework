#include <stdio.h>
#include "testunit.h"

void it_works(Group *group) {
	assert_equal(group->name, "Tic tac toe tests");
}

Group *tic_tac_toe() {
	Group *group;
	
	group = make_group("Tic tac toe tests");
	
	add_to_group(group, (void*)it_works);
	
	return group;
}

int main(int argc, const char* argv[]) {
	Suite *suite = make_suite();
	add_group_to_suite(
		suite,
		tic_tac_toe()
	);
	run_suite(suite);
}