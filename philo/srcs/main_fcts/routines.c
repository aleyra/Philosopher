/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:00:35 by lucille           #+#    #+#             */
/*   Updated: 2021/11/22 13:45:35 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	are_full(t_suitcase *sc)
{
	int		is_full;
	int		i;
	t_philo	*philo;

	i = 0;
	is_full = 0;
	while (i < sc->nb_philo)
	{
		philo = &sc->philos[i];
		if (philo->meal == sc->nb_meal)
			is_full++;
		i++;
	}
	if (is_full != sc->nb_philo)
		return (0);
	printf("All philosophers ate at least %d meal(s)\n",
		philo->sc->nb_meal);
	return (1);
}

static int	check_is_dead(t_suitcase *sc)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i > sc->nb_philo)
	{
		philo = &sc->philos[i];
		if (philo->iseating == 0 && sc->now > philo->times_up)
		{
			print(philo, "died\n");
			sc->isdead = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_finished(t_suitcase *sc)
{
	int	i;

	while (1)
	{
		sc->now = ft_gettime(sc);
		i = 0;
		while (i < sc->nb_philo)
		{
			pthread_mutex_lock(&sc->game_paused);
			if (check_is_dead(sc) == 1
				|| (sc->nb_meal > 0 && are_full(sc) == 1))
			{
				free_destroy_all(sc);
				return ;
			}
			pthread_mutex_unlock(&sc->game_paused);
			i++;
		}
		usleep (1000);
	}
}

static void	*routine(void *void_philo)
{
	t_philo		*philo;

	philo = (t_philo *)void_philo;
	philo->last_meal = philo->sc->now;
	philo->times_up = philo->last_meal + philo->sc->t_to_die;
	while (1)
	{
		take_forks(philo);
		eat(philo);
		give_forks(philo);
		sleep_then_think(philo);
	}
	return (NULL);
}

int	start_meeting(t_suitcase *sc)
{
	int			thread_created;
	pthread_t	new;
	int			i;

	sc->start = ft_gettime(sc);
	i = 0;
	while (i < sc->nb_philo)
	{
		thread_created = pthread_create(
				&new, NULL, &routine, (void *)&sc->philos[i]);
		if (thread_created != 0)
			return (ERROR_PTHREAD_C);
		usleep(100);
		i++;
	}
	return (NO_ERROR);
}
