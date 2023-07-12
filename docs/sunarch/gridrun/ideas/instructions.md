| c/v | (I) | instruction   | type           | comment                                           |
|:---:|:---:|---------------|----------------|---------------------------------------------------|
|  v  |  a  | additive      | junction       |                                                   |
|     |  b  |               |                |                                                   |
|     |  c  |               |                |                                                   |
|     |  d  | division      | operation      | add [div & mod] operation to HEAD operation queue |
|  v  |  e  | executive     | junction       | execute turn intention                            |
|     |  f  |               |                |                                                   |
|     |  g  | get           | I/O            | read value from input                             |
|     |  h  |               |                |                                                   |
|  v  |  i  | ?             | junction       |                                                   |
|     |  j  |               |                |                                                   |
|     |  k  |               |                |                                                   |
|     |  l  | left          | turn intention | add (-90˚) to **e**xecute turn intention          |
|     |  m  | multiply      | operation      |                                                   |
|     |  n  | nop           |                | no operation                                      |
|  v  |  o  | operative     | junction       | comparison from queue                             |
|     |  p  | put           | I/O            | write value to output                             |
|     |  q  | queue         | operand        | add HEAD var index to HEAD operand queue          |
|     |  r  | right         | turn intention | add(90˚) to **e**xecute turn intention            |
|     |  s  | sum           | operation      | add **s**um operation to HEAD operation queue     |
|     |  t  |               |                |                                                   |
|  v  |  u  | unconditional | junction       |                                                   |
|     |  v  |               |                |                                                   |
|     |  w  |               |                |                                                   |
|     |  x  |               |                |                                                   |
|     |  y  |               |                |                                                   |
|     |  z  |               |                |                                                   |

### junctions

- a : additive
- e : executive
- i : ?
- o : operative
- u : unconditional

### I/O

- g : get
- p : put

### operations

- d : division
- m : multiply
- s : sum

# from previous, not yet in current

- apply
    - HEAD operation queue -> HEAD operand queue => HEAD var index
- eXecute
    - reverse HEAD to the last **e**xecute junction

# history

1. initial partial list
2. changed concept so that vowels represent branching
