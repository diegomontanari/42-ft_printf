/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:29:27 by dmontana          #+#    #+#             */
/*   Updated: 2025/02/26 14:29:29 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(void *ptr, int *count // I need to pass the pointer for global scope
{
	unsigned long	nbr;

	if (!ptr)
		return (ft_print_str("(nil)", count)); 
	nbr = (unsigned long) ptr; // I cast the memory adress to print it next
	ft_print_str("0x", count); // Since memory adresses are exadecimal, and exadecimals have the prefix "0x" I need to print it first
	ft_print_nbr_base(nbr, "0123456789abcdef", count);
}

/*
NOTE, BASE INDICATORS FOR DIFFERENT NUMERAL SYSTEMS:
The base indicators (prefixes) for different numeral systems are as follows:

Hexadecimal: 0x (e.g., 0x1A3F)
Octal: 0 (e.g., 0751)
Binary: 0b (e.g., 0b1011)
*/
