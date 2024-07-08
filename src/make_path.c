/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:30:16 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 22:41:04 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list *make_path(t_shell *shell)
{
	if (!shell) return NULL;

	t_list *path = NULL;

	t_list_value raw_path = find_strict(shell->env)->val;

	t_matrix arr = __split(raw_path);

	// char *first = __strdup(arr[0]);

}
