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

int	ft_str_is_alpha(char *str);

void	teste(char *str)
{
	printf("\"%s\" -> %d\n", str, ft_str_is_alpha(str));
}

int	main(void)
{
	teste("abc");
	teste("ABCdef");
	teste("");
	teste("abc1");
	teste("a b");
	teste("Ola!");
	teste("@[`{");
	return (0);
}
