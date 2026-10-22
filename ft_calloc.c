#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s = (unsigned char *)b;
	size_t i;

	i = 0;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}

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