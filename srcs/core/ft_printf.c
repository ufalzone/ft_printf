/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:14:04 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/18 13:43:12 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - %c Imprime un seul caractère.
// -%s Imprime une chaîne de caractères.
// - %p L'argument du pointeur void * doit être imprimé au format hexadécimal.
// - %d Imprime un nombre décimal (base 10).
// - %i Imprime un nombre entier en base 10.
// - %u Imprime un nombre décimal non signé (base 10).
// - %x Imprime un nombre au format hexadécimal (base 16) en minuscules.
// - %X Imprime un nombre au format hexadécimal (base 16) en majuscules.
// - %% Imprime un signe de pourcentage

#include "../../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;
	size_t	i;
	int		size;

	i = 0;
	len = ft_printf_strlen(format);
	size = 0;
	va_start(ap, format);
	while (i < len)
	{
		if (format[i] == '%' && format[i + 1])
		{
			size += ft_redirect(format[i + 1], ap);
			i += 2;
		}
		else
		{
			size += ft_printf_putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (size);
}
