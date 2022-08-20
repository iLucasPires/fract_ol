/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:37:10 by coder             #+#    #+#             */
/*   Updated: 2022/08/20 14:37:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double ft_pow(double number)
{
	return (number * number);
} 
 
double find_c(float min, float max, float axle , int size)
{
	return (min + axle * (max - min) / size);
}  