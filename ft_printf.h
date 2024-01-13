/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:06:54 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/11 23:21:50 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int				ft_printf(char const *format, ...);
unsigned char	check_flags(char **ptr);
void			set_flags(unsigned char flags, char c);
int				ft_numlen(unsigned int num, unsigned int base_len);
int				ft_putnchar(char *s, int count);

#endif