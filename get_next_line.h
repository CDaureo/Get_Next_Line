/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:55:02 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/23 13:57:52 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t ft_strlen(const char *s);
char *ft_strjoin(char *str_storage, char *buff);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strchr(char *s, int c);


# endif
