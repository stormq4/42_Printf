/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 20:08:42 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/10/28 20:08:44 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putnbr_rec(long long n, int fd)
{
	int	count;

	if (n >= 10)
	{
		count = pf_putnbr_rec(n / 10, fd);
		pf_putchar_fd(n % 10 + '0', fd);
		return (count + 1);
	}
	return (pf_putchar_fd(n + '0', fd));
}

int	pf_putnbr_fd_u(unsigned int n, int fd)
{
	long long	nbr;
	int			len;

	nbr = n;
	len = pf_putnbr_rec(nbr, fd);
	return (len);
}

int	pf_putnbr_fd(int n, int fd)
{
	long long	nbr;
	int			len;

	nbr = n;
	len = 0;
	if (n < 0)
	{
		nbr = -nbr;
		len += pf_putchar_fd('-', fd);
	}
	len += pf_putnbr_rec(nbr, fd);
	return (len);
}
