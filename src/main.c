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

	print_list(shell->env);
	
	__t_shell__(&shell);
	return 0;
}
