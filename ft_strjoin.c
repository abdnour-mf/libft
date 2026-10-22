#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{

	size_t len = ft_strlen(s1) + ft_strlen(s2);
	char *str;
	size_t i = 0;

	str = malloc (len + 1);
	if (str == NULL)
		return (NULL);
	
	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while(s2[i])
	{
		str[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	str[len] = '\0';

	return (str);    
}
