#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i = 0;
    while(s[i])
    {
        if(s[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }
    if (s[i] == (char)c)
        return ((char *)&s[i]);
    return (NULL);
}
/* #include <string.h>
#include <stdio.h>
int main()
{
     char s[] = "hello world";
    char c = 'o';
    printf("%s\n", ft_strchr(s,c)); 

    char str[] = { (char)200, 'A', '\0' };

    printf("ft_strchr: %p\n", (void *)ft_strchr(str, 200));
    printf("strchr:    %p\n", (void *)strchr(str, 200));
    printf("%zu\n", sizeof(str));  // 3
    printf("%c\n", str[0]);       // ?
    printf("%c\n", str[1]);       // A

    return (0);
} */