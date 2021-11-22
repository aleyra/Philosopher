/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:02:20 by lucille           #+#    #+#             */
/*   Updated: 2021/11/22 13:35:38 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_gettime(t_suitcase *sc)
{
	gettimeofday(&sc->tv, NULL);
	return ((sc->tv.tv_sec * 1000) + (sc->tv.tv_usec / 1000));
}
