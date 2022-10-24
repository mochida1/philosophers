#!/bin/bash
#printf "\e[93m \e[0m\n"
#TESTS FOR ARGUMENTS
make
printf "\n\e[92m***********************************\n"
printf "TESTING ARGUMENTS\n"
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