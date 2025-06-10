# 📣 ft_printf – Reimplementing printf in C

This project is part of the 42 school curriculum. The goal is to recreate the powerful and widely used `printf` function from the C Standard Library, supporting multiple format specifiers and learning how to work with **variadic functions** in C.

---

## 📚 Project Overview

- 📌 Language: C  
- 🛠 Output: `libftprintf.a` static library  
- 💡 Authorized functions: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`  
- 📎 Dependencies: `libft`  
- 📁 Required files: `*.c`, `*.h`, `Makefile`

---

## ✅ Mandatory Features

You must implement the following format specifiers:

| Specifier | Description                     |
|-----------|---------------------------------|
| `%c`      | Prints a single character       |
| `%s`      | Prints a null-terminated string |
| `%p`      | Prints a pointer in hexadecimal |
| `%d` / `%i` | Prints a signed integer (base 10) |
| `%u`      | Prints an unsigned integer (base 10) |
| `%x`      | Prints a number in hex (lowercase) |
| `%X`      | Prints a number in hex (UPPERCASE) |
| `%%`      | Prints a literal `%` symbol     |

### 🔑 Function prototype

```c
int ft_printf(const char *format, ...);
```
- Does not implement original printf's buffer management
- Must mimic the behavior of standard printf as closely as possible
- Output is written using write()
- Should handle edge cases and variadic argument management

## 🔧 Makefile
Your Makefile must include the following rules:
- all – Compiles the library
- clean – Removes object files
- fclean – Removes object files and the library
- re – Rebuilds everything

## 🧠 Learning Outcomes
- Using variadic functions in C
- Handling formatted output and type-specific behavior
- Writing modular and reusable code
- Understanding how printf actually works under the hood

## 📌 Note
- No memory leaks allowed
- No use of libtool or global variables
- Code must follow the 42 Norm
- libftprintf.a must be created at the root of your repository

