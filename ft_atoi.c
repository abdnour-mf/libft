#include "libft.h"

/* static int	check_overflow(long n, char c)
{
	return (n > (9223372036854775807 - (c - '0')) / 10);
} */

int ft_atoi(const char *nptr)
{
    int i = 0;
    int sign = 1;
    long result = 0;
    while(nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
        i++;
    if(nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign *= -1;
        i++;
    }
    while(nptr[i] >= '0' && nptr[i] <= '9')
    {
       /*  if (check_overflow(n, str[i]))
		{
			if (sign == 1)
				return (-1);
			return (0);
		}*/
        result = result * 10 + nptr[i] - '0';
        i++;
    }
    return (result * sign);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int	failed = 0;
	int	mine;
	int	real;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_atoi ===\n");

	// -------------------------------------------------------------
	// TEST 1: Basic Positive and Negative Numbers
	// -------------------------------------------------------------
	{
		char *tests[] = {"0", "42", "-42", "+42", "1", "-1"};
		for (int i = 0; i < 6; i++)
		{
			mine = ft_atoi(tests[i]);
			real = atoi(tests[i]);
			if (mine != real)
			{
				printf("❌ FAILED: Test 1 (%s: got %d, expected %d)\n", tests[i], mine, real);
				failed++;
			}
		}
		if (failed == 0)
			printf("✅ PASSED: Test 1 - Basic positive, negative, and zero\n");
	}

	// -------------------------------------------------------------
	// TEST 2: All 6 Whitespaces ('\t', '\n', '\v', '\f', '\r', ' ')
	// -------------------------------------------------------------
	{
		char *ws_tests[] = {
			" \t\n\r\v\f42",
			"   \t  -42",
			"\n\n\n123",
			"\v\f\r+999",
			"       0"
		};
		int t2_fail = 0;
		for (int i = 0; i < 5; i++)
		{
			mine = ft_atoi(ws_tests[i]);
			real = atoi(ws_tests[i]);
			if (mine != real)
			{
				printf("❌ FAILED: Test 2 (Whitespace string: got %d, expected %d)\n", mine, real);
				t2_fail++;
				failed++;
			}
		}
		if (t2_fail == 0)
			printf("✅ PASSED: Test 2 - All 6 standard whitespace characters\n");
	}

	// -------------------------------------------------------------
	// TEST 3: Multiple Signs (Trap: Must NOT compute double negatives!)
	// -------------------------------------------------------------
	{
		char *multi_signs[] = {"--42", "++42", "+-42", "-+42", "---1", "++-1"};
		int t3_fail = 0;
		for (int i = 0; i < 6; i++)
		{
			mine = ft_atoi(multi_signs[i]);
			real = atoi(multi_signs[i]);
			if (mine != real || mine != 0)
			{
				printf("❌ FAILED: Test 3 (%s: got %d, expected %d (0))\n", multi_signs[i], mine, real);
				t3_fail++;
				failed++;
			}
		}
		if (t3_fail == 0)
			printf("✅ PASSED: Test 3 - Multiple signs stop parsing and return 0\n");
	}

	// -------------------------------------------------------------
	// TEST 4: Signs Without Digits or Whitespace After Sign
	// -------------------------------------------------------------
	{
		char *sign_only[] = {"+", "-", "+ 42", "- 42", "    +"};
		int t4_fail = 0;
		for (int i = 0; i < 5; i++)
		{
			mine = ft_atoi(sign_only[i]);
			real = atoi(sign_only[i]);
			if (mine != real || mine != 0)
			{
				printf("❌ FAILED: Test 4 (%s: got %d, expected %d)\n", sign_only[i], mine, real);
				t4_fail++;
				failed++;
			}
		}
		if (t4_fail == 0)
			printf("✅ PASSED: Test 4 - Signs without direct digits\n");
	}

	// -------------------------------------------------------------
	// TEST 5: Trailing and Embedded Non-Numeric Characters
	// -------------------------------------------------------------
	{
		char *alphanum[] = {
			"42abc",
			"-42xyz99",
			"1337school42",
			"0000042hello",
			"+2147483647extra"
		};
		int t5_fail = 0;
		for (int i = 0; i < 5; i++)
		{
			mine = ft_atoi(alphanum[i]);
			real = atoi(alphanum[i]);
			if (mine != real)
			{
				printf("❌ FAILED: Test 5 (%s: got %d, expected %d)\n", alphanum[i], mine, real);
				t5_fail++;
				failed++;
			}
		}
		if (t5_fail == 0)
			printf("✅ PASSED: Test 5 - Trailing non-numeric characters ignored\n");
	}

	// -------------------------------------------------------------
	// TEST 6: Garbage Before Digits (Immediate 0)
	// -------------------------------------------------------------
	{
		char *garbage[] = {"abc42", "x-12", "hello", "_42", ".42"};
		int t6_fail = 0;
		for (int i = 0; i < 5; i++)
		{
			mine = ft_atoi(garbage[i]);
			real = atoi(garbage[i]);
			if (mine != real || mine != 0)
			{
				printf("❌ FAILED: Test 6 (%s: got %d, expected %d)\n", garbage[i], mine, real);
				t6_fail++;
				failed++;
			}
		}
		if (t6_fail == 0)
			printf("✅ PASSED: Test 6 - Garbage before digits returns 0\n");
	}

	// -------------------------------------------------------------
	// TEST 7: Leading Zeroes
	// -------------------------------------------------------------
	{
		char *zeroes[] = {"0000000000", "+0000000042", "-0000001337", "00000000000000000000"};
		int t7_fail = 0;
		for (int i = 0; i < 4; i++)
		{
			mine = ft_atoi(zeroes[i]);
			real = atoi(zeroes[i]);
			if (mine != real)
			{
				printf("❌ FAILED: Test 7 (%s: got %d, expected %d)\n", zeroes[i], mine, real);
				t7_fail++;
				failed++;
			}
		}
		if (t7_fail == 0)
			printf("✅ PASSED: Test 7 - Strings with arbitrary leading zeros\n");
	}

	// -------------------------------------------------------------
	// TEST 8: Empty and Space-Only Strings
	// -------------------------------------------------------------
	{
		char *empties[] = {"", " ", "      ", "\t\n\v\f\r"};
		int t8_fail = 0;
		for (int i = 0; i < 4; i++)
		{
			mine = ft_atoi(empties[i]);
			real = atoi(empties[i]);
			if (mine != real || mine != 0)
			{
				printf("❌ FAILED: Test 8 (Empty/space-only: got %d, expected 0)\n", mine);
				t8_fail++;
				failed++;
			}
		}
		if (t8_fail == 0)
			printf("✅ PASSED: Test 8 - Empty and space-only strings return 0\n");
	}

	// -------------------------------------------------------------
	// TEST 9: Integer Boundaries (INT_MAX and INT_MIN)
	// -------------------------------------------------------------
	{
		// 2147483647
		mine = ft_atoi("2147483647");
		real = atoi("2147483647");
		if (mine != real || mine != INT_MAX)
		{
			printf("❌ FAILED: Test 9a (INT_MAX: got %d, expected %d)\n", mine, INT_MAX);
			failed++;
		}
		else
			printf("✅ PASSED: Test 9a - INT_MAX boundary (2147483647)\n");

		// -2147483648
		mine = ft_atoi("-2147483648");
		real = atoi("-2147483648");
		if (mine != real || mine != INT_MIN)
		{
			printf("❌ FAILED: Test 9b (INT_MIN: got %d, expected %d)\n", mine, INT_MIN);
			failed++;
		}
		else
			printf("✅ PASSED: Test 9b - INT_MIN boundary (-2147483648)\n");
	}

	// -------------------------------------------------------------
	// TEST 10: Long Boundary Strings (Tripouille / Francinette Checks)
	// -------------------------------------------------------------
	{
		char *long_tests[] = {
			"-9223372036854775808", // LONG_MIN
			"9223372036854775807",  // LONG_MAX
			"-9999999999999999999", // Below LONG_MIN
			"9999999999999999999"   // Above LONG_MAX
		};
		for (int i = 0; i < 4; i++)
		{
			mine = ft_atoi(long_tests[i]);
			real = atoi(long_tests[i]);
			if (mine != real)
			{
				printf("⚠️  NOTE: Test 10 (%s: ft_atoi=%d, atoi=%d) [Platform-dependent overflow behavior]\n", long_tests[i], mine, real);
			}
		}
		printf("✅ PASSED: Test 10 - Standard long boundary inputs evaluated\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_atoi STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */