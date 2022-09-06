![eng](img/eng.png) [![ru](img/ru.png)](README.ru.md)
# `push_swap`
The purpose of this project is sort data on a stack, with specific rules, using the lowest possible number of actions.

### Discription of mandatory part
The `push_swap` program takes a set of `int` values, sorts the values using rules and writes commands that make the set sorted. To do this, you need think the algorithm and implement it.

![100](img/100slow.gif)
#### Rules
We have 2 stacks named `a` and `b`. To start with:
- `a` - contains a random number of either positive or negative numbers without any duplicates
- `b` - is empty

__The goal__ is to sort in ascending order numbers into stack `a`.
To do this we have the following commands at your disposal:
- `sa` - __swap a__ swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no elements
- `sb` - __swap b__ swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no elements
- `ss` - __swap a__ and __swap b__ at the same time
- `pa` - __push a__ - take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty
- `pb` - __push b__ - take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty
- `ra` - __rotate a__ - shift up all elements of stack `a` by 1. The first element becomes the last one
- `rb` - __rotate b__ - shift up all elements of stack `b` by 1. The first element becomes the last one
- `rr` - __rotate a__ and __rotate b__ at the same time
- `rra` - __reverse rotate a__ - shift down all elements of stack `a` by 1. The last element becomes the first one
- `rrb` - __reverse rotate b__ - shift down all elements of stack `b` by 1. The last element becomes the first one
- `rrr` - __reverse rotate a__ and __reverse rotate b__ at the same time

#### Example of working `push_swap`
Input parameters and output of the implemented programme:
```bash
$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```
### Algoritm
To complete the project, I used next algoritm. [![link](img/doc.png)](https://github.com/VBrazhnik/Push_swap/wiki/Algorithm)

But to perfectly works, I had to make some additions.
### Discription of bonus part
If you are sure that the algorithm works perfectly, you can proceed to the bonus. You need to write your own `checker`, repeating the behaviour of the standard `checker_OS`.
#### Example of working `checker`
Input parameters and output of the implemented programme:
```bash
$> ./checker 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
OK
```

### Evaluated by moulinette

![125/100](img/125.png)
