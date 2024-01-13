/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:00:56 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/11 23:21:18 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(unsigned int num, unsigned int base_len)
{
	int	len;

	len = 1;
	if (num < base_len)
		return (len);
	return (len + ft_numlen(num / base_len, base_len));
}

int	ft_putnchar(char *s, int count)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (s[i] && i < count)
	{
		res += write(1, &s[i], 1);
		i++;
	}
	return (res);
}
