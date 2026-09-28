*This project has been created as part of the 42 curriculum by dluis-ma*

# Philosophers


## Description

**Philosophers** is a concurrency project based on the classic "Dining Philosophers" problem, developed as part of the 42 curriculum.
The goal of this project is to simulate a group of philosophers who alternate between **thinking**, **eating** and **sleeping**, while safely sharing **forks** (resources) without causing **deadlocks** or **data races**.

The project emphasizes synchronization concepts, including:
- Thread management using **POSIX threads (pthreads)**
- Mutual exclusion with **mutexes**
- Timing and monitoring with `gettimeofday`
- Deadlock and data races avoidance strategies
- Concurrency logic and resource sharing


---


## Instructions

### Compilation


To compile the project, run:
```bash
 make
```
This will generate the executable:
```bash
./philo
```


---


### Execution

Launch philosophers by running:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

number_of_philosophers – total philosophers at the table

time_to_die – maximum time (ms) a philosopher can go without eating before dying

time_to_eat – time (ms) a philosopher spends eating

time_to_sleep – time (ms) a philosopher spends sleeping

number_of_times_each_philosopher_must_eat (optional) – simulation stops after each philosopher eats this many times


---


### Usage Examples

```bash
./philo 5 800 200 200
# Starts a simulation with 5 philosophers

./philo 5 800 200 200 7
# Stops after each philosopher has eaten 7 times
```


---


## Resources
### Documentation & References

Process vs Thread: https://medium.com/@utkarshshukla.author/process-vs-thread-understanding-the-differences-and-when-to-use-each-9a9f0cfb6188

Mastering Concurrency in C with Pthreads: A Comprehensive Guide: https://dev.to/emanuelgustafzon/mastering-concurrency-in-c-with-pthreads-a-comprehensive-guide-56je

Mutex Introduction (pthreads) | C Programming Tutorial: https://www.youtube.com/watch?v=raLCgPK-Igc

How to use gettimeofday function: https://www.youtube.com/watch?v=cunJcNgtxMk


## AI Usage

AI tools were used as a support resource during the development of this project, primarily for:

- Clarifying concurrency concepts such as threads, mutexes, deadlocks, and data races  
- Understanding synchronization strategies and timing mechanisms  
- Help on how to structure the project
- Reviewing logic to avoid deadlocks, data races and ensure proper resource management
- Improve this document's structure

All design decisions, implementation, and final code were written and validated by the project author, in compliance with the 42 rules regarding academic integrity.