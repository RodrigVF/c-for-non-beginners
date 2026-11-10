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

int	ft_strlen(char *str);

void	teste(char *str)
{
	printf("ft_strlen(\"%s\") = %d\n", str, ft_strlen(str));
}

int	main(void)
{
	teste("");
	teste("a");
	teste("42");
	teste("Ola, Piscine!");
	teste("tem\0coisa escondida");
	return (0);
}
