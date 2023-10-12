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



### build_model

#### get all states:

```c++
enum class status {
    S1,S2,S3,REFUSE
};

```



#### get all Alphabet

```c++
enum class alphabet {
    Q1,Q2,Q3,Q4
};

std::unordered_map<char_type, alphabet> cher_table = {
    {'\n',alphabet::Q1},
    {'\\',alphabet::Q2},
    {' ', alphabet::Q3}
}

template<typename char_type>
alphabet get_alphabet(char_type input) {
    if (cher_table.find(input) != cher_table.end()) {
    	return cher_table[input];
    } else {
        return alphabet::Q4;
    }
}
```



#### Implement conversion functions

```c++
static std::unordered_map<std::tuple<int,int>,states> transfer_function = {
  {{static_cast<int>(states::S1),static_cast<int>(alphabet::Q1)},/* -> */states::S3},
  {{static_cast<int>(states::S1),static_cast<int>(alphabet::Q2)},/* -> */states::S2},
  {{static_cast<int>(states::S1),static_cast<int>(alphabet::Q3)},/* -> */states::S1},
  {{static_cast<int>(states::S1),static_cast<int>(alphabet::Q4)},/* -> */states::S1},
  {{static_cast<int>(states::S2),static_cast<int>(alphabet::Q1)},/* -> */states::S1},
  {{static_cast<int>(states::S2),static_cast<int>(alphabet::Q2)},/* -> */states::S1},
  {{static_cast<int>(states::S2),static_cast<int>(alphabet::Q3)},/* -> */states::S2},
  {{static_cast<int>(states::S2),static_cast<int>(alphabet::Q4)},/* -> */states::S1},
};

template<typename char_type>
states transition_status(states now, char_type input) {
  int input_S = static_cast<int>(now);
  int input_Q = static_cast<int>(get_alphabet(input));
  auto key = std::make_tuple(input_S,input_Q);
  if(transfer_function.find(key)!= transfer_function.end())
    return transfer_function[key];
  else {
    return states::REFUSE;
  }
}
```



#### Overall logic

```c++
void main_logic() {
}
```

