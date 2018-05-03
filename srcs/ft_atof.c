/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:57:43 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/03 15:08:27 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_first_part(char const *str)
{
	double	ret;
	int		i;

	i = 0;
	ret = 0.0;
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10.0 + (str[i++] - '0');
	return (ret);
}

static double	get_last_part(char const *str)
{
	double	ret;
	double	coeff;
	int		i;

	i = 0;
	ret = 0.0;
	coeff = 10.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret += ((double)(str[i++] - '0') / coeff);
		coeff *= 10.0;
	}
	return (ret);
}

double			ft_atof(char const *str)
{
	double	ret;
	int		i;
	int		sign;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		++i;
	sign = (str[i] == '-' ? -1 : 1);
	if (str[i] == '-' || str[i] == '+')
		++i;
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.')
		return (0);
	ret = get_first_part(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	if (str[i] != '.')
		return (ret * (double)sign);
	ret += get_last_part(str + i + 1);
	return (ret * (double)sign);
}
