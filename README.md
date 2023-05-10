
# get_next_line

42's get_next_line project

Re-code the libc's readline function in c.

Get_next_line is allows to read a line ending with a newline character ('\n') from a file descriptor.


### Return value

- char * -> The line read by the function
- (null) -> Either an error occurred or reached EOF (End Of File)



## Usage/Examples

First of all you need to include it
```c
#include "get_next_line.h"
```

protoype :
```c
char	*get_next_line(int fd);
```
where fd is a file descriptor

