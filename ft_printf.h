/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:10:41 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/11/02 15:36:02 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdlib.h"

int		ft_printf(const char *string, ...);
int		pf_power(int ground, int power);
int		pf_putstr_fd(char *s, int fd);
int		pf_putchar_fd(char c, int fd);
int		pf_putnbr_fd(int n, int fd);
int		pf_putnbr_fd_u(unsigned int n, int fd);
int		pf_pointer(unsigned long n, int fd);
int		pf_putnbr_rec_hu(unsigned int n, int fd);
int		pf_putnbr_rec_h(unsigned long n, int fd);

#endif
