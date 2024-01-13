/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:07:44 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/11 17:29:23 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(char const *format, ...)
{
	int		res;
	char	flags;
	va_list	ap;

	res = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			flags = check_format(format++);
			res += print_string(flags, &format, ap);
			flags = 0;
		}
		else if (write(1, format, 1) == -1)
			return (res);
		res += 1;
	}
	return (res);
}
