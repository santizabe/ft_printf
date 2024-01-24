/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:40:27 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/23 17:25:02 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_err(const char **format, va_list ap)
{
	int		res;
	void	*ptr;

	res = 0;
	res += write(1, "%", 1);
	ptr = va_arg(ap, void *);
	while (**format && **format != '%')
	{
		res += write(1, *format, 1);
		(*format)++;
	}
	return (res);
}
