# Compiler Design and Construction — Lab 1 & Lab 2 (Parts 1 & 2)

This folder contains C++ programs, Flex specifications, and Bison grammar files for **Compiler Design and Construction Lab 1 (Part 1)** and **Lab 2 (Part 2)**.

- **Lab 1 (Part 1) — Q1–Q15:** compiler front-end topics — finite automata (DFAs), lexical analysis, grammar transformations, FIRST/FOLLOW computation, and parser construction (top-down LL(1), shift-reduce, SLR, LR(1), LALR(1), Flex/Bison).
- **Lab 2 (Part 2) — Q16–Q26:** semantic analysis and back-end topics — symbol tables, scope management, type checking, semantic rules, intermediate code generation, code generation, and code optimization.

## Lab 1 (Part 1) — Q1 to Q15

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

## Lab 2 (Part 2) — Q16 to Q26

| File | Description |
| --- | --- |
| `SymbolTableImplementation.cpp` | Implements a symbol table (insert/search/display) (Q16). |
| `SymbolTableConstructionScopeManagement.cpp` | Symbol table construction with multi-level scope management (Q17). |
| `TypeCheckingExpression.cpp` | Type checking for expressions and assignments (Q18). |
| `SemanticRulesforControlStrctures.cpp` | Semantic rules for control structures such as `if`/`while` (Q19). |
| `IntermediateCodeGenforExpression.cpp` | Intermediate code (quadruples) for arithmetic expressions (Q20). |
| `TACGenforControlFlowStatement.cpp` | Three-address code generation for control-flow statements (Q21). |
| `IntermediateCodeGenforFunctionsParameter.cpp` | Intermediate code for function declarations, calls, and parameters (Q22). |
| `CodeGeneration.cpp` | Generates 8086-style assembly code from quadruples (Q23). |
| `ConstantFoldingnConstantPropagation.cpp` | Optimizes constant folding and constant propagation (Q24). |
| `DeadCodeElemnControlFlowGraph.cpp` | Dead-code elimination using a control-flow graph (Q25). |
| `PeepHoleOptimization.cpp` | Applies peephole optimization on generated code (Q26). |

## Requirements

Install the following tools before running the programs:

- `g++` or another C++ compiler
- `gcc` for generated C files
- Flex
- Bison

On Windows, WinFlexBison or MSYS2 can be used (this setup uses MSYS2 UCRT64). After installing, make sure `flex`, `bison`, `gcc`, and `g++` are available from the terminal.

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

> Note: the `.vscode/` folder is intentionally not committed — it contains machine-specific build/run configs (MSYS2 paths, `active_cpp_run.exe` output).

## Submission Note

Generated files such as `.exe`, `lex.yy.c`, and Bison output files are ignored by `.gitignore`. The folder is intended to keep only the lab source files (`.cpp`, `.l`, `.y`) along with this README and `.gitignore`.

Student: Saugat Bikram Thapa  
Roll No./Section: 80117731/A
