#include "libft.h"
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t i;
	unsigned char *dest;
	const unsigned char *sorc;

	if (dst == src || n == 0)
		return (dst);
	dest = (unsigned char *)dst;
	sorc = (const unsigned char *)src;
	if(dst < src)
		return (ft_memcpy(dst, src, n));
	i = n;
	while(i > 0)
	{
		i--;
        dest[i] = sorc[i];
	}
	return (dst);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buf1[] = "1234567890";
	char	buf2[] = "1234567890";
	int		failed = 0;

	printf("=== RUNNING TESTS FOR ft_memmove ===\n");

	// Test 1: Non-overlapping copy
	char src[] = "Hello 42";
	char dst1[20] = {0};
	char dst2[20] = {0};
	ft_memmove(dst1, src, 8);
	memmove(dst2, src, 8);
	if (memcmp(dst1, dst2, 20) != 0)
	{
		printf("❌ FAILED: Non-overlapping copy\n");
		failed++;
	}
	else
		printf("✅ PASSED: Non-overlapping copy\n");

	// Test 2: Overlapping - dst > src (Requires backward copy)
	// buf1: "1234567890" -> copy 5 bytes from buf1 to buf1 + 2
	ft_memmove(buf1 + 2, buf1, 5);
	memmove(buf2 + 2, buf2, 5);
	if (memcmp(buf1, buf2, sizeof(buf1)) != 0)
	{
		printf("❌ FAILED: Overlapping copy (dst > src)\n");
		failed++;
	}
	else
		printf("✅ PASSED: Overlapping copy (dst > src)\n");

	// Test 3: Overlapping - dst < src (Requires forward copy)
	char buf3[] = "1234567890";
	char buf4[] = "1234567890";
	ft_memmove(buf3, buf3 + 2, 5);
	memmove(buf4, buf4 + 2, 5);
	if (memcmp(buf3, buf4, sizeof(buf3)) != 0)
	{
		printf("❌ FAILED: Overlapping copy (dst < src)\n");
		failed++;
	}
	else
		printf("✅ PASSED: Overlapping copy (dst < src)\n");

	// Test 4: Zero length (n = 0)
	char zbuf1[] = "abcdef";
	char zbuf2[] = "abcdef";
	ft_memmove(zbuf1, zbuf1 + 1, 0);
	memmove(zbuf2, zbuf2 + 1, 0);
	if (memcmp(zbuf1, zbuf2, sizeof(zbuf1)) != 0)
	{
		printf("❌ FAILED: Zero length (n = 0)\n");
		failed++;
	}
	else
		printf("✅ PASSED: Zero length (n = 0)\n");

	// Test 5: Both pointers NULL (tested safely on your function only)
	if (ft_memmove(NULL, NULL, 5) != NULL)
	{
		printf("❌ FAILED: ft_memmove(NULL, NULL, 5) did not return NULL\n");
		failed++;
	}
	else
		printf("✅ PASSED: ft_memmove(NULL, NULL, 5) safely returns NULL\n");

	if (failed == 0)
		printf("\n🎉 ALL ft_memmove TESTS PASSED SUCCESSFULLY!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */
