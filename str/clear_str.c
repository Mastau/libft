/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:22:09 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/12 18:44:17 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	clear_str(char **str)
{
	char	**cpy;

	cpy = str;
	if (!str)
		return ;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(cpy);
}
