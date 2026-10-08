#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
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
}