Philosopher is a programm that handles multithreading without data-races

Philosophers is a simulation in which Philosophers(Threads) sit at a table and fight over forks(mutexes) and need a working algorithm in which they can eat, sleep and die in a specific rythm to survive. The goal is to kill them when the times given to the programm are conflicting and to make them survive if they are not. The limit on my philosophers is 5ms.

>Every function is completely protected, threads are cleaned up properly no matter what happens
>The programm is intended for 200 philosophers but can handle a lot more
>There are sleep buffers in place that kill the programm in an appropriate amount of time.
