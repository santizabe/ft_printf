/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:04:16 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/11 17:35:15 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

unsigned char	check_flags(char **ptr)
{
	unsigned char	flags;

	flags = 0;
	while (strchr("#0 -+", **ptr))
	{
		set_flags(&flags, **ptr);
		(*ptr)++;
	}
	return (flags);
}

int	check_width(char **format)
{
	char	*tmp;

	tmp = *format;
	while (ft_isdigit(**format))
		(*format)++;
	return (ft_atoi(tmp));
}

