void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i = 0;
    char *p = (char *)s;
    while(i < n)
    {
        if(p[i] == (unsigned char)c)
            return (&p[i]);
        i++;
    }
    return (NULL);
}