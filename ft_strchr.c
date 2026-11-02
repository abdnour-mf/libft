#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while(s[i])
    {
        if (s[i] ==(char)c)
            return ((char *)&s[i]);
        i++;
    }
    if (s[i] == (char)c)
        return ((char *)&s[i]);
    return (NULL);
}

// #include <stdio.h>
// #include <string.h>

/* int	main(void)
{
	int		failed = 0;
	char	*mine;
	char	*real;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_strchr ===\n");

	// -------------------------------------------------------------
	// TEST 1: Basic Search (First Occurrence)
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		mine = ft_strchr(str, 'i');
		real = strchr(str, 'i');
		if (mine != real || (mine && mine != &str[2]))
		{
			printf("❌ FAILED: Test 1 (First occurrence of 'i': got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Basic search (first occurrence)\n");
	}

	// -------------------------------------------------------------
	// TEST 2: Character Not in String (Return NULL)
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		mine = ft_strchr(str, 'z');
		real = strchr(str, 'z');
		if (mine != real || mine != NULL)
		{
			printf("❌ FAILED: Test 2 (Character not found should return NULL: got %p)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 2 - Character not found returns NULL\n");
	}

	// -------------------------------------------------------------
	// TEST 3: Locating the Null Terminator '\0' (Mandatory libc rule)
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		mine = ft_strchr(str, '\0');
		real = strchr(str, '\0');
		if (mine != real || mine != &str[10])
		{
			printf("❌ FAILED: Test 3 (Search '\\0': got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 3 - Locating null terminator '\\0'\n");
	}

	// -------------------------------------------------------------
	// TEST 4: Empty String with '\0' and Non-'\0'
	// -------------------------------------------------------------
	{
		char empty[] = "";
		mine = ft_strchr(empty, '\0');
		real = strchr(empty, '\0');
		if (mine != real || mine != &empty[0])
		{
			printf("❌ FAILED: Test 4a (Empty string with '\\0': got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 4a - Empty string searching '\\0'\n");

		mine = ft_strchr(empty, 'a');
		real = strchr(empty, 'a');
		if (mine != real || mine != NULL)
		{
			printf("❌ FAILED: Test 4b (Empty string with 'a' should return NULL: got %p)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 4b - Empty string searching 'a'\n");
	}

	// -------------------------------------------------------------
	// TEST 5: First and Last Character Matches
	// -------------------------------------------------------------
	{
		char str[] = "42Network";
		// First char
		mine = ft_strchr(str, '4');
		real = strchr(str, '4');
		if (mine != real || mine != &str[0])
		{
			printf("❌ FAILED: Test 5a (First character match failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 5a - First character match\n");

		// Last char before '\0'
		mine = ft_strchr(str, 'k');
		real = strchr(str, 'k');
		if (mine != real || mine != &str[8])
		{
			printf("❌ FAILED: Test 5b (Last character match failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 5b - Last character match\n");
	}

	// -------------------------------------------------------------
	// TEST 6: Int Overflow / Extended Values (c > 127 or c + 256)
	// (libft-unit-test & francinette trap: passing 'a' + 256 = 353)
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		mine = ft_strchr(str, 't' + 256);
		real = strchr(str, 't' + 256);
		if (mine != real || mine != &str[0])
		{
			printf("❌ FAILED: Test 6 (Value with +256 overflow: got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 6 - Overflow value (c + 256) handled via char conversion\n");
	}

	// -------------------------------------------------------------
	// TEST 7: Negative Int Value (Extended ASCII)
	// -------------------------------------------------------------
	{
		char str[] = "Special\x80""Char";
		mine = ft_strchr(str, (char)-128);
		real = strchr(str, (char)-128);
		if (mine != real || mine != &str[7])
		{
			printf("❌ FAILED: Test 7 (Extended/negative byte search failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 7 - Negative/Extended byte match\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_strchr STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */