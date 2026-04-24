# CSE220_HW7
/*
    Name: Brian Chau
    SBU ID: 116125954
*/

My functions follow the assignment specifications. The readme will only write down specific things about the implementation that
are not specificed.

error handling
- Although error handling is not needed, meaning you don't check the input, there is error handling for memory allocation
- After every malloc and calloc, the pointer is checked in order to make sure memory allocation works. 
- If memory allocation failed, the function will immediately exit. For all functions but insert_bst_sf, null is returned
- Any function that calls a function which uses malloc, checks to see if the memory allocation succceeded. If it fails,
then the function will immediately halt, free all memory it alllocated and then return NULL as well.

In general
- Since functions in ctype.h were designed to be used with unsigned chars, all chars are typecasted to unsigned before being passed in as arguments to these functions. 

insert_bst_sf
- Important thing to note is that if malloc fails, then the function will return root. 
- Null is not returned as the tree will still exist, the matrix just won't be added.

find_bst_sf
- If root is NULL, the function will automatically return NULL

free_bst_sf
- The function uses recursion with the base case being when root is null.
- Otherwise, it will free all of its elements then free itself.

add_mat_sf
- It does have a dimension check. This is not necessary but is simply kept in because it was made before I confirmed that error handling was not necessary for the helper functions.

mult_mat_sf
- It does have a dimension check. This is not necessary but is simply kept in because it was made before I confirmed that error handling was not necessary for the helper functions.

transpose_mat_sf
- Note, that for add, mult and transpose_mat_sf, they uses array notation to access the values matrix.

create_matrix_sf
- To convert the numbers in the expr to ints and unsigned ints, the function uses strtoul and strtol then type casts them to unsigned int and int as needed.

-infix2postfix_sf
- Note that the function uses isspace to determine a space character. This means that the function will also go over tabs, newlines and some others.
- The stack uses operationIndex to figure out what the top of the stack is. If operationIndex = -1, it means the stack is empty.

evaluate_expr_sf
- Whenever the function terminates, it uses the helper function clearStack to deallocate any intermediate arrays.
-Intermediate arrays are denoted with a name '?'.

execute_script_sf
- The function uses getline to read each line. 
- Rather than using EOF, the loop checks for -1
- The result will always store the last computed matrix
- Rather than returning the result, it is copied as result will be freed by free_bst_sf as it is in the tree.

Although the scripts are guarenteed to be semantically valid, my code still has error handling for malloc and calloc.
Specifically, it checks when memory allocation has failed and if it has it returns null. Because of this, there are several
null checks throughout my code to check for failure. When they detect null due to memory allocation failure, the function
immediately halts, frees memory it was using, then return null.

Test Case Structure
My test cases follow the same structure as the unit test cases, not as recommended in Piazza. This is because to check the output
with valgrind, I would have to include what is returned in valgrind. The problem is that this can change from computer to computer,
due to different sizes for certain types. As a result, even if the code worked and returned the right output, I would still get an
error due to valgrind writing down different stuff in its memcheck. Therefore, I have opt'ed to follow the format of the unit test 
cases. 

-Just like the unit_tests.c the bst is not freed for the insert, find_bst functions as well as evaluate_expr. This is because free_bst is not yet tested
  -If free_bst was erroneous, this would cause the insert_bst and find_bst functions as well as evaluate_expr to fail which could be a false positive if insert and find actually worked.

There are some diffences in my test cases compared to the unit_tests
-For evaluate_expr_sf's tests, student_tests also checks the name of the returned matrix. This is to ensure that 
everything is propery set, including the name of the matrix, not just it content.

- infix2postfix and create_matrix test cases free their result after the test ends in student_tests. This is to ensure that no memory 
leaks as the tests go on. 
  - These do not affect the final result as the free happens after test is completed

