# Philosophers
Implementation of the Dining Philosopher Problem in C using threads and mutexes (/philo) and v (/philo_bonus)

### Build
- Version based on threads and mutexes:
cd philo && make

- Version based processes and semaphore:
cd philo_bonus && make

### Run
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
