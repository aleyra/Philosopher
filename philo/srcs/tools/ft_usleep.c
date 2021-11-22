/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:18:57 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/22 13:34:40 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time, t_suitcase *sc)
{
	long	wait_time;

	wait_time = sc->now + time;
	while (sc->now < wait_time && sc->isdead == 1)
	{
		usleep(200);
	}
}
