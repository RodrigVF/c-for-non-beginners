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

int	ft_atoi(char *str);

void	teste(char *rotulo, char *str)
{
	printf("ft_atoi(\"%s\") = %d\n", rotulo, ft_atoi(str));
}

int	main(void)
{
	teste("42", "42");
	teste("   -42", "   -42");
	teste("\\t\\n\\v\\f\\r +17abc", "\t\n\v\f\r +17abc");
	teste("--+-5", "--+-5");
	teste("+-+-12", "+-+-12");
	teste("abc", "abc");
	teste("", "");
	teste("2147483647", "2147483647");
	teste("-2147483648", "-2147483648");
	teste(" 1 2", " 1 2");
	teste("0042", "0042");
	teste("- 3", "- 3");
	return (0);
}
