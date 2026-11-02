#include "libft.h"

// fill the first n bytes with the value of c

void    *ft_memset(void *s, int c, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        ((unsigned char *)s)[i] = (unsigned char)c;
        i++;
    }
    return (s);
}

//void * : points to memory of any type



// #include <stdio.h>
// #include <string.h>

/*int	main(void)
{
	unsigned char	real_buf[8];
	unsigned char	my_buf[8];
	int				values[] = {0, 'A', -1, 128, 255, 258};
	size_t			lengths[] = {0, 1, 4, 8};
	size_t			i;
	size_t			j;
	size_t			n;
	int				errors;
	int				failed;
	void			*real_ptr;
	void			*my_ptr;

	errors = 0;
	i = 0;
	while (i < sizeof(values) / sizeof(values[0]))
	{
		j = 0;
		while (j < sizeof(lengths) / sizeof(lengths[0]))
		{
			memset(real_buf, 0xAA, sizeof(real_buf));
			memset(my_buf, 0xAA, sizeof(my_buf));
			n = lengths[j];
			real_ptr = memset(real_buf, values[i], n);
			my_ptr = ft_memset(my_buf, values[i], n);
			failed = (real_ptr != real_buf || my_ptr != my_buf);
			if (memcmp(real_buf, my_buf, sizeof(real_buf)) != 0)
				failed = 1;
			printf("c=%d, n=%zu | memset=%s, ft_memset=%s | %s\n",
				values[i], n, real_ptr == real_buf ? "OK" : "FAIL",
				my_ptr == my_buf ? "OK" : "FAIL",
				failed ? "FAIL" : "PASS");
			if (failed)
				errors++;
			j++;
		}
		i++;
	}
	printf("\nTotal: %zu | Passed: %zu | Failed: %d\n",
		(sizeof(values) / sizeof(values[0]))
		* (sizeof(lengths) / sizeof(lengths[0])),
		(sizeof(values) / sizeof(values[0]))
		* (sizeof(lengths) / sizeof(lengths[0])) - errors, errors);
	return (errors != 0);
}
 */


/* int	main(void)
{
	char	buf1[50];
	char	buf2[50];
	int		failed = 0;

	printf("=== RUNNING TESTS FOR ft_memset ===\n");

	// Test 1: Standard character fill ('A')
	memset(buf1, 0, 50);
	memset(buf2, 0, 50);
	ft_memset(buf1, 'A', 10);
	memset(buf2, 'A', 10);
	if (memcmp(buf1, buf2, 50) != 0)
	{
		printf("❌ FAILED: Standard character fill ('A')\n");
		failed++;
	}
	else
		printf("✅ PASSED: Standard character fill ('A')\n");

	// Test 2: Zero fill (0)
	memset(buf1, 'X', 50);
	memset(buf2, 'X', 50);
	ft_memset(buf1, 0, 20);
	memset(buf2, 0, 20);
	if (memcmp(buf1, buf2, 50) != 0)
	{
		printf("❌ FAILED: Zero fill (0)\n");
		failed++;
	}
	else
		printf("✅ PASSED: Zero fill (0)\n");

	// Test 3: Extended ASCII / High byte value (> 127) - Where signed char fails!
	// 200 becomes negative (-56) in a signed char, causing incorrect behavior.
	memset(buf1, 0, 50);
	memset(buf2, 0, 50);
	ft_memset(buf1, 200, 15);
	memset(buf2, 200, 15);
	if (memcmp(buf1, buf2, 50) != 0)
	{
		printf("❌ FAILED: High byte value (200) -> Check if you used 'char' instead of 'unsigned char'!\n");
		failed++;
	}
	else
		printf("✅ PASSED: High byte value (200) handled correctly\n");

	// Test 4: Zero length (n = 0)
	memset(buf1, 'A', 10);
	memset(buf2, 'A', 10);
	ft_memset(buf1, 'B', 0);
	memset(buf2, 'B', 0);
	if (memcmp(buf1, buf2, 10) != 0)
	{
		printf("❌ FAILED: Zero length (n = 0)\n");
		failed++;
	}
	else
		printf("✅ PASSED: Zero length (n = 0)\n");

	if (failed == 0)
		printf("\n🎉 ALL ft_memset TESTS PASSED SUCCESSFULLY!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);

	return (0);
} */
