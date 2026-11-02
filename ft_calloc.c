#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int	main(void)
{
	int		failed = 0;
	void	*ptr;

	printf("=== EXHAUSTIVE STRESS TESTS: ft_calloc ===\n");

	// -------------------------------------------------------------
	// TEST 1: Basic Allocation & Full Zero-Initialization
	// -------------------------------------------------------------
	{
		size_t			nmemb = 10;
		size_t			size = sizeof(int);
		unsigned char	*bytes;
		int				all_zero = 1;

		ptr = ft_calloc(nmemb, size);
		if (!ptr)
		{
			printf("❌ FAILED: Test 1 (Allocation failed for basic array)\n");
			failed++;
		}
		else
		{
			bytes = (unsigned char *)ptr;
			for (size_t i = 0; i < nmemb * size; i++)
			{
				if (bytes[i] != 0)
				{
					all_zero = 0;
					break;
				}
			}
			if (!all_zero)
			{
				printf("❌ FAILED: Test 1 (Bytes are not zero-initialized!)\n");
				failed++;
			}
			else
				printf("✅ PASSED: Test 1 - Basic allocation and complete zero-fill\n");
			free(ptr);
		}
	}

	// -------------------------------------------------------------
	// TEST 2: Dirty Memory Check
	// (Allocate dirty buffer, free it, call ft_calloc to verify zeroing)
	// -------------------------------------------------------------
	{
		size_t count = 128;
		char *dirty = malloc(count);
		if (dirty)
		{
			memset(dirty, 0xFF, count);
			free(dirty);
		}

		ptr = ft_calloc(count, 1);
		if (!ptr)
		{
			printf("❌ FAILED: Test 2 (Allocation failed after freeing dirty memory)\n");
			failed++;
		}
		else
		{
			int clean = 1;
			unsigned char *b = (unsigned char *)ptr;
			for (size_t i = 0; i < count; i++)
			{
				if (b[i] != 0)
				{
					clean = 0;
					break ;
				}
			}
			if (!clean)
			{
				printf("❌ FAILED: Test 2 (Dirty memory was not zeroed out!)\n");
				failed++;
			}
			else
				printf("✅ PASSED: Test 2 - Zeroes out previously dirtied heap space\n");
			free(ptr);
		}
	}

	// -------------------------------------------------------------
	// TEST 3: Zero Size Boundaries (nmemb == 0, size == 0)
	// Must return a pointer that can be freed safely without crashing
	// -------------------------------------------------------------
	{
		// 3a: nmemb == 0, size > 0
		ptr = ft_calloc(0, sizeof(int));
		if (ptr == NULL)
		{
			// Note: POSIX allows either NULL or a unique freeable pointer.
			// However, in 42's Moulinette, standard malloc(0) behavior is expected.
			printf("⚠️  NOTE: Test 3a (Returned NULL for nmemb == 0 - acceptable per POSIX, but ensure freeability)\n");
		}
		else
		{
			free(ptr);
			printf("✅ PASSED: Test 3a - nmemb == 0 returns valid freeable pointer\n");
		}

		// 3b: nmemb > 0, size == 0
		ptr = ft_calloc(10, 0);
		if (ptr == NULL)
			printf("⚠️  NOTE: Test 3b (Returned NULL for size == 0 - acceptable per POSIX)\n");
		else
		{
			free(ptr);
			printf("✅ PASSED: Test 3b - size == 0 returns valid freeable pointer\n");
		}

		// 3c: nmemb == 0, size == 0
		ptr = ft_calloc(0, 0);
		if (ptr == NULL)
			printf("⚠️  NOTE: Test 3c (Returned NULL for 0, 0 - acceptable per POSIX)\n");
		else
		{
			free(ptr);
			printf("✅ PASSED: Test 3c - Both 0 returns valid freeable pointer\n");
		}
	}

	// -------------------------------------------------------------
	// TEST 4: Integer Overflow Detection (SIZE_MAX Trap)
	// (Must return NULL without segfaulting)
	// -------------------------------------------------------------
	{
		// SIZE_MAX overflow via extreme numbers
		ptr = ft_calloc(SIZE_MAX, 2);
		if (ptr != NULL)
		{
			printf("❌ FAILED: Test 4a (Overflow not detected on SIZE_MAX * 2! Returned %p)\n", ptr);
			free(ptr);
			failed++;
		}
		else
			printf("✅ PASSED: Test 4a - SIZE_MAX * 2 overflow returns NULL\n");

		// Sub-overflow: (SIZE_MAX / 2) + 1 * 2
		ptr = ft_calloc((SIZE_MAX / 2) + 1, 2);
		if (ptr != NULL)
		{
			printf("❌ FAILED: Test 4b (Overflow not detected on (SIZE_MAX/2 + 1) * 2! Returned %p)\n", ptr);
			free(ptr);
			failed++;
		}
		else
			printf("✅ PASSED: Test 4b - Intermediate SIZE_MAX overflow returns NULL\n");

		// Francinette classic trap: SIZE_MAX, SIZE_MAX
		ptr = ft_calloc(SIZE_MAX, SIZE_MAX);
		if (ptr != NULL)
		{
			printf("❌ FAILED: Test 4c (Overflow not detected on SIZE_MAX * SIZE_MAX! Got %p)\n", ptr);
			free(ptr);
			failed++;
		}
		else
			printf("✅ PASSED: Test 4c - Extreme square overflow returns NULL\n");
	}

	// -------------------------------------------------------------
	// TEST 5: Large Single Allocation
	// -------------------------------------------------------------
	{
		size_t large_count = 100000;
		ptr = ft_calloc(large_count, sizeof(char));
		if (!ptr)
		{
			printf("❌ FAILED: Test 5 (Large allocation of 100k bytes failed)\n");
			failed++;
		}
		else
		{
			unsigned char *b = (unsigned char *)ptr;
			if (b[0] == 0 && b[large_count / 2] == 0 && b[large_count - 1] == 0)
				printf("✅ PASSED: Test 5 - Large allocation (100k bytes) verified zeroed\n");
			else
			{
				printf("❌ FAILED: Test 5 (Large buffer not cleanly zeroed)\n");
				failed++;
			}
			free(ptr);
		}
	}

	// -------------------------------------------------------------
	// SUMMARY
	// -------------------------------------------------------------
	if (failed == 0)
		printf("\n🎉 ALL ft_calloc STRESS TESTS PASSED!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */

