#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i = ft_strlen(s);
    while(i >= 0)
    {
        if(s[i] == c)
            return ((char *)&s[i]);
        i--;
    }
    return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	char	*str;
	char	*p;

	str = "hello";
	p = ft_strrchr(str, 'l');

	printf("String: %s\n", str);
	printf("From found character: %s\n", p);
	printf("Character: %c\n", *p);
	printf("Address: %p\n", (void *)p);

	return (0);
} */