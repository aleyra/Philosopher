/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:00:35 by lucille           #+#    #+#             */
/*   Updated: 2021/12/01 13:00:23 by lburnet          ###   ########lyon.fr   */
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
	sc->endgame = 1;
	return (1);
}

static int	check_is_dead(t_suitcase *sc)
{
	int		i;
	t_philo	*philo;

	i = 0;
	sc->now = ft_gettime(sc);
	while (i < sc->nb_philo)
	{
		philo = &sc->philos[i];
		if (sc->now > philo->times_up)
		{
			print_message(philo, "died\n");
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

	while (sc->isdead == 0 && sc->endgame == 0)
	{
		sc->now = ft_gettime(sc);
		i = 0;
		while (i < sc->nb_philo)
		{
			pthread_mutex_lock(&sc->game_paused);
			check_is_dead(sc);
			if (sc->nb_meal > 0)
				are_full(sc);
			pthread_mutex_unlock(&sc->game_paused);
			i++;
		}
	}
}

void	*routine(void *void_philo)
{
	t_philo		*philo;

	philo = (t_philo *)void_philo;
	while (philo->sc->ready != 1)
	{
		usleep(100);
	}
	philo->times_up = philo->sc->now + philo->sc->t_to_die;
	if (philo->who % 2 == 0)
		usleep(philo->sc->t_to_eat + 10);
	while (philo->sc->isdead == 0
		&& (philo->sc->nb_meal == -1 || philo->meal < philo->sc->nb_meal))
	{
		take_forks(philo);
		if (philo->sc->nb_philo == 1)
			ft_usleep(philo->sc->t_to_die + 10, philo->sc);
		eat(philo);
		give_forks(philo);
		sleep_then_think(philo);
	}
	return (NULL);
}
