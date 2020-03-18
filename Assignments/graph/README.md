# For Grader/Professor
- Ignored some clang-format issues
    - It seemed to have some problem with my comments and some small indentation places
- Ignored 1 clang-tidy warnings as it would cause MANY changes throughout program

# Graph

Graph class with several graph algorithms including depth-first search, 
breadth-first search, dijkstra's shortest path, minimum spanning tree


## Included Files

- `CMakeLists.txt`: For complex projects, `cmake CMakeLists.txt` will
  generate a `Makefile`. We can then use `make` to compile the
  project. Optional for a small project like this, but included as an
  example.

- `graph.h, graph.cpp`: Graph class

- `graphtest.cpp`: Test functions

- `main.cpp`: A generic main file to call testAll() to run all tests

- `output.txt`: Output from `./simple.compile.sh > output.txt 2>&1`
showing how the program is compiled and run

- `simplecompile.sh`: Unix bash script file to compile, run clang-tidy
  as well as other programs and then delete the executable. Can be
  used to create an output.txt file

- `.clang-tidy`: Specify the options for clang-tidy program, so we do
  not have to enter them on the command line each time.
  Usage: `clang-tidy *.cpp -- -std=c++14`

- `.clang-format`: LLVM specification of how formatting should work. CLion
automatically detects this file and formats based on the options provided.
You can also run `clang-format main.cpp > main.cpp-better-formatted` to
see how clang-format would format your file.
  
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
./simplecompile.sh
```


## Style check
Based on options defined in `.clang-tidy`
```
clang-tidy *.cpp -- -std=c++14
```

### Style Explanation
These options are defined in `.clang-tidy` file.

If you make changes to `.clang-tidy` file, explain the reasoning below

Perform all check except the following:

- cert-err58-cpp: Using static variable which may cause throw
- cppcoreguidelines-avoid-magic-numbers: magic numbers needed for testing
- cppcoreguidelines-owning-memory: not using gsl, so assigning new owners
- cppcoreguidelines-pro-bounds-array-to-pointer-decay: do not give warnings on assert
- cppcoreguidelines-pro-bounds-constant-array-index: array index not constant
- cppcoreguidelines-pro-bounds-pointer-arithmetic: need to use array indexes
- cppcoreguidelines-special-member-functions: no move constructor or move assignment for now
- fuchsia-*: Checks specific to fuschia system
- google-build-using-namespace: for simplicity allow `using namespace std;`
- google-global-names-in-headers: OK to say `using namespace std;` for class code
- google-readability-braces-around-statements: allow compact code without `{`
- hicpp-braces-around-statements: want compact code
- hicpp-no-array-decay: allow assert
- hicpp-special-member-functions: no move constructor or move assignment for now
- llvm-header-guard: header guards do not have full directory name
- modernize-pass-by-value: Not using move for objects
- modernize-use-trailing-return-type: not ready for auto func() -> int format yet
- readability-braces-around-statements: allow compact code without `{` (this option
9.0.0) is not available in CSS Linux lab under LLVM 3.8.1, but is needed on my PC when using
- readability-magic-numbers: needed for testing



