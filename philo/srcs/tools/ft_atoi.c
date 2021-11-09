/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:38:29 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/09 11:40:35 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	can_atoi(const char *str)
{
	int	i;

	if (!(str[0] == '-' || ft_isdigit(str[0])))
		return (0);
	if (str[0] == '-' && ft_strlen(str) == 1)
		return (0);
	i = 1;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	atoi;

	i = 0;
	if (str[i] == 0)
		return (0);
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	atoi = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi = atoi * 10 + (str[i] - '0');
		i++;
	}
	atoi *= sign;
	printf("test\n");//
	return (atoi);
}
