#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char *str;
	size_t start;
	size_t end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	str = ft_substr(s1, start, end - start);
	return (str);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set);

int	main(void)
{
	int		failed = 0;
	char	*res;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_strtrim ===\n");

	// -------------------------------------------------------------
	// TEST 1: Basic Both-End Trimming
	// -------------------------------------------------------------
	{
		res = ft_strtrim("   Hello 42!   ", " ");
		if (!res || strcmp(res, "Hello 42!") != 0)
		{
			printf("❌ FAILED: Test 1 (Expected \"Hello 42!\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Basic space trimming\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 2: Multi-Character Set Trimming
	// -------------------------------------------------------------
	{
		res = ft_strtrim("abracadabra", "ab");
		if (!res || strcmp(res, "racadabr") != 0)
		{
			printf("❌ FAILED: Test 2 (Expected \"racadabr\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 2 - Multi-character set trimming\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 3: All-Trimmed String (Critical Underflow Trap)
	// (Must return valid, freeable empty string "", NOT NULL!)
	// -------------------------------------------------------------
	{
		res = ft_strtrim("xxxxxxxx", "x");
		if (!res)
		{
			printf("❌ FAILED: Test 3a (All-trimmed returned NULL! Must return freeable \"\")\n");
			failed++;
		}
		else if (strcmp(res, "") != 0 || res[0] != '\0')
		{
			printf("❌ FAILED: Test 3a (Expected \"\", got \"%s\")\n", res);
			free(res);
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 3a - All-trimmed string returns \"\"\n");
			free(res);
		}

		res = ft_strtrim(" \t \n \r \v \f ", " \t\n\r\v\f");
		if (!res || strcmp(res, "") != 0)
		{
			printf("❌ FAILED: Test 3b (All-whitespace trimmed returned \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 3b - All-whitespace set trimmed cleanly\n");
			free(res);
		}
	}

	// -------------------------------------------------------------
	// TEST 4: Empty s1 ("")
	// -------------------------------------------------------------
	{
		res = ft_strtrim("", "abc");
		if (!res || strcmp(res, "") != 0)
		{
			printf("❌ FAILED: Test 4 (Empty s1 returned \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 4 - Empty s1 returns \"\"\n");
			free(res);
		}
	}

	// -------------------------------------------------------------
	// TEST 5: Empty Set ("") -> No Trimming
	// -------------------------------------------------------------
	{
		res = ft_strtrim("  keep spaces  ", "");
		if (!res || strcmp(res, "  keep spaces  ") != 0)
		{
			printf("❌ FAILED: Test 5 (Expected \"  keep spaces  \", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 5 - Empty set leaves string untouched\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 6: Middle Characters Untouched
	// -------------------------------------------------------------
	{
		res = ft_strtrim("xxHello xxx Worldxx", "x");
		if (!res || strcmp(res, "Hello xxx World") != 0)
		{
			printf("❌ FAILED: Test 6 (Middle set characters were improperly trimmed! Got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 6 - Middle matching characters preserved\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 7: Only Beginning Trimmed / Only Ending Trimmed
	// -------------------------------------------------------------
	{
		// Only start
		res = ft_strtrim("000042", "0");
		if (!res || strcmp(res, "42") != 0)
		{
			printf("❌ FAILED: Test 7a (Expected \"42\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 7a - Only prefix trimmed\n");
		free(res);

		// Only end
		res = ft_strtrim("420000", "0");
		if (!res || strcmp(res, "42") != 0)
		{
			printf("❌ FAILED: Test 7b (Expected \"42\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 7b - Only suffix trimmed\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 8: Nothing to Trim (No matches in set)
	// -------------------------------------------------------------
	{
		res = ft_strtrim("NoMatchesHere", "xyz");
		if (!res || strcmp(res, "NoMatchesHere") != 0)
		{
			printf("❌ FAILED: Test 8 (Expected \"NoMatchesHere\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 8 - No set characters present\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 9: NULL Defense
	// -------------------------------------------------------------
	{
		res = ft_strtrim(NULL, "abc");
		if (res != NULL)
		{
			printf("❌ FAILED: Test 9a (s1 == NULL must return NULL)\n");
			free(res);
			failed++;
		}
		else
			printf("✅ PASSED: Test 9a - s1 == NULL returns NULL\n");

		res = ft_strtrim("abc", NULL);
		if (res != NULL)
		{
			printf("❌ FAILED: Test 9b (set == NULL must return NULL)\n");
			free(res);
			failed++;
		}
		else
			printf("✅ PASSED: Test 9b - set == NULL returns NULL\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_strtrim STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
}