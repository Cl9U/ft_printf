*This project has been created as part of the 42 curriculum by sfaraji.*

# ft_printf

## Description

`ft_printf` is a re-implementation of the C standard `printf`, built as a
static library (`libftprintf.a`). It reads a format string, replaces each
conversion with the matching variadic argument, writes the result with
`write`, and returns the number of characters printed (or `-1` on error).

**Result:** this project was validated with a score of 100/100.

Only the mandatory part is implemented. Supported conversions:

| Conversion | Prints |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` for a `NULL` pointer) |
| `%p` | a pointer in hexadecimal (`(nil)` for `NULL`) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` / `%X` | an unsigned hexadecimal number, lowercase / uppercase |
| `%%` | a literal percent sign |

Behaviour worth knowing:

- An unknown conversion such as `%k` is printed as it appears and consumes no
  argument, like glibc's `printf`.
- A `NULL` format string returns `-1`.
- If `write` fails, `ft_printf` stops and returns `-1`.

### How it works

`ft_printf` walks the format string once. For every `%`, `ft_parse` returns the
handler function matching the next character, and that handler reads exactly
one argument with `va_arg` and prints it. Each handler returns the number of
bytes it wrote, and `ft_printf` adds them up. The handlers share one prototype,
`int handler(va_list *args)`, so the dispatcher stays small.

| File | Role |
|---|---|
| `ft_printf.c` | main loop, running count, error handling |
| `ft_parse.c` | maps a specifier to its handler function |
| `ft_print_char.c`, `ft_print_str.c`, `ft_print_ptr.c`, `ft_print_nbr.c`, `ft_print_unsigned.c`, `ft_print_hex_low.c`, `ft_print_hex_up.c`, `ft_print_percent.c` | one handler per conversion |
| `ft_printchar_count.c`, `ft_utoa.c`, `ft_itoa.c`, `ft_strlen.c` | small helpers |
| `ft_printf.h` | prototypes and types |

## Instructions

Build the library:

```sh
make          # builds libftprintf.a
make clean    # removes object files
make fclean   # removes object files and the library
make re       # fclean + all
```

Use it in your own program:

```c
#include "ft_printf.h"

int main(void)
{
	int n;

	n = ft_printf("Hello %s, you are %d years old (%x)\n", "42", 42, 42);
	ft_printf("printed %d characters\n", n);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -I.
```

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- The System V AMD64 ABI document, for how variadic arguments are passed
  (register save area, `va_list` layout)
- The C standard's section on `<stdarg.h>`
- YouTube videos on how registers work, how the CPU communicates with RAM, and how the CPU works.
- AI was used as a study and deep to explain how variadic arguments, `va_list` and the x86-64 calling convention work.