#include "libft.h"

/* void	ft_lstadd_back(t_list **lst, t_list *new)
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
} */

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;
	
	if (!lst || !new)
		return;
	if (!*lst)
	{
	//if the list is empty then make the head point directly on new
		*lst = new;
		return;
	}
	tmp = *lst;
	while(tmp->next)
		tmp = tmp->next;
	new->next = NULL;
	tmp->next =	new;
}