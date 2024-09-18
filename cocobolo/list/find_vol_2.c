/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vol_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:40:57 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/18 23:27:35 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static t_node	*__find_if__(t_node *curr, t_node *last, t_list_Upredicate_b p)
{
	if (!curr || curr->prev == last)
		return (NULL);
	if (p(curr) == true)
		return (curr);
	return (__find_if__(curr->next, last, p));
}

t_node	*find_if(t_node *first, t_node *last, t_list_Upredicate_b p)
{
	if (!first || !last || !p)
		return (NULL);
	return (__find_if__(first, last, p));
}

static t_node	*__rfind_if__(t_node *curr, t_node *last, t_list_Upredicate_b p)
{
	if (!curr || curr->next == last)
		return (NULL);
	if (p(curr) == true)
		return (curr);
	return (__find_if__(curr->prev, last, p));
}

t_node	*rfind_if(t_node *first, t_node *last, t_list_Upredicate_b p)
{
	if (!first || !last || !p)
		return (NULL);
	return (__rfind_if__(last, first, p));
}

#pragma GCC diagnostic pop
