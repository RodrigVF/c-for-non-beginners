/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:35:13 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/11 12:35:13 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

void	teste(char *str, char *charset)
{
	char	**tab;
	int		i;

	tab = ft_split(str, charset);
	printf("ft_split(\"%s\", \"%s\") =", str, charset);
	if (tab == NULL)
	{
		printf(" NULL\n");
		return ;
	}
	i = 0;
	while (tab[i] != NULL)
	{
		printf(" [%s]", tab[i]);
		free(tab[i]);
		i++;
	}
	printf(" (%d palavra(s))\n", i);
	free(tab);
}

int	main(void)
{
	teste("  Ola  Piscine 42 ", " ");
	teste("a,b;;c", ",;");
	teste("", " ");
	teste("    ", " ");
	teste("semseparador", "");
	teste("abcabc", "abc");
	teste(",x,", ",");
	teste("linha1|linha2|", "|");
	return (0);
}
