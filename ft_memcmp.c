#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	i = 0;
	p1 = s1;
	p2 = s2;
    if (n == 0) 
		return (0);
    
    while(i < n - 1 && p1[i] == p2[i])
        i++;
    return (p1[i] - p2[i]);
}

/* #include <stdio.h>
#include <string.h>

static int	normalize_sign(int val)
{
	if (val < 0)
		return (-1);
	if (val > 0)
		return (1);
	return (0);
}

int	main(void)
{
	int	failed = 0;
	int	mine;
	int	real;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_memcmp ===\n");

	// -------------------------------------------------------------
	// TEST 1: Identical Buffers
	// -------------------------------------------------------------
	{
		char b1[] = "Hello 42";
		char b2[] = "Hello 42";
		mine = ft_memcmp(b1, b2, 8);
		real = memcmp(b1, b2, 8);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 1 (Identical buffers: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Identical buffers match\n");
	}

	// -------------------------------------------------------------
	// TEST 2: Difference Within n Limit (s1 < s2 and s1 > s2)
	// -------------------------------------------------------------
	{
		char b1[] = "abcdef";
		char b2[] = "abcdeg";
		mine = ft_memcmp(b1, b2, 6);
		real = memcmp(b1, b2, 6);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 2a (s1 < s2: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 2a - Difference within n (s1 < s2)\n");

		mine = ft_memcmp(b2, b1, 6);
		real = memcmp(b2, b1, 6);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 2b (s1 > s2: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 2b - Difference within n (s1 > s2)\n");
	}

	// -------------------------------------------------------------
	// TEST 3: Difference Beyond n Boundary (Must return 0)
	// -------------------------------------------------------------
	{
		char b1[] = "abcdef";
		char b2[] = "abcxyz";
		mine = ft_memcmp(b1, b2, 3);
		real = memcmp(b1, b2, 3);
		if (mine != 0)
		{
			printf("❌ FAILED: Test 3 (Difference beyond n returned non-zero: mine=%d)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 3 - Difference beyond n ignored\n");
	}

	// -------------------------------------------------------------
	// TEST 4: n == 0 Boundary (Must return 0 immediately)
	// -------------------------------------------------------------
	{
		char b1[] = "12345";
		char b2[] = "67890";
		mine = ft_memcmp(b1, b2, 0);
		real = memcmp(b1, b2, 0);
		if (mine != 0)
		{
			printf("❌ FAILED: Test 4 (n == 0 returned non-zero: mine=%d)\n", mine);
			failed++;
		}
		else
			printf("✅ PASSED: Test 4 - n == 0 returns 0\n");
	}

	// -------------------------------------------------------------
	// TEST 5: Comparing Past Embedded '\0' in Binary Data
	// (Crucial: memcmp must NOT stop at '\0')
	// -------------------------------------------------------------
	{
		char b1[8] = {'a', 'b', '\0', 'c', 'd', 'e', 'f', 'g'};
		char b2[8] = {'a', 'b', '\0', 'c', 'd', 'e', 'f', 'z'};

		mine = ft_memcmp(b1, b2, 8);
		real = memcmp(b1, b2, 8);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 5 (Stopped at '\\0' instead of scanning binary data: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 5 - Scans past embedded '\\0' to detect difference\n");
	}

	// -------------------------------------------------------------
	// TEST 6: Strings Identical to '\0' but Differing Afterward
	// (strncmp would return 0; memcmp MUST return non-zero)
	// -------------------------------------------------------------
	{
		char b1[6] = {'t', 'e', 's', 't', '\0', '1'};
		char b2[6] = {'t', 'e', 's', 't', '\0', '2'};

		mine = ft_memcmp(b1, b2, 6);
		real = memcmp(b1, b2, 6);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 6 (Failed difference after null byte: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 6 - Flags differences situated after null byte\n");
	}

	// -------------------------------------------------------------
	// TEST 7: Unsigned Char Cast Trap (\200 vs \0)
	// (Signed char gives negative; unsigned char gives positive)
	// -------------------------------------------------------------
	{
		char b1[] = "test\200";
		char b2[] = "test\0";

		mine = ft_memcmp(b1, b2, 6);
		real = memcmp(b1, b2, 6);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 7 (Unsigned char trap: mine=%d, real=%d. Needs unsigned char cast!)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 7 - Unsigned byte comparison (\\200 vs \\0)\n");
	}

	// -------------------------------------------------------------
	// TEST 8: Extended ASCII High-Byte Difference (\xff vs \0)
	// -------------------------------------------------------------
	{
		unsigned char u1[] = {0xff, 0xaa, 0x00, 0x01};
		unsigned char u2[] = {0xff, 0xaa, 0x00, 0x02};

		mine = ft_memcmp(u1, u2, 4);
		real = memcmp(u1, u2, 4);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 8 (Extended ASCII diff: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 8 - Extended byte arrays with boundary difference\n");
	}

	// -------------------------------------------------------------
	// TEST 9: Difference at the Exact Last Byte (n - 1)
	// -------------------------------------------------------------
	{
		char b1[] = "123456789";
		char b2[] = "123456780";

		mine = ft_memcmp(b1, b2, 9);
		real = memcmp(b1, b2, 9);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 9 (Mismatch at last byte: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 9 - Difference at index n - 1\n");
	}

	// -------------------------------------------------------------
	// TEST 10: Difference at the Very First Byte (index 0)
	// -------------------------------------------------------------
	{
		char b1[] = "a2345";
		char b2[] = "z2345";

		mine = ft_memcmp(b1, b2, 5);
		real = memcmp(b1, b2, 5);
		if (normalize_sign(mine) != normalize_sign(real))
		{
			printf("❌ FAILED: Test 10 (Mismatch at index 0: mine=%d, real=%d)\n", mine, real);
			failed++;
		}
		else
			printf("✅ PASSED: Test 10 - Difference at index 0\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_memcmp STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */


/* #include <stdio.h>
#include <string.h>
#include "libft.h"

static int total;
static int failed;

static void test(const char *name, const void *a,
    const void *b, size_t n)
{
    int real = memcmp(a, b, n);
    int mine = ft_memcmp(a, b, n);
    int ok = (real == 0 && mine == 0)
        || (real < 0 && mine < 0)
        || (real > 0 && mine > 0);

    total++;
    if (!ok)
        failed++;
    printf("[%s] %s | libc: %d | ft: %d\n",
        ok ? "PASS" : "FAIL", name, real, mine);
}

int main(void)
{
    unsigned char a[] = {1, 2, 3, 4, 5};
    unsigned char b[] = {1, 2, 3, 4, 5};
    unsigned char c[] = {1, 2, 9, 4, 5};
    unsigned char d[] = {1, 2, 3, 4, 9};
    unsigned char high1[] = {0x80, 0xFF, 0x00};
    unsigned char high2[] = {0x7F, 0xFF, 0x00};
    unsigned char high3[] = {0xFF, 0x00, 0x80};
    unsigned char high4[] = {0x80, 0x00, 0xFF};
    unsigned char zeros1[] = {'a', '\0', 'x'};
    unsigned char zeros2[] = {'a', '\0', 'y'};
    unsigned char empty[] = {0};

    printf("===== BASIC =====\n");
    test("identical arrays", a, b, 5);
    test("difference at first byte", a, c, 1);
    test("difference in middle", a, c, 5);
    test("difference at last byte", a, d, 5);
    test("same first 2 bytes", a, c, 2);
    test("difference just outside n", a, c, 1);

    printf("\n===== SIZE BOUNDARIES =====\n");
    test("n = 0", a, c, 0);
    test("n = 1", a, c, 1);
    test("n = 2", a, c, 2);
    test("n = 3", a, c, 3);
    test("n = full size", a, b, sizeof(a));

    printf("\n===== SIGNED CHAR TRAPS =====\n");
    test("0x80 vs 0x7F", high1, high2, 3);
    test("0xFF vs 0x80", high3, high1, 3);
    test("0x80 vs 0x80", high1, high4, 1);
    test("0xFF vs 0x00", high3, high4, 1);
    test("0x00 vs 0xFF", high4 + 1, high3 + 1, 1);

    printf("\n===== NULL BYTES / BINARY =====\n");
    test("difference after null byte", zeros1, zeros2, 3);
    test("same bytes including null", zeros1, zeros2, 2);
    test("zero-filled arrays", empty, empty, 1);

    printf("\n===== SUMMARY =====\n");
    printf("Total: %d | Passed: %d | Failed: %d\n",
        total, total - failed, failed);
    return (failed != 0);
}
 */