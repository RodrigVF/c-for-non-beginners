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
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

void	teste(int size, char **strs, char *sep)
{
	char	*res;

	res = ft_strjoin(size, strs, sep);
	if (res == NULL)
	{
		printf("retornou NULL\n");
		return ;
	}
	printf("size=%d sep=\"%s\" -> \"%s\"\n", size, sep, res);
	free(res);
}

int	main(void)
{
	char	*strs[4];

	strs[0] = "Ola";
	strs[1] = "Piscine";
	strs[2] = "";
	strs[3] = "42";
	teste(4, strs, ", ");
	teste(2, strs, "");
	teste(1, strs, " -- ");
	teste(0, strs, ", ");
	teste(3, strs, "+");
	return (0);
}
