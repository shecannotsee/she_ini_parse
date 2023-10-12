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

