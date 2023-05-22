/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:21:52 by pmessett          #+#    #+#             */
/*   Updated: 2023/04/18 10:17:21 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"

int		ft_printf(const char *s, ...);
void	ft_putchar(char c, unsigned int *size);
void	ft_putstr(char *s, unsigned int *size);
void	ft_putnbr(int n, unsigned int *size);
void	ft_putnbr_base(unsigned int n, char *base, unsigned int *size);
void	ft_putunsnbr(unsigned int n, unsigned int *size);
void	ft_putaddr(unsigned long int n, unsigned int *size);

#endif
