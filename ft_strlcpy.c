#include "libft.h"
size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));

	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	int		failed = 0;
	size_t	ret;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_strlcpy ===\n");

	// -------------------------------------------------------------
	// TEST 1: Buffer Overrun & Canary Check
	// Ensure ft_strlcpy does NOT write past (dstsize - 1)
	// -------------------------------------------------------------
	{
		char buf[10];
		memset(buf, 'X', sizeof(buf));
		ret = ft_strlcpy(buf, "1234567890", 5);
		// With size 5, it should write '1','2','3','4','\0' into buf[0..4]
		// buf[5] through buf[9] MUST remain 'X'
		if (ret != 10 || strcmp(buf, "1234") != 0)
		{
			printf("❌ FAILED: Test 1 (Truncation content/return mismatch)\n");
			failed++;
		}
		else if (buf[5] != 'X' || buf[6] != 'X')
		{
			printf("❌ FAILED: Test 1 (Buffer overrun detected past dstsize!)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Buffer overrun guard & truncation\n");
	}

	// -------------------------------------------------------------
	// TEST 2: Exact Fit Boundary (dstsize == strlen(src) + 1)
	// -------------------------------------------------------------
	{
		char buf[6];
		memset(buf, 'A', sizeof(buf));
		ret = ft_strlcpy(buf, "apple", 6);
		if (ret != 5 || strcmp(buf, "apple") != 0 || buf[5] != '\0')
		{
			printf("❌ FAILED: Test 2 (Exact fit boundary failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 2 - Exact fit boundary\n");
	}

	// -------------------------------------------------------------
	// TEST 3: One Byte Short (dstsize == strlen(src))
	// -------------------------------------------------------------
	{
		char buf[5];
		memset(buf, 'A', sizeof(buf));
		ret = ft_strlcpy(buf, "apple", 5);
		// Should copy "appl" + '\0'
		if (ret != 5 || strcmp(buf, "appl") != 0 || buf[4] != '\0')
		{
			printf("❌ FAILED: Test 3 (One-byte short boundary failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 3 - Off-by-one under-fit boundary\n");
	}

	// -------------------------------------------------------------
	// TEST 4: dstsize == 0 (Must not write; dst untouched)
	// -------------------------------------------------------------
	{
		char buf[10] = "untouched";
		ret = ft_strlcpy(buf, "newdata", 0);
		if (ret != 7 || strcmp(buf, "untouched") != 0)
		{
			printf("❌ FAILED: Test 4 (dstsize == 0 modified destination or wrong return)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 4 - dstsize == 0 preserves buffer\n");
	}

	// -------------------------------------------------------------
	// TEST 5: dstsize == 0 with dst == NULL
	// (Common tester edge case: counting length without buffer)
	// -------------------------------------------------------------
	{
		ret = ft_strlcpy(NULL, "42Network", 0);
		if (ret != 9)
		{
			printf("❌ FAILED: Test 5 (dst == NULL with size == 0 failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 5 - Safe return on NULL dst when size == 0\n");
	}

	// -------------------------------------------------------------
	// TEST 6: dstsize == 1 (Only writes null terminator)
	// -------------------------------------------------------------
	{
		char buf[5] = "AAAA";
		ret = ft_strlcpy(buf, "hello", 1);
		if (ret != 5 || buf[0] != '\0' || buf[1] != 'A')
		{
			printf("❌ FAILED: Test 6 (dstsize == 1 failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 6 - dstsize == 1 sets ONLY null byte\n");
	}

	// -------------------------------------------------------------
	// TEST 7: Empty Source String ("")
	// -------------------------------------------------------------
	{
		char buf[5] = "BBBB";
		ret = ft_strlcpy(buf, "", 5);
		if (ret != 0 || buf[0] != '\0' || buf[1] != 'B')
		{
			printf("❌ FAILED: Test 7 (Empty source string failed)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 7 - Empty source string\n");
	}

	// -------------------------------------------------------------
	// TEST 8: Long String Truncation
	// -------------------------------------------------------------
	{
		const char *long_src = "A very long sentence used to verify that size_t handles big strings properly.";
		char buf[16];
		memset(buf, 'Z', sizeof(buf));
		ret = ft_strlcpy(buf, long_src, sizeof(buf));
		if (ret != strlen(long_src) || strlen(buf) != 15 || buf[15] != '\0')
		{
			printf("❌ FAILED: Test 8 (Long string truncation)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 8 - Long string truncation\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_strlcpy STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */