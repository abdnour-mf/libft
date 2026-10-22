#include "libft.h"

/* char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i = 0;
	size_t j;

	if (needle[i] == '\0')	return ((char *)haystack);
	
	while(haystack[i])
	{
		j = 0;
		while (needle[j] && i + j < len && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
} */

char *ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t i = 0;
	size_t j;

	if (sub[i] == '\0') return ((char *) str);
	while(str[i] && i < len)
	{
		j = 0;
		while(sub[j] && i + j < len && str[i + j] == sub[j])
			j++;
		if (sub[j] == '\0')
			return ((char *)&sub[i]);
		i++;
	}
	return (NULL);
}

#include <stdio.h>

int main()
{
	char str[] = "hello world 1337!";
	char str1[] = "hello worl 1337!";
	char sub[] = "world";

	printf("%s\n", ft_strnstr(str, sub,17));
	printf("%s\n", ft_strnstr(str1, sub,17));
	return 0;
}