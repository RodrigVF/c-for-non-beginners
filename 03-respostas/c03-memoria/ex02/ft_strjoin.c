/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	if (size <= 0)
		return (0);
	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	total += ft_strlen(sep) * (size - 1);
	return (total);
}

char	*ft_append(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*fim;
	int		i;

	res = malloc(sizeof(char) * (ft_total_len(size, strs, sep) + 1));
	if (res == NULL)
		return (NULL);
	fim = res;
	i = 0;
	while (i < size)
	{
		fim = ft_append(fim, strs[i]);
		if (i < size - 1)
			fim = ft_append(fim, sep);
		i++;
	}
	*fim = '\0';
	return (res);
}
