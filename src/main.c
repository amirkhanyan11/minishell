#include <stdio.h>
#include <cocobolo.h>


int main()
{
	t_list *list = make_list();

	for (int i = 1; i <= 10; i++)
	{
		push_back(list, i);
	}
	print_list(list);
	list_clear(list);
	return 0;
}
