#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *str;

	if (!s)
    	return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

int	main(void)
{
	int		failed = 0;
	char	*sub;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_substr ===\n");

	// -------------------------------------------------------------
	// TEST 1: Basic Substring Extraction
	// -------------------------------------------------------------
	{
		sub = ft_substr("tripouille", 0, 4);
		if (!sub || strcmp(sub, "trip") != 0)
		{
			printf("❌ FAILED: Test 1 (Expected \"trip\", got \"%s\")\n", sub ? sub : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Basic prefix substring\n");
		free(sub);
	}

	// -------------------------------------------------------------
	// TEST 2: Extraction from Middle
	// -------------------------------------------------------------
	{
		sub = ft_substr("tripouille", 4, 4);
		if (!sub || strcmp(sub, "ouil") != 0)
		{
			printf("❌ FAILED: Test 2 (Expected \"ouil\", got \"%s\")\n", sub ? sub : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 2 - Mid-string extraction\n");
		free(sub);
	}

	// -------------------------------------------------------------
	// TEST 3: start Beyond String Length (Mandatory 42 Trap)
	// (Must return valid freeable empty string "", NOT NULL!)
	// -------------------------------------------------------------
	{
		sub = ft_substr("tripouille", 20, 5);
		if (!sub)
		{
			printf("❌ FAILED: Test 3 (start > strlen returned NULL! Must return \"\")\n");
			failed++;
		}
		else if (strcmp(sub, "") != 0 || sub[0] != '\0')
		{
			printf("❌ FAILED: Test 3 (Expected empty string \"\", got \"%s\")\n", sub);
			free(sub);
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 3 - start > strlen returns valid empty string\n");
			free(sub);
		}
	}

	// -------------------------------------------------------------
	// TEST 4: start Exactly at strlen
	// -------------------------------------------------------------
	{
		sub = ft_substr("hello", 5, 3);
		if (!sub || strcmp(sub, "") != 0)
		{
			printf("❌ FAILED: Test 4 (start == strlen must return \"\")\n");
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 4 - start == strlen returns \"\"\n");
			free(sub);
		}
	}

	// -------------------------------------------------------------
	// TEST 5: len Far Exceeds Remaining String (Over-Allocation Trap)
	// -------------------------------------------------------------
	{
		// len is huge; must safely cap to remaining characters ("llo")
		sub = ft_substr("hello", 2, 500000);
		if (!sub || strcmp(sub, "llo") != 0)
		{
			printf("❌ FAILED: Test 5 (Expected \"llo\", got \"%s\")\n", sub ? sub : "NULL");
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 5 - Huge len clamped to string bounds\n");
			free(sub);
		}
	}

	// -------------------------------------------------------------
	// TEST 6: len == 0
	// -------------------------------------------------------------
	{
		sub = ft_substr("tripouille", 3, 0);
		if (!sub)
		{
			printf("❌ FAILED: Test 6 (len == 0 returned NULL! Must return freeable \"\")\n");
			failed++;
		}
		else if (strcmp(sub, "") != 0)
		{
			printf("❌ FAILED: Test 6 (Expected \"\", got \"%s\")\n", sub);
			free(sub);
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 6 - len == 0 returns valid empty string\n");
			free(sub);
		}
	}

	// -------------------------------------------------------------
	// TEST 7: Empty Source String ("")
	// -------------------------------------------------------------
	{
		sub = ft_substr("", 0, 5);
		if (!sub || strcmp(sub, "") != 0)
		{
			printf("❌ FAILED: Test 7 (Empty string source failed)\n");
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 7 - Source string is \"\"\n");
			free(sub);
		}
	}

	// -------------------------------------------------------------
	// TEST 8: NULL Source String Protection
	// -------------------------------------------------------------
	{
		sub = ft_substr(NULL, 0, 5);
		if (sub != NULL)
		{
			printf("❌ FAILED: Test 8 (s == NULL must return NULL)\n");
			free(sub);
			failed++;
		}
		else
			printf("✅ PASSED: Test 8 - s == NULL returns NULL\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_substr STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */