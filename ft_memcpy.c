#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char		*dest;
	const unsigned char	*sorc;
	size_t				i;

//undefined behavior, but just in case
	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	sorc = (const unsigned char *)src;
    i = 0;
    while (i < n)
    {
        dest[i] = sorc[i];
        i++;
    }
    return (dst);
}

/* #include <stdio.h>
int main()
{
	int src = 20;
	int dst;

	ft_memcpy(&dst, &src, sizeof(int));
	printf("%d\n", src);
	printf("%d\n", dst);
} */

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "Hello 42 Network!";
	char	dst1[30];
	char	dst2[30];
	int		failed = 0;

	printf("=== RUNNING TESTS FOR ft_memcpy ===\n");

	// Test 1: Standard copy
	memset(dst1, 0, sizeof(dst1));
	memset(dst2, 0, sizeof(dst2));
	ft_memcpy(dst1, src, strlen(src) + 1);
	memcpy(dst2, src, strlen(src) + 1);
	if (memcmp(dst1, dst2, sizeof(dst1)) != 0)
	{
		printf("❌ FAILED: Standard copy\n");
		failed++;
	}
	else
		printf("✅ PASSED: Standard copy\n");

	// Test 2: Partial copy (n = 5)
	memset(dst1, 'A', sizeof(dst1));
	memset(dst2, 'A', sizeof(dst2));
	ft_memcpy(dst1, src, 5);
	memcpy(dst2, src, 5);
	if (memcmp(dst1, dst2, sizeof(dst1)) != 0)
	{
		printf("❌ FAILED: Partial copy\n");
		failed++;
	}
	else
		printf("✅ PASSED: Partial copy\n");

	// Test 3: Zero length (n = 0)
	memset(dst1, 'Z', sizeof(dst1));
	memset(dst2, 'Z', sizeof(dst2));
	ft_memcpy(dst1, src, 0);
	memcpy(dst2, src, 0);
	if (memcmp(dst1, dst2, sizeof(dst1)) != 0)
	{
		printf("❌ FAILED: Zero length (n = 0)\n");
		failed++;
	}
	else
		printf("✅ PASSED: Zero length (n = 0)\n");

	// Test 4: Both pointers NULL (libft-tester / Moulinette edge case)
	if (ft_memcpy(NULL, NULL, 5) != NULL)
	{
		printf("❌ FAILED: ft_memcpy(NULL, NULL, 5) did not return NULL\n");
		failed++;
	}
	else
		printf("✅ PASSED: ft_memcpy(NULL, NULL, 5) safely returns NULL\n");

	// Test 5: Binary data with embedded '\0' and extended values
	unsigned char	bin_src[6] = {0, 255, 128, 0, 42, 100};
	unsigned char	bin_dst1[6] = {0};
	unsigned char	bin_dst2[6] = {0};
	ft_memcpy(bin_dst1, bin_src, 6);
	memcpy(bin_dst2, bin_src, 6);
	if (memcmp(bin_dst1, bin_dst2, 6) != 0)
	{
		printf("❌ FAILED: Binary data copy\n");
		failed++;
	}
	else
		printf("✅ PASSED: Binary data copy\n");

	if (failed == 0)
		printf("\n🎉 ALL ft_memcpy TESTS PASSED SUCCESSFULLY!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */
// const char *src
//char * const src

//srt[i] i++ *(str + i)
//i[str] i++ *(i + str)