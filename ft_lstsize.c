#include "libft.h"

/* unsigned int ft_lstsize(t_list *lst)
{
    unsigned int count;

    count = 0;
    while(lst)
    {
        count++;
        lst = lst->next;
    }
    return (count);
} */

/* int main(void)
{
    t_list *head = NULL;
    t_list *a = ft_lstnew("A");
    t_list *b = ft_lstnew("B");
    t_list *c = ft_lstnew("C");

    ft_lstadd_front(&head, a);
    ft_lstadd_front(&head, b);
    ft_lstadd_front(&head, c);

    printf("List size: %u\n", ft_lstsize(head));

    free(c);
    free(b);
    free(a);
    return (0);
} */

unsigned int ft_lstsize(t_list *lst)
{
    unsigned int size;

    size = 0;
    //lst is the head and holds the adress of the first node.
    if (!lst)
        return (0);
    while(lst)
    {
        size++;
        lst = lst->next;
    }
    return (size);
}