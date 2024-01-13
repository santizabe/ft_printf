/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:07:00 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/11 17:33:29 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_handler(unsigned char flags, int *w_p_h, char f, va_list ap)
{
	if (f == 'c')
		return (handle_char(flags, w_p_h, va_arg(ap, char)));
	else if (f == 's')
		return (handle_string(flags, w_p_h, va_arg(ap, char *)));
	else if (f == 'd' || f == 'i')
		return (handle_int(flags, w_p_h, va_arg(ap, int)));
	else if (ft_strchr("uxX", f))
		return (handle_unsigned(flags, w_p_h, va_arg(ap, unsigned int)), f);
	else if (f == 'p')
		return (handle_pointer(flags, w_p_h, va_arg(ap, void *)));
	return (0);
}

int	print_string(char flags, char **format, va_list ap)
{
	unsigned char	flag_h;
	int				w_p_handler[2];

	if (flags == -1)
		return (print_err(*format, ap));
	if (flags & 1)
		flag_h = check_flags(format);
	if (flags & 2)
		w_p_handler[0] = check_width(format);
	if (flags & 4 && **format == '.')
	{
		w_p_handler[1] = ft_atoi(++(*format));
		if (flag_h & 2)
			flag_h = flag_h ^ 2;
	}
	return (conv_handler(flag_h, &w_p_handler[0], **format, ap));
}
