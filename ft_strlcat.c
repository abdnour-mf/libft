size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t slen = 0;
    size_t dlen = 0;
    size_t i = 0;

    while(src[slen])    slen++;
    while(dst[dlen])    dlen++;
    if(size <= dlen)   return (size + slen);
    while(dlen + i < size - 1 && src[i])
    {
        dst[i + dlen] = src[i];
        i++;
    }
    dst[dlen + i] = '\0';
    return (slen + dlen);
}