/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:02:20 by lucille           #+#    #+#             */
/*   Updated: 2021/11/16 16:26:13 by lucille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	ft_gettime(t_suitcase *sc)
{
	gettimeofday(&sc->tv, NULL);
	return ((sc->tv.tv_sec * 1000) + (sc->tv.tv_usec / 1000));
}
