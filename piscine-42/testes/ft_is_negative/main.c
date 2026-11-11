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
#include <limits.h>

void	ft_is_negative(int n);

void	teste(int n)
{
	printf("ft_is_negative(%d) = ", n);
	ft_is_negative(n);
	printf("\n");
}

int	main(void)
{
	setbuf(stdout, NULL);
	teste(-1);
	teste(0);
	teste(1);
	teste(-42);
	teste(INT_MAX);
	teste(INT_MIN);
	return (0);
}
