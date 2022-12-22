# README - Printf

## Files

- ft_printf_<letter>.c : files specific to a certain type <letter>
- ft_printf_utils.c : useful functions
- ft_printf.c : analysis of the string

## Special features of this version of printf

# flag "0"
    - types : d, i, u, x, X
    - pad the number with zeros
    - can't be used with '.' and '-'
```c
Example
>> printf("[%010d]", 57483)
>> [0000057483]
```

# flag ".number"
    - types : d, i, u, x, X, s
    - for d, i, u, x, X 
        -> precision specifies the minimum number of digits to be written
        -> If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.
    - for s
        -> this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.
    - for c

____________________________

# flag "#"
    - types : x and X
    - add "0x" or "0X"

```c
Exemple
>> printf("[%#x]", 16)
>> [0x10]
```

# flag "+"
    - types : d, i 
    - add "+" to a positive number, "-" if negative

# flag " "
    - types : d, i
    - add " " if it is a positive number, "-" if negative

# flag "%number"
    - types : c, s, p, d, i, u, x, X
    - left justify

# flag "%-(number)"
    - types : c, s, p, d, i, u, x, X
    - if there is a padding, right justify the padding (instead of left)

# Exemples
```sh
>> printf("[% 6i]", -25)
>> [   -25]
```
```sh
>> printf("[%6s]", "-25")
>> [   -25]
```
```sh
>> printf("[%-6s]", "-25")
>> [-25   ]
```
```sh
>> printf("[%-111.9d]", 5555)
>>[000005555                                                                                                      ]
```
```c
>> printf("[%-50.10d]", 5)
>> [0000000005                                        ]
// In this example treat the .10 first then treat the -50
```
```c
>> printf("[%50.10s]", "lolololllllllllllllllllllllllllllllllllllllllll")
>> [                                        lololollll]
// The . flag works differently with strings : .10 is the maximum length of the given string while 50 is the minimum length of the result.
```
```c
>> printf("[%#.10x]", 57483)
>> [0x000000e08b] // -> length = 14 (with brackets)
```

## Run the project

Simply do:
```sh
make && gcc libftprintf.a <your_test_file>.c && ./a.out
```
