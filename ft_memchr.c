#include "libft.h"
void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    const unsigned char *ptr;

    ptr = s;
    i = 0;
    while(i < n)
    {
        if(ptr[i] == (unsigned char)c)
            return ((void *)&ptr[i]);
        i++;
    }
    return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	int		failed = 0;
	void	*mine;
	void	*real;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_memchr ===\n");

	// -------------------------------------------------------------
	// TEST 1: Basic Search in Standard String
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		mine = ft_memchr(str, 'p', 10);
		real = memchr(str, 'p', 10);
		if (mine != real || mine != &str[3])
		{
			printf("❌ FAILED: Test 1 (Basic search: got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Basic search in string\n");
	}

	// -------------------------------------------------------------
	// TEST 2: Multiple Occurrences (Must return FIRST occurrence)
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		mine = ft_memchr(str, 'i', 10);
		real = memchr(str, 'i', 10);
		// 'i' appears at index 2 and index 6 -> must return index 2
		if (mine != real || mine != &str[2])
		{
			printf("❌ FAILED: Test 2 (First occurrence: got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 2 - Returns first occurrence\n");
	}

	// -------------------------------------------------------------
	// TEST 3: Character Not Found Within n
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		mine = ft_memchr(str, 'z', 10);
		real = memchr(str, 'z', 10);
		if (mine != real || mine != NULL)
		{
			printf("❌ FAILED: Test 3 (Not found must return NULL: got %p)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 3 - Character not found returns NULL\n");
	}

	// -------------------------------------------------------------
	// TEST 4: Binary Data & Searching Beyond Embedded '\0'
	// (Crucial: memchr must NOT stop at '\0')
	// -------------------------------------------------------------
	{
		// Buffer with '\0' in the middle, target is past '\0'
		char bin[] = {'a', 'b', '\0', 'c', 'd', 'e'};
		mine = ft_memchr(bin, 'd', 6);
		real = memchr(bin, 'd', 6);
		if (mine != real || mine != &bin[4])
		{
			printf("❌ FAILED: Test 4 (Binary search past '\\0': got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 4 - Scans past embedded '\\0' in binary data\n");
	}

	// -------------------------------------------------------------
	// TEST 5: Searching Explicitly for '\0' in Binary Data
	// -------------------------------------------------------------
	{
		char bin[] = {'x', 'y', 'z', '\0', '1', '2'};
		mine = ft_memchr(bin, '\0', 6);
		real = memchr(bin, '\0', 6);
		if (mine != real || mine != &bin[3])
		{
			printf("❌ FAILED: Test 5 (Search for '\\0': got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 5 - Searching for byte 0x00 ('\\0')\n");
	}

	// -------------------------------------------------------------
	// TEST 6: Strict n Boundary Limit (Character exists, but beyond n)
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		// 'e' is at index 9. If n = 9, indices inspected are 0..8 (not found)
		mine = ft_memchr(str, 'e', 9);
		real = memchr(str, 'e', 9);
		if (mine != real || mine != NULL)
		{
			printf("❌ FAILED: Test 6a (Matched character beyond n limit: got %p)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 6a - Target beyond n limit returns NULL\n");

		// If n = 10, 'e' at index 9 must be matched
		mine = ft_memchr(str, 'e', 10);
		real = memchr(str, 'e', 10);
		if (mine != real || mine != &str[9])
		{
			printf("❌ FAILED: Test 6b (Failed to match character at index n - 1)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 6b - Target at exact boundary (n - 1) matched\n");
	}

	// -------------------------------------------------------------
	// TEST 7: n == 0 Boundary (Must return NULL immediately)
	// -------------------------------------------------------------
	{
		char str[] = "tripouille";
		mine = ft_memchr(str, 't', 0);
		real = memchr(str, 't', 0);
		if (mine != real || mine != NULL)
		{
			printf("❌ FAILED: Test 7 (n == 0 must return NULL: got %p)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 7 - n == 0 returns NULL\n");
	}

	// -------------------------------------------------------------
	// TEST 8: Extended ASCII & Negative Bytes (\x80 / -128)
	// (Verifies unsigned char casting of both c and buffer)
	// -------------------------------------------------------------
	{
		unsigned char data[] = {0x10, 0x20, 0x80, 0xfe, 0xff};
		
		// Search with -128 (which is 0x80 in 8-bit two's complement)
		mine = ft_memchr(data, -128, sizeof(data));
		real = memchr(data, -128, sizeof(data));
		if (mine != real || mine != &data[2])
		{
			printf("❌ FAILED: Test 8a (Negative char -128 / 0x80 search failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 8a - Negative/Extended byte match (-128 / 0x80)\n");

		// Search with 0xff using int value 255
		mine = ft_memchr(data, 255, sizeof(data));
		real = memchr(data, 255, sizeof(data));
		if (mine != real || mine != &data[4])
		{
			printf("❌ FAILED: Test 8b (0xff / 255 match failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 8b - High-bit byte match (0xff / 255)\n");
	}

	// -------------------------------------------------------------
	// TEST 9: Int Overflow in Search Character (c + 256)
	// (francinette / tripouille mandatory trap: 'a' + 256 = 353)
	// -------------------------------------------------------------
	{
		char str[] = "abcdef";
		mine = ft_memchr(str, 'c' + 256, 6);
		real = memchr(str, 'c' + 256, 6);
		if (mine != real || mine != &str[2])
		{
			printf("❌ FAILED: Test 9 (c + 256 overflow: got %p, expected %p)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 9 - c + 256 overflow truncated to unsigned char\n");
	}

	// -------------------------------------------------------------
	// TEST 10: First Byte Match (Index 0)
	// -------------------------------------------------------------
	{
		char str[] = "42Network";
		mine = ft_memchr(str, '4', 9);
		real = memchr(str, '4', 9);
		if (mine != real || mine != &str[0])
		{
			printf("❌ FAILED: Test 10 (First byte match failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 10 - Match at index 0\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_memchr STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */

/* #include <stdio.h>
#include <limits.h>

// If ft_memchr uses signed char:
// void *ft_memchr(const void *s, int c, size_t n)

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

static int	g_total = 0;
static int	g_failed = 0;

static void test_memchr(const char *name, const void *s,
		int c, size_t n)
{
	void		*real;
	void		*mine;
	ptrdiff_t	real_offset;
	ptrdiff_t	mine_offset;
	int			ok;

	real = memchr(s, c, n);
	mine = ft_memchr(s, c, n);
	real_offset = real ? (const char *)real - (const char *)s : -1;
	mine_offset = mine ? (const char *)mine - (const char *)s : -1;
	ok = (real_offset == mine_offset);

	g_total++;
	if (!ok)
		g_failed++;
	printf("[%s] %s | libc offset: %td | ft offset: %td\n",
		ok ? "PASS" : "FAIL", name, real_offset, mine_offset);
}

int main(void)
{
	unsigned char	data[] = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'
	};
	unsigned char	high[] = {
		0x00, 0x7F, 0x80, 0x81, 0xFE, 0xFF, 0x41
	};
	unsigned char	zeros[] = {
		'a', '\0', 'b', '\0', 'c'
	};
	unsigned char	repeated[] = {
		'x', 'y', 'x', 'z', 'x'
	};

	printf("===== BASIC SEARCHES =====\n");
	test_memchr("first byte", data, 'a', 8);
	test_memchr("middle byte", data, 'd', 8);
	test_memchr("last byte", data, 'h', 8);
	test_memchr("missing byte", data, 'z', 8);
	test_memchr("repeated byte - first occurrence", repeated, 'x', 5);
	test_memchr("search uppercase", data, 'A', 8);
	test_memchr("search lowercase", data, 'b', 8);

	printf("\n===== SIZE BOUNDARIES =====\n");
	test_memchr("n = 0", data, 'a', 0);
	test_memchr("n = 1, found", data, 'a', 1);
	test_memchr("n = 1, not found", data, 'b', 1);
	test_memchr("found exactly at n-1", data, 'c', 3);
	test_memchr("byte just outside n", data, 'd', 3);
	test_memchr("n smaller than buffer", data, 'h', 4);
	test_memchr("n equals buffer size", data, 'h', sizeof(data));
	test_memchr("n greater than buffer size", data, 'h', sizeof(data));

	printf("\n===== NULL BYTE / BINARY DATA =====\n");
	test_memchr("search null byte", zeros, '\0', 5);
	test_memchr("search byte after null", zeros, 'b', 5);
	test_memchr("search byte before null", zeros, 'a', 5);
	test_memchr("search second null", zeros, '\0', 4);
	test_memchr("search null with n = 1", zeros, '\0', 1);
	test_memchr("null outside searched range", zeros, '\0', 1);

	printf("\n===== SIGNED / UNSIGNED CHAR =====\n");
	test_memchr("search 0x7F", high, 0x7F, sizeof(high));
	test_memchr("search 0x80", high, 0x80, sizeof(high));
	test_memchr("search 0x81", high, 0x81, sizeof(high));
	test_memchr("search 0xFE", high, 0xFE, sizeof(high));
	test_memchr("search 0xFF", high, 0xFF, sizeof(high));
	test_memchr("search 0x100 (converts to 0x00)", high, 0x100, sizeof(high));
	test_memchr("search 0x180 (converts to 0x80)", high, 0x180, sizeof(high));
	test_memchr("search -1 (converts to 0xFF)", high, -1, sizeof(high));
	test_memchr("search -128 (converts to 0x80)", high, -128, sizeof(high));

	printf("\n===== EMPTY / EDGE CASES =====\n");
	test_memchr("empty string, search null", "", '\0', 1);
	test_memchr("empty string, search character", "", 'a', 1);
	test_memchr("one-byte buffer, found", "A", 'A', 1);
	test_memchr("one-byte buffer, not found", "A", 'B', 1);

	printf("\n===== SUMMARY =====\n");
	printf("Total: %d | Passed: %d | Failed: %d\n",
		g_total, g_total - g_failed, g_failed);
	return (g_failed != 0);
} */