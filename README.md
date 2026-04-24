# CSE220_HW7
/*
    Name: Brian Chau
    SBU ID: 116125954
*/

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

-Just like the unit_tests.c the bst is not freed for the insert and find_bst functions. This is because free_bst is not yet tested
  -If free_bst was erroneous, this would cause the insert_bst and find_bst functions to fail which could be a false positive if insert and find actually worked.

There are some diffences in my test cases compared to the unit_tests
-For evaluate_expr_sf's tests, student_tests also checks the name of the returned matrix. This is to ensure that 
everything is propery set, including the name of the matrix, not just it content.

- infix2postfix, evaluate_expr and create_matrix test cases free their result after the test ends in student_tests. This is to ensure that no memory 
leaks as the tests go on. 
  - These do not affect the final result as the free happens after test is completed

