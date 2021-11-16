/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:51:15 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/16 15:09:58 by lucille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_suitcase0(t_suitcase **sc)
{
	*sc = malloc(sizeof(t_suitcase));
	if (!sc)
		return (ERROR_MALLOC);
	(*sc)->nb_meal = -1;
	(*sc)->nb_philo = -1;
	(*sc)->t_to_die = -1;
	(*sc)->t_to_eat = -1;
	(*sc)->t_to_sleep = -1;
	(*sc)->forks_m = NULL;
	(*sc)->philos = NULL;
	return (NO_ERROR);
}

static int	init_suitcase1(t_suitcase *sc)
{
	int	i;

	sc->forks_m = malloc(sc->nb_philo * sizeof(pthread_mutex_t));
	if (sc->forks_m == NULL)
		return (ERROR_MALLOC);
	i = 0;
	while (i < sc->nb_philo)
	{
		pthread_mutex_init(&sc->forks_m[i], NULL);
		i++;
	}
	pthread_mutex_init(&sc->write_m, NULL);
	pthread_mutex_init(&sc->isdead, NULL);
	pthread_mutex_lock(&sc->isdead);//pourquoi ?
	return (NO_ERROR);
}

static int	init_philos(t_suitcase *sc)
{
	int	i;
	int	err;

	sc->philos = malloc(sc->nb_philo * sizeof(t_philo));
	if (sc->philos == NULL)
		return (ERROR_MALLOC);
	i = 0;
	while (i < sc->nb_philo)
	{
		sc->philos[i].who = i;
		sc->philos[i].iseating = 0;
		sc->philos[i].lfork = i;
		sc->philos[i].rfork = (i + 1) % sc->nb_philo;
		sc->philos[i].meal = 0;
		sc->philos[i].sc = sc;
		pthread_mutex_init(&sc->philos[i].mutex, NULL);
		pthread_mutex_init(&sc->philos[i].eat_m, NULL);
		pthread_mutex_lock(&sc->philos[i].eat_m);//pourquoi ?
		i++;
	}
	err = init_suitcase1(sc);
	if (err != NO_ERROR)
		return (err);
	return (NO_ERROR);
}

int	main(int ac, char *av[])
{
	t_suitcase	*sc;
	int	err;

	sc = NULL;
	err = NO_ERROR;
	if (ac < 5 || ac > 6)
		return (ft_exit(NULL, WRONG_NB_ARG));
	if (init_suitcase0(&sc) == ERROR_MALLOC)
		return (ft_exit(sc, ERROR_MALLOC));
	err = ft_parsing(ac, av, sc);
	if (err != NO_ERROR)
		return (ft_exit(sc, err));
	err = init_philos(sc);
	if (err != NO_ERROR)
		return (ft_exit(sc, err));
	return (ft_exit(sc, NO_ERROR));
}
