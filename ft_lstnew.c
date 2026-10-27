#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

int main()
{
    //char *str = ;
    t_list *node = ft_lstnew("hello");

    printf("Node address:   %p\n", (void *)node);
    printf("Content pointer: %p\n", node->content);
    printf("Content value:   %s\n", (char *)node->content);
    printf("Next pointer:    %p\n", (void *)node->next);

    free(node);
    return (0);
}

/* t_list *ft_lstnew(void *content)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

int main()
{
    t_list *a = ft_lstnew("hello");
    printf("")

} */