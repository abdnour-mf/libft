#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h> // To compare with the real isascii

/* int	main(void)
{
	int test_values[] = {
		0, 1, 31,                  // Low control characters
		32, ' ',                   // Space
		'A', 'z', '0', '~',        // Standard printable ASCII
		127,                       // DEL character (boundary of isascii)
		128, 255, 300,             // Extended ASCII and out-of-range (should fail)
		-1, -128                   // Negative numbers (should fail)
	};
	int num_tests = sizeof(test_values) / sizeof(test_values[0]);
	int failed = 0;

	printf("=== RUNNING TESTS FOR ft_isascii ===\n");
	for (int i = 0; i < num_tests; i++)
	{
		int c = test_values[i];
		int mine = ft_isascii(c);
		int real = isascii(c);

		int mine_bool = (mine != 0);
		int real_bool = (real != 0);

		if (mine_bool != real_bool)
		{
			printf("❌ FAILED for input: %d | Yours: %d | Real: %d\n", c, mine, real);
			failed++;
		}
		else
		{
			printf("✅ PASSED for input: %d\n", c);
		}
	}

	if (failed == 0)
		printf("\n🎉 ALL ft_isascii TESTS PASSED SUCCESSFULLY!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);
		
	return (0);
} */