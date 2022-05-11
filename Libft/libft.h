/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:28:32 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/11 18:35:57 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t max);
size_t	ft_strlcat(char *dest, const char *src, size_t max);
void	*ft_memchr(void *dst, int c, size_t n);
int		ft_memcmp(void *dst, void *src, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(char *src, int c);
char    *ft_strrchr(char *src, int c);
int		ft_strncmp(char *dst, char *src, size_t n);
char    *ft_strnstr(char *str, char *to_find, size_t n);
char	*ft_strdup(const char *str);
void    *ft_calloc(size_t count, size_t size);
int 	ft_atoi(char *str);
char	*ft_substr(char const *s, unsigned int start,size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char    *ft_itoa(int nbr);

#endif
