# Operating Systems — Homework 2

This repository contains the solutions for Homework 2.

The assignments focus on Linux processes and demonstrate process creation, process hierarchy, program execution, passing arguments to programs, and synchronization between parent and child processes.

## Assignments

### Assignment 0 — Multiple Fork Calls

The objective is to understand the process hierarchy when multiple sequential `fork()` system calls are executed.

The program performs three consecutive `fork()` calls.

Each process created by a `fork()` continues executing the following code, so the number of processes doubles after every successful `fork()`:

```text
1 fork  → 2 processes
2 forks → 4 processes
3 forks → 8 processes
```

The final process tree contains **8 processes**.

**Concepts:**

* `fork()`
* Process creation
* Parent-child relationships
* Process hierarchy
* Return values of `fork()`

**File:**

* `assignment0.c`

---

### Assignment 1 — Simple Fork and Exec

The program creates a child process using `fork()`.

The child uses `execl()` to execute the `ls` command and list the contents of the current directory.

The parent uses `waitpid()` to wait for the child to finish before printing:

```text
Parent process done
```

The use of `waitpid()` guarantees that the directory listing appears before the parent's message.

**Concepts:**

* `fork()`
* `execl()`
* `waitpid()`
* Parent-child synchronization
* Replacing a process image

**File:**

* `assignment1.c`

---

### Assignment 2 — Multiple Forks and Execs

The program creates two child processes.

The first child executes:

```bash
ls
```

The second child executes:

```bash
date
```

The parent waits for both children and then prints:

```text
Parent process done
```

The process hierarchy is:

```text
             Parent
             /    \
            /      \
       Child 1    Child 2
          |          |
         ls         date
```

The program is structured so that only the parent creates the second child.

**Concepts:**

* Multiple `fork()` calls
* Multiple child processes
* `execl()`
* `waitpid()`
* Process hierarchy
* Process synchronization

**File:**

* `assignment2.c`

---

### Assignment 3 — Fork and Exec with Arguments

The program creates a child process using `fork()`.

The child uses `execl()` to execute the `echo` command with the argument:

```text
Hello from the child process
```

The command executed by the child is equivalent to:

```bash
echo "Hello from the child process"
```

The parent waits for the child to finish and then prints:

```text
Parent process done
```

**Concepts:**

* `fork()`
* `execl()`
* Passing arguments to `execl()`
* `waitpid()`

**File:**

* `assignment3.c`

---

### Assignment 4 — Fork and Exec with Command-Line Arguments

The program uses `fork()` to create a child process.

The child uses `execl()` to execute the `grep` command and search for a specific word inside `test.txt`.

For example:

```bash
grep главное test.txt
```

The parent waits for the child to finish and then prints:

```text
Parent process completed
```

Example `test.txt`:

```text
Кофе купленное не в кафе - называется Нескафе.
Секрет успеха прост, но это секрет.
Бабки не главное-главное их пенсия.
(с) Джейсон Стэтхем
```

Searching for `успеха` produces:

```text
Секрет успеха прост, но это секрет.
Parent process completed
```

**Concepts:**

* `fork()`
* `execl()`
* Passing multiple arguments
* `grep`
* File searching
* `waitpid()`

**Files:**

* `assignment4.c`
* `test.txt`

---

## Important System Calls

### `fork()`

`fork()` creates a new child process.

Its return value is different in the parent and child:

| Return value | Meaning                                                   |
| ------------ | --------------------------------------------------------- |
| `< 0`        | Process creation failed                                   |
| `0`          | Code is executing in the child                            |
| `> 0`        | Code is executing in the parent; value is the child's PID |

For example:

```c
int ret = fork();

if (ret < 0) {
    // fork failed
}
else if (ret == 0) {
    // child process
}
else {
    // parent process
}
```

### `execl()`

`execl()` replaces the current process image with another program.

For example:

```c
execl("/bin/ls", "ls", (char *)NULL);
```

The child process becomes the `ls` program.

`execl()` does not create a new process. It replaces the program running inside the existing process.

Arguments can also be passed:

```c
execl("/bin/echo", "echo",
      "Hello from the child process",
      (char *)NULL);
```

### `waitpid()`

`waitpid()` allows the parent process to wait for a specific child process to finish.

Example:

```c
waitpid(ret, NULL, 0);
```

This is important when the parent must wait for the child's output before continuing.

---

## Process Hierarchy

The basic relationship between a parent and child process is:

```text
Parent Process
      |
      +--- Child Process
              |
              +--- execl()
                    |
                    +--- External Program
```

For Assignment 0, because all processes continue to execute subsequent `fork()` calls, the number of processes doubles after each call:

```text
                    P0
                  /    \
                P1      P2
               /  \    /  \
             P3   P4  P5   P6
            /
           P7
```

The exact PID arrangement depends on process scheduling, but the important result is that there are **8 processes after three sequential `fork()` calls**.

---

## Compilation

The programs can be compiled using `gcc`:

```bash
gcc assignment0.c -o assignment0
gcc assignment1.c -o assignment1
gcc assignment2.c -o assignment2
gcc assignment3.c -o assignment3
gcc assignment4.c -o assignment4
```

Then run them with:

```bash
./assignment0
./assignment1
./assignment2
./assignment3
./assignment4
```

For Assignment 0, the process hierarchy can also be inspected using:

```bash
pstree -p
```

or with:

```bash
htop
```

In `htop`, enable tree view to see the parent-child relationships.

---

## Summary


These assignments demonstrate how Linux processes are created and managed using `fork()`, how a process can execute another program using `execl()`, and how parent and child processes can be synchronized using `waitpid()`.

## GitHub Repository

GitHub repository:

**https://github.com/haykmatshkalian/OS_HWs**

## Author

Hayk Matshkalyan
