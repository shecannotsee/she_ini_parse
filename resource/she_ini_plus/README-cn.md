这是一个基于ini格式扩展的文件类型解析器

### 1.基本的ini

对于基本的ini格式

```ini
; Comments
[section1]
key = value
[section2]
key = value
```

上述已经表示了基本ini格式的所有语法了

section和key-value有着一对多的关系

### 2.简易ini的缺陷

简易的ini文件很难做到复杂关系的处理，并且很难做到模块化的支持

为了支持复杂关系处理与模块化支持，我想通过增加key的type来统一解决该问题

### 3.对于缺陷的修复

root.ini

```ini
[section1]
// 添加子模块,处理多级关系
module:node.ini = scetion1-1
// 二进制数据,使用base64进行转义,转义回来为she_ini_plus
binary:she_ini_plus = c2hlX2luaV9wbHVz
keyxxx = 114514

[section2]
key = value
// 引用同级目录section1中的keyxxx,建立复杂的多级关系
&section1:keyxxx
```

node.ini

```ini
[section1-1]
key = value
```

以上的对象类型可以总结如下，用()来处理查找路径，不带()则是最后的值

在手动加载了root.ini文件后可以用以下路径来获取值

(section1)-(node.ini)-(section1-1)-(key)-value

(section1)-(she_ini_plus)-c2hlX2luaV9wbHVz

(section1)-(keyxxx)-114514

(section2)-(key)-value

(section2)-(keyxxx)-114514

在手动加载了node.ini文件后可以用以下路径来获取值

(section1-1)-(key)-value



### 4.规则总结

#### (1)注释规则

注释通过`//`或者`#`来定义



#### (2)通俗ini规则

普通规则：section通过`[`定义开始，通过`]`定义结尾，key-value通过`=`来进行定义



#### (3)key类型定义规则

key类型通过`:`来定义，具体类型有：module、binary总是通过使用base64来对不可见数据进行处理

```ini
# module
module:node.ini = scetion1-1
# binary
binary:she_ini_plus = c2hlX2luaV9wbHVz
```

module对应的key应是相应的文件，module对应的value应是相应文件的section



#### (4)引用定义规则

引用：将别的section中的key引用到本section中

```ini
[section1]
keyxxx = 114514
[section2]
&section1:keyxxx
```

`&`后应该跟随一个section名，`:`后应跟随对应section的key，**引用只会在同级section中建立这种关系**



#### (5)易于阅读以及分隔符规则

若value长度过长可以使用`\`来进行换行操作（请注意，不要再`\`后加入任何字符，否则可能被当成转义来使用），转义字符仅对ini特定字符使用，包含如下字符`[`、`]`、`:`、`=`，若想要传递二进制数据请使用binary类型

```ini
# 解析出来key是"value"
key = valu\
	  e
# 解析出来key是"value;"
key = value\;
```

默认使用`\n`当成分隔操作，也可以手动使用`;`来进行分隔操作

```ini
# 以下两种写法key解析出来均是"value"
key = valu\
      e
key = valu\
      e;
```



### 5.一些其他的修改

- `;`不再用于表示注释，用类C语言的`//`来处理注释，并且`;`用来做结束符号处理
- `#`可以用作注释

