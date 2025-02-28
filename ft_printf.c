/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:28:36 by dmontana          #+#    #+#             */
/*   Updated: 2025/02/26 14:28:39 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifiers(const char c, int*count, va_list args)
{
	if (c == 'c')
		ft_print_char(va_arg(args, int), count); // va_arg accesses the next argument in the list of variable arguments. But since C does not retain type information, I need to specify it.
	else if (c == 's')
		ft_print_str(va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_print_int(va_arg(args, int), count);
	else if (c == 'u')
		ft_print_uns_int(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_print_low_hex(va_arg(args, unsigned int), count);
	else if (c == 'X')
		ft_print_up_hex(va_arg(args, unsigned int), count);
	else if (c == 'p')
		ft_print_ptr(va_arg(args, void *), count);
	else if (c == '%')
		ft_print_char('%', count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args; // I declare my va_list
	int		count; // need a counter to measure and return the number of chars printed, to emulate printf
	count = 0;
	va_start(args, s); // s is a char and it's the last fixed argument
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s)
				ft_specifiers(*s, &count, args); // args signals that the next argument is a variadic one (Actually it is the next argument), but since I'm just giving an argument on a function I'm calling I don't need to specify the type
		else
			ft_print_char(*s, &count); // If I pass the value directly into other functions, any increment will only have a local scope and count will not be recognized. By passing a pointer, changes affect the original variable (because the memory adress, "the cell" is one.)
		}
		s++;
	}
	va_end(args);
	return (count);
}
