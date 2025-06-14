# 42-get_next_line

## 📖 Overview
Implemented a function `get_next_line(int fd)` that reads from a file descriptor and returns one line at a time, handling partial reads, buffer overflows, and memory management manually.

## 🔍 Function Prototype
```c
char *get_next_line(int fd);
```

## 🧠 Learning Outcomes

- Using static variables to maintain state between function calls
- Working with file descriptors and the read() system call
- Memory buffering for efficient file I/O

## 📂 Project Structure

```
get_next_line/
├── get_next_line.c              # Core function logic
├── get_next_line_utils.c        # Helper functions
├── get_next_line.h              # Header file
├── get_next_line_bonus.c        # Bonus version supporting multiple FDs
├── get_next_line_utils_bonus.c
├── get_next_line_bonus.h
└── README.md
```

## 🛠️ Compilation

For the mandatory version:
```bash
gcc your_file.c get_next_line.c get_next_line_utils.c
```
Add `#include "get_next_line.h"` in any file where you call get_next_line()

For the bonus version:
```bash
gcc your_file.c get_next_line_bonus.c get_next_line_utils_bonus.c
```
Add `#include "get_next_line_bonus.h"` in any file where you call get_next_line()

## 📌 Notes

> ⚠️ **Norminette Compliance**  
> This project follows the [42 Norminette](https://github.com/42School/norminette) — a strict C coding style guide. It enforces rules like max 25 lines per function, separate declarations/assignments, and consistent formatting. Code is written for readability and structure over brevity.
