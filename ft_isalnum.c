#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h> // To compare with the real isalnum

/* int	main(void)
{
	int test_values[] = {
		'a', 'z', 'A', 'Z',        // Letters
		'0', '5', '9',             // Digits
		'/', ':', '@', '[', '`',   // Characters just outside alphanumeric ranges
		' ', '\n', '\t', '\0',     // Whitespaces and null byte
		-1, 0, 127, 255, 300       // Out-of-range edge cases
	};
	int num_tests = sizeof(test_values) / sizeof(test_values[0]);
	int failed = 0;

	printf("=== RUNNING TESTS FOR ft_isalnum ===\n");
	for (int i = 0; i < num_tests; i++)
	{
		int c = test_values[i];
		int mine = ft_isalnum(c);
		int real = isalnum(c);

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
		printf("\n🎉 ALL ft_isalnum TESTS PASSED SUCCESSFULLY!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);
		
	return (0);
} */
