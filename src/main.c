#include <stdio.h>
#include <cocobolo.h>

int main()
{
	t_list *list = make_list();
	
	// size_t size = pathconf(".", _PC_PATH_MAX);

	// char some[size];

	// getcwd(some, size);

	// push_back(list, some);
	push_back(list, "some");

	print_list(list);
	list_clear(&list);
	return 0;
}
