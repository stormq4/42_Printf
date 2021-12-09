/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_put.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 14:07:19 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/10/29 09:52:53 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	pf_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	pf_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return (pf_putstr_fd("(null)", fd));
	i = 0;
	while (s[i])
	{
		pf_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}
