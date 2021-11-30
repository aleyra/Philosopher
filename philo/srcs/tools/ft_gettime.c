/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:02:20 by lucille           #+#    #+#             */
/*   Updated: 2021/11/30 14:37:59 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_gettime(t_suitcase *sc)
{
	gettimeofday(&sc->tv, NULL);
	return ((sc->tv.tv_sec * 1000) + (sc->tv.tv_usec / 1000));
}
