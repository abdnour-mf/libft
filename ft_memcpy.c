#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    char *dest = (char *)dst;
    const char *sorc = (const char *)src;
    size_t i;

    i = 0;
    while (i < n)
    {
        dest[i] = sorc[i];
        i++;
    }
    return (dst);
}