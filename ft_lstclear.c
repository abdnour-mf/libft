#include "libft.h"
/* void ft_lstclear(t_list **lst, void (*del)(void *))
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
} */

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *tmp;

    if (!lst)
        return ;
    while(*lst)
    {
        //1st attempt : the first node’s next, which is the address of B.
        tmp = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = tmp;
    //0(head) -> 1 -> 2 -> 3 -> 4 -> NULL
    //we point tmp on 2 then we delete 1
    //then we point tmp on 3 then we delete 2
    }
    *lst = NULL;
}