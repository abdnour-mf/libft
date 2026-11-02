#include "libft.h"

char *ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char *str;
	unsigned int i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while(s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}


/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Test function 1: Alternating case based on even/odd index
static char	test_even_upper(unsigned int i, char c)
{
	if (i % 2 == 0 && (c >= 'a' && c <= 'z'))
		return (c - 32);
	return (c);
}

// Test function 2: Add index to character value
static char	test_add_index(unsigned int i, char c)
{
	return (c + (char)i);
}

// Test function 3: Return exact index digit as char
static char	test_index_char(unsigned int i, char c)
{
	(void)c;
	return ('0' + (char)(i % 10));
}

int	main(void)
{
	int		failed = 0;
	char	*res;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_strmapi ===\n");

	// -------------------------------------------------------------
	// TEST 1: Basic Transformation & Index Sensitivity
	// -------------------------------------------------------------
	{
		res = ft_strmapi("abcdef", test_even_upper);
		if (!res || strcmp(res, "AbCdEf") != 0)
		{
			printf("❌ FAILED: Test 1 (Expected \"AbCdEf\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Even/odd index alternating transformation\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 2: Index Addition Verification
	// -------------------------------------------------------------
	{
		// "00000" with f(i, c) = c + i -> "01234"
		res = ft_strmapi("00000", test_add_index);
		if (!res || strcmp(res, "01234") != 0)
		{
			printf("❌ FAILED: Test 2 (Expected \"01234\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 2 - Sequential index validation (c + i)\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 3: Replacing Characters with Index Modulo
	// -------------------------------------------------------------
	{
		res = ft_strmapi("hello", test_index_char);
		if (!res || strcmp(res, "01234") != 0)
		{
			printf("❌ FAILED: Test 3 (Expected \"01234\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 3 - Full overwrite with index characters\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 4: Empty String ("")
	// (Must return valid, freeable allocated "", without calling f)
	// -------------------------------------------------------------
	{
		res = ft_strmapi("", test_even_upper);
		if (!res)
		{
			printf("❌ FAILED: Test 4 (Empty string returned NULL! Must return freeable \"\")\n");
			failed++;
		}
		else if (res[0] != '\0' || strlen(res) != 0)
		{
			printf("❌ FAILED: Test 4 (Expected \"\", got \"%s\")\n", res);
			failed++;
		}
		else
			printf("✅ PASSED: Test 4 - Empty string returns allocated \"\"\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 5: Heap Isolation & Source Constness
	// -------------------------------------------------------------
	{
		char	src[] = "immutable";
		res = ft_strmapi(src, test_even_upper);
		if (!res || res == src)
		{
			printf("❌ FAILED: Test 5 (Returned identical pointer instead of fresh heap allocation)\n");
			failed++;
		}
		else if (strcmp(src, "immutable") != 0)
		{
			printf("❌ FAILED: Test 5 (Source string was modified!)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 5 - Source string preserved and fresh heap buffer returned\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 6: Single Character
	// -------------------------------------------------------------
	{
		res = ft_strmapi("z", test_even_upper);
		if (!res || strcmp(res, "Z") != 0)
		{
			printf("❌ FAILED: Test 6 (Expected \"Z\", got \"%s\")\n", res ? res : "NULL");
			failed++;
		}
		else
			printf("✅ PASSED: Test 6 - Single character string\n");
		free(res);
	}

	// -------------------------------------------------------------
	// TEST 7: NULL Defense
	// -------------------------------------------------------------
	{
		res = ft_strmapi(NULL, test_even_upper);
		if (res != NULL)
		{
			printf("❌ FAILED: Test 7a (s == NULL must return NULL)\n");
			free(res);
			failed++;
		}
		else
			printf("✅ PASSED: Test 7a - s == NULL returns NULL\n");

		res = ft_strmapi("test", NULL);
		if (res != NULL)
		{
			printf("❌ FAILED: Test 7b (f == NULL must return NULL)\n");
			free(res);
			failed++;
		}
		else
			printf("✅ PASSED: Test 7b - f == NULL returns NULL\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_strmapi STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */
