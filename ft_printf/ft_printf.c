/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faresms <faresms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 02:33:21 by faresms           #+#    #+#             */
/*   Updated: 2025/03/01 08:14:58 by faresms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		i;
	int		printed_chars;

	va_start (ap, str);
	i = 0;
	printed_chars = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 'c')
				printed_chars += ft_putchar(va_arg(ap, int));
			else if (str[i] == 's')
				printed_chars += ft_putstr(va_arg(ap, char *));
			else if (str[i] == 'd' || str[i] == 'i')
				printed_chars += ft_putnbr(va_arg(ap, int));
			else if (str[i] == 'u')
				printed_chars += ft_putunsigned((unsigned int)
						va_arg(ap, unsigned int));
			else if (str[i] == 'x' || str[i] == 'X')
				printed_chars += ft_puthex((unsigned int)va_arg(ap, unsigned long), str[i]);
			else if (str[i] == 'p')
				printed_chars += ft_putptr(va_arg(ap, void *));
			else if (str[i] == '%')
				printed_chars += ft_putchar('%');
		}
		else
			printed_chars += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (printed_chars);
}

// int	main(void)
// {
// 	printf("%p\n", ((void*)0));
// 	ft_printf("%p\n", ((void*)0));
// }
