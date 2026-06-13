# Compiler Design Lab (COMP 409)

This repository contains implementations of basic Compiler Design concepts as part of lab exercises.

## 📁 Repository Structure

- lab1.cpp  → Lexical Analyzer (Symbol Table Generation)
- lab2.cpp  → Regular Expression Validator (b...abb pattern)
- lab3.cpp  → Removal of Left Recursion
- code.txt  → Input file for Lab 1

## Lab Descriptions

### Lab 1: Lexical Analyzer
- Reads source code from `code.txt`
- Identifies tokens (keywords, identifiers, operators, delimiters, constants)
- Generates a symbol table

### Lab 2: Regular Expression Validation
- Implements regex matching without using libraries
- Checks whether string:
  - starts with `b`
  - ends with `abb`
- Outputs: Valid / Invalid

### Lab 3: Removal of Left Recursion
- Removes immediate left recursion from grammar
- Converts grammar into equivalent non-left-recursive form
- Suitable for top-down parsing

## How to Run

Compile and run each file separately:

```bash
g++ lab1.cpp -o lab1
./lab1

g++ lab2.cpp -o lab2
./lab2

g++ lab3.cpp -o lab3
./lab3
```

## Input Requirement (Lab 1)

- `code.txt` must be present in the same directory as `lab1.cpp`
- It contains the source code to be analyzed

## 🔗 GitHub Repository

https://github.com/sanjibdahal/compiler_lab

## 📚 Course Details

- Course: COMP 409 - Compiler Design
- Semester: IV/I
- Institution: Kathmandu University
