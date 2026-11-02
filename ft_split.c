#include "libft.h"

static size_t counter(char const *s, char c)
{
	size_t i;
	size_t count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while(s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}
static char **free_spli(char **result, size_t count)
{
	size_t i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static char **fill_words(char const *s, char c, char **result)
{
	size_t i;
	size_t j;
	size_t start;

	i = 0;
	j = 0;
	while(s[i])
	{
		while(s[i] && s[i] == c)
			i++;
		start = i;
		while(s[i] && s[i] != c)
			i++;
		if (start != i)
		{
			result[j] = ft_substr(s, start, i - start);
				if (!result[j])
					return (free_spli(result, j));
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

char **ft_split(char const *s, char c)
{
	char **result;

	if (!s)
		return (NULL);
	result = malloc((counter(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return ((fill_words(s, c, result)));
}



/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int g_total = 0;
static int g_failed = 0;

static void test_split(const char *name, const char *input,
	char delimiter, const char *expected[])
{
	char    **result;
	size_t  expected_count;
	size_t  i;
	int     ok;

	expected_count = 0;
	while (expected[expected_count])
		expected_count++;

	result = ft_split(input, delimiter);
	ok = 1;

	if (!result)
	{
		if (expected_count != 0)
			ok = 0;
	}
	else
	{
		i = 0;
		while (i < expected_count)
		{
			if (!result[i] || strcmp(result[i], expected[i]) != 0)
				ok = 0;
			i++;
		}
		if (result[expected_count] != NULL)
			ok = 0;
	}

	g_total++;
	if (!ok)
		g_failed++;

	printf("[%s] %s\n", ok ? "PASS" : "FAIL", name);

	if (!ok)
	{
		printf("    Expected:");
		i = 0;
		while (i < expected_count)
		{
			printf(" [%s]", expected[i]);
			i++;
		}
		printf("\n    Got:     ");
		if (!result)
			printf("NULL");
		else
		{
			i = 0;
			while (i < 100 && result[i])
			{
				printf(" [%s]", result[i]);
				i++;
			}
			if (i == 100)
				printf(" [possible missing terminator]");
			if (i == 0)
				printf("(empty array)");
		}
		printf("\n");
	}

	if (result)
	{
		i = 0;
		while (i < expected_count && result[i])
		{
			free(result[i]);
			i++;
		}
		free(result);
	}
}

int main(void)
{
	static const char *e0[] = {NULL};
	static const char *e1[] = {"hello", NULL};
	static const char *e2[] = {"hello", "world", NULL};
	static const char *e3[] = {"one", "two", "three", NULL};
	static const char *e4[] = {"a", "b", "c", "d", NULL};
	static const char *e5[] = {"hello", "world", "42", NULL};
	static const char *e6[] = {"supercalifragilistic", NULL};
	static const char *e7[] = {"a", "ab", "abc", "abcd", NULL};
	static const char *e10[] = {"a", "b", NULL};
	static const char *e11[] = {"one,two,three", NULL};
	static const char *e13[] = {"one", "two", NULL};
	static const char *e15[] = {"a", NULL};
	static const char *e18[] = {"a", "b", "c", NULL};
	static const char *e19[] = {"abc", "def", NULL};
	static const char *e20[] = {"123", "456", "789", NULL};
	static const char *e25[] = {"a", "b", "c", "d", NULL};
	static const char *e26[] = {"abc", NULL};
	static const char *e27[] = {"hello world", NULL};
	static const char *e32[] = {"abc", "def", "ghi", NULL};
	static const char *e34[] = {"hello", NULL};
	static const char *e37[] = {"a", NULL};
	static const char *e_comma[] = {"one", "two", NULL};
	static const char *e_delimiters[] = {" ", " a ", " b ", " ", NULL};
	static const char *e_punctuation[] = {"hello,world!", NULL};

	printf("\n===== BASIC CASES =====\n");
	test_split("one word", "hello", ' ', e1);
	test_split("two words", "hello world", ' ', e2);
	test_split("three words", "one two three", ' ', e3);
	test_split("four words", "a b c d", ' ', e4);
	test_split("words with numbers", "hello world 42", ' ', e5);
	test_split("long word", "supercalifragilistic", ' ', e6);
	test_split("different word lengths", "a ab abc abcd", ' ', e7);

	printf("\n===== EMPTY / DELIMITER ONLY =====\n");
	test_split("empty string", "", ' ', e0);
	test_split("one delimiter", " ", ' ', e0);
	test_split("multiple spaces", "     ", ' ', e0);
	test_split("only commas", ",,,,,", ',', e0);
	test_split("only tabs", "\t\t\t", '\t', e0);
	test_split("only newlines", "\n\n\n", '\n', e0);
	test_split("only hyphens", "-----", '-', e0);

	printf("\n===== LEADING / TRAILING DELIMITERS =====\n");
	test_split("leading delimiter", " hello", ' ', e1);
	test_split("trailing delimiter", "hello ", ' ', e1);
	test_split("both sides", " hello ", ' ', e1);
	test_split("multiple leading", "   hello", ' ', e1);
	test_split("multiple trailing", "hello   ", ' ', e1);
	test_split("leading and trailing", "  hello world  ", ' ', e2);
	test_split("leading and trailing commas", ",one,two,", ',', e_comma);

	printf("\n===== CONSECUTIVE DELIMITERS =====\n");
	test_split("two spaces", "hello  world", ' ', e2);
	test_split("many spaces", "a     b", ' ', e10);
	test_split("many commas", "one,,,,two", ',', e13);
	test_split("alternating delimiters", "a,b,,c,,,d", ',', e25);
	test_split("delimiters everywhere", " , a , b , ", ',', e_delimiters);
	test_split("repeated delimiters at both ends",
		"///abc///def///", '/', e19);

	printf("\n===== DIFFERENT DELIMITERS =====\n");
	test_split("comma delimiter", "one,two,three", ',', e3);
	test_split("dash delimiter", "one-two-three", '-', e3);
	test_split("slash delimiter", "one/two/three", '/', e3);
	test_split("letter delimiter", "oneXtwoXthree", 'X', e3);
	test_split("digit delimiter", "one1two1three", '1', e3);
	test_split("dot delimiter", "one.two.three", '.', e3);
	test_split("semicolon delimiter", "a;b;c", ';', e18);

	printf("\n===== DELIMITER NOT PRESENT =====\n");
	test_split("delimiter absent", "hello world", ',', e27);
	test_split("single character", "a", ',', e15);
	test_split("long string without delimiter", "abc", ' ', e26);

	printf("\n===== SPECIAL CHARACTERS =====\n");
	test_split("tab delimiter", "one\ttwo\tthree", '\t', e3);
	test_split("newline delimiter", "one\ntwo\nthree", '\n', e3);
	test_split("punctuation inside words",
		"hello,world!", ' ', e_punctuation);
	test_split("digits as words", "123 456 789", ' ', e20);
	test_split("mixed punctuation", "abc-def-ghi", '-', e32);
	test_split("space inside input", "hello world", 'x', e27);

	printf("\n===== EDGE CASES =====\n");
	test_split("delimiter is null byte", "hello", '\0', e34);
	test_split("empty string and null delimiter", "", '\0', e0);
	test_split("single character with null delimiter", "a", '\0', e37);
	test_split("delimiter at first position", ",abc", ',', e26);
	test_split("delimiter at last position", "abc,", ',', e26);

	printf("\n===== SUMMARY =====\n");
	printf("Total: %d | Passed: %d | Failed: %d\n",
		g_total, g_total - g_failed, g_failed);

	return (g_failed != 0);
}
 */