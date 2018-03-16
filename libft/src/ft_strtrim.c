/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:37:59 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:15 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*cp;

	j = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
		i--;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j <= i)
		j++;
	if (!(cp = (char*)malloc(sizeof(char) * (i - j + 2))))
		return (NULL);
	while (j <= i)
	{
		cp[k] = (char)s[j];
		k++;
		j++;
	}
	cp[k] = '\0';
	return (cp);
}
