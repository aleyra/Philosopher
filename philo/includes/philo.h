/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:51:25 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/16 16:47:38 by lucille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "pthread.h"
# include "string.h"
# include "unistd.h"
# include "stdlib.h"
# include "sys/time.h"

typedef struct s_suitcase	t_suitcase;
typedef struct s_philo		t_philo;
typedef enum e_error		t_error;
typedef enum e_what			t_what;

struct s_philo
{
	int					who;
	int					iseating;
	unsigned long long	limit;//?
	unsigned long long	last_eat;
	int					lfork;
	int					rfork;
	int					meal;
	t_suitcase			*sc;//pour pouvoir revenir en arrière ?
	pthread_mutex_t		mutex;
	pthread_mutex_t		eat_m;
};

struct s_suitcase
{
	int					nb_philo;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					nb_meal;
	unsigned long long	start;
	struct timeval		tv;
	t_philo				*philos;
	pthread_mutex_t		*forks_m;
	pthread_mutex_t		game_paused;
	pthread_mutex_t		isdead;
	int					gameover;
};

enum e_error
{
	NO_ERROR,
	WRONG_NB_ARG,
	ERROR_MALLOC,
	NOT_AN_INT,
	NOT_POS,
};

enum e_what
{
	FORK_TAKEN,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	IS_DIED,
	FINISHED_SUCCESS
};

//fct in display
void				error_message(int err);
void				print_philos(t_suitcase *p);
void				screen_message(t_philo *philo, int what);

//fct in parsing
int					ft_parsing(int ac, char *av[], t_suitcase *p);

//fct in tools
int					can_atoi(const char *str);
int					ft_atoi(const char *str);
int					ft_exit(t_suitcase *sc, int err);
unsigned long long	ft_gettime(t_suitcase *sc);
int					ft_isdigit(int c);
int					ft_strlen(const char *str);
#endif
