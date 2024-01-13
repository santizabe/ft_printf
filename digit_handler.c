/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:02:28 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/12 15:00:25 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(unsigned char flags, int *info, unsigned int n)
{
	int	res;

	return (res);
}

int	handle_int(unsigned char flags, int *w_p_h, int num)
{
	int				info[3];
	int				numlen;
	unsigned int	n;

	numlen = ft_numlen(num, 10);
	n = num;
	if (num < 0)
		n = num * -1;
	if (((flags & 16) || num < 0) && --w_p_h[0] > -2)
	{
		info[2] = 1;
		if (num >= 0)
			info[2] = 2;
	}
	info[1] = w_p_h[1] - numlen;
	info[0] = w_p_h[0] - numlen;  
	if (info[1] > 0)
		info[0] = w_p_h[0] - (numlen + w_p_h[1]);
	return (print_number(flags, &info[0], n));
}

//------47
// Control when num = 0 and precision. E.g. prec = 4 -> 0000;
// w_p_h[0] = width, w_p_h[1] = precision.
// Info contains the converted width, precision and sign
// info[2] = 1 -> '-';	info[2] = 2 -> '+';