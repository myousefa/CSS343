# Movie Store

## Replace all TODO with actual information DONE

Author(s): Mohammed Ali

GitHub URL: https://github.com/uwbclass/uwb2020wi343b-movies-myousefa

Expected Mark: 95%

## Checklist

Development Platform: Visual Studio Code

Tested on CSS Linux Lab: Yes

Tested on Travis: Yes

clang-tidy messages: Too many to count (Did not have time to get through all of them).

valgrind messages: No Memory Leaks

## Command Functionality Checklist

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Done (Full)
History: Done (Full)
Borrow: Done (Full)
Return: Done (Full)

## Functionality and Where to Find Thins

State the file and function where the information can be found

invalid command code: This can be found in the TranactionFactory create function. It will check each command and will print invalid command.

invalid movie type: This can be found in the MovieFactory create function. It will check each movie and will print invalid movie type.

invalid customer ID: This can be found in the Store.cpp class. A function called verifyCustomer will check for invalid customer ID's.
 
invalid movie: The Borrow class and Return class both do this to ensure the movie is actually checked out by the Customer based on there ID. 

factory classes: Two factory classes. One for movies and the other for commands (transaction factory). 

hashtable: Used for customers. Storing them with there ID. It is also used in the Store class. 

container used for comedy movies: Used a vector that is located inside of Store.h

function for sorting comedy movies: Used a vector that is located in the Store class. The vector is called Comedy and holds the comedy movies. 

function where comedy movies are sorted: The addInvHelper function in the Store class adds into a sorted style.

functions called when retrieving a comedy movie based on title and year: In the transaction class the FindMovie function does this.

functions called for retrieving and printing customer history: In the Customer class there is a function that prints the history.

container used for customer history: Used a vector that is located in Customer.h

functions called when borrowing a movie: When a borrow command is called the Borrow class handles this. It goes into the doTransactionCommand and processes the movie. 

explain borrowing a movie that does not exist: The Borrow class handles this case. While processing the command in doTransactionCommand it tests for this and prints out that this movie does not exist. 

explain borrowing a movie that has 0 stock: The Borrow class handles this case. While processing the command in doTransactionCommand it tests for this at the end as an edge case. It prints that the movie has no stock. 

explain returning a movie that customer has not checked out: The Return class handles this case. When processing the command in doTransactionCommand it tests for this and prints out "Customer + ID did not borrow this movie."

any static_cast or dynamic_cast used: Used in operators for children of Movie class (Drama, Comedy, and Classic).


