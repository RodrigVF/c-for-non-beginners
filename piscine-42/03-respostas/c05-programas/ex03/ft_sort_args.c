/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:03:22 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/11 12:03:22 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_sort(char **tab, int size)
{
	int		i;
	int		trocou;
	char	*tmp;

	trocou = 1;
	while (trocou)
	{
		trocou = 0;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				trocou = 1;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	ft_sort(argv + 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		i++;
	}
	return (0);
}
