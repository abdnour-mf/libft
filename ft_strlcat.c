#include "libft.h"
size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dlen;
	size_t slen;
	size_t i;

	slen = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (dlen >= size)
		return (slen + size);
	while(dlen + i < size - 1 && src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

/* #include <stdio.h>
int main()
{
	char dst[12] = "hello ";
	char *src = "world";
	printf("%ld\n",ft_strlcat(dst, src, 12));
	printf("%s\n", dst);
} */

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	int		failed = 0;
	size_t	ret;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_strlcat ===\n");

	// -------------------------------------------------------------
	// TEST 1: Normal Concatenation (Ample room)
	// -------------------------------------------------------------
	{
		char dst[30] = "Hello ";
		ret = ft_strlcat(dst, "World!", sizeof(dst));
		// Expected: return = 6 + 6 = 12, dst = "Hello World!"
		if (ret != 12 || strcmp(dst, "Hello World!") != 0)
		{
			printf("❌ FAILED: Test 1 (Normal concat: ret=%zu, dst=\"%s\")\n", ret, dst);
			failed++;
		}
		else
			printf("✅ PASSED: Test 1 - Normal concatenation\n");
	}

	// -------------------------------------------------------------
	// TEST 2: Truncation & Canary Check (dstsize < strlen(dst) + strlen(src) + 1)
	// -------------------------------------------------------------
	{
		char buf[15];
		memset(buf, 'X', sizeof(buf));
		strcpy(buf, "abc"); // buf[0]='a', buf[1]='b', buf[2]='c', buf[3]='\0'
		buf[3] = '\0';
		buf[4] = 'X';       // Reset canary

		// dst initial len = 3, src len = 5 ("12345"), dstsize = 7
		// Space available for src: 7 - 3 - 1 = 3 chars -> "123"
		// Expected dst: "abc123\0", at index 6 is '\0', index 7..14 must stay 'X'
		// Expected return: 3 + 5 = 8
		ret = ft_strlcat(buf, "12345", 7);
		if (ret != 8 || strcmp(buf, "abc123") != 0)
		{
			printf("❌ FAILED: Test 2 (Truncation content/return mismatch: ret=%zu, dst=\"%s\")\n", ret, buf);
			failed++;
		}
		else if (buf[7] != 'X' || buf[8] != 'X')
		{
			printf("❌ FAILED: Test 2 (Buffer overrun! Wrote past dstsize - 1)\n");
			failed++;
		}
		else
			printf("✅ PASSED: Test 2 - Truncation & canary boundary\n");
	}

	// -------------------------------------------------------------
	// TEST 3: dstsize <= strlen(dst) Boundary Case 1 (dstsize == strlen(dst))
	// -------------------------------------------------------------
	{
		char dst[20] = "12345";
		// dst len = 5, dstsize = 5 -> dstsize <= strlen(dst)
		// Expected: return = dstsize + strlen(src) = 5 + 3 = 8
		// dst must NOT be modified at all!
		ret = ft_strlcat(dst, "abc", 5);
		if (ret != 8 || strcmp(dst, "12345") != 0)
		{
			printf("❌ FAILED: Test 3 (dstsize == strlen(dst): ret=%zu, dst=\"%s\")\n", ret, dst);
			failed++;
		}
		else
			printf("✅ PASSED: Test 3 - dstsize == strlen(dst) (dst untouched)\n");
	}

	// -------------------------------------------------------------
	// TEST 4: dstsize < strlen(dst) Boundary Case 2 (dstsize smaller than dst len)
	// -------------------------------------------------------------
	{
		char dst[20] = "1234567";
		// dst len = 7, dstsize = 3
		// Expected: return = dstsize + strlen(src) = 3 + 4 = 7
		// dst must NOT be modified at all!
		ret = ft_strlcat(dst, "test", 3);
		if (ret != 7 || strcmp(dst, "1234567") != 0)
		{
			printf("❌ FAILED: Test 4 (dstsize < strlen(dst): ret=%zu, dst=\"%s\")\n", ret, dst);
			failed++;
		}
		else
			printf("✅ PASSED: Test 4 - dstsize < strlen(dst) (dst untouched)\n");
	}

	// -------------------------------------------------------------
	// TEST 5: dstsize == 0
	// -------------------------------------------------------------
	{
		char dst[10] = "hello";
		// dstsize = 0 -> dst untouched
		// return = dstsize + strlen(src) = 0 + 5 = 5
		ret = ft_strlcat(dst, "world", 0);
		if (ret != 5 || strcmp(dst, "hello") != 0)
		{
			printf("❌ FAILED: Test 5 (dstsize == 0: ret=%zu, dst=\"%s\")\n", ret, dst);
			failed++;
		}
		else
			printf("✅ PASSED: Test 5 - dstsize == 0\n");
	}

	// -------------------------------------------------------------
	// TEST 6: dstsize == 0 with dst == NULL (libft-unit-test edge case)
	// -------------------------------------------------------------
	{
		// When dstsize is 0, strlcat should not read dst, only src len
		ret = ft_strlcat(NULL, "42Network", 0);
		if (ret != 9)
		{
			printf("❌ FAILED: Test 6 (dst == NULL with size == 0: ret=%zu)\n", ret);
			failed++;
		}
		else
			printf("✅ PASSED: Test 6 - dst == NULL when dstsize == 0\n");
	}

	// -------------------------------------------------------------
	// TEST 7: Exact Fit Boundary (dstsize == strlen(dst) + strlen(src) + 1)
	// -------------------------------------------------------------
	{
		char dst[10] = "Hi";
		// dst len = 2, src len = 3 ("You") -> total needed = 2 + 3 + 1 = 6
		// dstsize = 6 -> exactly fits with '\0'
		ret = ft_strlcat(dst, "You", 6);
		if (ret != 5 || strcmp(dst, "HiYou") != 0)
		{
			printf("❌ FAILED: Test 7 (Exact fit boundary: ret=%zu, dst=\"%s\")\n", ret, dst);
			failed++;
		}
		else
			printf("✅ PASSED: Test 7 - Exact fit boundary\n");
	}

	// -------------------------------------------------------------
	// TEST 8: dst Empty String ("")
	// -------------------------------------------------------------
	{
		char dst[10] = "";
		ret = ft_strlcat(dst, "abc", 10);
		if (ret != 3 || strcmp(dst, "abc") != 0)
		{
			printf("❌ FAILED: Test 8 (Empty dst: ret=%zu, dst=\"%s\")\n", ret, dst);
			failed++;
		}
		else
			printf("✅ PASSED: Test 8 - Empty dst\n");
	}

	// -------------------------------------------------------------
	// TEST 9: src Empty String ("")
	// -------------------------------------------------------------
	{
		char dst[10] = "NotEmpty";
		ret = ft_strlcat(dst, "", 10);
		if (ret != 8 || strcmp(dst, "NotEmpty") != 0)
		{
			printf("❌ FAILED: Test 9 (Empty src: ret=%zu, dst=\"%s\")\n", ret, dst);
			failed++;
		}
		else
			printf("✅ PASSED: Test 9 - Empty src\n");
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_strlcat STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */
