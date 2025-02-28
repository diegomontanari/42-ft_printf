/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:29:09 by dmontana          #+#    #+#             */
/*   Updated: 2025/02/26 14:29:12 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr_base(unsigned long nbr, char *base, int *count)
{
	size_t	len;

	len = ft_strlen(base); // Compute the length of the base using the ft_strlen function
	if (nbr == 0)
	{
		ft_print_char(base[0], count); // If the number is 0, print the first character of the base (1st is 0 for every base) and increment the count
		return ;
	}
	if (nbr >= len)
	{
		ft_print_nbr_base(nbr / len, base, count); // recursively call the function with the number divided by the length of the base
	}
	ft_print_char(base[nbr % len], count); // Print the character in the base that corresponds to the remainder of the number divided by the length of the base and increment the count
}
