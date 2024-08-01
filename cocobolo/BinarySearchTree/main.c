/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:28:29 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 18:12:19 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main()
{
	int arr[] = {8, 1, 2, 9, 6, 55, 4, 7, 5, 3};
	const int size = sizeof(arr) / sizeof(int);

	t_tree *tree = make_tree_from_array(arr, size);
	print_preorder(tree);
	node_clear(tree, 8);
	print_preorder(tree);
	node_clear(tree, 7);
	print_preorder(tree);
	return 0;
}
