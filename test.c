#include <stdio.h>
#include <stdlib.h>
typedef struct s_list
{
	int a;
	char *str;
}t_list;
void	arge(void *p)
{
	t_list *c;
	c = p;
	printf(("%d ", c->a));
	printf(("%s \n", c->str));
}
int main()
{
	t_list *node;

	node = malloc(sizeof(t_list));
	node->a = 1337;
	node->str = "1337";
	arge(node);
}