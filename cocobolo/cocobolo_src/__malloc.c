/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:03:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 21:47:25 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void	__attribute__((malloc))	*__malloc(size_t n)
{
	void	*ptr;

	ptr = malloc(n);
	if (NULL == ptr)
		__exit("Bad alloc");
	return (ptr);
}