/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:40:27 by irlozano          #+#    #+#             */
/*   Updated: 2024/06/27 13:38:22 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
void	ft_format(va_list arguments, char format, size_t *counter);

void	ft_putchar(char c, size_t *counter);
void	ft_putstr(char *s, size_t *counter);
void	ft_putnbr(long n, size_t *counter);
void	ft_putpointer(unsigned long pointer, size_t *counter);
void	ft_puthexa(unsigned int nbr, size_t *counter, char case_type);

#endif
