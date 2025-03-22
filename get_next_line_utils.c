/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:59:50 by cdaureo-          #+#    #+#             */
/*   Updated: 2024/10/23 14:00:44 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/** 
 * The ft_strlen function is designed to compute the length of a string. 
 * It starts by initializing a counter 'i' to zero. If the input string 
 * 's' is NULL, it immediately returns 0, indicating that there is no 
 * string to measure. It then enters a loop that continues until it 
 * encounters the null terminator, incrementing 'i' for each character. 
 * Finally, it returns the value of 'i', which represents the length of the string.
 */
size_t ft_strlen(const char *s)
{
	size_t i;
	i = 0;
	
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

/** 
 * The ft_strchr function searches for the first occurrence of a 
 * specified character 'c' within the input string 's'. It starts 
 * by initializing an index 'i' to zero. The function loops through 
 * the string, checking each character. If it finds a match, it 
 * returns a pointer to that character within the string. If the 
 * character 'c' is the null terminator, it returns a pointer to the 
 * end of the string. If the character is not found, it returns NULL.
 */
char *ft_strchr(char *s, int c)
{
	int	i;
	
	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

/** 
 * The ft_strdup function creates a duplicate of the input string 's'. 
 * It first calculates the length of the string using ft_strlen. It 
 * then allocates sufficient memory to hold the duplicate string, 
 * including space for the null terminator. If the memory allocation 
 * fails, it returns NULL. After successful allocation, it copies 
 * each character from the original string to the newly allocated 
 * space and ensures the duplicate is null-terminated. Finally, 
 * it returns a pointer to the duplicated string.
 */
char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dupe;
	size_t	size;


	size = ft_strlen(s);
	dupe = malloc((size + 1) * sizeof(char));
	if (dupe == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		dupe[i] = s[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}
/** 
 * The ft_strjoin function concatenates two strings, str_storage and buff, 
 * into a new dynamically allocated string. It first checks if str_storage 
 * is NULL; if it is, it allocates memory for an empty string. The function 
 * then allocates enough memory for the combined length of both strings, 
 * including a null terminator. If memory allocation fails, it frees any 
 * previously allocated memory for str_storage and returns NULL. It then 
 * copies the contents of str_storage into the new string, followed by 
 * the contents of buff. After ensuring the new string is null-terminated, 
 * it frees the memory allocated for str_storage and returns a pointer to 
 * the new concatenated string.
 */
char	*ft_strjoin(char *str_storage, char *buff)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!str_storage)
	{
		str_storage = malloc(sizeof(char) + 1);
		if (!str_storage)
			return (0);
		str_storage[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(str_storage) + ft_strlen(buff)) + 1);
	if (!str)
		return (free(str_storage), str_storage = NULL, NULL);
	i = -1;
	while (str_storage[++i])
		str[i] = str_storage[i];
	c = -1;
	while (buff[++c])
		str[i + c] = buff[c];
	str[i + c] = '\0';
	free(str_storage);
	str_storage = NULL;
	return (str);
}
/** 
 * The ft_substr function extracts a substring from the input string 's', 
 * starting at the specified index 'start' and up to a maximum length 'len'. 
 * It first calculates the length of the original string using ft_strlen. 
 * If 's' is NULL, it returns NULL. If 'start' exceeds the string length, 
 * it allocates memory for an empty string and returns it. If the requested 
 * substring length exceeds the remaining length of the string, it adjusts 
 * 'len' accordingly. It allocates memory for the new substring, copies 
 * the specified characters, null-terminates the substring, and returns 
 * a pointer to the result.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;
	size_t	size_len;

	size_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (0);
	if (start > size_len)
	{
		result = malloc(sizeof(char) * (1));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (size_len - start < len)
		len = size_len - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (start < size_len && i < len && s[start])
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
