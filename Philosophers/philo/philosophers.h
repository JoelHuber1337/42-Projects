/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:48:00 by johuber           #+#    #+#             */
/*   Updated: 2025/07/28 18:07:30 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	int					id;
	int					amount;
	int					meals;
	long				death;
	long				food;
	long				sleep;
	long				m_time;
	pthread_mutex_t		*right;
	pthread_mutex_t		m_meals;
	pthread_mutex_t		*left;
	struct s_data		*data;
	struct s_philo		*next;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t		fork;
	pthread_mutex_t		**forks;
	pthread_t			*threads;
	pthread_mutex_t		m_mortis;
	pthread_mutex_t		p_start;
	pthread_mutex_t		print;
	int					mortis;
	int					amount;
	long				death;
	long				food;
	long				sleep;
	long				hunger;
	t_philo				*philo;
}	t_data;

int						main(int arc, char **arv);

//PARSER
int						wrong_parsing(t_data *data, int arc, char **arv);
int						check_int(t_data *data, int arc, char **arv);
int						make_data(t_data *data);
int						assign_input(t_data *data, long tmp, int x);
int						assign_philo(t_data *data, t_philo *philo, int x);
pthread_mutex_t			**init_forks(long amount);
void					assign_forks(t_data *data, pthread_mutex_t **forks);

//Execution
int						run_philosophers(t_data *data);
void					*monitoring(void *input);
int						solo_leveling(t_data *data);
void					kill_all(t_philo *philo);

//Monitoring
long					get_time(void);
void					*master_key(t_data *data);
void					un_lock_start(t_philo *philo, int key);
void					limit_reached(t_data *data);
void					kill_all(t_philo *philo);
void					end_simulation(t_data *data, int error, long time);

//Philosophers
void					*philosophers(void *input);
int						taking_second_fork(t_data *data, \
						t_philo *philo, long start);
void					sleep_alarm(t_data *data, long sleep);
int						check_time(t_data *data, long time);
void					wait_till_start(t_data *data);
void					jobless_philosophers(t_data *data, \
						t_philo *philo, long start);

//ERROR HANDLING
int						error_msg(char *str);

//UTILS
int						ft_strlen(char *str);
long					ft_atol(char *str);
int						check_char(char *str);
t_philo					*get_last_node(t_philo *philo);

//FREE FUNCTIONS
int						destroy_data_mutex(t_data *data);
int						free_philo(t_philo *philo);
int						ft_free_forks(pthread_mutex_t **forks, long size);
void					ft_free_all(t_data *data);
int						ft_free_parsing(t_data *data, pthread_mutex_t **forks);

#endif