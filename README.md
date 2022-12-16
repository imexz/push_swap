# push_swap
This project is about sorting data on two stacks, with a limited set of instructions, using the lowest possible number of actions.

The goal of this project is to write a program, which calculates and displays on the standard output the smallest program, made of push_swap language instructions, that sorts the integers received as arguments.

| instruction | description |
| --- | --- |
| sa (swap a) | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| sb (swap b) | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| ss | sa and sb at the same time. |
| pa (push a) | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| pb (push b) | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| ra (rotate a) | Shift up all elements of stack a by 1. The first element becomes the last one. |
| rb (rotate b) | Shift up all elements of stack b by 1. The first element becomes the last one. |
| rr | ra and rb at the same time. |
| rra (reverse rotate a) | Shift down all elements of stack a by 1. The last element becomes the first one. |
| rrb (reverse rotate b) | Shift down all elements of stack b by 1. The last element becomes the first one. |
| rrr | rra and rrb at the same time. |

Bonus: A program to check if the given input was properly sorted by the push_swap program. Prints OK to stdout, if the instructions lead to a sorted stack, otherwise KO. 

## Usage

- Run `make`
- Set an environment variable in your current shell and assign it with a set of integers (e.g. INPUT_SET="1 2 4 3 5")
  - Run `push_swap <set of integers, e.g. $INPUT_SET>` or
  - Run `push_swap $INPUT_SET | checker $INPUT_SET`

## Algorithm
- Sort the set and assign the sorted index for each stack element.
- Get longest already sorted subset, criterium:
  - On 1. iteration: next element must be the element with the next expected index (current_element_index + 1 == next_element_index),
  - On 2. iteration: next element must be greater than the current one
- Push all numbers not included in the subset to stack b.
  - Check if a swap instruction would increase the size of the longest sorted subset, execute swap if this is the case.
- Calculate the element on stack b with fewest actions needed to insert into stack a. Do so until stack b is empty.
- Calculate the final rotation direction to get stack a sorted. Rotated accordingly.

- Finally compare the number of actions needed for the 1. iteration (index)  with those of the 2. iteration (greater than).
- Pick the list with less actions needed.
- Print the list of actions.
