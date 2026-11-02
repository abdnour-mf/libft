#include "libft.h"

char *ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t i = 0;
	size_t j;

	if (sub[i] == '\0') 
		return ((char *) str);
	while(i < len && str[i])
	{
		j = 0;
		while(sub[j] && j < len - i && str[i + j] == sub[j])
			j++;
		if (sub[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}



/* #include <stdio.h>
#include <string.h>
#include "libft.h"

static int g_total = 0;
static int g_failed = 0;

 Reference implementation using strstr 
static char *reference_strnstr(const char *str,
    const char *sub, size_t len)
{
    char *found;
    size_t sub_len;

    if (sub[0] == '\0')
        return ((char *)str);
    sub_len = strlen(sub);
    found = strstr(str, sub);
    while (found != NULL)
    {
        if ((size_t)(found - str) <= len
            && sub_len <= len - (size_t)(found - str))
            return (found);
        found = strstr(found + 1, sub);
    }
    return (NULL);
}

static void test(const char *name, const char *str,
    const char *sub, size_t len)
{
    char *real;
    char *mine;
    long real_pos;
    long mine_pos;
    int ok;

    real = reference_strnstr(str, sub, len);
    mine = ft_strnstr(str, sub, len);
    real_pos = real ? (long)(real - str) : -1;
    mine_pos = mine ? (long)(mine - str) : -1;
    ok = (real_pos == mine_pos);
    g_total++;
    if (!ok)
        g_failed++;
    printf("[%s] %-36s | ref: %ld | ft: %ld\n",
        ok ? "PASS" : "FAIL", name, real_pos, mine_pos);
}

int main(void)
{
    printf("===== BASIC SEARCHES =====\n");
    test("match at beginning", "hello world", "hello", 11);
    test("match in middle", "hello world", "world", 11);
    test("match at end", "abcdef", "ef", 6);
    test("not found", "hello world", "xyz", 11);
    test("single character found", "abcdef", "d", 6);
    test("single character missing", "abcdef", "z", 6);

    printf("\n===== EMPTY STRINGS =====\n");
    test("empty needle", "hello", "", 5);
    test("empty needle, len zero", "hello", "", 0);
    test("empty haystack", "", "hello", 5);
    test("both empty", "", "", 0);
    test("empty haystack, len positive", "", "", 5);

    printf("\n===== LENGTH BOUNDARIES =====\n");
    test("len zero", "hello", "h", 0);
    test("len one, match", "hello", "h", 1);
    test("len one, no match", "hello", "e", 1);
    test("match exactly within len", "hello", "ell", 4);
    test("match ends at len", "hello", "lo", 5);
    test("match crosses len boundary", "hello", "lo", 4);
    test("needle longer than len", "hello", "hello", 4);
    test("len smaller than haystack", "hello world", "world", 5);
    test("len larger than string", "hello", "lo", 100);

    printf("\n===== PARTIAL / REPEATED MATCHES =====\n");
    test("partial prefix only", "abcdef", "abcx", 6);
    test("repeated characters", "aaaaab", "aaab", 6);
    test("first of multiple matches", "abcabc", "bc", 6);
    test("overlapping candidates", "abababc", "ababc", 7);
    test("needle equals haystack", "hello", "hello", 5);
    test("needle longer than haystack", "abc", "abcd", 10);
    test("match after failed partial", "aababc", "abc", 6);
    test("multiple partial matches", "ababac", "abac", 6);

    printf("\n===== SPECIAL CHARACTERS =====\n");
    test("space", "hello world", " ", 11);
    test("punctuation", "hello, world!", ", w", 13);
    test("newline", "hello\nworld", "\nwo", 11);
    test("tab", "hello\tworld", "\tw", 11);
    test("digits", "abc123xyz", "123", 9);
    test("mixed case", "Hello World", "hello", 11);

    printf("\n===== SUMMARY =====\n");
    printf("Total: %d | Passed: %d | Failed: %d\n",
        g_total, g_total - g_failed, g_failed);
    return (g_failed != 0);
}
 */

/* #include <stdio.h>
#include <string.h>

#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
	// strnstr is natively available in BSD libc
#else
	// Linux glibc lacks strnstr by default, manual prototype if using libbsd:
	char *strnstr(const char *big, const char *little, size_t len);
#endif

int	main(void)
{
	int		failed = 0;
	char	*res;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_strnstr ===\n");

	// -------------------------------------------------------------
	// TEST 1: Empty Needle ("") with Various len (Mandatory BSD Rule)
	// -------------------------------------------------------------
	{
		char hay[] = "FindMe";

		res = ft_strnstr(hay, "", 6);
		if (res != hay)
		{
			printf("❌ FAILED: Test 1a (Empty needle with len > 0 must return haystack: got %p, expected %p)\n", res, hay);
			failed++;
		}
		else
			printf("✅ PASSED: Test 1a - Empty needle with len > 0\n");

		// Even when len == 0, empty needle MUST return haystack!
		res = ft_strnstr(hay, "", 0);
		if (res != hay)
		{
			printf("❌ FAILED: Test 1b (Empty needle with len == 0 must return haystack: got %p, expected %p)\n", res, hay);
			failed++;
		}
		else
			printf("✅ PASSED: Test 1b - Empty needle with len == 0\n");
	}

	// -------------------------------------------------------------
	// TEST 2: Basic Matches (Start, Middle, End)
	// -------------------------------------------------------------
	{
		char hay[] = "Foo Bar Baz";

		// Match at beginning
		res = ft_strnstr(hay, "Foo", 11);
		if (res != &hay[0])
		{
			printf("❌ FAILED: Test 2a (Match at beginning failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 2a - Match at beginning\n");

		// Match in middle
		res = ft_strnstr(hay, "Bar", 11);
		if (res != &hay[4])
		{
			printf("❌ FAILED: Test 2b (Match in middle failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 2b - Match in middle\n");

		// Match at very end
		res = ft_strnstr(hay, "Baz", 11);
		if (res != &hay[8])
		{
			printf("❌ FAILED: Test 2c (Match at end failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 2c - Match at end\n");
	}

	// -------------------------------------------------------------
	// TEST 3: Strict len Boundary (Truncated Match Trap)
	// -------------------------------------------------------------
	{
		char hay[] = "abcdefgh";

		// Needle "def" begins at index 3, ends at index 5.
		// Total characters needed: indices 0, 1, 2, 3, 4, 5 -> requires len >= 6.

		// len = 5: Should FAIL because the full needle does not fit
		res = ft_strnstr(hay, "def", 5);
		if (res != NULL)
		{
			printf("❌ FAILED: Test 3a (Needle extends past len boundary! Must return NULL, got %p)\n", res);
			failed++;
		}
		else
			printf("✅ PASSED: Test 3a - Needle cut off by len boundary returns NULL\n");

		// len = 6: Exact fit boundary, must SUCCEED
		res = ft_strnstr(hay, "def", 6);
		if (res != &hay[3])
		{
			printf("❌ FAILED: Test 3b (Exact fit boundary failed: got %p, expected %p)\n", res, &hay[3]);
			failed++;
		}
		else
			printf("✅ PASSED: Test 3b - Exact len boundary fit succeeds\n");
	}

	// -------------------------------------------------------------
	// TEST 4: Partial False Matches with Overlapping Substrings
	// -------------------------------------------------------------
	{
		char hay[] = "aabbaabbabc";
		
		// Target is "abbabc", previous matches like "aabbaa" will fail halfway
		res = ft_strnstr(hay, "abbabc", 11);
		if (res != &hay[5])
		{
			printf("❌ FAILED: Test 4 (Overlapping false prefix backtrack failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 4 - Overlapping false-prefix search\n");
	}

	// -------------------------------------------------------------
	// TEST 5: Needle Longer Than Haystack
	// -------------------------------------------------------------
	{
		char hay[] = "short";
		res = ft_strnstr(hay, "much longer needle", 20);
		if (res != NULL)
		{
			printf("❌ FAILED: Test 5 (Needle longer than haystack must return NULL)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 5 - Needle longer than haystack returns NULL\n");
	}

	// -------------------------------------------------------------
	// TEST 6: len == 0 with Non-Empty Needle
	// -------------------------------------------------------------
	{
		char hay[] = "tripouille";
		res = ft_strnstr(hay, "trip", 0);
		if (res != NULL)
		{
			printf("❌ FAILED: Test 6 (Non-empty needle with len == 0 must return NULL)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 6 - Non-empty needle with len == 0 returns NULL\n");
	}

	// -------------------------------------------------------------
	// TEST 7: Stop Searching at '\0' in Haystack Despite Large len
	// -------------------------------------------------------------
	{
		// Buffer has '\0' at index 4, followed by the needle in garbage space
		char hay[20] = {'b', 'o', 'n', 'j', '\0', 't', 'o', 't', 'o', '\0'};

		// Looking for "toto" within len = 15. Since hay ends at index 4, must return NULL!
		res = ft_strnstr(hay, "toto", 15);
		if (res != NULL)
		{
			printf("❌ FAILED: Test 7 (Read past '\\0' into garbage buffer! Got %p, expected NULL)\n", res);
			failed++;
		}
		else
			printf("✅ PASSED: Test 7 - Stops searching at '\\0' regardless of large len\n");
	}

	// -------------------------------------------------------------
	// TEST 8: Single Character Needle
	// -------------------------------------------------------------
	{
		char hay[] = "42 Network";
		res = ft_strnstr(hay, "N", 10);
		if (res != &hay[3])
		{
			printf("❌ FAILED: Test 8 (Single char needle match failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 8 - Single character needle match\n");
	}

	// -------------------------------------------------------------
	// TEST 9: Both Strings Empty ("" and "")
	// -------------------------------------------------------------
	{
		char hay[] = "";
		res = ft_strnstr(hay, "", 5);
		if (res != hay)
		{
			printf("❌ FAILED: Test 9 (Empty haystack with empty needle failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 9 - Both haystack and needle empty\n");
	}

	// -------------------------------------------------------------
	// TEST 10: Non-Existent Needle
	// -------------------------------------------------------------
	{
		char hay[] = "abcdefgh";
		res = ft_strnstr(hay, "xyz", 8);
		if (res != NULL)
		{
			printf("❌ FAILED: Test 10 (Non-existent needle must return NULL)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 10 - Non-existent needle returns NULL\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_strnstr STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */

