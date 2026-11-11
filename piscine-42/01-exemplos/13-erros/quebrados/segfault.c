/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segfault.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	char	*str;

	str = "imutavel";
	write(1, "vou tentar mudar um literal...\n", 31);
	str[0] = 'I';
	write(1, "nunca chego aqui\n", 17);
	return (0);
}
