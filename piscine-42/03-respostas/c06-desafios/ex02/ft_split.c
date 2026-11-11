/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:34:48 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/11 12:34:48 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_eh_sep(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_conta_palavras(char *str, char *charset)
{
	int	total;

	total = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && ft_eh_sep(*str, charset))
			str++;
		if (*str != '\0')
			total++;
		while (*str != '\0' && !ft_eh_sep(*str, charset))
			str++;
	}
	return (total);
}

char	*ft_copia_palavra(char *str, char *charset)
{
	char	*palavra;
	int		len;
	int		i;

	len = 0;
	while (str[len] != '\0' && !ft_eh_sep(str[len], charset))
		len++;
	palavra = malloc(sizeof(char) * (len + 1));
	if (palavra == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		palavra[i] = str[i];
		i++;
	}
	palavra[i] = '\0';
	return (palavra);
}

char	**ft_libera(char **tab, int ate)
{
	while (ate > 0)
	{
		ate--;
		free(tab[ate]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * (ft_conta_palavras(str, charset) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		if (!ft_eh_sep(*str, charset))
		{
			tab[i] = ft_copia_palavra(str, charset);
			if (tab[i] == NULL)
				return (ft_libera(tab, i));
			i++;
			while (*str != '\0' && !ft_eh_sep(*str, charset))
				str++;
		}
		else
			str++;
	}
	tab[i] = NULL;
	return (tab);
}
