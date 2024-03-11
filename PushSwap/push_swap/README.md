This is a Programm made to sort Intigers with the shortest possible movement in two Stacks.

It runs on a Target sorting Algorythm that figures out the Cost of moving an Integer to the correct position by finding the closest biggest or closest smallest number in the other stack.
It accepts any integer from INT_MAX to INT_MIN.

The Output outlines the moves the Programm made to sort the Intigers, following moves are possible:
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.

The Syntax of this programm works either ./push_swap "Insert_Numbers" or ./push_swap Insert_Numbers . 
