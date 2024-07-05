#include <stdio.h>
#include <cocobolo.h>


int main()
{
	t_list *list = make_list();

	for (int i = 1; i <= 10; i++)
	{
		push_front(list, i);
	}

	// push_front(list, 1);
	// push_front(list, 2);
	// push_front(list, 3);

	print_list(list);

	return 0;
}
