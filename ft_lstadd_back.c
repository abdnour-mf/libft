#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
        return ;
	if (!*lst)
	{
		*lst = new;
		new->next = NULL
		return ;
	}
	t_list *last = *lst;
	while(last->next)
		last = last->next;
	new->next = NULL;
	last->next = new;
}