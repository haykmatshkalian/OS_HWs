# Operating Systems — Process Scheduling Simulation

## Objective

The objective of this homework is to understand CPU process scheduling and implement two scheduling algorithms: First Come First Served (FCFS) and Shortest Job First (SJF).

## 1. Task 1 — First Come First Served (FCFS)

The FCFS algorithm executes processes in order of arrival time. If multiple processes arrive at the same time, the process with the smaller PID is selected first.

The program calculates waiting time, turnaround time, and response time for each process. Since FCFS is non-preemptive, response time is equal to waiting time.

## 2. Task 2 — Shortest Job First (SJF)

The non-preemptive SJF algorithm selects the available process with the shortest burst time. If two processes have the same burst time, the process with the earlier arrival time is selected.

Once a process starts executing, it continues until completion. If no process is available, the simulation advances to the next arrival time.

## 3. Scheduling Metrics

The program calculates the following metrics for each process:

- **Waiting Time (WT)** — Time a process spends waiting before execution.
- **Turnaround Time (TAT)** — Total time between process arrival and completion.
- **Response Time (RT)** — Time between process arrival and its first execution.

The program also displays a Gantt chart showing the execution order and calculates the average waiting, turnaround, and response times for each algorithm.

## Compilation and Execution

Compile the program using G++:

```bash
g++ -Wall -Wextra -std=c++17 scheduling.cpp -o scheduling
```

Run the program using:

```bash
./scheduling
```

Enter the number of processes, followed by the arrival time and burst time of each process.

## Overall Observation

Through this task, I learned how FCFS and non-preemptive SJF schedule processes, how to calculate scheduling metrics, and how different scheduling algorithms affect waiting and turnaround times.

## Files on the Server

- `scheduling.cpp` — Implementation of FCFS and SJF scheduling algorithms.
- `README.md` — Homework documentation.

## GitHub Repository

https://github.com/haykmatshkalian/OS_HWs

## Author

**Hayk Matshkalyan**
