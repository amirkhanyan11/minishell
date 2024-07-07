#include <stdio.h>
#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_shell *shell = make_shell(env);

	while (true)
	{
		display_prompt();
		char * line = readline(NULL);

		if (0 == __strcmp(line, "pwd")) pwd(shell);

		else if (0 == __strcmp(line, "history")) display_history(shell);

		else if (0 == __strcmp(line, "exit")) break;

		push_back(shell->history, line);
	}

	t_node *node = find(shell->env, "PATH", list_value_contains);

	if (node)
	{
		t_list * foo = make_list_from_matrix(__split(node->val, ':'));
		t_node *a = find(foo, ".local", list_value_contains);
		if (a) printf ("%s\n",  a->val);
	}
	
	__t_shell__(&shell);
	return 0;
}
