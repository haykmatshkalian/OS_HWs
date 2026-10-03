# Operating Systems — Dynamic Memory Allocation in C

## Objective

The objective of this homework is to understand dynamic memory allocation in C using `malloc()`, `calloc()`, `realloc()`, and `free()`. The programs demonstrate how to allocate memory at runtime, work with dynamically allocated arrays and strings, resize memory, and release it when it is no longer needed.

## 1. Task 1 — Dynamic Array Using `malloc()`

The program asks the user to enter the number of integers, dynamically allocates an array using `malloc()`, and reads the values from the user.

It then calculates and prints the sum of all elements. Finally, it releases the allocated memory using `free()`.

## 2. Task 2 — Zero-Initialized Array Using `calloc()`

This program uses `calloc()` to allocate an array of integers. Unlike `malloc()`, `calloc()` initializes all allocated elements to zero.

The program first displays the initial values, then asks the user to enter new values. It prints the updated array, calculates the average, and frees the allocated memory.

## 3. Task 3 — Resizing an Array Using `realloc()`

The program initially allocates memory for 10 integers using `malloc()` and reads 10 values from the user.

After that, it uses `realloc()` to resize the array to hold only 5 integers. The first five elements are printed, and the allocated memory is released.

A temporary pointer is used with `realloc()` to avoid losing the original pointer if memory reallocation fails.

## 4. Task 4 — Dynamic Array of Strings

This program dynamically allocates memory for an array of three strings. Each string has space for up to 50 characters, including the null terminator.

After reading and displaying the first three strings, the program uses `realloc()` to increase the pointer array size from three to five elements.

It then allocates memory for two additional strings, reads them, and displays all five strings.

Finally, each string and the pointer array itself are freed.

## 5. Task 5 — Finding the Highest and Lowest Grades

The program asks the user to enter the number of students and dynamically allocates an integer array to store their grades.

After reading the grades, it finds and displays the highest and lowest values.

The program uses the first grade as the initial highest and lowest values, then compares the remaining grades. Finally, it releases the allocated memory.

## Compilation and Execution

Each program can be compiled separately using GCC:

```bash
gcc p1.c -o p1
gcc p2.c -o p2
gcc p3.c -o p3
gcc p4.c -o p4
gcc p5.c -o p5
```

Run a program using:

```bash
./p1
```

Replace `p1` with `p2`, `p3`, `p4`, or `p5` to run the other programs.

## Overall Observation

Through these tasks, I practiced dynamic memory management in C. I learned how `malloc()` and `calloc()` allocate memory, how `realloc()` changes the size of allocated memory, and why `free()` is necessary to prevent memory leaks.

I also practiced working with dynamically allocated arrays and strings, checking for allocation failures, and handling memory safely.

## Files on the Server

- `p1.c` — Dynamic integer array using `malloc()`.
- `p2.c` — Zero-initialized integer array using `calloc()`.
- `p3.c` — Resizing an integer array using `realloc()`.
- `p4.c` — Dynamic array of strings.
- `p5.c` — Finding the highest and lowest grades.
- `README.md` — Homework documentation.

## GitHub Repository

https://github.com/haykmatshkalian/OS_HWs

## Author

**Hayk Matshkalyan**
