#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h> // To compare with the real isalpha


/* int	main(void)
{
	int test_values[] = {
		'a', 'z', 'A', 'Z',        // Standard letters
		'0', '9',                  // Digits (should fail)
		'@', '[', '`', '{',        // Characters right outside alphabetic ranges
		' ', '\n', '\t',           // Whitespaces
		-1, 0, 127, 255, 300       // Edge case / out-of-range values
	};
	int num_tests = sizeof(test_values) / sizeof(test_values[0]);
	int failed = 0;

	printf("=== RUNNING TESTS FOR ft_isalpha ===\n");
	for (int i = 0; i < num_tests; i++)
	{
		int c = test_values[i];
		int mine = ft_isalpha(c);
		int real = isalpha(c);

		// Note: ft_isalpha and isalpha might return different non-zero integers,
		// but both must agree on whether it's 0 (false) or non-zero (true).
		int mine_bool = (mine != 0);
		int real_bool = (real != 0);

		if (mine_bool != real_bool)
		{
			printf("❌ FAILED for input: %d (char: '%c') | Yours: %d | Real: %d\n", c, c, mine, real);
			failed++;
		}
		else
		{
			printf("✅ PASSED for input: %d (char: '%c')\n", c, c);
		}
	}

	if (failed == 0)
		printf("\n🎉 ALL ft_isalpha TESTS PASSED SUCCESSFULLY!\n");
	else
	{
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);
		printf("Tip: Remember that ft_isalpha should return non-zero for letters and 0 for anything else.\n");
	}
	return (0);
} */


/* int	main(void)
{
	char	test_chars[] = {'A', 'z', '5', '@', ' '};
	int	i;

	printf("--- Testing ft_isalpha vs real isalpha ---\n\n");
	
	i = 0;
	while (i < 5)
	{
		char c = test_chars[i];
		int mine = ft_isalpha(c);
		int real = isalpha(c);

		printf("Character: '%c' (ASCII: %d)\n", c, c);
		printf("  -> ft_isalpha: %d\n", mine);
		printf("  -> real isalpha: %d\n\n", real);
		i++;
	}
	return (0);
} */


/* int	main(void)
{
	int	tests[] = {'A', 'Z', 'a', 'z', 'M', 'm',
		'0', '9', ' ', '\n', '@', '[', '`', '{', -1, 128};
	int	i;
	int	real_result;
	int	my_result;
	int	errors;

	errors = 0;
	printf("%-8s %-15s %-15s %-10s\n",
		"Input", "Real isalpha", "ft_isalpha", "Status");
	printf("------------------------------------------------\n");
	i = 0;
	while (i < (int)(sizeof(tests) / sizeof(tests[0])))
	{
		real_result = (isalpha(tests[i]) != 0);
		my_result = ft_isalpha(tests[i]);
		printf("%-8d %-15d %-15d %-10s\n",
			tests[i], real_result, my_result,
			(real_result == my_result) ? "PASS" : "FAIL");
		if (real_result != my_result)
			errors++;
		i++;
	}
	printf("------------------------------------------------\n");
	printf("Total: %d | Passed: %d | Failed: %d\n",
		(int)(sizeof(tests) / sizeof(tests[0])) - errors, 
		(int)(sizeof(tests) / sizeof(tests[0])) - errors, errors);
	return (errors != 0);
} */

