#include "libft.h"


int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;

    while(i < n && s1[i] && s1[i] == s2[i])
        i++;
    if (i == n)
        return (0);
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* #include <stdio.h>
#include <string.h>

static int	normalize_sign(int val)
{
	if (val < 0)
		return (-1);
	if (val > 0)
		return (1);
	return (0);
}

int	main(void)
{
	int	failed = 0;
	int	mine;
	int	real;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_strncmp ===\n");

	// -------------------------------------------------------------
	// TEST 1: Identical Strings & Complete Match
	// -------------------------------------------------------------
	{
		mine = ft_strncmp("Hello 42", "Hello 42", 8);
		real = strncmp("Hello 42", "Hello 42", 8);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 1 (Exact match: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Identical strings match\n");
	}

	// -------------------------------------------------------------
	// TEST 2: Difference Within n Limit (s1 < s2 and s1 > s2)
	// -------------------------------------------------------------
	{
		mine = ft_strncmp("abc", "abd", 3);
		real = strncmp("abc", "abd", 3);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 2a (s1 < s2: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 2a - Difference within n (s1 < s2)\n");

		mine = ft_strncmp("abd", "abc", 3);
		real = strncmp("abd", "abc", 3);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 2b (s1 > s2: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 2b - Difference within n (s1 > s2)\n");
	}

	// -------------------------------------------------------------
	// TEST 3: Difference Outside n Limit (Must return 0)
	// -------------------------------------------------------------
	{
		mine = ft_strncmp("abcdef", "abcxyz", 3);
		real = strncmp("abcdef", "abcxyz", 3);
		if (mine != 0)
		{
			printf("❌ FAILED: Test 3 (Diff outside n should return 0: mine=%d)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 3 - Difference outside n returns 0\n");
	}

	// -------------------------------------------------------------
	// TEST 4: n == 0 (Must return 0 immediately)
	// -------------------------------------------------------------
	{
		mine = ft_strncmp("12345", "67890", 0);
		real = strncmp("12345", "67890", 0);
		if (mine != 0)
		{
			printf("❌ FAILED: Test 4 (n == 0 should return 0: mine=%d)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 4 - n == 0 returns 0\n");
	}

	// -------------------------------------------------------------
	// TEST 5: Stop Comparison at '\0' When n is Large
	// -------------------------------------------------------------
	{
		mine = ft_strncmp("tripouille", "tripouille", 42);
		real = strncmp("tripouille", "tripouille", 42);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 5 (n > strlen stopped incorrectly: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 5 - Stop at '\\0' when n is large\n");
	}

	// -------------------------------------------------------------
	// TEST 6: Prefix vs Full String (One string ends before other)
	// -------------------------------------------------------------
	{
		mine = ft_strncmp("test", "testing", 6);
		real = strncmp("test", "testing", 6);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 6a (Short s1: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 6a - Short s1 against longer s2\n");

		mine = ft_strncmp("testing", "test", 6);
		real = strncmp("testing", "test", 6);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 6b (Long s1: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 6b - Longer s1 against short s2\n");
	}

	// -------------------------------------------------------------
	// TEST 7: Empty String Edge Cases
	// -------------------------------------------------------------
	{
		mine = ft_strncmp("", "", 5);
		real = strncmp("", "", 5);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 7a (Both empty: mine=%d)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 7a - Both strings empty\n");

		mine = ft_strncmp("", "1", 1);
		real = strncmp("", "1", 1);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 7b (s1 empty: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 7b - s1 empty against s2\n");
	}

	// -------------------------------------------------------------
	// TEST 8: Unsigned Char Cast Trap (\200 vs \0)
	// (francinette / tripouille mandatory trap)
	// -------------------------------------------------------------
	{
		mine = ft_strncmp("test\200", "test\0", 6);
		real = strncmp("test\200", "test\0", 6);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 8 (Unsigned char trap: mine=%d, real=%d. Needs unsigned char cast!)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 8 - Unsigned char comparison with \\200\n");
	}

	// -------------------------------------------------------------
	// TEST 9: High Bit Extended ASCII Comparison (\xff vs \0)
	// -------------------------------------------------------------
	{
		mine = ft_strncmp("\xff\xaa\xde", "\xff\xaa\xdf", 3);
		real = strncmp("\xff\xaa\xde", "\xff\xaa\xdf", 3);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 9 (Extended ASCII differences: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 9 - Extended ASCII comparison\n");
	}
    // -------------------------------------------------------------
	// TEST 10: Embedded Null with Differing Garbage Past '\0'
	// (Verifies comparison halts strictly at '\0' and ignores garbage)
	// -------------------------------------------------------------
	{
		char b1[10] = {'a', 'b', 'c', '\0', 'X', 'X', 'X', 'X', 'X', 'X'};
		char b2[10] = {'a', 'b', 'c', '\0', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'};

		mine = ft_strncmp(b1, b2, 8);
		real = strncmp(b1, b2, 8);
		if (mine != 0)
		{
			printf("❌ FAILED: Test 10 (Did not stop at '\\0'! Read garbage past null: mine=%d, expected=0)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 10 - Stops at '\\0' despite differing bytes after null\n");
	}

	// -------------------------------------------------------------
	// TEST 11: Exact Match Where n == strlen(s1) + 1
	// (Checks boundary right at the null terminator byte)
	// -------------------------------------------------------------
	{
		mine = ft_strncmp("1234", "1234", 5);
		real = strncmp("1234", "1234", 5);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 11 (Failed right on the '\\0' boundary)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 11 - Exact boundary on the '\\0' byte\n");
	}

	// -------------------------------------------------------------
	// TEST 12: Both Strings Are Just "\0" With Non-Zero n
	// -------------------------------------------------------------
	{
		mine = ft_strncmp("\0a", "\0b", 2);
		real = strncmp("\0a", "\0b", 2);
		if (mine != 0)
		{
			printf("❌ FAILED: Test 12 (Strings start with '\\0' but compared past it: mine=%d)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 12 - First character is '\\0' with n > 1\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_strncmp STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */