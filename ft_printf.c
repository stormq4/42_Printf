/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 14:03:46 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/11/02 17:43:26 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	pf_checkfill(char c, va_list args)
{
	if (c == 'c')
		return (pf_putchar_fd(va_arg(args, unsigned int), 1));
	else if (c == 's')
		return (pf_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return (pf_pointer(va_arg(args, unsigned long), 1));
	else if (c == 'd' || c == 'i')
		return (pf_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (pf_putnbr_fd_u(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (pf_putnbr_rec_h((unsigned long)va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (pf_putnbr_rec_hu(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (pf_putchar_fd('%', 1));
	return (0);
}

int	pf_printpf(va_list args, const char *string, size_t len)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			len += pf_checkfill(string[i + 1], args);
			i++;
		}
		else
			len += pf_putchar_fd(string[i], 1);
		i++;
	}
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	size_t	len;

	len = 0;
	va_start(args, string);
	len = pf_printpf(args, string, len);
	va_end(args);
	return (len);
}
