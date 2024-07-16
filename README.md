# Push_swap

## Overview

This project involves implementing a sorting algorithm in C that sorts integers using a limited set of operations on two stacks, named a and b. The goal is to sort the integers in stack_a in ascending order with the least number of operations possible. This project is an excellent opportunity to explore algorithm complexity and improve the understanding of sorting algorithms.

## Objectives

    Develop a sorting algorithm using C.
    Understand and manage algorithm complexity.
    Comply with C programming norms and best practices.
    Implement efficient memory management.
    Enhance problem-solving and critical-thinking skills.

## Rules

    Two stacks are used: a and b.
    At the beginning, stack a contains a set of unique random integers, and stack b is empty.
    The goal is to sort the integers in stack a in ascending order using the following operations:
        sa (swap a): Swap the top two elements of stack a.
        sb (swap b): Swap the top two elements of stack b.
        ss: Perform sa and sb simultaneously.
        pa (push a): Move the top element of stack b to stack a.
        pb (push b): Move the top element of stack a to stack b.
        ra (rotate a): Shift all elements of stack a up by one.
        rb (rotate b): Shift all elements of stack b up by one.
        rr: Perform ra and rb simultaneously.
        rra (reverse rotate a): Shift all elements of stack a down by one.
        rrb (reverse rotate b): Shift all elements of stack b down by one.
        rrr: Perform rra and rrb simultaneously.