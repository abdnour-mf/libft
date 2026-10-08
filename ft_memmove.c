void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t i;
	char *dest = (char *)dst;

	if(dst < src)
	{
		i = 0;
		while(i < n)
        	dest[i] = ((const char *)src)[i++];
	}
	else if(src < dst)
	{
		i = n;
		while(i > 0)
        	dest[--i] = ((const char *)src)[i];
	}
	return (dst);
}