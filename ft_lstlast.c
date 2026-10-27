#include "libft.h"

/* t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while(lst->next)
        lst = lst->next;
    return (lst);
} */

t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    //we check till the we find that a node is pointing to NULL
    while (lst->next)
        lst = lst->next;
    return (lst);
}