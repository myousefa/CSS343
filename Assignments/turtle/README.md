# turtleprogram

Turtle Graphics as part of [Logo](https://en.wikipedia.org/wiki/Logo_(programming_language) 
was one of the first languages explicitly designed for teaching beginning programming.

A Turtle Program is a set of instructions directing the on-screen turtle to draw graphics. 
To draw a square, one would execute:
```
Forward 10 Right 90 Forward 10 Right 90 Forward 10 Right 90 Forward 10 Right 90
```

Other commands, such as PENUP, PENDOWN, PENCOLOR, etc, 
as well as conditionals and looping operators were later added to the language.

There should be no warnings when compiled with `-Wall -Wextra -Wno-sign-compare`
`clang-tidy turtleprogram.cpp -- -std=c++14` should not give any warnings. 
You can modify `.clang-tidy` as long as each modification is explained in README.md
(and you do not disable all checks)
`valgrind ./turtleprogram` should not have any `definitely lost` bytes. You might
still have `indirectly lost`, `possibly lost` or `still reachable` bytes due
to libraries used.
 

## Included Files

- `CMakeLists.txt`: For complex projects, `cmake CMakeLists.txt` will
  generate a `Makefile`. We can then use `make` to compile the
  project. Optional for a small project like this, but included as an
  example.

- `turtleprogram.cpp`: Definitions for turtle functions

- `turtleprogramtest.cpp`: Test functions to test turtle

- `main.cpp`: A generic main file to call testAll() to run all tests

- `output.txt`: Output from `./simple.compile.sh > output.txt 2>&1`
showing how the program is compiled and run

- `simplecompile.sh`: Unix bash script file to compile, run clang-tidy
  as well as other programs and then delete the executable. Can be
  used to create an output.txt file

- `.clang-tidy`: Specify the options for clang-tidy program, so we do
  not have to enter them on the command line each time.
  Usage: `clang-tidy *.cpp -- -std=c++14`

- `.gitattributes`: Options for git. Making sure that simplecompile.sh
  always has the correct line endings when moving between Windows and
  unix systems

- `.gitignore`: Files that should not be checked into git. Mostly ide
  files and executables.

- `.travis.yml`: When GitHub is configured correctly, checking the
  project into GitHub should trigger Travis CI to compile and run the
  program.

## Compile and Run

```
cmake CmakeLists.txt
make
./ass1-turtleprogram
```

or

```
clang++ -std=c++14 -Wall -Wextra *.cpp -o ass1-turtleprogram
./ass1-turtleprogram
```

## Style check

```
clang-tidy *.cpp -- -std=c++14
```

### Style Explanation
These options are defined in `.clang-tidy` file.

Perform all check except the following:

- cppcoreguidelines-pro-bounds-array-to-pointer-decay: do not give warnings on assert
- google-build-using-namespace: for simplicity allow `using namespace std;`
- google-readability-braces-around-statements: allow compact code without `{`
- readability-braces-around-statements: allow compact code without `{` (this option
is not available in CSS Linux lab under LLVM 3.8.1, but is needed on my PC when using
9.0.0)
- hicpp-no-array-decay: allow assert
- modernize-use-trailing-return-type: not ready for auto func() -> int format yet
- hicpp-braces-around-statements: want compact code
- cppcoreguidelines-pro-bounds-pointer-arithmetic: need to use array indexes
- llvm-header-guard: header guards do not have full directory name
- google-global-names-in-headers: OK to say `using namespace std;` for class code
- cppcoreguidelines-special-member-functions: no move constructor or move assignment for now
- hicpp-special-member-functions: no move constructor or move assignment for now
- cppcoreguidelines-owning-memory: not using gsl, so assigning new owners



Based on LLVM style in https://llvm.org/docs/CodingStandards.html#the-low-level-issues

```
CheckOptions:
 - { key: readability-identifier-naming.ClassCase,           value: CamelCase  }
 - { key: readability-identifier-naming.StructCase,          value: CamelCase  }
 - { key: readability-identifier-naming.EnumCase,            value: CamelCase  }
 - { key: readability-identifier-naming.VariableCase,        value: CamelCase  }
 - { key: readability-identifier-naming.GlobalConstantCase,  value: UPPER_CASE }
 - { key: readability-identifier-naming.FunctionCase,        value: camelBack  }
 - { key: readability-identifier-naming.PublicMethodCase,    value: camelBack  }
 - { key: readability-identifier-naming.PrivateMethodCase,   value: camelBack  }
 - { key: readability-identifier-naming.PublicMemberCase,    value: CamelCase  } 
```

## Hints

- Do not push your `.vs` directory to GitHub. Visual Studio
creates this directory to store cached files. Storing it in GitHub will
waste space and time.

- Do not push your executable to GitHub. You don't need a version controlled
executable

- Pay attention to clang-format suggestions: You should not have `int I=0;`
It should be `int I = 0;`. You should not have `if(Num==10)` It should be
`if (Num == 10)`

## Misc

This files is part of a repository located at
https://github.com/pisan343/ass1-turtleprogram BUT most students will use it as
the starting code for GitHub Classroom exercise

When using via GitHub Classroom, the Travis CI output will be at

https://travis-ci.com/uwbclass/ass1-turtleprogram-GitHubUserName
