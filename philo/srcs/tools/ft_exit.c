/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:07:02 by lucille           #+#    #+#             */
/*   Updated: 2021/11/22 12:10:52 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_destroy_philos(t_suitcase *sc)
{
	int	i;

	if (sc->philos != NULL)
	{
		i = 0;
		while (i > sc->nb_philo)
		{
			pthread_mutex_destroy(&sc->philos[i].mutex);
			i++;
		}
		free (sc->philos);
		sc->philos = NULL;
	}
}

void	free_destroy_all(t_suitcase *sc)
{
	int	i;

	free_destroy_philos(sc);
	if (sc->forks != NULL)
	{
		i = 0;
		while (i < sc->nb_philo)
			pthread_mutex_destroy(&sc->forks[i++]);
		free (sc->forks);
		sc->forks = NULL;
	}
	pthread_mutex_destroy(&sc->game_paused);
}

int	ft_exit(t_suitcase *sc, int err)
{
	if (err != NO_ERROR)
		error_message(err);
	free_destroy_all(sc);
	if (sc != NULL)
		free(sc);
	return (err);
}
