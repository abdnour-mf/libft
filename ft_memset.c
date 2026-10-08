// #include <stdio.h>

// fill the first n bytes with the value of c

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

//void * : points to memory of any type

/* int main() 
{
    int i = 0;
    int buffer[3] = {1, 22, 1337};
    while(i < 3)   
    {
        printf("%d", buffer[i]);
        printf("\t");
        i++;
    }
    printf("\n");
    ft_memset(buffer, 0, sizeof(buffer));
    i = 0;
    while(i <3)   
    {
        printf("%d", buffer[i]);
        printf("\t");
        i++;
    }
    // result is 0 0 0

    printf("\n");

     ft_memset(buffer, 1, sizeof(buffer));
    i = 0;
    while(i <3)   
    {
        printf("%d", buffer[i]);
        printf("\t");
        i++;
    }
    // result is (16843009 three times) and not 1

} */