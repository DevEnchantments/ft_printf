/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faresms <faresms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 02:33:21 by faresms           #+#    #+#             */
/*   Updated: 2025/04/06 18:07:27 by faresms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_converter(char str, va_list ap)
{
	int	printed_chars;

	printed_chars = 0;
	if (str == 'c')
		printed_chars += ft_putchar(va_arg(ap, int));
	else if (str == 's')
		printed_chars += ft_putstr(va_arg(ap, char *));
	else if (str == 'd' || str == 'i')
		printed_chars += ft_putnbr(va_arg(ap, int));
	else if (str == 'u')
		printed_chars += ft_putunsigned((unsigned int)
				va_arg(ap, unsigned int));
	else if (str == 'x' || str == 'X')
		printed_chars += ft_puthex((unsigned int)
				va_arg(ap, unsigned long), str);
	else if (str == 'p')
		printed_chars += ft_putptr(va_arg(ap, void *));
	else if (str == '%')
		printed_chars += ft_putchar('%');
	return (printed_chars);
}

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
			printed_chars += format_converter(str[i], ap);
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
// 	char	c;
// 	char	*str;
// 	void	*ptr;
// 	int		i;
// 	int		d;
// 	unsigned int u;
// 	int		hex;

// 	str = "Fares";
// 	c = 'F';
// 	ptr = (void *)0x1234abcd;
// 	i = -2147483648;
// 	d = 2147483647;
// 	u = 4294967295;
// 	hex = 3735928559;
// 	printf("PRINTF   : [%c] [%s] [%p] [%d] [%i] [%u] [%x] [%X] [%%]\n",
// 		c, str, ptr, d, i, u, hex, hex);
// 	ft_printf("FT_PRINTF: [%c] [%s] [%p] [%d] [%i] [%u] [%x] [%X] [%%]\n",
// 		c, str, ptr, d, i, u, hex, hex);
// }
