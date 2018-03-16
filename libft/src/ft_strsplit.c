/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:58:35 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:15 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int		count_words(char *str, char c)
{
	int in_word;
	int count;

	in_word = 0;
	count = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			++count;
		}
		++str;
	}
	return (count);
}

static int		strlen_next_word(char *str, int *index, char c)
{
	int len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[*index] == c)
		++(*index);
	while (str[*index] != c && str[*index] != '\0')
	{
		++(*index);
		++len;
	}
	return (len);
}

static void		strcpy_next_word(char *dest, char *src, int *index, char c)
{
	int i;

	i = 0;
	while (src[*index] == c)
		++(*index);
	while (src[*index] != c && src[*index] != '\0')
	{
		dest[i] = src[*index];
		++(*index);
		++i;
	}
	dest[i] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	int		n_words;
	char	**arr;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	n_words = count_words((char*)s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (n_words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (i < n_words)
	{
		if (!(arr[i] = (char *)malloc(sizeof(char) *
						(strlen_next_word((char*)s, &j, c) + 1))))
			return (NULL);
		strcpy_next_word(arr[i], (char*)s, &k, c);
		++i;
	}
	arr[i] = 0;
	return (arr);
}
