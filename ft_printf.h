/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:41:08 by dmontana          #+#    #+#             */
/*   Updated: 2025/01/09 13:51:54 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
WHAT: Remember that define is used to create a macro, 
which is just a text substitution.
HOW: Every occurrence of TYPES in the code will be replaced with cspdiuxX 
before compilation.
*/ 

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int			ft_printf(const char *s, ...);
void		ft_specifiers(const char c, int *count, va_list args);
void		ft_print_char(const char c, int *count);
void		ft_print_str(const char *s, int *count);
size_t		ft_strlen(const char *str);
void		ft_print_nbr_base(unsigned long nbr, char *base, int *count);
void		ft_print_int(int nbr, int *count);
void		ft_print_uns_int(unsigned int nbr, int *count);
void		ft_print_low_hex(unsigned int nbr_hex, int *count);
void		ft_print_up_hex(unsigned int nbr_hex, int *count);
void		ft_print_ptr(void *ptr, int *count);

#endif
