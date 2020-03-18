# Binary Search Tree

Implement a Binary Search Tree template based on the starter code provided. 
BST must be able to handle different types of data. 

You must implement all the public functions in the starter code.
You can implement private functions as needed.

## Included Files

- `CMakeLists.txt`: For complex projects, `cmake CMakeLists.txt` will
  generate a `Makefile`. We can then use `make` to compile the
  project. Optional for a small project like this, but included as an
  example.

- `bst.hpp`: Definitions for Binary Search Tree (template file)

- `bsttest.cpp`: Test functions

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
./simplecompile.sh
./ass2-bst
```

or

```
cmake CmakeLists.txt
make
./ass2-bst
```

or

```
clang++ -std=c++14 -Wall -Wextra *.cpp -o ass2-bst
./ass2-bst
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

# For Professor

- Ignored clang-tidy warnings on using c-style arrays
- Ignore clang-tidy warnings on putting else if and else statements after return statements for readability purposes

## Difficulties
- Remove Function was difficult hard time figuring out the successor
- Rebalance was also difficult. Confused on how to sort