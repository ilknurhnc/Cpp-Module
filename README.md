# 42 C++ Modules (CPP00–CPP06)

This repository contains my solutions for the first **seven 42 C++ Modules** (CPP00 to CPP06). These modules build a solid foundation in modern C++ and object-oriented programming through small, progressively harder exercises.

> Goal: practice core C++ syntax, OOP design, memory management, and runtime behavior by implementing classes and testing them via small programs.

---

## Modules Overview (CPP00–CPP06)

### CPP00 — Basics & First Classes
Focus:
- Namespaces, `iostream`, basic input/output
- Classes, member functions, `this`
- Encapsulation, access specifiers (`public/private`)
- Simple project structure with headers/source files

What you should be able to do after CPP00:
- Write and use a simple class with a clean interface.

---

### CPP01 — Memory, References, Pointers
Focus:
- Stack vs heap, `new` / `delete`
- References vs pointers
- Member function pointers (depending on exercises)
- Object lifetime and scope

Outcome:
- Build intuition for memory ownership and safe allocation patterns.

---

### CPP02 — Orthodox Canonical Form
Focus:
- Copy constructor, copy assignment operator, destructor
- Deep copy vs shallow copy
- Operator overloading (typical)
- Fixed-point / small numeric class patterns (typical)

Outcome:
- Implement correct copy semantics and avoid double-free / leaks.

---

### CPP03 — Inheritance
Focus:
- Inheritance and class hierarchies
- Protected members
- Constructor/destructor order
- Method overriding basics

Outcome:
- Design base/derived classes and understand object initialization flows.

---

### CPP04 — Polymorphism & Abstract Interfaces
Focus:
- Virtual functions and runtime polymorphism
- Abstract classes and pure virtual methods
- Deep copy in class hierarchies
- Correct destructor behavior (virtual destructors)

Outcome:
- Use polymorphism correctly and prevent memory/slicing issues.

---

### CPP05 — Exceptions & Bureaucracy-style Design (Typical 42 Theme)
Focus:
- Exceptions (`try/catch/throw`)
- Rule-based class design (forms/grades theme in 42 modules)
- Robust error handling and validation
- Interactions between multiple classes

Outcome:
- Write safer C++ code with explicit failure paths and strong invariants.

---

### CPP06 — Casting & Type Conversions
Focus:
- `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`
- Type conversion edge cases
- Runtime checks (RTTI) and safe downcasting
- Serialization-style conversions (typical)

Outcome:
- Understand when casting is safe, when it is dangerous, and how to validate types.

---

## Build & Run

Each module usually contains multiple exercises (`ex00`, `ex01`, ...).  
Navigate into an exercise directory and run:

```bash
make
./<executable>

Example:

cd CPP03/ex00
make
./<executable>


Folder naming can vary by setup (e.g., cpp03/ex00, CPP03/ex00). Adjust paths accordingly.

Project Structure (Typical)
CPP00/
  ex00/
  ex01/
CPP01/
  ex00/
  ex01/
...
CPP06/
  ex00/
  ex01/


Each exercise typically includes:

*.hpp / *.h — class definitions (interfaces)

*.cpp — implementations

main.cpp — tests for the exercise

Makefile — build rules

How to Read This Repo

Suggested approach:

Start from CPP00 and follow order

For each exercise:

read main.cpp first (expected behavior)

then read class headers (.hpp)

then implementations (.cpp)

Compare outputs to the subject requirements

Notes

These solutions are built for educational purposes in the 42 curriculum.

Code style and constraints (e.g., allowed functions, flags, forbidden libraries) follow 42 rules for each module.

If you spot an issue or improvement opportunity, feel free to open an issue or PR.
