### one_line_divide function logic

pseudo code like this:

```
bool escape_symbol = false;

when meet '\n' && escape_symbol == false
	return
when meet '\'
	escape_symbol = true
when meet '\n' && escape_symbol == true
	escape_symbol = false and counton
when meet space 
	keep escape_symbol

when meet other
	escape_symbol = false

```



### Escape character

In this project like:

#### 1.Used for segmentation

```ini
[Jack\info]
adress = china\shanghai
```

equal to 

```ini
[Jackinfo]
adress = chinashanghai
```

equal to c code

```c
char section[] = {'J','a','c','k','i','n','f',o};
char key[] = {'a','d','d','r','e','s','s'};
char value[] = {'c','h','i','n','a','s','h','a','n','g','h','a','i'};
```



#### 2.Used to handle long text

```ini
[Jack\
	  info]
adress = china\
              shanghai
```

equal to 

```ini
[Jackinfo]
adress = chinashanghai
```

equal to c code

```c
char section[] = {'J','a','c','k','i','n','f',o};
char key[] = {'a','d','d','r','e','s','s'};
char value[] = {'c','h','i','n','a','s','h','a','n','g','h','a','i'};
```



#### 

error tips1:

```ini
adress = china\Z
               shanghai

```

equal to 

```ini
adress = chinaZ
shangahi
```



error tips2:

```ini
adress = china\
Z               shanghai

```

equal to 

```ini
adress = chinaZshangahi
```



#### 3.use escape character

```ini
[Jack\\info]
adress = china\\shanghai
```

equal to c code

```c
char section[] = {'J','a','c','k','\\','i','n','f',o};
char key[] = {'a','d','d','r','e','s','s'};
char value[] = {'c','h','i','n','a','\\','s','h','a','n','g','h','a','i'};
```

