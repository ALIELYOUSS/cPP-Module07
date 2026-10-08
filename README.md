# C++ Module 07: Templates

Solutions for **42's C++ Module 07**, focused on function templates, class
templates, generic programming, and type-independent code in C++98.

## Exercises

| Directory | Topic | Main API |
| --- | --- | --- |
| `ex00` | Function templates | `swap`, `min`, `max` |
| `ex01` | Applying a function to an array | `iter` |
| `ex02` | Generic dynamic array | `Array<T>` |

## Requirements

- A C++ compiler with C++98 support
- `make`
- Unix-like environment

All exercises are compiled with:

```text
c++ -Wall -Wextra -Werror -std=c++98
```

## Build and Run

Each exercise is independent and has its own Makefile. Build an exercise from
its directory:

```bash
cd ex00
make
./ex00
```

The other exercises use the same pattern:

```bash
cd ../ex01
make
./ex01

cd ../ex02
make
./ex02
```

## Exercise Details

### `ex00` - Function Templates

`swap.hpp` provides generic implementations of `swap`, `min`, and `max` for
types that support copying and comparison. The demo applies them to integers
and `std::string` values.

### `ex01` - `iter`

`iter.hpp` applies a callback to every element of an array:

```cpp
template <typename T>
void iter(T *array, std::size_t length, void (*function)(T const &));
```

The implementation safely returns when the array or callback is null. The demo
iterates over integer and string arrays using a templated print function.

### `ex02` - `Array<T>`

`Array.hpp` implements a generic dynamically allocated array with:

- Default construction of an empty array.
- Construction with a requested size and value-initialized elements.
- Deep-copy construction and assignment.
- `size()` for retrieving the number of elements.
- Mutable and const `operator[]` access.
- `OutOfRangeException` for invalid indexes.

Example:

```cpp
Array<int> values(3);
values[0] = 42;
std::cout << values.size() << '\\n';
```

## Makefile Commands

Run these commands inside `ex00`, `ex01`, or `ex02`:

```bash
make          # Build the exercise
make clean    # Remove object files
make fclean   # Remove object files and the executable
make re       # Rebuild from scratch
```

To clean all exercises from the repository root:

```bash
for directory in ex00 ex01 ex02; do make -C "$directory" fclean; done
```

## Project Structure

```text
.
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   └── swap.hpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   └── iter.hpp
├── ex02/
│   ├── Array.hpp
│   ├── Makefile
│   └── main.cpp
└── README.md
```

## C++98 Focus

This module practices reusable type-independent code without relying on C++11
features. It also reinforces const-correctness, copy semantics, exception
handling, and manual resource management through a generic container.
