/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 20:56:29 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"

t_shell *shell = NULL;

// int main()
// {
// 	int arr[] = {8, 1, 2, 9, 6, 55, 4, 7, 5, 3};
// 	const int size = sizeof(arr) / sizeof(int);

// 	t_tree *tree = make_tree_from_array(arr, size);
// 	print_preorder(tree);
// 	node_clear(tree, 8);
// 	print_preorder(tree);
// 	node_clear(tree, 7);
// 	print_preorder(tree);
// 	return 0;
// }

// int main(int ac, char **av, char **env)
// {
// 	shell = make_shell(env);

// 	// fetch -> decode -> execute
// 	while (true)
// 	{
// 		string line = read_line();
// 		// char * line = av[1];

// 		a_cmd_container cmds = make_cmd_container(line);

// 		if (!line || (cmds && cmds->size == 1 && cmds->arr[0] && list_value_same(cmds->arr[0]->name, "exit")))
// 		{
// 			printf("exit\n");
// 			break;
// 		}

// 		if (NULL != cmds)
// 		{
// 			size_t i = 0;

// 			while (i < cmds->size)
// 			{
// 				eval(cmds, i++);
// 			}

// 			while (-1 != wait(NULL));
// 		}

// 		if (__strcmp(line, "\n"))
// 		{
// 			push_back(shell->history, line);

// 			add_history(line);
// 		}

// 	}
// 	__t_shell__(shell);

// 	return 0;
// }

// #ifdef __APPLE__
// void	__attribute__((destructor)) moid(void)
// {
// 	// printf(GREEN);
// 	printf("\n\nLeaks report\n");
// 	system("leaks minishell");
// 	// printf(RESET);
// }
// #endif // __APPLE__
