/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	sinal(int n)
{
	if (n < 0)
		return (-1);
	if (n > 0)
		return (1);
	return (0);
}

void	teste(int caso, char *s1, char *s2)
{
	printf("caso %d: esperado %d, obtido %d\n",
		caso, sinal(strcmp(s1, s2)), sinal(ft_strcmp(s1, s2)));
}

int	main(void)
{
	teste(1, "abc", "abc");
	teste(2, "abc", "abd");
	teste(3, "abd", "abc");
	teste(4, "", "a");
	teste(5, "a", "");
	teste(6, "", "");
	teste(7, "abc", "ab");
	teste(8, "ab", "abc");
	teste(9, "\200", "a");
	return (0);
}
