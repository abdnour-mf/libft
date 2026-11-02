#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i;
	
	if (!s || !f)
        return ;
    i = 0;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// Test function 1: Alternating uppercase based on even/odd index
static void	test_even_upper(unsigned int i, char *c)
{
	if (i % 2 == 0 && (*c >= 'a' && *c <= 'z'))
		*c -= 32;
}

// Test function 2: Add index offset to character
static void	test_add_index(unsigned int i, char *c)
{
	*c += (char)i;
}

// Test function 3: Shift character by 1
static void	test_rot1(unsigned int i, char *c)
{
	(void)i;
	*c += 1;
}

int	main(void)
{
	int	failed = 0;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_striteri ===\n");

	// -------------------------------------------------------------
	// TEST 1: Basic In-Place Modification & Index Alternation
	// -------------------------------------------------------------
	{
		char	str[] = "abcdef";

		ft_striteri(str, test_even_upper);
		if (strcmp(str, "AbCdEf") != 0)
		{
			printf("❌ FAILED: Test 1 (Expected \"AbCdEf\", got \"%s\")\n", str);
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Even/odd index alternating in-place mutation\n");
	}

	// -------------------------------------------------------------
	// TEST 2: Index Addition Verification
	// -------------------------------------------------------------
	{
		char	str[] = "00000";

		ft_striteri(str, test_add_index);
		if (strcmp(str, "01234") != 0)
		{
			printf("❌ FAILED: Test 2 (Expected \"01234\", got \"%s\")\n", str);
			failed++;
		}
		else
			printf("✅ PASSED: Test 2 - Sequential index validation (c + i)\n");
	}

	// -------------------------------------------------------------
	// TEST 3: Uniform Shift
	// -------------------------------------------------------------
	{
		char	str[] = "abc";

		ft_striteri(str, test_rot1);
		if (strcmp(str, "bcd") != 0)
		{
			printf("❌ FAILED: Test 3 (Expected \"bcd\", got \"%s\")\n", str);
			failed++;
		}
		else
			printf("✅ PASSED: Test 3 - Pointer dereference mutation\n");
	}

	// -------------------------------------------------------------
	// TEST 4: Empty String ("")
	// -------------------------------------------------------------
	{
		char	str[] = "";

		ft_striteri(str, test_even_upper);
		if (str[0] != '\0')
		{
			printf("❌ FAILED: Test 4 (Empty string was corrupted!)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 4 - Empty string remains untouched\n");
	}

	// -------------------------------------------------------------
	// TEST 5: Null-Terminator Integrity Check
	// (Ensure f is never called on '\0')
	// -------------------------------------------------------------
	{
		char	str[5] = "test";

		// test_rot1 would shift '\0' to '\1' if called out-of-bounds
		ft_striteri(str, test_rot1);
		if (str[4] != '\0')
		{
			printf("❌ FAILED: Test 5 (Null terminator was overwritten!)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 5 - Null terminator preserved without modification\n");
	}

	// -------------------------------------------------------------
	// TEST 6: Single Character
	// -------------------------------------------------------------
	{
		char	str[] = "x";

		ft_striteri(str, test_even_upper);
		if (strcmp(str, "X") != 0)
		{
			printf("❌ FAILED: Test 6 (Expected \"X\", got \"%s\")\n", str);
			failed++;
		}
		else
			printf("✅ PASSED: Test 6 - Single character string\n");
	}

	// -------------------------------------------------------------
	// TEST 7: NULL Pointer Guards (Must not crash)
	// -------------------------------------------------------------
	{
		char	str[] = "safe";

		ft_striteri(NULL, test_even_upper);
		printf("✅ PASSED: Test 7a - s == NULL safely ignored\n");

		ft_striteri(str, NULL);
		if (strcmp(str, "safe") != 0)
		{
			printf("❌ FAILED: Test 7b (String mutated when f was NULL)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 7b - f == NULL safely ignored\n");

		ft_striteri(NULL, NULL);
		printf("✅ PASSED: Test 7c - Both NULL safely ignored\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_striteri STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */
