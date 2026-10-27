#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memmove(void *dst, const void *src, size_t len);
void ft_bzero(void *s, size_t n);
char *ft_strtrim(char const *s1, char const *set);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strdup(const char *s1);
void *ft_calloc(size_t count, size_t size);
void *ft_memset(void *s, int c, size_t n);

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));


#endif