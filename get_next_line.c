/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:59:53 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/23 14:02:55 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * new_line:
 * - This function extracts a line from `str_storage` until the first newline character (`\n`).
 * - It finds the position of the newline using `ft_strchr`, calculates the length of the line,
 *   and creates a substring containing everything from the start up to the newline.
 * - The function returns the extracted line or `NULL` if there's an error.
 */
static char	*new_line(char *str_storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(str_storage, '\n');
	len = (ptr - str_storage) + 1;
	line = ft_substr(str_storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

/*
 * cleaner:
 * - This function cleans up `str_storage` after a line is extracted.
 * - It locates the newline character (`\n`) and creates a new string starting from the
 *   character right after the newline, copying the remaining data into `new_storage`.
 * - If there's no more data after the newline, the function frees `str_storage` and returns `NULL`.
 * - If the new storage allocation fails, it also frees `str_storage` and returns `NULL`.
 */
static char	*cleaner(char *str_storage)
{
	char	*new_storage;
	char	*ptr;

	ptr = ft_strchr(str_storage, '\n');
	if (!ptr || !*(ptr + 1))
		return (free(str_storage), NULL);
	new_storage = ft_strdup(ptr + 1);
	free(str_storage);
	return (new_storage);
}

/*
 * reader:
 * - This function reads data from the file descriptor (`fd`) into a buffer.
 * - It appends the read data to `str_storage`, creating a new temporary storage using `ft_strjoin`.
 * - The function reads until it encounters a newline (`\n`) or the end of the file.
 * - If there's an error, it frees the allocated memory and returns `NULL`.
 */
static char	*reader(int fd, char *str_storage)
{
	ssize_t	i;
	char	*buff;
	char	*temp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(str_storage), NULL);
	i = read(fd, buff, BUFFER_SIZE);
	while (i > 0)
	{
		buff[i] = '\0';
		temp = ft_strjoin(str_storage, buff);
		str_storage = temp;
		if (ft_strchr(buff, '\n'))
			break ;
		i = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (i == -1)
		return (free(str_storage), NULL);
	return (str_storage);
}
/*
 * get_next_line:
 * - This is the main function that reads and returns the next line from the file.
 * - It uses a static variable `str_storage` to store the data between multiple function calls.
 * - If there’s no data in storage or if there’s no newline, it reads more data from the file.
 * - Once it has a complete line, it extracts the line using `new_line` and updates the storage using `clean_storage`.
 * - It returns the extracted line, or `NULL` if an error occurs or the file is empty.
 */
char	*get_next_line(int fd)
{
	static char *str_storage = NULL;
	char *line;


	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!str_storage || !ft_strchr(str_storage, '\n'))
	{
		str_storage = reader(fd ,str_storage);
	}
	if (!str_storage)
		return (NULL);
	
	line = new_line(str_storage);
	if (!line)
	{
		return (free(str_storage), str_storage = NULL, NULL);
	}
	str_storage = cleaner(str_storage);
	return (line);
}