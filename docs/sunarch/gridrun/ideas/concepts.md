## operations

- add / sum
- multiply
- div & mod
- negate

## queue

- apply / execute queue
- clear queue

## periphery

- input
- output

## variable index

```
move down         move up
<-------- pointer ------>
             |
             V
| -2 | -1 |  0 |  1 |  2 |
--------------------------
|    |    |    |    |    |
                  Λ
                  |
            random access
```

## control flow

### return to previous branching

```
       Λ
       |
       | /-------|
       |V        |
-----> J -----> -|
       |
       V
```

### goto / jump

```
-----> o
        \
         V
         o ----->
```

### hop/bridge

```
     |
     |
-----)----->
     |
     V
```

## branching

### additive (a) junction: compare 2

```
               x
               |
               V
x <= y  <----- a ----->  x >= y
               Λ
               |
               y
```

### executive (e) junction: based on turn intention

turn left:
```
       Λ
       |
-----> e
```

turn right:
```
-----> e
       |
       V
```

### (i) junction

### operative (o) junction: comparison from queue

```
     x < y
       Λ
       |
-----> o -----> x = y
       |
       V
     x > y
```

### unconditional (u) junction

```
       Λ
       |
-----> u ----->
       |
       V
```

