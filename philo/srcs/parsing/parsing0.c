/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:25:03 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/22 10:41:22 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	assign_int(int *to_be_assign, char *str)
{
	*to_be_assign = ft_atoi(str);
	if (*to_be_assign <= 0)
		return (NOT_POS);
	return (NO_ERROR);
}

int	ft_parsing(int ac, char *av[], t_suitcase *sc)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (can_atoi(av[i]) == 1)
			return (NOT_AN_INT);
		if (i == 1 && assign_int(&sc->nb_philo, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 2 && assign_int(&sc->t_to_die, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 3 && assign_int(&sc->t_to_eat, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 4 && assign_int(&sc->t_to_sleep, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 5 && assign_int(&sc->nb_meal, av[i]) != NO_ERROR)
			return (NOT_POS);
		i++;
	}
	if (sc->nb_philo > 200 || sc->t_to_die < 60 || sc->t_to_eat < 60
		|| sc->t_to_sleep < 60)
		return (FORBIDDEN);
	return (NO_ERROR);
}
