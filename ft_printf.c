/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:07:44 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/24 01:16:42 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

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
			flags = check_format(++format);
			res += print_string(flags, &format, ap);
			flags = 0;
			continue ;
		}
		else
			res += write(1, format, 1);
		format++;
	}
	return (res);
}

// int	main(void)
// {
// 	printf("\n%d\n", printf("%0#5x", 0));
// 	printf("\n%d", ft_printf("%0#5x", 0));
// 	return (0);
// }
