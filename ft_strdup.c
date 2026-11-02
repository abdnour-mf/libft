#include "libft.h"

char *ft_strdup(const char *s)
{
	char *copy;
	size_t len = ft_strlen(s);
	size_t i = 0;

	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	while(s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s);

int	main(void)
{
	int		failed = 0;
	char	*dup;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_strdup ===\n");

	// -------------------------------------------------------------
	// TEST 1: Standard String & Content Equality
	// -------------------------------------------------------------
	{
		const char	*src = "Hello 1337 MED!";
		dup = ft_strdup(src);
		if (!dup)
		{
			printf("❌ FAILED: Test 1 (Returned NULL for valid string)\n");
			failed++;
		}
		else if (strcmp(dup, src) != 0)
		{
			printf("❌ FAILED: Test 1 (Content mismatch: got \"%s\", expected \"%s\")\n", dup, src);
			free(dup);
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 1 - Basic string copy\n");
			free(dup);
		}
	}

	// -------------------------------------------------------------
	// TEST 2: Heap Independence (Deep Copy Verification)
	// -------------------------------------------------------------
	{
		char	src[] = "Mutable Source";
		dup = ft_strdup(src);
		if (!dup)
		{
			printf("❌ FAILED: Test 2 (Allocation failed)\n");
			failed++;
		}
		else if (dup == src)
		{
			printf("❌ FAILED: Test 2 (Returned identical pointer instead of new heap allocation!)\n");
			failed++;
		}
		else
		{
			// Mutate duplicate; source must remain unaffected
			dup[0] = 'Z';
			if (src[0] == 'Z')
			{
				printf("❌ FAILED: Test 2 (Mutating copy altered source string!)\n");
				failed++;
			}
			else
				printf("✅ PASSED: Test 2 - Heap isolation and independent memory\n");
			free(dup);
		}
	}

	// -------------------------------------------------------------
	// TEST 3: Empty String ("")
	// -------------------------------------------------------------
	{
		const char	*src = "";
		dup = ft_strdup(src);
		if (!dup)
		{
			printf("❌ FAILED: Test 3 (Empty string returned NULL! Must return freeable allocated \"\")\n");
			failed++;
		}
		else if (dup[0] != '\0' || strlen(dup) != 0)
		{
			printf("❌ FAILED: Test 3 (Empty string copy not null-terminated)\n");
			free(dup);
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 3 - Empty string allocation & termination\n");
			free(dup);
		}
	}

	// -------------------------------------------------------------
	// TEST 4: Null Terminator Exact Position & Length Check
	// -------------------------------------------------------------
	{
		const char	*src = "CheckTermination123";
		size_t		len = strlen(src);

		dup = ft_strdup(src);
		if (!dup)
		{
			printf("❌ FAILED: Test 4 (Allocation failed)\n");
			failed++;
		}
		else if (dup[len] != '\0')
		{
			printf("❌ FAILED: Test 4 (Missing null terminator at index %zu)\n", len);
			free(dup);
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 4 - Precise null terminator placement\n");
			free(dup);
		}
	}

	// -------------------------------------------------------------
	// TEST 5: Embedded Non-Printable & Extended ASCII Bytes
	// -------------------------------------------------------------
	{
		const char	src[] = "Tab\tNewline\nExtended" "\x80" "End";
		dup = ft_strdup(src);
		if (!dup)
		{
			printf("❌ FAILED: Test 5 (Allocation failed on special chars)\n");
			failed++;
		}
		else if (strcmp(dup, src) != 0)
		{
			printf("❌ FAILED: Test 5 (Mismatch on tabs, newlines, or extended ASCII)\n");
			free(dup);
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 5 - Special characters & extended ASCII preserved\n");
			free(dup);
		}
	}

	// -------------------------------------------------------------
	// TEST 6: Large String Duplication
	// -------------------------------------------------------------
	{
		size_t	big_len = 50000;
		char	*big_src = malloc(big_len + 1);

		if (!big_src)
		{
			printf("⚠️  SKIPPED: Test 6 (Failed to allocate source buffer for test)\n");
		}
		else
		{
			memset(big_src, 'A', big_len);
			big_src[big_len] = '\0';
			dup = ft_strdup(big_src);
			if (!dup)
			{
				printf("❌ FAILED: Test 6 (Failed to duplicate 50k character string)\n");
				failed++;
			}
			else if (dup[0] != 'A' || dup[big_len - 1] != 'A' || dup[big_len] != '\0')
			{
				printf("❌ FAILED: Test 6 (50k character string integrity failure)\n");
				failed++;
			}
			else
				printf("✅ PASSED: Test 6 - Large string duplication (50,000 bytes)\n");
			free(big_src);
			free(dup);
		}
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_strdup STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */