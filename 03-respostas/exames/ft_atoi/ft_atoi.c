/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seu_login <seu_login@student.42sp.org.br>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:00:00 by seu_login         #+#    #+#             */
/*   Updated: 2026/11/10 10:00:00 by seu_login        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		i;
	int		sinal;
	long	resultado;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sinal = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sinal = -sinal;
		i++;
	}
	resultado = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultado = resultado * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(resultado * sinal));
}
