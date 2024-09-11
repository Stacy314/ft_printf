/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:40:46 by apechkov          #+#    #+#             */
/*   Updated: 2024/05/29 17:20:32 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (print_char(va_arg(ap, int)));
	else if (specifier == 's')
		return (print_str(va_arg(ap, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_digit((long)va_arg(ap, int), 10, specifier));
	else if (specifier == 'x' || specifier == 'X')
		return (print_digit((long)va_arg(ap, unsigned int), 16, specifier));
	else if (specifier == 'u')
		return (print_digit((long)va_arg(ap, unsigned int), 10, specifier));
	else if (specifier == 'p')
		return (print_address(va_arg(ap, unsigned long)));
	else if (specifier == '%')
		return (print_char('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;

	i = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			i += print_format(*(++format), ap);
		}
		else
		{
			i += write(1, format, 1);
		}
		++format;
	}
	va_end(ap);
	return (i);
}

/*int main()
{
    int count;

    count = ft_printf("%d\n", 255);
    printf("The chars written are %d\n", count);
    count = printf("%d\n", 255);
    printf("The chars written are %d\n", count);
    return (0);
}*/