/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/07/09 11:09:27 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_char(char a);
int	ft_print_str(char *word);
int	ft_print_hexa(unsigned long long hexadec);
int	ft_newitoa(int nbr);
int	ft_newutoa(int nbr);
int	ft_print_xhexa(unsigned int hexadec);
int	ft_print_x_may_hexa(unsigned int hexadec);
int	print_base(unsigned long long nbr, char *base, int cont);

#endif