/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putnbr_h.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 20:08:50 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/11/02 15:38:07 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putnbr_rec_hu(unsigned int n, int fd)
{
	int	count;

	if (n >= 16)
	{
		count = pf_putnbr_rec_hu(n / 16, fd);
		if (n % 16 < 10)
			pf_putchar_fd(n % 16 + '0', fd);
		else
			pf_putchar_fd(n % 16 + 'A' - 10, fd);
		return (count + 1);
	}
	if (n % 16 < 10)
		return (pf_putchar_fd(n % 16 + '0', fd));
	else
		return (pf_putchar_fd(n % 16 + 'A' - 10, fd));
}

int	pf_putnbr_rec_h(unsigned long n, int fd)
{
	int	count;

	if (n >= 16)
	{
		count = pf_putnbr_rec_h(n / 16, fd);
		if (n % 16 < 10)
			pf_putchar_fd(n % 16 + '0', fd);
		else
			pf_putchar_fd(n % 16 + 'a' - 10, fd);
		return (count + 1);
	}
	if (n % 16 < 10)
		return (pf_putchar_fd(n % 16 + '0', fd));
	else
		return (pf_putchar_fd(n % 16 + 'a' - 10, fd));
}

int	pf_pointer(unsigned long n, int fd)
{
	int	len;

	len = pf_putstr_fd("0x", fd);
	len += pf_putnbr_rec_h(n, fd);
	return (len);
}
