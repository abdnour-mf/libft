#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i = 0;
    if (n == 0) return (0);

    char *p1 = (char *)s1;
    char *p2 = (char *)s2;
    while(i < n && p1[i] == p2[i])
        i++;
    return (p1[i] - p2[i]);
}

/* #include <stdio.h>
int	main(void)
{
	char	str1[] = "abc";
	char	str2[] = "abd";

	int		a[] = {10, 20, 30};
	int		b[] = {10, 20, 40};

	printf("=== CHAR ===\n");
	printf("Same: %d\n", ft_memcmp(str1, str1, 3));
	printf("abc vs abd: %d\n", ft_memcmp(str1, str2, 3));

	printf("\n=== INT ===\n");
	printf("Same: %d\n", ft_memcmp(a, a, sizeof(a)));
	printf("a vs b: %d\n", ft_memcmp(a, b, sizeof(a)));

	return (0);
} */