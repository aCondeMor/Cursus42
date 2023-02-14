/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:04:23 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/15 23:30:11 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	if ((fd > 0) && (str))
	{
		ft_putstr_fd(str, fd);
		ft_putchar_fd('\n', fd);
	}
}
