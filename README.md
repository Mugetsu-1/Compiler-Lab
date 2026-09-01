# Compiler Design and Construction Lab 1

This folder contains C++ programs, Flex specifications, and Bison grammar files for Compiler Design and Construction Lab 1. The exercises cover basic compiler front-end concepts such as finite automata, lexical analysis, grammar transformations, FIRST/FOLLOW computation, and parser construction.

## Contents

| File | Description |
| --- | --- |
| `DFA_Start01.cpp` | DFA that accepts binary strings starting with `01` (Q1A). |
| `DFA_End01.cpp` | DFA that accepts binary strings ending with `01` (Q1B). |
| `DFA_AcceptSubstring001.cpp` | DFA that accepts binary strings containing `001` (Q1C). |
| `Prefix_Substring_Siffix.cpp` | Prints prefixes, suffixes, and substrings of a string (Q2). |
| `CommentChecker.cpp` | Checks C/C++ style comments (Q3). |
| `ValidateC_Identifiers.cpp` | Validates C identifiers and keywords (Q4). |
| `LexicalAnalyzer.cpp` | Performs simple lexical analysis (Q5). |
| `Lexer.l` | Flex specification for lexical analysis (Q6). |
| `CFG+LeftRecursion_LeftFactorElem.cpp` | Removes left recursion and performs left factoring (Q7). |
| `FirstFollowComputation.cpp` | Computes FIRST and FOLLOW sets (Q8). |
| `LL(1)ParsingTable.cpp` | Constructs an LL(1) parsing table (Q9). |
| `topDownLL(1)StackPArser.cpp` | Implements a stack-based LL(1) parser (Q10). |
| `ShiftReducerParser.cpp` | Simulates shift-reduce parsing (Q11). |
| `SLRParsingTableConstruction.cpp` | Constructs an SLR parsing table (Q12). |
| `LR(1)ParsingTableConstruction.cpp` | Constructs LR(1) parser states/table (Q13). |
| `LALR(1)ParsingTableConstruction.cpp` | Demonstrates LALR(1) state merging (Q14). |
| `F1_parser.l` | Flex scanner for the Bison parser (Q15). |
| `F2_parser.y` | Bison grammar for syntax analysis (Q15). |

## Requirements

Install the following tools before running the programs:

- `g++` or another C++ compiler
- `gcc` for generated C files
- Flex
- Bison

On Windows, WinFlexBison can be used. After installing it, make sure `flex`, `bison`, `gcc`, and `g++` are available from the terminal.

## Running C++ Programs

Compile any `.cpp` file with `g++`, then run the generated executable.

```powershell
g++ DFA_Start01.cpp -o program.exe
.\program.exe
```

## Running a Flex File

Use this for standalone `.l` files such as `Lexer.l`.

```powershell
flex Lexer.l
gcc lex.yy.c -o lexer.exe
.\lexer.exe
```

After running the lexer, enter the input text. To finish input:

- Windows: press `Enter`, then `Ctrl + Z`, then `Enter`
- Linux/macOS: press `Ctrl + D`

## Running the Flex and Bison Parser

Use this for the parser files `F1_parser.l` and `F2_parser.y`.

```powershell
bison -d F2_parser.y
flex F1_parser.l
gcc F2_parser.tab.c lex.yy.c -o parser.exe
.\parser.exe
```

If your Bison installation generates a different output name, compile the generated `.tab.c` file shown in your folder.

## Submission Note

Generated files such as `.exe`, `lex.yy.c`, and Bison output files are ignored by `.gitignore`. The folder is intended to keep only the lab source files (`.cpp`, `.l`, `.y`) along with this README and `.gitignore`.

Student: Saugat Bikram Thapa  
Roll No./Section: 80117731/A
