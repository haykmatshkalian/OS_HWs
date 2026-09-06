# OS Homework 1 — Pointer Analysis
link: https://github.com/haykmatshkalian/OS_hw1

## Assignment 1 — Pointer Basics

**What it does:**
Creates an integer variable and a pointer to its memory address. It prints the address using both methods and then changes the variable through the pointer.

**How it works:**
`&a` gets the address of `a`, while `addr_a` stores that address. `*addr_a` accesses the value stored at that address.

**Pointer observation:**
Both `&a` and `addr_a` contain the same address. Changing `*addr_a` directly changes `a`.

**Example:**
`a = 10` → `*addr_a = *addr_a + 5` → `a = 15`.

---

## Assignment 2 — Array and Pointer Arithmetic

**What it does:**
Creates an array of five integers, prints its elements using a pointer, and doubles each element using pointer arithmetic.

**How it works:**
`addr_arr` points to the first element. `*(addr_arr + i)` moves through the array and accesses each element.

**Pointer observation:**
Pointer arithmetic allows the program to access array elements without using `arr[i]`. Modifying the dereferenced pointer modifies the original array.

**Example:**
`5 10 15 20 25` → `10 20 30 40 50`.

---

## Assignment 3 — Swap Using Pointers

**What it does:**
Swaps the values of two variables using a `swap()` function and pointers.

**How it works:**
The addresses of `a` and `b` are passed using `&a` and `&b`. The function dereferences the pointers to access and exchange the original values.

**Pointer observation:**
Pointers allow a function to modify variables outside its own local scope because it receives their memory addresses.

**Example:**
`a = 10, b = 20` → after `swap()` → `a = 20, b = 10`.

---

## Assignment 4 — Double Pointer

**What it does:**
Demonstrates a pointer to a pointer and uses it to access the value of an integer.

**How it works:**
`ptr_a` stores the address of `a`, while `ptr_ptr_a` stores the address of `ptr_a`. Two dereferences (`**`) reach the value of `a`.

**Pointer observation:**
A double pointer adds another level of indirection: `*ptr_a` accesses `a`, while `**ptr_ptr_a` reaches `a` through `ptr_a`.

**Example:**
`a = 10` → `*ptr_a = 10` and `**ptr_ptr_a = 10`.

---

## Assignment 5 — String and Pointer Arithmetic

**What it does:**
Prints the characters of `"Hello"` using a pointer and counts the number of characters.

**How it works:**
The pointer starts at the first character. `ptr + i` moves to the next character, and the loop stops when it reaches the null terminator `'\0'`.

**Pointer observation:**
Pointers can be used to traverse character arrays one element at a time. The null terminator indicates the end of a C string.

**Example:**
`"Hello"` → `H e l l o` → `5` characters.
