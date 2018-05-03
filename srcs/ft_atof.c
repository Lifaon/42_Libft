/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:57:43 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/03 15:40:13 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char const *str)
{
	double	ret;
	double	coeff;
	int		i;
	int		sign;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		++i;
	sign = (str[i] == '-' ? -1 : 1);
	if (str[i] == '-' || str[i] == '+')
		++i;
	if (!(str[i] >= '0' && str[i] <= '9') && \
		(str[i] != '.' || !(str[i + 1] >= '0' && str[i + 1] <= '9')))
		return (0);
	ret = 0.0;
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10.0 + (str[i++] - '0');
	if (str[i++] != '.')
		return (ret * (double)sign);
	coeff = 1.0;
	while (str[i] >= '0' && str[i] <= '9' && (coeff *= 10.0))
		ret += ((double)(str[i++] - '0') / coeff);
	return (ret * (double)sign);
}
