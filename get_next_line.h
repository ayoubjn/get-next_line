/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajana <ajana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:33:41 by ajana             #+#    #+#             */
/*   Updated: 2021/11/29 22:48:37 by ajana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_printf(const char *s, ...);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
