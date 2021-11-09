/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:25:03 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/09 11:40:45 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	assign_int(int *to_be_assign, char *str)
// {
// 	*to_be_assign = ft_atoi(str);
// 	if (*to_be_assign <= 0)
// 		return (NOT_POS);
// 	return (NO_ERROR);
// }

static int	in_while1(int i, char *av[], t_p *p)
{
	if (i == 0)
	{
		p->nb_philo = ft_atoi(av[i]);
	printf("test ici \n");//
		if (p->nb_philo <= 0)
			return (NOT_POS);
	}
	else if (i == 1)
	{
		p->t_to_die = ft_atoi(av[i]);
		if (p->t_to_die <= 0)
			return (NOT_POS);
	}
	else if (i == 2)
	{
		p->t_to_eat = ft_atoi(av[i]);
		if (p->t_to_eat <= 0)
			return (NOT_POS);
	}
	return (NO_ERROR);
}

static int	in_while2(int i, char *av[], t_p *p)
{
	if (i == 3)
	{
		p->t_to_sleep = ft_atoi(av[i]);
		if (p->t_to_sleep <= 0)
			return (NOT_POS);
	}
	else if (i == 4)
	{
		p->nb_meal = ft_atoi(av[i]);
		if (p->nb_meal <= 0)
			return (NOT_POS);
	}
	return (NO_ERROR);
}

int	ft_parsing(int ac, char *av[], t_p *p)
{
	int	i;
	int	err;

	i = 0;
	while (i < ac)
	{
		printf("i = %d\n", i);//
		if (can_atoi(av[i]) == 0)
			return (NOT_AN_INT);
		printf("can atoi\n");//
		// if (i == 0 && assign_int(&p->nb_philo, av[i]) != NO_ERROR)
		// 	return (NOT_POS);
		// if (i == 1 && assign_int(&p->t_to_die, av[i]) != NO_ERROR)
		// 	return (NOT_POS);
		// else if (i == 2 && assign_int(&p->t_to_eat, av[i]) != NO_ERROR)
		// 	return (NOT_POS);
		// else if (i == 3 && assign_int(&p->t_to_sleep, av[i]) != NO_ERROR)
		// 	return (NOT_POS);
		// else if (i == 4 && assign_int(&p->nb_meal, av[i]) != NO_ERROR)
		// 	return (NOT_POS);
		err = in_while1(i, av, p);
		if (err != NO_ERROR)
			return (err);
		err = in_while2(i, av, p);
		if (err != NO_ERROR)
			return (err);
		i++;
	}
	print_philos(p);//
	return (NO_ERROR);
}
