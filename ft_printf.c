/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:14:04 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/17 20:27:49 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//   %c Prints a single character.
//   %s Prints a string (as defined by the common C convention).
//   %p The void * pointer argument has to be printed in hexadecimal format.
//   %d Prints a decimal (base 10) number.
//   %i Prints an integer in base 10.
//   %u Prints an unsigned decimal (base 10) number.
//   %x Prints a number in hexadecimal (base 16) lowercase format.
//   %X Prints a number in hexadecimal (base 16) uppercase format.
//   %% Prints a percent sign.

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;
	size_t	i;
	int		size;

	i = 0;
	len = ft_strlen(format);
	size = 0;
	va_start(ap, format);
	while (i < len)
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == 'c')
				size += ft_putchar(va_arg(ap, int));
			else if (format[i + 1] == 's')
				size += ft_putstr(va_arg(ap, char *));
			else if (format[i + 1] == 'p')
			{
				ft_putstr("0x");
				(size += ft_putnbr_base((size_t)va_arg(ap, size_t),
						"0123456789abcdef") + 2);
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				size += ft_putnbr(va_arg(ap, int));
			else if (format[i + 1] == 'u')
				size += ft_putnbr(va_arg(ap, unsigned int));
			else if (format[i + 1] == 'x')
				size += ft_putnbr_base(va_arg(ap, unsigned int),
						"0123456789abcdef");
			else if (format[i + 1] == 'X')
				size += ft_putnbr_base(va_arg(ap, unsigned int),
						"0123456789ABCDEF");
			else if (format[i + 1] == '%')
				size += ft_putchar('%');
			else
				size += ft_putchar(format[i]);
			i += 2;
		}
		else
		{
			size += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (size);
}

int	main(void)
{
	int	x;
	
    x = -5;
	ft_printf(" %u ", -1);
    ft_printf("\n");
	printf(" %u ", -1);
}
