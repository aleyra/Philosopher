/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:51:15 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/09 10:45:58 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_exit(t_p *p, int err)
{
	if (err != NO_ERROR)
		error_message(err);
	if (p != NULL)
		free(p);
	return (err);
}

static int	init_philo(t_p *p)
{
	p = malloc(sizeof(t_p));
	if (!p)
		return (ERROR_MALLOC);
	p->nb_meal = -1;
	p->nb_philo = -1;
	p->t_to_die = -1;
	p->t_to_eat = -1;
	p->t_to_sleep = -1;
	return (NO_ERROR);
}

int	main(int ac, char *av[])
{
	t_p	*philos;
	int	err;

	philos = NULL;
	err = NO_ERROR;
	if (ac < 5 || ac > 6)
		return (ft_exit(NULL, WRONG_NB_ARG));
	if (init_philo(philos) == ERROR_MALLOC)
		return (ft_exit(philos, ERROR_MALLOC));
	err = ft_parsing(ac, av, philos);
	if (err != NO_ERROR)
		return (ft_exit(philos, err));
	return (ft_exit(philos, NO_ERROR));
}
