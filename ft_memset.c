void    *ft_memset(void *s, int c, size_t n)
{
    size_t i = 0;
    char *p = (char *)s;
    while (i < n)
    {
        p[i] = (unsigned char)c;
        i++;
    }
    return (s);
}