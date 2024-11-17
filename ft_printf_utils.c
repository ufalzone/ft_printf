/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:17:07 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/17 20:19:02 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
        n = -n;
		i++;
	}
	if (n >= 10)
		i+=ft_putnbr(n / 10);	
    ft_putchar(n % 10 + '0');
	i++;
	return (i);
}

int	ft_putnbr_base(size_t n, char *base)
{
	int i;
	i = 0;
	if (n >= 16)
    {
		i+=ft_putnbr_base(n / 16, base);
        
    }
    ft_putchar(base[n % 16]);
	i++;
	return (i);
}