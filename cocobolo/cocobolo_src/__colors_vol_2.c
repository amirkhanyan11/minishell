/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __colors_vol_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:34:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:34:40 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void	__red__(const char *const message)
{
	printf(RED);
	if (NULL != message)
	{
		printf("%s", message);
		printf(RESET);
	}
}

void	__cyan__(const char *const message)
{
	printf(CYAN);
	if (NULL != message)
	{
		printf("%s", message);
		printf(RESET);
	}
}

void	__blue__(const char *const message)
{
	printf(BLUE);
	if (NULL != message)
	{
		printf("%s", message);
		printf(RESET);
	}
}

void	__yellow__(const char *const message)
{
	printf(YELLOW);
	if (NULL != message)
	{
		printf("%s", message);
		printf(RESET);
	}
}
