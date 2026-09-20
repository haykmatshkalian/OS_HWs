# Operating Systems — Processes Homework

This homework demonstrates how Linux processes are created, synchronized, and terminated using `fork()`, `wait()`, `waitpid()`, `exit()`, and `atexit()`.

## Assignment 1 — Basic Process Creation

The program uses `fork()` to create a child process.

The child prints its PID using `getpid()` and then exits. The parent prints its own PID without waiting for the child.

### Observation

The parent and child run independently, so their output order may be different each time.

**Concepts:**

* `fork()`
* `getpid()`
* Parent and child processes
* Process IDs

**File:** `prob1.c`

---

## Assignment 2 — `wait()` and `waitpid()`

The program first uses `wait()` so the parent waits for the child to finish.

The child exits with a status code, for example:

```c
exit(5);
```

The parent gets this status using:

```c
WEXITSTATUS(status)
```

A second child is then created, and `waitpid()` is used to wait for that specific child.

### Observation

`wait()` waits for a child process, while `waitpid()` allows the parent to wait for a specific child.

**Concepts:**

* `wait()`
* `waitpid()`
* Exit status
* Process synchronization

**File:** `prob2.c`

---

## Assignment 3 — `atexit()`

The program registers two functions using `atexit()`.

```c
atexit(function1);
atexit(function2);
```

When the program calls `exit()`, the registered functions are executed before the program terminates.

They are executed in **reverse order of registration**.

### Observation

Changing the location of `exit()` changes when the program terminates, but the registered `atexit()` functions are still called.

`atexit()` can be useful for cleanup tasks such as closing files or releasing resources.

**Concepts:**

* `atexit()`
* `exit()`
* Program cleanup

**File:** `prob3.c`

---

## Assignment 4 — Fork and Exit Status

The program creates two child processes.

Each child uses a different exit code:

```c
exit(5);
exit(10);
```

The parent uses `waitpid()` to wait for each child and checks the result using:

```c
WIFEXITED(status)
```

and:

```c
WEXITSTATUS(status)
```

### Observation

The parent can determine whether each child exited normally and can retrieve its exit status.

**Concepts:**

* Multiple child processes
* `fork()`
* `exit()`
* `waitpid()`
* Exit status

**File:** `prod4.c`

---

## Assignment 5 — Zombie Processes

The first version creates a child and does not use `wait()` in the parent.

The child finishes, but the parent continues running. As a result, the child becomes a **zombie process**.

The process was observed using `htop`.

### Zombie Process


The screenshot inside the directory shows the terminated child remaining as a zombie while the parent is still running.

The program was then modified to use:

```c
wait(NULL);
```

The parent collects the child's exit information, so the child does not remain as a zombie.

### Observation

`wait()` and `waitpid()` prevent zombie processes by allowing the parent to collect the termination status of its child.

**Concepts:**

* Zombie processes
* `wait()`
* `waitpid()`
* Process termination
* `htop`

**File:** `prob5.c`

---

## Overall Observation

During the assignments, `htop` was used to observe the processes and their behavior.

The main observations were:

* `fork()` creates a new child process.
* Parent and child have different PIDs.
* `wait()` synchronizes the parent with a child.
* `waitpid()` allows the parent to wait for a specific child.
* `exit()` provides an exit status.
* `atexit()` runs registered functions when the program terminates.
* Without `wait()` or `waitpid()`, a terminated child can become a zombie.

## Compilation

The programs can be compiled using:

```bash
gcc prob1.c -o prob1
gcc prob2.c -o prob2
gcc prob3.c -o prob3
gcc prob4.c -o prob4
gcc prob5_1.c -o prob5_1
gcc prob5_2.c -o prob5_2
```

## GitHub Repository

**https://github.com/haykmatshkalian/OS_HWs**

## Author

Hayk Matshkalyan
