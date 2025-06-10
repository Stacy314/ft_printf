/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:23:37 by apechkov          #+#    #+#             */
/*   Updated: 2024/05/29 19:23:38 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (*str != '\0')
	{
		print_char((int)*str);
		++i;
		++str;
	}
	return (i);
}

int	print_digit(long n, int base, char specifier)
{
	int		i;
	char	*symbols;
	char	*symbols_upper;

	i = 0;
	symbols = "0123456789abcdef";
	symbols_upper = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, 'x') + 1);
	}
	else if (n < base)
	{
		if (specifier == 'X')
			return (print_char(symbols_upper[n]));
		return (print_char(symbols[n]));
	}
	else
	{
		i = print_digit(n / base, base, specifier);
		return (i + print_digit(n % base, base, specifier));
	}
}

int	print_digit_u(unsigned long n, int base, char specifier)
{
	int		i;
	char	*symbols;

	i = 0;
	symbols = "0123456789abcdef";
	if (n < (unsigned long)base)
		return (print_char(symbols[n]));
	else
	{
		i = print_digit_u(n / base, base, specifier);
		return (i + print_digit_u(n % base, base, specifier));
	}
}

int	print_address(unsigned long address)
{
	int				len;

	len = 0;
	if (!address)
		len += print_str("(nil)");
	else
	{
		len = print_str("0x");
		len += print_digit_u(address, 16, 'x');
	}
	return (len);
}
