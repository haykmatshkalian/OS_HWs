# Operating Systems — Data Alignment in C

## Objective

The objective of this homework is to understand data alignment, struct padding, and how `#pragma pack` affects memory layout in C.

## 1. Task 1 — Understanding Data Alignment

The program declares variables of type `int`, `char`, `double`, and `short`. It prints their sizes and memory addresses.

The output shows that the sizes are 4, 1, 8, and 2 bytes, respectively. The addresses demonstrate how variables are aligned in memory.

## 2. Task 2 — Struct Padding

The program defines two structs containing the same fields in different orders.

Both structs occupy 16 bytes. This demonstrates that the compiler inserts padding between fields to satisfy alignment requirements. In this example, changing the field order does not reduce the struct size.

## 3. Task 3 — Data Alignment with `#pragma pack`

The program compares a normal struct with a packed struct using `#pragma pack(1)`.

The normal struct occupies 16 bytes, while the packed struct occupies 13 bytes. Packing reduces padding by allowing fields to be placed with less restrictive alignment.

## 4. Bonus Task — Different Packing Values

The program compares normal alignment with `#pragma pack(1)`, `#pragma pack(2)`, and `#pragma pack(4)`.

The observed sizes are:

- Normal struct: 16 bytes
- `#pragma pack(1)`: 13 bytes
- `#pragma pack(2)`: 14 bytes
- `#pragma pack(4)`: 16 bytes

These results show how different packing values affect struct size and field alignment.

## Compilation and Execution

Compile each program separately using GCC:

```bash
gcc p1.c -o p1
gcc p2.c -o p2
gcc p3.c -o p3
gcc p3_bonus.c -o p3_bonus
```

Run a program using:

```bash
./p1
```

Replace `p1` with `p2`, `p3`, or `p3_bonus` to run the other programs.

## Overall Observation

Through these tasks, I learned how data types are aligned in memory, how padding affects struct size, and how `#pragma pack` changes alignment and memory usage.

## Files on the Server

- `p1.c` — Data type sizes and addresses.
- `p2.c` — Struct padding and field order.
- `p3.c` — Normal and packed struct comparison.
- `p3_bonus.c` — Comparison of different packing values.
- `README.md` — Homework documentation.

## GitHub Repository

https://github.com/haykmatshkalian/OS_HWs

## Author

**Hayk Matshkalyan**
