/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:51:15 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/30 20:18:24 by lucille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	in_while(t_suitcase *sc, int i)
{
	int			thread_created;

	sc->philos[i].who = i + 1;
	sc->philos[i].lfork = i;
	sc->philos[i].rfork = (i + 1) % sc->nb_philo;
	sc->philos[i].meal = 0;
	sc->philos[i].sc = sc;
	sc->philos[i].times_up = MY_LONG_MAX;
	pthread_mutex_init(&sc->philos[i].eat, NULL);
	pthread_mutex_init(&sc->forks[i], NULL);
	thread_created = pthread_create(
			&sc->philos[i].thread_id, NULL, &routine, (void *)&sc->philos[i]);
	pthread_detach(sc->philos[i].thread_id);
	return (thread_created);
}

static int	init_philos(t_suitcase *sc)
{
	int			i;

	sc->philos = malloc(sc->nb_philo * sizeof(t_philo));
	sc->forks = malloc(sc->nb_philo * sizeof(pthread_mutex_t));
	if (sc->philos == NULL || sc->forks == NULL)
		return (ERROR_MALLOC);
	i = 0;
	while (i < sc->nb_philo)
	{
		if (in_while(sc, i) != 0)
			return (ERROR_PTHREAD_C);
		i++;
	}
	pthread_mutex_init(&sc->game_paused, NULL);
	pthread_mutex_init(&sc->write, NULL);
	sc->isdead = 0;
	sc->start = ft_gettime(sc);
	sc->now = ft_gettime(sc);
	sc->ready = 1;
	return (NO_ERROR);
}

static int	initialize(t_suitcase **sc, int ac, char *av[])
{
	int	err;

	*sc = malloc(sizeof(t_suitcase));
	if (!sc)
		return (ERROR_MALLOC);
	(*sc)->nb_meal = -1;
	(*sc)->nb_philo = -1;
	(*sc)->t_to_die = -1;
	(*sc)->t_to_eat = -1;
	(*sc)->t_to_sleep = -1;
	(*sc)->forks = NULL;
	(*sc)->philos = NULL;
	(*sc)->endgame = 0;
	(*sc)->now = 0;
	(*sc)->ready = 0;
	err = ft_parsing(ac, av, *sc);
	if (err != NO_ERROR)
		return (err);
	err = init_philos(*sc);
	if (err != NO_ERROR)
		return (err);
	return (NO_ERROR);
}

int	main_loop(t_suitcase *sc)
{
	check_finished(sc);
	return (NO_ERROR);
}

int	main(int ac, char *av[])
{
	t_suitcase	*sc;
	int			err;

	sc = NULL;
	err = NO_ERROR;
	if (ac < 5 || ac > 6)
		return (ft_exit(NULL, WRONG_NB_ARG));
	err = initialize(&sc, ac, av);
	if (err != NO_ERROR)
		return (ft_exit(sc, err));
	main_loop(sc);
	return (ft_exit(sc, NO_ERROR));
}
