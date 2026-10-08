void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i = 0;
    char *dest = (char *)dst;
    while(i < n)
    {
        dest[i] = ((const char *)src)[i];
        i++;
    }
    return (dst);
}