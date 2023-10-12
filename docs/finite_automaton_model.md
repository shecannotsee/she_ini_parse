### one_line_divide

**The five tuples are as follows:**

#### 1.States

S1: not_during_esacpe

S2: during_esacpe

S3: accept

#### 2.Alphabet

```c++
char symbol[]={'\n','\\',' ','?'}
// '?' means other character
// we call symbol[0] -> Q1
// we call symbol[1] -> Q2
// we call symbol[2] -> Q3
// we call symbol[3] -> Q4
```

#### 3.Transition Function

S1 + Q1 -> S3          S2 + Q1 -> S1

S1 + Q2 -> S2          S2 + Q2 -> S1

S1 + Q3 -> S1          S2 + Q3 -> S2

S1 + Q4 -> S1          S2 + Q4 -> S1



#### 4.Initial State

S1

#### 5.Accept States

S3