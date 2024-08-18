/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __colors_vol_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:47:29 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:34:27 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void	__italic__(const char *const message)
{
	printf(ITALIC_ON);
	if (NULL != message)
	{
		printf("%s", message);
		printf(ITALIC_OFF);
	}
}

void	__purple__(const char *const message)
{
	printf(PURPLE);
	if (NULL != message)
	{
		printf("%s", message);
		printf(RESET);
	}
}

void	__reset__(const char *const message)
{
	printf(RESET);
	if (NULL != message)
	{
		printf("%s", message);
		printf(RESET);
	}
}

void	__green__(const char *const message)
{
	printf(GREEN);
	if (NULL != message)
	{
		printf("%s", message);
		printf(RESET);
	}
}
