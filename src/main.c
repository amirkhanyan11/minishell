#include <stdio.h>
#include "minishell.h"

int main()
{
	t_shell *shell = make_shell();

	while (true)
	{
		display_prompt();
		char * line = readline(NULL);

		if (__strcmp(line, "pwd")) pwd(shell);

		else if (__strcmp(line, "history")) display_history(shell);

		push_back(shell->history, line);
	}
	

	__t_shell__(&shell);
	return 0;
}
