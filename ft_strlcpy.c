size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t len = 0;
    size_t i = 0;
    while (src[len])    len++;
    if (size == 0)  return (len);

    while (i < size - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (len);
}