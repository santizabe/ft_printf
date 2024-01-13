/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:38:07 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/11 17:18:34 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(unsigned char flags, int *w_p_h, char c)
{
	int	width;
	int	res;

	width = w_p_h[0];
	if (flags & 4)
	{
		res += write(1, &c, 1);
		while (width && width--)
			res += write(1, " ", 1);
	}
	else
	{
		while (width && width--)
			res += write(1, " ", 1);
		res += write(1, &c, 1);
	}
	return (res);
}

int	handle_string(unsigned char flags, int *w_p_h, char *s)
{
	int	width;
	int	strlen;
	int	res;

	strlen = ft_strlen(s);
	if (w_p_h[1] && w_p_h[1] < strlen)
		strlen = w_p_h[1];
	width = w_p_h[0] - strlen;
	if (flags & 4)
	{
		res += ft_putnchar(s, strlen);
		while (width > 0 && width--)
			res += write(1, " ", 1);
	}
	else
	{
		while (width > 0 && width--)
			res += write(1, " ", 1);
		res += ft_putnchar(s, strlen);
	}
	return (res);
}
