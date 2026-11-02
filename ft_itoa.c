#include "libft.h"

static size_t counter(long n)
{
    size_t digit;
    
    digit = 0;
    if (n == 0)
        return (1);
    if (n < 0)
    {
        digit++;
        n = -n;
    }
    while (n > 0)
    {
        n /= 10;
        digit++;
    }
    return (digit);
}

char *ft_itoa(int n)
{
    char *number;
    long nb;
    int i;

    nb = n;
    i = counter(n);
    number = malloc((i + 1) * sizeof(char));
    if (!number)
        return (NULL);
    if (nb == 0)
        number[0] = '0';
    if (nb < 0)
    {
        number[0] = '-';
        nb = -nb;
    }
    number[i] = '\0';
    while(nb)
    {
        number[--i] = nb % 10 + '0';
        nb /= 10;
    }
    return (number);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char	*ft_itoa(int n);

typedef struct s_itoa_test
{
	int			input;
	const char	*expected;
	const char	*desc;
}	t_itoa_test;

int	main(void)
{
	int		failed = 0;
	char	*res;

	t_itoa_test tests[] = {
		// Zero
		{0, "0", "Zero"},

		// Single positive and negative digits
		{1, "1", "Single digit positive (1)"},
		{7, "7", "Single digit positive (7)"},
		{-1, "-1", "Single digit negative (-1)"},
		{-8, "-8", "Single digit negative (-8)"},

		// Standard numbers
		{42, "42", "Standard positive (42)"},
		{-42, "-42", "Standard negative (-42)"},
		{1337, "1337", "Multiple digits (1337)"},
		{-1337, "-1337", "Multiple digits negative (-1337)"},
		{10000, "10000", "Powers of ten (10000)"},
		{-10000, "-10000", "Negative powers of ten (-10000)"},

		// Alternating digits and special patterns
		{1020304, "1020304", "Embedded zeros"},
		{-1020304, "-1020304", "Negative embedded zeros"},

		// Boundary tests: INT_MAX and INT_MIN
		{INT_MAX, "2147483647", "INT_MAX (2147483647)"},
		{INT_MAX - 1, "2147483646", "INT_MAX - 1"},
		{INT_MIN + 1, "-2147483647", "INT_MIN + 1"},
		{INT_MIN, "-2147483648", "INT_MIN (-2147483648) [CRUCIAL TRAP]"},

		// End marker
		{0, NULL, NULL}
	};

	printf("=== EXHAUSTIVE STRESS TESTS: ft_itoa ===\n");

	for (int i = 0; tests[i].desc != NULL; i++)
	{
		res = ft_itoa(tests[i].input);
		if (!res)
		{
			printf("❌ FAILED: [%s] -> returned NULL!\n", tests[i].desc);
			failed++;
		}
		else if (strcmp(res, tests[i].expected) != 0)
		{
			printf("❌ FAILED: [%s] -> input %d: got \"%s\", expected \"%s\"\n",
				tests[i].desc, tests[i].input, res, tests[i].expected);
			failed++;
			free(res);
		}
		else
		{
			// Verify precise null-termination
			size_t expected_len = strlen(tests[i].expected);
			if (res[expected_len] != '\0')
			{
				printf("❌ FAILED: [%s] -> missing null terminator at exact index %zu\n",
					tests[i].desc, expected_len);
				failed++;
			}
			else
			{
				printf("✅ PASSED: [%s] -> %d => \"%s\"\n",
					tests[i].desc, tests[i].input, res);
			}
			free(res);
		}
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_itoa STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */
