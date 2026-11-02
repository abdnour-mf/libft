#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i = ft_strlen(s);
    while(i >= 0)
    {
        if(s[i] == (char)c)
            return ((char *)&s[i]);
        i--;
    }
    return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	int		failed = 0;
	char	*mine;
	char	*real;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_strrchr ===\n");

	// -------------------------------------------------------------
	// TEST 1: Multiple Occurrences (Must return the LAST one)
	// -------------------------------------------------------------
	{
		char str[] = "bonjour toto";
		mine = ft_strrchr(str, 'o');
		real = strrchr(str, 'o');
		// 'o' is at indices 1, 4, 9, 11 -> last is at index 11
		if (mine != real || mine != &str[11])
		{
			printf("❌ FAILED: Test 1 (Last occurrence of 'o': got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Multiple occurrences (returns last occurrence)\n");
	}

	// -------------------------------------------------------------
	// TEST 2: Single Occurrence (Beginning, Middle, End)
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";

		// Match first character ('t')
		mine = ft_strrchr(str, 't');
		real = strrchr(str, 't');
		if (mine != real || mine != &str[0])
		{
			printf("❌ FAILED: Test 2a (Match at index 0 failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 2a - First character match\n");

		// Match last character ('e')
		mine = ft_strrchr(str, 'e');
		real = strrchr(str, 'e');
		if (mine != real || mine != &str[9])
		{
			printf("❌ FAILED: Test 2b (Match at last index failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 2b - Last character match\n");
	}

	// -------------------------------------------------------------
	// TEST 3: Character Not Found (Must return NULL)
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		mine = ft_strrchr(str, 'z');
		real = strrchr(str, 'z');
		if (mine != real || mine != NULL)
		{
			printf("❌ FAILED: Test 3 (Not found must return NULL: got %p)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 3 - Character not found returns NULL\n");
	}

	// -------------------------------------------------------------
	// TEST 4: Locating Null Terminator '\0'
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		mine = ft_strrchr(str, '\0');
		real = strrchr(str, '\0');
		if (mine != real || mine != &str[10])
		{
			printf("❌ FAILED: Test 4 (Search '\\0': got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 4 - Locating null terminator '\\0'\n");
	}

	// -------------------------------------------------------------
	// TEST 5: Empty String ("")
	// -------------------------------------------------------------
	{
		char empty[] = "";

		mine = ft_strrchr(empty, '\0');
		real = strrchr(empty, '\0');
		if (mine != real || mine != &empty[0])
		{
			printf("❌ FAILED: Test 5a (Empty string with '\\0': got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 5a - Empty string searching '\\0'\n");

		mine = ft_strrchr(empty, 'a');
		real = strrchr(empty, 'a');
		if (mine != real || mine != NULL)
		{
			printf("❌ FAILED: Test 5b (Empty string with 'a' must return NULL)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 5b - Empty string searching 'a'\n");
	}

	// -------------------------------------------------------------
	// TEST 6: Int Overflow / Extended Values (c + 256)
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		mine = ft_strrchr(str, 't' + 256);
		real = strrchr(str, 't' + 256);
		if (mine != real || mine != &str[0])
		{
			printf("❌ FAILED: Test 6 (c + 256 overflow: got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 6 - Overflow value (c + 256)\n");
	}

	// -------------------------------------------------------------
	// TEST 7: Extended ASCII Byte Match (Safe literal concatenation)
	// -------------------------------------------------------------
	{
		char str[] = "Special\x80" "Char\x80" "End";
		// Last '\x80' is at index 12
		mine = ft_strrchr(str, (char)-128);
		real = strrchr(str, (char)-128);
		if (mine != real || mine != &str[12])
		{
			printf("❌ FAILED: Test 7 (Extended byte: got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 7 - Negative/Extended byte match\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_strrchr STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */

