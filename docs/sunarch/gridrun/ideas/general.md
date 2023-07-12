# basic elements

- main:
    - sequence
    - selection (if)
    - iteration (while)
- I/O
    - input
    - output

# options

- input = stdin
- output = stdout
- tail (length for HEADs) = 3
- speed (default operations per cycle) = 1
- visual (display) = False

# concepts

- cycles

# HEAD

- operand queue
- operation queue
- split
- wait for other
- destroy
- toggle execution

# shared

- variable index

# possible instructions

| c/v | (I) | possible instructions / meanings                   |
|:---:|:---:|----------------------------------------------------|
|  v  |  a  | add, apply                                         |
|     |  b  | backwards (direction), branch, bridge              |
|     |  c  | char, choose, compare, const, crossroads           |
|     |  d  | div, down (direction)                              |
|  v  |  e  | end, execute, exit                                 |
|     |  f  | for, fork, forward (direction), from               |
|     |  g  | get, goto                                          |
|     |  h  | hop                                                |
|  v  |  i  | if, input, iterate                                 |
|     |  j  | join, jump, junction                               |
|     |  k  | keep, key, kill                                    |
|     |  l  | left (direction), loop                             |
|     |  m  | modulo, multiply                                   |
|     |  n  | nop                                                |
|  v  |  o  | output                                             |
|     |  p  | pipe (toggle), pointer, pop, push, put             |
|     |  q  | queue, quit                                        |
|     |  r  | reverse, right (direction)                         |
|     |  s  | seek, select, set, skip, split, source, store, sum |
|     |  t  | target, to, turn                                   |
|  v  |  u  | up (direction), use                                |
|     |  v  | value, var, variable                               |
|     |  w  | while, withdraw, write                             |
|     |  x  | eXecute, eXit                                      |
|     |  y  | yield                                              |
|     |  z  | zero                                               |

# directions

## v.1

|  .  |  u  |  .  |
|:---:|:---:|:---:|
|  l  |  .  |  r  |
|  .  |  d  |  .  |

## v.2

|  .  |  f  |  .  |
|:---:|:---:|:---:|
|  l  |  .  |  r  |
|  .  |  b  |  .  |

## v.3

|  .  |  (-)  |  .  |
|:---:|:-----:|:---:|
|  l  |   .   |  r  |
|  .  | ll/rr |  .  |

# note

Started on 2021-11-13
