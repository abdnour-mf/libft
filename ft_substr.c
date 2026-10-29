#include "libft.h"

/* size_t ft_strlen(const char *s)
{
	size_t len = 0;

	while (s[len])
		len++;
	return (len);
} */

/* char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i = 0;
	char *sub;
	size_t len_all;
	size_t s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[i] = '\0';
		return (sub);
	}

	if (len <= (s_len - start))
		len_all = len;
	else
		len_all = s_len - start;

	sub = malloc(len_all + 1);
	if (sub == NULL)
		return (NULL);
	while(i < len_all)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
} */


char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	size_t i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start; 
	sub = malloc(len + 1);
	if(!sub)
		return (NULL);
	while(i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/* int main()
{
	char s[] = "hello";
	printf("%s\n", ft_substr(s, 2, 10));
	return (0);
} */