/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:43:11 by msloot            #+#    #+#             */
/*   Updated: 2023/11/10 22:22:15 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *, ...);

int	main(void)
{
	ft_printf("hello %d school I am %s\n", 42, "msloot");
	return (0);
}
