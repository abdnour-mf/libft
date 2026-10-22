#include "libft.h"

static size_t counter (char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while(s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void free_result(char **result, size_t j)
{
    while (j > 0)
        free(result[--j]);
    free(result);
}

/* char **ft_split(char const *s, char c)
{
	char **result;
	size_t i;
	size_t j;
	size_t start;
	size_t len;
	
	
	i = 0;
	j = 0;
	result = ft_calloc((counter(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while(s[i])
	{
		if (s[i] != c)
		{
			len = 0;
			start = i;
			while (s[i] != c && s[i])
			{	
				len++;
				i++;
			}
		}
		result [j] = ft_substr(s, start, len);
		j++;
		i++;
	}
	result[j] = NULL;
	return (result);
} */

char **ft_split(char const *s, char c)
{
    char    **result;
    size_t  i;
    size_t  j;
    size_t  start;
    size_t  len;

    if (!s)
        return (NULL);
    i = 0;
    j = 0;
    result = ft_calloc(counter(s, c) + 1, sizeof(char *));
    if (!result)
        return (NULL);
    while (s[i])
    {
        if (s[i] != c)
        {
            start = i;
            len = 0;
            while (s[i] && s[i] != c)
            {
                len++;
                i++;
            }
            result[j] = ft_substr(s, start, len);
            if (!result[j])
            {
                free_result(result, j);
                return (NULL);
            }
            j++;
        }
        else
            i++;
    }
    result[j] = NULL;
    return (result);
}

int main(void)
{
    char **result;

    result = ft_split("hello world", ' ');
    printf("%s\n", result[0]);
    printf("%s\n", result[1]);
    printf("%p\n", (void *)result[2]);
    free(result[0]);
    free(result[1]);
    free(result);
    return (0);
}

/* int main()
{
	printf("%lu\n", counter("  hh hshs hs hxhs hs ", ' '));
	printf("%lu\n", counter(" ", ' '));
	printf("%lu\n", counter("", ' '));
	printf("%lu\n", counter("hello wrold", ' '));
	return (0);
} */