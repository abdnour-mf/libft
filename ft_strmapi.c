char  *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *res;
    unsigned int i;

    res = malloc(ft_strlen(s) + 1);
    if (!res)
        return (NULL);
    i = 0;
    while(res[i])
    {
        res[i] = (*f)(i, s[i]);
        i++;
    }
    res[i] = '\0';
    return (res);
}

int main()
{
    
}