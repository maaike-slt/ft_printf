/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:06:28 by msloot            #+#    #+#             */
/*   Updated: 2023/11/12 17:55:33 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(const char *input, size_t i, va_list args)
{
	if (input[i + 1] == 's')
		ft_putstr(va_arg(args, char *));
	else if (input[i + 1] == 'i' || input[i + 1] == 'd')
		ft_putnbr(va_arg(args, int));
	else if (input[i + 1] == 'u')
		ft_putnbr(va_arg(args, unsigned int));
	else if (input[i + 1] == 'c')
		ft_putchar(va_arg(args, int));
	else if (input[i + 1] == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (input[i + 1] == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else
		write(1, "%", 1);
	return (0);
}

static int	ft_input_iter(const char *input, va_list args)
{
	size_t	i;

	(void)args;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
			ft_convert(input, i, args);
		else
			write(1, &input[i], 1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		ret;

	va_start(args, input);
	ret = ft_input_iter(input, args);
	va_end(args);
	return (ret);
}
