/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototipo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_diz_oi(void);

int	main(void)
{
	ft_diz_oi();
	return (0);
}

void	ft_diz_oi(void)
{
	write(1, "oi! eu fui definida DEPOIS da main\n", 35);
}
