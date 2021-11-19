/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:07:02 by lucille           #+#    #+#             */
/*   Updated: 2021/11/19 15:30:49 by lucille          ###   ########.fr       */
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
			pthread_mutex_destroy(&sc->philos[i].a_table);
			i++;
		}
		free (sc->philos);
	}
}

int	ft_exit(t_suitcase *sc, int err)
{
	int	i;

	if (err != NO_ERROR)
		error_message(err);
	free_destroy_philos(sc);
	if (sc->forks != NULL)
	{
		i = 0;
		while (i < sc->nb_philo)
			pthread_mutex_destroy(&sc->forks[i++]);
		free (sc->forks);
	}
	pthread_mutex_destroy(&sc->game_paused);
	pthread_mutex_destroy(&sc->isdead);
	if (sc != NULL)
		free(sc);
	return (err);
}
