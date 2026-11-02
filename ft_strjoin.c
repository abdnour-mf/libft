#include "libft.h"

/* char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	size_t i;
	size_t j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
} */

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	size_t len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len);
	ft_strlcat(str, s2, len);
	return (str);
}


/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2);

int	main(void)
{
	int		failed = 0;
	char	*res;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_strjoin ===\n");

	// -------------------------------------------------------------
	// TEST 1: Basic Concatenation
	// -------------------------------------------------------------
	{
		res = ft_strjoin("Hello ", "World!");
		if (!res || strcmp(res, "Hello World!") != 0)
		{
			printf("❌ FAILED: Test 1 (Expected \"Hello World!\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Basic concatenation\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 2: First String Empty ("")
	// -------------------------------------------------------------
	{
		res = ft_strjoin("", "42Network");
		if (!res || strcmp(res, "42Network") != 0)
		{
			printf("❌ FAILED: Test 2 (Expected \"42Network\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 2 - s1 is empty\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 3: Second String Empty ("")
	// -------------------------------------------------------------
	{
		res = ft_strjoin("1337MED", "");
		if (!res || strcmp(res, "1337MED") != 0)
		{
			printf("❌ FAILED: Test 3 (Expected \"1337MED\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 3 - s2 is empty\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 4: Both Strings Empty ("" and "")
	// (Must return valid, freeable allocated "")
	// -------------------------------------------------------------
	{
		res = ft_strjoin("", "");
		if (!res)
		{
			printf("❌ FAILED: Test 4 (Both empty returned NULL! Must return freeable \"\")\n");
			failed++;
		}
		else if (strcmp(res, "") != 0 || res[0] != '\0')
		{
			printf("❌ FAILED: Test 4 (Expected \"\", got \"%s\")\n", res);
			free(res);
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 4 - Both strings empty return \"\"\n");
			free(res);
		}
	}

	// -------------------------------------------------------------
	// TEST 5: Heap Isolation (Must not return pointer alias)
	// -------------------------------------------------------------
	{
		char s1[] = "Hello";
		char s2[] = "";

		res = ft_strjoin(s1, s2);
		if (res == s1 || res == s2)
		{
			printf("❌ FAILED: Test 5 (Returned original pointer alias instead of newly allocated heap string!)\n");
			failed++;
		}
		else
		{
			printf("✅ PASSED: Test 5 - Proper heap isolation\n");
			free(res);
		}
	}

	// -------------------------------------------------------------
	// TEST 6: NULL Pointer Inputs Protection
	// -------------------------------------------------------------
	{
		res = ft_strjoin(NULL, "World");
		if (res != NULL)
		{
			printf("❌ FAILED: Test 6a (s1 == NULL must return NULL)\n");
			free(res);
			failed++;
		}
		else
			printf("✅ PASSED: Test 6a - s1 == NULL returns NULL\n");

		res = ft_strjoin("Hello", NULL);
		if (res != NULL)
		{
			printf("❌ FAILED: Test 6b (s2 == NULL must return NULL)\n");
			free(res);
			failed++;
		}
		else
			printf("✅ PASSED: Test 6b - s2 == NULL returns NULL\n");

		res = ft_strjoin(NULL, NULL);
		if (res != NULL)
		{
			printf("❌ FAILED: Test 6c (Both NULL must return NULL)\n");
			free(res);
			failed++;
		}
		else
			printf("✅ PASSED: Test 6c - Both NULL return NULL\n");
	}

	// -------------------------------------------------------------
	// TEST 7: Single Character Strings
	// -------------------------------------------------------------
	{
		res = ft_strjoin("a", "b");
		if (!res || strcmp(res, "ab") != 0)
		{
			printf("❌ FAILED: Test 7 (Expected \"ab\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 7 - Single characters\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 8: Long Strings & Memory Integrity
	// -------------------------------------------------------------
	{
		size_t	len = 20000;
		char	*big1 = malloc(len + 1);
		char	*big2 = malloc(len + 1);

		if (big1 && big2)
		{
			memset(big1, 'A', len);
			big1[len] = '\0';
			memset(big2, 'B', len);
			big2[len] = '\0';

			res = ft_strjoin(big1, big2);
			if (!res || strlen(res) != (len * 2) || res[0] != 'A' || res[len * 2 - 1] != 'B')
			{
				printf("❌ FAILED: Test 8 (Large string concatenation integrity failed)\n");
				failed++;
			}
			else
				printf("✅ PASSED: Test 8 - Large strings (40,000 bytes) concatenated cleanly\n");
			free(res);
		}
		free(big1);
		free(big2);
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_strjoin STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
}
 */