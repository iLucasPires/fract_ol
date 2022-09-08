/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 05:23:25 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/08 05:25:00 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	raw_atof(const char *str, double acc)
{
	double	scale;

	scale = 10;
	acc = acc * 10.0 + (*str - '0');
	while (*(++str))
	{
		if (scale < 10)
		{
			scale /= 10;
			acc += (*str - '0') * scale;
		}
		else if (*str == '.')
			scale /= 10;
		acc = acc * 10.0 + (*str - '0');
	}
	return (acc);
}

double	ft_atof(const char *str)
{
	double	final;
	int		neg;

	neg = 1;
	if (*str == '-')
	{
		str++;
		neg = -1;
	}
	final = raw_atof(str, 0);
	return (final * neg);
}