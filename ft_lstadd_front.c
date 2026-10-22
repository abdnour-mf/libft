#include "libft.h"
/* typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list; */

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    new->next = *lst;
    *lst = new;
}

/* int main()
{
    t_list *head = NULL;
    t_list *tmp;

    t_list *a = ft_lstnew("A");
    t_list *b = ft_lstnew("B");
    t_list *c = ft_lstnew("first");

    ft_lstadd_front(&head, a);
    ft_lstadd_front(&head, b);
    ft_lstadd_front(&head, c);
    tmp = head;

    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
    free(b);
    free(a);
    free(c);
    return (0);
} */