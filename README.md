# ft_printf
# ft\_printf: Roadmap and README Guide

A step-by-step process to finish ft\_printf (subject v12.1), plus a guide for writing the README yourself.

## 1. Core concepts recap

- **Variadic functions**: `ft_printf(const char *, ...)` receives a fixed first argument and then any number of extra ones. The format string is the only clue about how many there are and what types they have. Tools from `<stdarg.h>`: `va_list`, `va_start`, `va_arg`, `va_end` (and `va_copy`).
- **Format string parsing**: walk through the string one character at a time. A normal character is written as is. A `%` means the next character is a conversion specifier. `%%` prints one `%`.
- **Return value**: the real `printf` returns the number of characters printed. Your function is compared against it, so this counts.
- **Conversions to handle**: `c s p d i u x X %`.
- **No buffering**: the subject says not to implement the buffer management of the original. Write directly with `write`.
- **Allowed external functions**: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`. Your libft is authorized.

## 2. Step-by-step process

### Step 0: Read and understand (before any code)

1. Re-read the subject once, slowly. Note the requirements that cause a 0: Norm errors, crashes, leaks, a Makefile that relinks.
2. Read `man 3 printf` (conversion specifiers) and `man 3 stdarg`.
3. On paper, trace how `printf("a%db", 42)` should be processed, character by character. Decide what happens at each `%`.

### Step 1: Set up the repository

1. Create the repository structure: sources, `ft_printf.h`, `Makefile`, a `libft` folder (copy of your libft sources and its Makefile), and `README.md` at the root.
2. Header file must be named `ft_printf.h` and contain the prototype `int ft_printf(const char *, ...);`.
3. Use include guards.
4. Decide how you will split files. Keep functions short for the Norm. One file per group of related conversions is a common choice.

### Step 2: Write the Makefile early

Requirements from the subject:

- Output library name: `libftprintf.a`, created at the **root** of the repository.
- Compiler: `cc` with `-Wall -Wextra -Werror`.
- Rules: `$(NAME)`, `all`, `clean`, `fclean`, `re`.
- Must use `ar` (using `libtool` is forbidden).
- Must **not relink** when nothing changed.
- Since libft is used, the Makefile must first compile libft using its own Makefile, then compile the project.

Test it: run `make` twice and check that the second run does nothing. Run `make re`, `make clean`, `make fclean`.

### Step 3: Build the skeleton

1. Write `ft_printf` with the `va_list` setup and cleanup.
2. Loop over the format string. Print normal characters. Detect `%`.
3. Send each specifier to a dispatching function (one place that decides which conversion to run).
4. Make every printing helper report how many characters it wrote, and add them up for the return value.
5. Test with only `%c`, `%s` and `%%`.

### Step 4: Add the conversions one group at a time

Suggested order, testing after each one against the real `printf`:

1. `%c`, `%%`
2. `%s` (think about the `NULL` case and compare with the real behavior)
3. `%d`, `%i` (think about negative numbers, `0`, `INT_MIN`)
4. `%u` (different type to read, think about `UINT_MAX`)
5. `%x`, `%X` (base conversion, you did something similar in the piscine)
6. `%p` (pointer in hexadecimal with `0x`, think about the null pointer case on your system)

### Step 5: Test against the real printf

For every test, compare **both the output and the return value**. Write your own test file (it is not graded, but it is useful in your defense).

Edge cases to try:

- empty format string
- format with no conversions
- `%%` alone and next to other conversions
- `0`, `INT_MIN`, `INT_MAX`, `UINT_MAX`, `LONG_MIN` for `%p`
- `NULL` for `%s` and `%p`
- several conversions in one call
- a format that ends with a lone `%` (what does the real printf do on your system?)

### Step 6: Quality checks (each of these can give a 0)

- [ ] Run `norminette` on every file, including headers.
- [ ] No segfaults, bus errors or double frees.
- [ ] No memory leaks (check with `valgrind` or leak tools if you allocate memory).
- [ ] Compiles with `-Wall -Wextra -Werror` without warnings.
- [ ] Makefile does not relink.
- [ ] File names are exactly what the subject requires.
- [ ] Only allowed functions are used.

### Step 7: Write the README

See section 3 below.

### Step 8: Prepare for the defense

- Be able to explain every line of your code in your own words.
- Be ready for a small modification request during evaluation (for example a minor behavior change or adding a small feature). Practice changing something in your code quickly.
- Be able to explain how `va_arg` works and why you chose your structure.
- Test with a classmate's tester or your peer's tests, as the subject allows.

### Step 9: Bonus (only if the mandatory part is perfect)

The bonus is evaluated **only** if the mandatory part is perfect.

- Flags `-`, `0`, `.` and field minimum width under all conversions.
- Flags `#`, space and `+`.
- Bonus code goes in `_bonus.c` and `_bonus.h` files and needs a `bonus` rule in the Makefile.
- The subject advises designing for the bonus from the beginning, so keep your parsing and dispatching extensible.

## 3. README step by step

The README must be called `README.md` and be at the root of the repository. It should let someone who does not know the project understand what it is, how to run it, and where to find more information. Write it in English (recommended) or the main language of your campus.

### Step 1: First line (mandatory format)

The very first line must be italicized and read exactly:

*This project has been created as part of the 42 curriculum by `<login1>[, <login2>[, <login3>]]`.*

Replace the placeholder with your own 42 login.

### Step 2: Description section

Present the project: its goal and a short overview. Questions to answer in your own words:

- What is `ft_printf` and what is it for?
- Which conversions does it support?
- What does the library `libftprintf.a` contain?
- What did the project teach you (for example variadic functions)?

### Step 3: Instructions section

Explain how to compile, install and use it. Questions to answer:

- Which command builds the library? Which commands clean it?
- How do I link it into another program? (give a short compile command example)
- What do I need to include in my code?
- Any requirement such as the compiler and flags?

### Step 4: Resources section

Two parts are required:

1. **Classic references** you actually used: `man 3 printf`, `man 3 stdarg`, C documentation, articles and tutorials about variadic functions.
2. **How AI was used**: say for which tasks and which parts of the project. Be honest and specific. For example: explaining the concept of variadic functions, or suggesting resources. Do not claim you used it for things you did not, and do not hide real use.

Keep notes while you work so this section is accurate at the end.

### Step 5: Algorithm and data structure (required)

The subject requires a **detailed explanation and justification of the chosen algorithm and data structure**. Questions to answer:

- How does your function process the format string?
- How do you pick the right conversion function? Why did you choose that approach (compare with at least one alternative)?
- How do you count the characters for the return value?
- How do you convert numbers to a base? Why is that approach suitable?
- Do you allocate memory? If yes, where and how is it freed? If no, why not?
- What makes your design easy to extend (for example for bonus flags)?

This is the section reviewers will use to check that you understand your own code.

### Step 6: Optional sections

Useful additions: usage examples, feature list, technical choices, known limitations, testing.

### README skeleton

```markdown
*This project has been created as part of the 42 curriculum by <login>.*

# ft_printf

## Description
(goal, overview, supported conversions)

## Instructions
(compilation, usage, linking example)

## Algorithm and data structure
(explanation and justification)

## Resources
(references, and how AI was used: tasks and parts of the project)
```

## 4. Final submission checklist

- [ ] `libftprintf.a` is built at the root by `make`
- [ ] Makefile has `$(NAME)`, `all`, `clean`, `fclean`, `re` and does not relink
- [ ] `ft_printf.h` exists with the prototype
- [ ] `libft` folder with sources and its Makefile is included
- [ ] Norm check passes on all files
- [ ] Output and return value match the real `printf` on your tests
- [ ] No crashes, no leaks
- [ ] README has the italic first line, Description, Instructions, Algorithm explanation, Resources with AI usage
- [ ] Everything is pushed to the assigned Git repository (only the repository content is graded)
- [ ] You can explain all your code and handle a small modification

## 5. Useful resources

- `man 3 printf` and `man 3 stdarg`
- Beej's Guide to C: https://beej.us/guide/bgc/
- GNU C Library manual, section on variadic functions
- cppreference page for `<stdarg.h>`
- `man ar` and the GNU Make manual (static libraries)
- Peers at your campus: explaining your design to a classmate is the best preparation for your defense
