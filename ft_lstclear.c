#include "libft.h"
void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *clear;
    t_list *next;
    if(!lst)
        return ;
    clear = *lst;
    while(clear)
    {
        next = clear->next;
        ft_lstdelone(clear, del);
        clear = next;
    }
    *lst = NULL;
}