/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:29:39 by dmontana          #+#    #+#             */
/*   Updated: 2025/02/26 14:29:41 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(const char *s, int *count)
{
	size_t	len;

	if (!s)
		ft_print_str("(null)", count);
	else
	{
		len = ft_strlen(s);
		write(1, s, len);
		*count += len;
	}
}
