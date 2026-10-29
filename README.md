*This project has been created as part of the 42 curriculum by abdnour.*

# Libft

## Description

Libft is a custom C library developed as part of the 42 curriculum. The goal is to recreate standard C library functions and add extra utility functions, in order to better understand C programming, memory management, strings, and data structures.

The library is compiled into `libft.a` and can be reused in all future C projects.

### Technical choices

- Written in C and compliant with the 42 Norm.
- Source files and the header (`libft.h`) are at the repository root.
- Compiled with `-Wall -Wextra -Werror`.
- The static library is created with `ar`.
- All dynamically allocated memory is handled and freed correctly.

## Library Description

### 1. Libc functions

Reimplementations of standard C library functions:

| Category | Functions |
|----------|-----------|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| String operations | `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat` |
| Memory operations | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| Conversion | `ft_atoi` |
| Memory allocation | `ft_calloc`, `ft_strdup` |

### 2. Additional functions

| Category | Functions |
|----------|-----------|
| String manipulation | `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split` |
| Integer conversion | `ft_itoa` |
| String iteration | `ft_strmapi`, `ft_striteri` |
| File descriptor output | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |

### 3. Linked list functions

The library also provides functions to create and manipulate singly linked lists using the `t_list` structure:

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

## Instructions

### Requirements

- A C compiler (`cc`)
- `make`
- The `ar` utility

### Compilation

Clone the repository and enter the project directory:

```bash
git clone [repo-url]
cd [repo-name]
make
```

This generates the static library `libft.a`.

Other Makefile rules:

| Command | Effect |
|---------|--------|
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | Rebuilds the library from scratch |

### Usage

Include `libft.h` in your C source file:

```c
#include "libft.h"

int main(void)
{
    ft_putstr_fd("Hello, Libft!\n", 1);
    return (0);
}
```

Then compile from the directory containing `libft.a` and `libft.h`, and link the library:

```bash
cc -Wall -Wextra -Werror main.c -o program
./program
```

## Resources

### References

- The 42 Libft project subject
- Linux manual pages (`man`) for the standard C library functions
- C language and compiler documentation
- Peer learning and practical testing

### Use of AI

AI tools were used as a learning aid to:

- Clarify the behavior of standard functions
- Identify edge cases
- Discuss memory management
- Help design tests comparing my functions with the standard library versions

All implementations were written, reviewed, and tested by me during development.