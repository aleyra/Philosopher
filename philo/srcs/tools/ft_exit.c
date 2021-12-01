/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:07:02 by lucille           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/30 15:45:58 by lburnet          ###   ########lyon.fr   */
=======
/*   Updated: 2021/11/30 20:49:47 by lucille          ###   ########.fr       */
>>>>>>> c7f22addb098499938fd6531071caaeaf67db52f
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_destroy_philos(t_suitcase *sc)
{
	int	i;

	if (sc->philos != NULL)
	{
		i = 0;
		while (i < sc->nb_philo)
		{
			pthread_mutex_destroy(&sc->philos[i].eat);
<<<<<<< HEAD
=======
			// pthread_detach(sc->philos[i].thread_id);
>>>>>>> c7f22addb098499938fd6531071caaeaf67db52f
			i++;
		}
		free (sc->philos);
		sc->philos = NULL;
	}
}

void	free_destroy_all(t_suitcase *sc)
{
	int		i;
	// void	*join;

	// i = 0;
	// while (i < sc->nb_philo)
	// {
	// 	pthread_join(sc->philos[i].thread_id, &join);
	// 	i++;
	// }
	// free(join);
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
	pthread_mutex_destroy(&sc->write);
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
