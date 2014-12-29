#include <project.h>

#include <signal.h>

static void test_simple_mix(t_test *test)
{
	debug_on();
	assert_printf("s: %s, p: %p, d:%d", "a string", &test_simple_mix, 42);
	debug_off();
} 

static void test_super_mix(t_test *test)
{
	debug_on();
	assert_printf("%s%p%d%d%p%s%p%p%s",
		"a", &free, 1, 2, &malloc, "b", &free, &malloc, "c")  ;
	debug_off();
}

void	suite_06_mix_sdp_percent(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_mix);
	SUITE_ADD_TEST(suite, test_super_mix);
}
