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

void	ft_print_ptr(void *ptr, int *count)
{
	unsigned long	nbr;

	if (!ptr)
		return (ft_print_str("(nil)", count));
	nbr = (unsigned long) ptr;
	ft_print_str("0x", count);
	ft_print_nbr_base(nbr, "0123456789abcdef", count);
}
