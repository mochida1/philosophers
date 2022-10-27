#!/bin/bash
#printf "\e[93m \e[0m\n"
#TESTS FOR ARGUMENTS
make
printf "\n\e[94m**********************************************************************\n"
printf "STARTING TESTS!\n"
printf "**********************************************************************\e[0m\n"
printf "\n\e[91m***********************************\n"
printf "TESTING ARGUMENTS\nThese should break\n"
printf "***********************************\e[0m\n"
printf "\e[93m./philo\e[0m\n"
./philo	
#if you dont use help, remove till next comment
printf "\e[93m./philo -h\e[0m\n"
./philo -h
printf "\e[93m./philo --help\e[0m\n"
./philo --help
printf "\e[93m./philo --h\e[0m\n"
./philo --h
printf "\e[93m./philo -help\e[0m\n"
./philo -help
printf "\e[93m./philo -argument\e[0m\n"
./philo -argument
printf "./philo --argument\e[0m\n"
./philo --argument
printf "\e[93m./philo -a number_of_philosophers\e[0m\n"
./philo -a number_of_philosophers
#those should fail
printf "\e[93m./philo 1\e[0m\n"
./philo 1
printf "\e[93m./philo 1 2\e[0m\n"
./philo 1 2
printf "\e[93m./philo 1 2 3\e[0m\n"
./philo 1 2 3
printf "\e[93m./philo 1 2 3 4 5 654321\e[0m\n"
./philo 1 2 3 4 5 654321 
printf "\e[93m./philo 1 2 3 4 c \e[0m\n"
./philo 1 2 3 4 c
printf "\e[93m./philo 1 2 3 4 4294967296 \e[0m\n"
./philo 1 2 3 4 4294967296


#remove till next argument if you're a bad person
printf "\n\e[92m***********************************\n"
printf "Now starting working helps\n"
printf "***********************************\e[0m\n"
printf "\e[93m./philo -h number_of_philosophers\e[0m\n"
./philo -h number_of_philosophers
printf "\e[93m./philo -h [number_of_philosophers]\e[0m\n"
./philo -h [number_of_philosophers]
printf "\e[93m./philo --help number_of_philosophers\e[0m\n"
./philo --help number_of_philosophers
printf "\e[93m./philo --help [number_of_philosophers]\e[0m\n"
./philo --help [number_of_philosophers]

printf "\e[93m./philo -h time_to_die\e[0m\n"
./philo -h time_to_die
printf "\e[93m./philo -h [time_to_die]\e[0m\n"
./philo -h [time_to_die]
printf "\e[93m./philo --help time_to_die\e[0m\n"
./philo --help time_to_die
printf "\e[93m./philo --help [time_to_die]\e[0m\n"
./philo --help [time_to_die]

printf "\e[93m./philo -h time_to_eat\e[0m\n"
./philo -h time_to_eat
printf "\e[93m./philo -h [time_to_eat]\e[0m\n"
./philo -h [time_to_eat]
printf "\e[93m./philo --help time_to_eat\e[0m\n"
./philo --help time_to_eat
printf "\e[93m./philo --help [time_to_eat]\e[0m\n"
./philo --help [time_to_eat]

printf "\e[93m./philo -h time_to_sleep\e[0m\n"
./philo -h time_to_sleep
printf "\e[93m./philo -h [time_to_sleep]\e[0m\n"
./philo -h [time_to_sleep]
printf "\e[93m./philo --help time_to_sleep\e[0m\n"
./philo --help time_to_sleep
printf "\e[93m./philo --help [time_to_sleep]\e[0m\n"
./philo --help [time_to_sleep]

printf "\e[93m./philo -h number_of_times_each_philosopher_must_eat\e[0m\n"
./philo -h number_of_times_each_philosopher_must_eat
printf "\e[93m./philo -h [number_of_times_each_philosopher_must_eat]\e[0m\n"
./philo -h [number_of_times_each_philosopher_must_eat]
printf "\e[93m./philo --help number_of_times_each_philosopher_must_eat\e[0m\n"
./philo --help number_of_times_each_philosopher_must_eat
printf "\e[93m./philo --help [number_of_times_each_philosopher_must_eat]\e[0m\n"
./philo --help [number_of_times_each_philosopher_must_eat]

printf "\n\e[91m***********************************\n"
printf "these should break\n"
printf "***********************************\e[0m\n"

printf "\e[93m./philo -h number_of_philosophers time_to_break\e[0m\n"
./philo -h number_of_philosophers time_to_break
printf "\e[93m./philo -h [number_of_philosophers] time_to_break\e[0m\n"
./philo -h [number_of_philosophers] time_to_break
printf "\e[93m./philo --help number_of_philosophers time_to_break\e[0m\n"
./philo --help number_of_philosophers time_to_break
printf "\e[93m./philo --help [number_of_philosophers] time_to_break\e[0m\n"
./philo --help [number_of_philosophers] time_to_break

printf "\e[93m./philo -h time_to_die time_to_break\e[0m\n"
./philo -h time_to_die time_to_break
printf "\e[93m./philo -h [time_to_die] time_to_break\e[0m\n"
./philo -h [time_to_die] time_to_break
printf "\e[93m./philo --help time_to_die time_to_break\e[0m\n"
./philo --help time_to_die time_to_break
printf "\e[93m./philo --help [time_to_die] time_to_break\e[0m\n"
./philo --help [time_to_die] time_to_break

printf "\e[93m./philo -h time_to_eat time_to_break\e[0m\n"
./philo -h time_to_eat time_to_break
printf "\e[93m./philo -h [time_to_eat] time_to_break\e[0m\n"
./philo -h [time_to_eat] time_to_break
printf "\e[93m./philo --help time_to_eat time_to_break\e[0m\n"
./philo --help time_to_eat time_to_break
printf "\e[93m./philo --help [time_to_eat] time_to_break\e[0m\n"
./philo --help [time_to_eat] time_to_break

printf "\e[93m./philo -h time_to_sleep time_to_break\e[0m\n"
./philo -h time_to_sleep time_to_break
printf "\e[93m./philo -h [time_to_sleep] time_to_break\e[0m\n"
./philo -h [time_to_sleep] time_to_break
printf "\e[93m./philo --help time_to_sleep time_to_break\e[0m\n"
./philo --help time_to_sleep time_to_break
printf "\e[93m./philo --help [time_to_sleep] time_to_break\e[0m\n"
./philo --help [time_to_sleep] time_to_break

printf "\e[93m./philo -h number_of_times_each_philosopher_must_eat time_to_break\e[0m\n"
./philo -h number_of_times_each_philosopher_must_eat time_to_break
printf "\e[93m./philo -h [number_of_times_each_philosopher_must_eat] time_to_break\e[0m\n"
./philo -h [number_of_times_each_philosopher_must_eat] time_to_break
printf "\e[93m./philo --help number_of_times_each_philosopher_must_eat time_to_break\e[0m\n"
./philo --help number_of_times_each_philosopher_must_eat time_to_break
printf "\e[93m./philo --help [number_of_times_each_philosopher_must_eat] time_to_break\e[0m\n"
./philo --help [number_of_times_each_philosopher_must_eat] time_to_break

printf "\n\e[91m***********************************\n"
printf "these should be considered errors\n"
printf "***********************************\e[0m\n"
printf "\e[93m./philo 0 0 0 0 \e[0m\n"
./philo 0 0 0 0
printf "\e[93m./philo 0 0 0 0 0 \e[0m\n"
./philo 0 0 0 0 0
printf "\e[93m../philo 0 1 2 3 \e[0m\n"
./philo 0 1 2 3
printf "\e[93m./philo 0 1 2 3 4\e[0m\n"
./philo 0 1 2 3 4
printf "\e[93m../philo 9 0 2 3 \e[0m\n"
./philo 9 0 2 3
printf "\e[93m./philo 9 200 200 200 0 \e[0m\n"
./philo 9 200 200 200 0

printf "\n\e[33m***********************************\n"
printf "these should work and kill philos\n"
printf "***********************************\e[0m\n"
printf "\e[93m./philo 1\e[0m\n"
./philo 1 2 3 4
printf "\e[93m./philo 1\e[0m\n"
./philo 1 2 3 4 5

printf "\n\e[92m***********************************\n"
printf "these should run till numbers eaten\n"
printf "***********************************\e[0m\n"

printf "\n\e[32m***********************************\n"
printf "these should run FOREVA!\n"
printf "***********************************\e[0m\n"