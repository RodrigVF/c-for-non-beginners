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

int	ft_str_is_numeric(char *str);

void	teste(char *str)
{
	printf("\"%s\" -> %d\n", str, ft_str_is_numeric(str));
}

int	main(void)
{
	teste("123");
	teste("0");
	teste("");
	teste("12a");
	teste("a12");
	teste(" 1");
	teste("-1");
	teste("/:");
	return (0);
}
