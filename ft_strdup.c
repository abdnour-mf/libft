#include "libft.h"

char *ft_strdup(const char *s)
{
    char *copy;
    size_t len = ft_strlen(s);
    size_t i = 0;

    copy = malloc(len + 1);
    if (copy == NULL)
        return (NULL);
    while(s[i])
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}