### overview

For general ini files,it always looks like this:

**placeholder.ini**

```ini
[title] #we call this line section
real_key = real_value
```

All characters in the file



### Usage in C++

It is not difficult to imagine that the following method can be used to obtain k-v (in c++):

```c++
// ......
ini_parse handle("placeholder.ini");
std::string value = handle.section("title").get_key("real_key");
std::cout << "print: " << value << std::endl;
// print: real_value
// ......
```



### necessary information

1. file name : to get ini file

2. value of section :  get section from ini file

3. value of key : get value of key from section

That's all.



