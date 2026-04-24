/*
    Name: Brian Chau
    SBU ID: 116125954
*/

#include "unit_tests.h"
#include "hw7.h"

TestSuite(operators_test, .timeout=TEST_TIMEOUT, .disabled=false); // return value of add, mult, transpose
TestSuite(operators_valgrind, .timeout=TEST_TIMEOUT, .disabled=false); 

TestSuite(insert_bst_test, .timeout=TEST_TIMEOUT, .disabled=false); // test insert_bst_sf for correct BST update
TestSuite(find_bst_test, .timeout=TEST_TIMEOUT, .disabled=false);
TestSuite(free_bst_test, .timeout=TEST_TIMEOUT, .disabled=false);

TestSuite(create_matrix_test, .timeout=TEST_TIMEOUT, .disabled=false);
TestSuite(infix2postfix_test, .timeout=TEST_TIMEOUT, .disabled=false);
TestSuite(evaluate_expr_test, .timeout=TEST_TIMEOUT, .disabled=false);

TestSuite(execute_test, .timeout=TEST_TIMEOUT, .disabled=false);
TestSuite(execute_test_valgrind, .timeout=TEST_TIMEOUT, .disabled=false);

/*Matrix operations (addition,multiplication, transpose) tests*/
Test(operators_test, add01, .description="Add 2 1x1 matrices") {
    matrix_sf *A = copy_matrix(1, 1, (int[]){-4});
    matrix_sf *B = copy_matrix(1, 1, (int[]){10});
    matrix_sf *C = add_mats_sf(A, B);
    expect_matrices_equal(C, 1, 1, (int[]){6});
    free(A);
    free(B);
    free(C);
} 
Test(operators_valgrind, add01) { expect_no_valgrind_errors(run_with_valgrind("student_add01")); }

Test(operators_test, add02, .description="Add 2 3x3 zero matrices") {
    matrix_sf *A = copy_matrix(3, 3, (int[]){0,0,0,0,0,0,0,0,0});
    matrix_sf *B = copy_matrix(3, 3, (int[]){0,0,0,0,0,0,0,0,0});
    matrix_sf *C = add_mats_sf(A, B);
    expect_matrices_equal(C, 3, 3, (int[]){0,0,0,0,0,0,0,0,0});
    free(A);
    free(B);
    free(C);
} 
Test(operators_valgrind, add02) { expect_no_valgrind_errors(run_with_valgrind("student_add02")); }

Test(operators_test, add03, .description="Add 2 4x3 matrices") {
    matrix_sf *A = copy_matrix(4, 3, (int[]){1,2,3,4,5,6,7,8,9,10,11,12});
    matrix_sf *B = copy_matrix(4, 3, (int[]){1,2,3,4,5,6,7,8,9,10,11,12});
    matrix_sf *C = add_mats_sf(A, B);
    expect_matrices_equal(C, 4, 3, (int[]){2,4,6,8,10,12,14,16,18,20,22,24});
    free(A);
    free(B);
    free(C);
} 
Test(operators_valgrind, add03) { expect_no_valgrind_errors(run_with_valgrind("student_add03")); }

Test(operators_test, add04, .description="Add 2 5x5 Identity matrices") {
    matrix_sf *A = copy_matrix(5, 5, (int[]){1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0});
    matrix_sf *B = copy_matrix(5, 5, (int[]){1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0});
    matrix_sf *C = add_mats_sf(A, B);
    expect_matrices_equal(C, 5, 5, (int[]){2,0,0,0,0,2,0,0,0,0,2,0,0,0,0,2,0,0,0,0,2,0,0,0,0});
    free(A);
    free(B);
    free(C);
} 
Test(operators_valgrind, add04) { expect_no_valgrind_errors(run_with_valgrind("student_add04")); }

Test(operators_test, add05, .description="Add 2 5x5 matrices which are negations of each other") {
    matrix_sf *A = copy_matrix(5, 5, (int[]){1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5});
    matrix_sf *B = copy_matrix(5, 5, (int[]){-1,-2,-3,-4,-5,-1,-2,-3,-4,-5,-1,-2,-3,-4,-5,-1,-2,-3,-4,-5,-1,-2,-3,-4,-5});
    matrix_sf *C = add_mats_sf(A, B);
    expect_matrices_equal(C, 5, 5, (int[]){0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    free(A);
    free(B);
    free(C);
} 
Test(operators_valgrind, add05) { expect_no_valgrind_errors(run_with_valgrind("student_add05")); }

Test(operators_test, add06, .description="Add 2 4x3 matrices to test communative property") {
    matrix_sf *A = copy_matrix(4, 3, (int[]){1,2,3,4,5,6,7,8,9,10,11,12});
    matrix_sf *B = copy_matrix(4, 3, (int[]){1,2,3,4,5,6,7,8,9,10,11,12});
    matrix_sf *C = add_mats_sf(A, B);
    expect_matrices_equal(C, 4, 3, (int[]){2,4,6,8,10,12,14,16,18,20,22,24});
    free(C);
    C = add_mats_sf(B, A);
    expect_matrices_equal(C, 4, 3, (int[]){2,4,6,8,10,12,14,16,18,20,22,24});
    free(A);
    free(B);
    free(C);
} 
Test(operators_valgrind, add06) { expect_no_valgrind_errors(run_with_valgrind("student_add06")); }

Test(operators_test, add07, .description="Add 2 row matrices") {
    matrix_sf *A = copy_matrix(1, 3, (int[]){1,2,3});
    matrix_sf *B = copy_matrix(1, 3, (int[]){1,2,3});
    matrix_sf *C = add_mats_sf(A, B);
    expect_matrices_equal(C, 1, 3, (int[]){2,4,6});
    free(A);
    free(B);
    free(C);
} 
Test(operators_valgrind, add07) { expect_no_valgrind_errors(run_with_valgrind("student_add07")); }

Test(operators_test, add08, .description="Add 2 column matrices") {
    matrix_sf *A = copy_matrix(3, 1, (int[]){1,2,3});
    matrix_sf *B = copy_matrix(3, 1, (int[]){1,2,3});
    matrix_sf *C = add_mats_sf(A, B);
    expect_matrices_equal(C, 3, 1, (int[]){2,4,6});
    free(A);
    free(B);
    free(C);
} 
Test(operators_valgrind, add08) { expect_no_valgrind_errors(run_with_valgrind("student_add08")); }

Test(operators_test, add09, .description="Add 3 different 3x3 matrices") {
    matrix_sf *A = copy_matrix(3, 3, (int[]){1,2,3,4,5,6,7,8,9});
    matrix_sf *B = copy_matrix(3, 3, (int[]){1,2,3,4,5,6,7,8,9});
    matrix_sf *C = copy_matrix(3, 3, (int[]){2,3,4,5,6,7,8,9,10});
    matrix_sf *D = add_mats_sf(A,B);
    matrix_sf *store = D;
    D = add_mats_sf(C,D);
    expect_matrices_equal(D, 3, 3, (int[]){4,7,10,13,16,19,22,25,28});
    free(A);
    free(B);
    free(C);
    free(D);
    free(store);
} 
Test(operators_valgrind, add09) { expect_no_valgrind_errors(run_with_valgrind("student_add09")); }

Test(operators_test, add10, .description="Add 3 different 3x3 matrices to test the associative property") {
    matrix_sf *A = copy_matrix(3, 3, (int[]){1,2,3,4,5,6,7,8,9});
    matrix_sf *B = copy_matrix(3, 3, (int[]){1,2,3,4,5,6,7,8,9});
    matrix_sf *C = copy_matrix(3, 3, (int[]){2,3,4,5,6,7,8,9,10});
    matrix_sf *D = add_mats_sf(A,C);
    matrix_sf *store = D;
    D = add_mats_sf(D,B);
    expect_matrices_equal(D, 3, 3, (int[]){4,7,10,13,16,19,22,25,28});
    free(A);
    free(B);
    free(C);
    free(D);
    free(store);
} 
Test(operators_valgrind, add10) { expect_no_valgrind_errors(run_with_valgrind("student_add10")); }

Test(operators_test, mult01, .description="Multiply 2 Identity matrices") {
    matrix_sf *G = copy_matrix(4, 4, (int[]){1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0});
    matrix_sf *D = copy_matrix(4, 4, (int[]){1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0});
    matrix_sf *Z = mult_mats_sf(G, D);
    expect_matrices_equal(Z, 4, 4, (int[]){1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0});
    free(G);
    free(D);
    free(Z);
}
Test(operators_valgrind, mult01) { expect_no_valgrind_errors(run_with_valgrind("student_mult01")); }

Test(operators_test, mult02, .description="Multiply 2 Reciprocal matrices") {
    matrix_sf *G = copy_matrix(2, 2, (int[]){1,1,0,1});
    matrix_sf *D = copy_matrix(2, 2, (int[]){1,-1,0,1});
    matrix_sf *Z = mult_mats_sf(G, D);
    expect_matrices_equal(Z, 2, 2, (int[]){1,0,0,1});
    free(G);
    free(D);
    free(Z);
}
Test(operators_valgrind, mult02) { expect_no_valgrind_errors(run_with_valgrind("student_mult02")); }

Test(operators_test, mult03, .description="Test the other way around") {
    matrix_sf *G = copy_matrix(2, 2, (int[]){1,1,0,1});
    matrix_sf *D = copy_matrix(2, 2, (int[]){1,-1,0,1});
    matrix_sf *Z = mult_mats_sf(D, G);
    expect_matrices_equal(Z, 2, 2, (int[]){1,0,0,1});
    free(G);
    free(D);
    free(Z);
}
Test(operators_valgrind, mult03) { expect_no_valgrind_errors(run_with_valgrind("student_mult03")); }

Test(operators_test, mult04, .description="Mulitply two larger rectangular matrices") {
    matrix_sf *G = copy_matrix(5, 4, (int[]){1,2,3,4,5,6,7,8,9,-1,-2,-3,-4,-5,-6,-7,-8,-9,0,2});
    matrix_sf *D = copy_matrix(4, 5, (int[]){-1,-2,-3,-4,-5,-6,-7,-8,-9,1,2,3,4,5,6,7,8,9,0,-2});
    matrix_sf *Z = mult_mats_sf(G, D);
    expect_matrices_equal(Z, 5, 5, (int[]){21,25,29,-7,7,29,33,37,-39,7,-28,-41,-54,-37,-52,-27,-31,-35,31,-7,76,95,114,113,27});
    free(G);
    free(D);
    free(Z);
}
Test(operators_valgrind, mult04) { expect_no_valgrind_errors(run_with_valgrind("student_mult04")); }

Test(operators_test, mult05, .description="Test smaller rectangular matrix") {
    matrix_sf *G = copy_matrix(3, 4, (int[]){1,2,3,4,5,6,7,8,9,-1,-2,-3});
    matrix_sf *D = copy_matrix(4, 3, (int[]){-1,-2,-3,-4,-5,-6,-7,-8,-9,1,2,3});
    matrix_sf *Z = mult_mats_sf(G, D);
    expect_matrices_equal(Z, 3, 3, (int[]){-26,-28,-30,-70,-80,-90,6,-3,-12});
    free(G);
    free(D);
    free(Z);
}
Test(operators_valgrind, mult05) { expect_no_valgrind_errors(run_with_valgrind("student_mult05")); }

Test(operators_test, mult06, .description="Test smaller rectangular matrix with different outer dimensions") {
    matrix_sf *G = copy_matrix(5, 4, (int[]){1,2,3,4,5,6,7,8,9,-1,-2,-3,-4,-5,-6,-7,-8,-9,0,2});
    matrix_sf *D = copy_matrix(4, 3, (int[]){-1,-2,-3,-4,-5,-6,-7,-8,-9,1,2,3});
    matrix_sf *Z = mult_mats_sf(G, D);
    expect_matrices_equal(Z, 5, 3, (int[]){-26,-28,-30,-70,-80,-90,6,-3,-12,59,67,75,46,65,84});
    free(G);
    free(D);
    free(Z);
}
Test(operators_valgrind, mult06) { expect_no_valgrind_errors(run_with_valgrind("student_mult06")); }

Test(operators_test, mult07, .description="Mulitply row and column vector") {
    matrix_sf *G = copy_matrix(3, 1, (int[]){1,2,3});
    matrix_sf *D = copy_matrix(1, 3, (int[]){-1,-2,-3});
    matrix_sf *Z = mult_mats_sf(G, D);
    expect_matrices_equal(Z, 3, 3, (int[]){-1,-2,-3,-2,-4,-6,-3,-6,-9});
    free(G);
    free(D);
    free(Z);
}
Test(operators_valgrind, mult07) { expect_no_valgrind_errors(run_with_valgrind("student_mult07")); }

Test(operators_test, mult08, .description="Mulitply row and column vector again but with swapped order") {
    matrix_sf *G = copy_matrix(1, 3, (int[]){1,2,3});
    matrix_sf *D = copy_matrix(3, 1, (int[]){-1,-2,-3});
    matrix_sf *Z = mult_mats_sf(G, D);
    expect_matrices_equal(Z, 1, 1, (int[]){-14});
    free(G);
    free(D);
    free(Z);
}
Test(operators_valgrind, mult08) { expect_no_valgrind_errors(run_with_valgrind("student_mult08")); }

Test(operators_test, mult09, .description="Mulitply three matrices") {
    matrix_sf *G = copy_matrix(3, 4, (int[]){1,2,3,4,5,6,7,8,9,-1,-2,-3});
    matrix_sf *D = copy_matrix(4, 3, (int[]){-1,-2,-3,-4,-5,-6,-7,-8,-9,1,2,3});
    matrix_sf *Z = mult_mats_sf(G, D);
    matrix_sf *F = copy_matrix(3,2, (int[]){1,2,3,4,5,6});
    matrix_sf *H = mult_mats_sf(Z, F);
    expect_matrices_equal(H, 3, 2, (int[]){-260,-344,-760,-1000,-63,-72});
    free(G);
    free(D);
    free(Z);
    free(F);
    free(H);
}
Test(operators_valgrind, mult09) { expect_no_valgrind_errors(run_with_valgrind("student_mult09")); }

Test(operators_test, mult10, .description="Mulitply zero matrices") {
    matrix_sf *G = copy_matrix(2, 2, (int[]){0,0,0,0});
    matrix_sf *D = copy_matrix(2, 2, (int[]){0,0,0,0});
    matrix_sf *Z = mult_mats_sf(G, D);
    expect_matrices_equal(Z, 2, 2, (int[]){0,0,0,0});
    free(G);
    free(D);
    free(Z);
}
Test(operators_valgrind, mult10) { expect_no_valgrind_errors(run_with_valgrind("student_mult10")); }

Test(operators_test, trans01, .description="Transpose a 1x1 matrix") {
    matrix_sf *M = copy_matrix(1, 1, (int[]){-7});
    matrix_sf *G = transpose_mat_sf(M);
    expect_matrices_equal(G, 1, 1, (int[]){-7});
    free(M);
    free(G);
}
Test(operators_valgrind, trans01) { expect_no_valgrind_errors(run_with_valgrind("student_trans01")); }

Test(operators_test, trans02, .description="Transpose a row matrix") {
    matrix_sf *M = copy_matrix(1, 3, (int[]){-7,1,2});
    matrix_sf *G = transpose_mat_sf(M);
    expect_matrices_equal(G, 3, 1, (int[]){-7,1,2});
    free(M);
    free(G);
}
Test(operators_valgrind, trans02) { expect_no_valgrind_errors(run_with_valgrind("student_trans02")); }

Test(operators_test, trans03, .description="Transpose a column matrix") {
    matrix_sf *M = copy_matrix(4, 1, (int[]){-7,1,2,4});
    matrix_sf *G = transpose_mat_sf(M);
    expect_matrices_equal(G, 1, 4, (int[]){-7,1,2,4});
    free(M);
    free(G);
}
Test(operators_valgrind, trans03) { expect_no_valgrind_errors(run_with_valgrind("student_trans03")); }

Test(operators_test, trans04, .description="Transpose a 2x4 matrix") {
    matrix_sf *M = copy_matrix(2, 4, (int[]){1,2,3,4,5,6,7,8});
    matrix_sf *G = transpose_mat_sf(M);
    expect_matrices_equal(G, 4, 2, (int[]){1,5,2,6,3,7,4,8});
    free(M);
    free(G);
}
Test(operators_valgrind, trans04) { expect_no_valgrind_errors(run_with_valgrind("student_trans04")); }

Test(operators_test, trans05, .description="Transpose a diagonal matrix") {
    matrix_sf *M = copy_matrix(3, 3, (int[]){1,0,0,0,2,0,0,0,3});
    matrix_sf *G = transpose_mat_sf(M);
    expect_matrices_equal(G, 3, 3, (int[]){1,0,0,0,2,0,0,0,3});
    free(M);
    free(G);
}
Test(operators_valgrind, trans05) { expect_no_valgrind_errors(run_with_valgrind("student_trans05")); }

Test(operators_test, trans06, .description="Transpose a matrix twice") {
    matrix_sf *M = copy_matrix(2, 4, (int[]){1,2,3,4,5,6,7,8});
    matrix_sf *G = transpose_mat_sf(M);
    matrix_sf *Z = transpose_mat_sf(G);
    expect_matrices_equal(Z, 2, 4, (int[]){1,2,3,4,5,6,7,8});
    free(M);
    free(G);
    free(Z);
}
Test(operators_valgrind, trans06) { expect_no_valgrind_errors(run_with_valgrind("student_trans06")); }

Test(operators_test, trans07, .description="Transpose a matrix with only elements on the anti-diagonal") {
    matrix_sf *M = copy_matrix(3, 3, (int[]){0,0,1,0,2,0,3,0,0});
    matrix_sf *G = transpose_mat_sf(M);
    expect_matrices_equal(G, 3, 3, (int[]){0,0,3,0,2,0,1,0,0});
    free(M);
    free(G);
}
Test(operators_valgrind, trans07) { expect_no_valgrind_errors(run_with_valgrind("student_trans07")); }

Test(operators_test, trans08, .description="Transpose a zero matrix") {
    matrix_sf *M = copy_matrix(3, 3, (int[]){0,0,0,0,0,0,0,0,0});
    matrix_sf *G = transpose_mat_sf(M);
    expect_matrices_equal(G, 3, 3, (int[]){0,0,0,0,0,0,0,0,0});
    free(M);
    free(G);
}
Test(operators_valgrind, trans08) { expect_no_valgrind_errors(run_with_valgrind("student_trans08")); }

Test(operators_test, trans09, .description="Transpose a rectangular matrix") {
    matrix_sf *M = copy_matrix(5, 3, (int[]){1,2,3,4,5,6,7,8,9,0,1,2,3,4,5});
    matrix_sf *G = transpose_mat_sf(M);
    expect_matrices_equal(G, 3, 5, (int[]){1,4,7,0,3,2,5,8,1,4,3,6,9,2,5});
    free(M);
    free(G);
}
Test(operators_valgrind, trans09) { expect_no_valgrind_errors(run_with_valgrind("student_trans09")); }

Test(operators_test, trans10, .description="Transpose a rectangular matrix twice") {
    matrix_sf *M = copy_matrix(5, 3, (int[]){1,2,3,4,5,6,7,8,9,0,1,2,3,4,5});
    matrix_sf *G = transpose_mat_sf(M);
    matrix_sf *Z = transpose_mat_sf(G);
    expect_matrices_equal(Z, 5, 3, (int[]){1,2,3,4,5,6,7,8,9,0,1,2,3,4,5});
    free(M);
    free(G);
    free(Z);
}
Test(operators_valgrind, trans10) { expect_no_valgrind_errors(run_with_valgrind("student_trans10")); }

/*Insert bst tests*/
Test(insert_bst_test, insert_bst01, .description="Test if insert_bst_sf creates one node tree.") {
    bst_sf *root = NULL;
    char names[] = "H";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.    
}

Test(insert_bst_test, insert_bst02, .description="Test if insert_bst_sf creates largestTree.") {
    bst_sf *root = NULL;
    char names[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.    
}

Test(insert_bst_test, insert_bst03, .description="Test if insert_bst_sf can sort characters in reverse order.") {
    bst_sf *root = NULL;
    char names[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.    
}


Test(insert_bst_test, insert_bst04, .description="Test if insert_bst_sf can sort characters in random order.") {
    bst_sf *root = NULL;
    char names[] = "QMJIFEWYPNOZGDVTLCHKSBUARX";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.    
}


Test(insert_bst_test, insert_bst05, .description="Test if insert_bst_sf can sort characters in a different random order.") {
    bst_sf *root = NULL;
    char names[] = "ZTUSFWBNPDJYQXRVAMCKHLEOIG";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.    
}


Test(insert_bst_test, insert_bst06, .description="Test if insert_bst_sf can sort characters in a different random order with only half.") {
    bst_sf *root = NULL;
    char names[] = "UJNBFGODMRLIT";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.    
}

Test(insert_bst_test, insert_bst07, .description="Test if insert_bst_sf can sort characters in a different random order with only half.") {
    bst_sf *root = NULL;
    char names[] = "ERLJFAPQBUHXC";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.    
}

Test(insert_bst_test, insert_bst08, .description="Test if insert_bst_sf can sort characters with it partially sorted.") {
    bst_sf *root = NULL;
    char names[] = "ABCDEFOPTSJVMQIUNZRHXGKWLY";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.    
}

Test(insert_bst_test, insert_bst09, .description="Test if insert_bst_sf can sort characters with it partially sorted.") {
    bst_sf *root = NULL;
    char names[] = "ABCDEFOWULQNTIPHGMRJKSVXYZ";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.    
}


Test(insert_bst_test, insert_bst10, .description="Test if insert_bst_sf can sort string of length 4.") {
    bst_sf *root = NULL;
    char names[] = "DRFE";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.    
}

// Search bst tests
Test(find_bst_test, search_bst01, .description="Test if find_bst returns the correct matrix for smallest possible tree.") {
    bst_sf *root = NULL;
    char names[] = "B";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char *search_names = "B";
    matrix_sf *mat;
    for (size_t i = 0; i < strlen(search_names); i++) {
        mat = find_bst_sf(search_names[i], root);
        cr_expect_eq(mat->name, search_names[i], 
            "The returned matrix did not have the expected name. Actual: %c, Expected: %c", mat->name, search_names[i]);
    } 
    
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.  
}

Test(find_bst_test, search_bst02, .description="Test if find_bst returns the correct matrix for largest possible tree.") {
    bst_sf *root = NULL;
    char names[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char *search_names = "XFG";
    matrix_sf *mat;
    for (size_t i = 0; i < strlen(search_names); i++) {
        mat = find_bst_sf(search_names[i], root);
        cr_expect_eq(mat->name, search_names[i], 
            "The returned matrix did not have the expected name. Actual: %c, Expected: %c", mat->name, search_names[i]);
    } 
    
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.  
}

Test(find_bst_test, search_bst03, .description="Test if find_bst returns the correct matrix for getting all nodes in a largest possible tree.") {
    bst_sf *root = NULL;
    char names[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char *search_names = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    matrix_sf *mat;
    for (size_t i = 0; i < strlen(search_names); i++) {
        mat = find_bst_sf(search_names[i], root);
        cr_expect_eq(mat->name, search_names[i], 
            "The returned matrix did not have the expected name. Actual: %c, Expected: %c", mat->name, search_names[i]);
    } 
    
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.  
}

Test(find_bst_test, search_bst04, .description="Test if find_bst returns the null since no search names will be in tree.") {
    bst_sf *root = NULL;
    char names[] = "ABC";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char *search_names = "XYZ";
    matrix_sf *mat;
    for (size_t i = 0; i < strlen(search_names); i++) {
        mat = find_bst_sf(search_names[i], root);
        cr_expect_eq(mat, NULL, "The return value should have been NULL, but it was %p", mat);
    } 
    
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.  
}

Test(find_bst_test, search_bst05, .description="Test if find_bst returns the correct matrix for a tree.") {
    bst_sf *root = NULL;
    char names[] = "ERLJFAPQBUHXC";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char *search_names = "JFCX";
    matrix_sf *mat;
    for (size_t i = 0; i < strlen(search_names); i++) {
        mat = find_bst_sf(search_names[i], root);
        cr_expect_eq(mat->name, search_names[i], 
            "The returned matrix did not have the expected name. Actual: %c, Expected: %c", mat->name, search_names[i]);
    } 
    
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.  
}

Test(find_bst_test, search_bst06, .description="Test if find_bst returns the correct matrix for a tree, some of the search matrices are not present.") {
    bst_sf *root = NULL;
    char names[] = "ERLJFAPQBUHXC";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char *search_names = "JFCXYD";
    matrix_sf *mat;
    for (size_t i = 0; i < strlen(search_names); i++) {
        mat = find_bst_sf(search_names[i], root);
        if (search_names[i] == 'Y' || search_names[i] == 'D')
            cr_expect_eq(mat, NULL, "The return value should have been NULL, but it was %p", mat);
        else{
            cr_expect_eq(mat->name, search_names[i], 
                "The returned matrix did not have the expected name. Actual: %c, Expected: %c", mat->name, search_names[i]);
        }
    } 
    
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.  
}

Test(find_bst_test, search_bst07, .description="Test if find_bst returns null if a null tree is passed in.") {
    bst_sf *root = NULL;
    char names[] = "";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char *search_names = "JFCXYD";
    matrix_sf *mat;
    for (size_t i = 0; i < strlen(search_names); i++) {
        mat = find_bst_sf(search_names[i], root);
        cr_expect_eq(mat, NULL, "The return value should have been NULL, but it was %p", mat);
    } 
    
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.  
}

Test(find_bst_test, search_bst08, .description="Testing when only one search term is present.") {
    bst_sf *root = NULL;
    char names[] = "A";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char *search_names = "ABCDEFGHIJ";
    matrix_sf *mat;
    for (size_t i = 0; i < strlen(search_names); i++) {
        mat = find_bst_sf(search_names[i], root);
        if (search_names[i] == 'A')
            cr_expect_eq(mat->name, search_names[i], 
                    "The returned matrix did not have the expected name. Actual: %c, Expected: %c", mat->name, search_names[i]);
        else{
            cr_expect_eq(mat, NULL, "The return value should have been NULL, but it was %p", mat);
        }
    } 
    
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.  
}

Test(find_bst_test, search_bst09, .description="Testing on a tree with a random patter.") {
    bst_sf *root = NULL;
    char names[] = "MUHKWVJRLSTQPNGOI";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char *search_names = "QPNGOI";
    matrix_sf *mat;
    for (size_t i = 0; i < strlen(search_names); i++) {
        mat = find_bst_sf(search_names[i], root);
        cr_expect_eq(mat->name, search_names[i], 
            "The returned matrix did not have the expected name. Actual: %c, Expected: %c", mat->name, search_names[i]);
    
    } 
    
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.  
}

Test(find_bst_test, search_bst10, .description="Repeatdly search the same term.") {
    bst_sf *root = NULL;
    char names[] = "NHWLKOQIVMJTSUGRP";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char *search_names = "WLKQIGGVMGG";
    matrix_sf *mat;
    for (size_t i = 0; i < strlen(search_names); i++) {
        mat = find_bst_sf(search_names[i], root);
        cr_expect_eq(mat->name, search_names[i], 
            "The returned matrix did not have the expected name. Actual: %c, Expected: %c", mat->name, search_names[i]);
    
    } 
    
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    // Note: test does not deallocate memory of BST.  
}

/*free_bst tests*/
Test(free_bst_test, free_bst01, .description="Free smallest possible tree.") {
    expect_no_valgrind_errors(run_with_valgrind("student_free01"));
}

Test(free_bst_test, free_bst02, .description="Free largest possible tree made in alphabetical order.") {
    expect_no_valgrind_errors(run_with_valgrind("student_free02"));
}

Test(free_bst_test, free_bst03, .description="Free largest possible tree made in reverse order.") {
    expect_no_valgrind_errors(run_with_valgrind("student_free03"));
}

Test(free_bst_test, free_bst04, .description="Free largest possible tree made in random order.") {
    expect_no_valgrind_errors(run_with_valgrind("student_free04"));
}

Test(free_bst_test, free_bst05, .description="Free largest possible tree made in another random order.") {
    expect_no_valgrind_errors(run_with_valgrind("student_free05"));
}

Test(free_bst_test, free_bst06, .description="Free a tree that contains half the alphabet.") {
    expect_no_valgrind_errors(run_with_valgrind("student_free06"));
}

Test(free_bst_test, free_bst07, .description="Free a tree that contains half the alphabet in another random order.") {
    expect_no_valgrind_errors(run_with_valgrind("student_free07"));
}

Test(free_bst_test, free_bst08, .description="Free a largest possible tree that was given partially sorted.") {
    expect_no_valgrind_errors(run_with_valgrind("student_free08"));
}

Test(free_bst_test, free_bst09, .description="Free a smaller tree.") {
    expect_no_valgrind_errors(run_with_valgrind("student_free09"));
}

Test(free_bst_test, free_bst10, .description="Free a tree of length 4.") {
    expect_no_valgrind_errors(run_with_valgrind("student_free10"));
}

Test(free_bst_test, free_bst11, .description="Free null tree.") {
    expect_no_valgrind_errors(run_with_valgrind("student_free11"));
}

/*Create matrix tests*/
Test(create_matrix_test, create01, .description="Create an 1x1 matrix") {
    matrix_sf *mat = create_matrix_sf('V', "1 1 [1]");
    expect_matrices_equal(mat, 1, 1, (int[]){1});
    cr_expect_eq(mat->name, 'V', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
    free(mat);
}

Test(create_matrix_test, create02, .description="Create a 0x0 matrix") {
    matrix_sf *mat = create_matrix_sf('F', "0 0 [0]");
    expect_matrices_equal(mat, 0, 0, (int[]){0});
    cr_expect_eq(mat->name, 'F', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
    free(mat);
}

Test(create_matrix_test, create03, .description="Create a row vector") {
    matrix_sf *mat = create_matrix_sf('G', "1 4 [1 2 3 4]");
    expect_matrices_equal(mat, 1, 4, (int[]){1,2,3,4});
    cr_expect_eq(mat->name, 'G', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
    free(mat);
}

Test(create_matrix_test, create04, .description="Create a 4x4 square matrix") {
    matrix_sf *mat = create_matrix_sf('V', "4 4 [1 2 3 4;5 6 7 8; 1 2 3 4; 5 6 7 8]");
    expect_matrices_equal(mat, 4, 4, (int[]){1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8});
    cr_expect_eq(mat->name, 'V', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
    free(mat);
}

Test(create_matrix_test, create05, .description="Create a 1x4 matrix with a lot of spaces") {
    matrix_sf *mat = create_matrix_sf('V', "1 4 [1                    3                 4                 5]");
    expect_matrices_equal(mat, 1, 4, (int[]){1,3,4,5});
    cr_expect_eq(mat->name, 'V', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
    free(mat);
}

Test(create_matrix_test, create06, .description="Create a 2x4 matrix with a lot of spaces") {
    matrix_sf *mat = create_matrix_sf('V', "2 4 [1                    3                 4                 5    ;   2 3    4             7]");
    expect_matrices_equal(mat, 2, 4, (int[]){1,3,4,5,2,3,4,7});
    cr_expect_eq(mat->name, 'V', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
    free(mat);
}

Test(create_matrix_test, create07, .description="Create a 6x1 matrix with a lot of spaces") {
    matrix_sf *mat = create_matrix_sf('A', "6 1 [1                   3              4                 5      2 3]");
    expect_matrices_equal(mat, 6, 1, (int[]){1,3,4,5,2,3});
    cr_expect_eq(mat->name, 'A', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
    free(mat);
}

Test(create_matrix_test, create08, .description="Create a 4x2 matrix with a lot of spaces") {
    matrix_sf *mat = create_matrix_sf('B', "4 2 [1  2            3      4 ;    1        2 3     4]");
    expect_matrices_equal(mat, 4, 2, (int[]){1,2,3,4,1,2,3,4});
    cr_expect_eq(mat->name, 'B', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
    free(mat);
}

Test(create_matrix_test, create09, .description="Create a 4x2 matrix with a lot of spaces and negative values") {
    matrix_sf *mat = create_matrix_sf('B', "4 2 [-1  2            -3      -4 ;    1        2 -3     4]");
    expect_matrices_equal(mat, 4, 2, (int[]){-1,2,-3,-4,1,2,-3,4});
    cr_expect_eq(mat->name, 'B', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
    free(mat);
}

Test(create_matrix_test, create10, .description="Create a 4x4 square matrix with negative values") {
    matrix_sf *mat = create_matrix_sf('V', "4 4 [1 -2 3 -4;5 -6 7 8; 1 2 3 -4; -5 6 7 8]");
    expect_matrices_equal(mat, 4, 4, (int[]){1,-2,3,-4,5,-6,7,8,1,2,3,-4,-5,6,7,8});
    cr_expect_eq(mat->name, 'V', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
    free(mat);
}

/* infix2postfix_sf() tests */
Test(infix2postfix_test, infix2postfix01, .description="Convert just a matrix infix expression") {
    char *actual = infix2postfix_sf("A");
    char *expected = "A";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
    free(actual);
}

Test(infix2postfix_test, infix2postfix02, .description="Convert just a small addition infix expression") {
    char *actual = infix2postfix_sf("A  +   B");
    char *expected = "AB+";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
    free(actual);
}

Test(infix2postfix_test, infix2postfix03, .description="Convert just a small multiplication infix expression") {
    char *actual = infix2postfix_sf("A *  B");
    char *expected = "AB*";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
    free(actual);
}

Test(infix2postfix_test, infix2postfix04, .description="Convert just a small tranpose infix expression") {
    char *actual = infix2postfix_sf("A    ' ");
    char *expected = "A'";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
    free(actual);
}

Test(infix2postfix_test, infix2postfix05, .description="Convert just a small infix expression to test precedence") {
    char *actual = infix2postfix_sf("A + C * B'");
    char *expected = "ACB'*+";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
    free(actual);
}

Test(infix2postfix_test, infix2postfix06, .description="Convert just a small infix expression with parenthesis") {
    char *actual = infix2postfix_sf("(   A+ C )*B'");
    char *expected = "AC+B'*";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
    free(actual);
}

Test(infix2postfix_test, infix2postfix07, .description="Convert a larger infix expression") {
    char *actual = infix2postfix_sf("(A+C)*B''*F+(G'*Y)");
    char *expected = "AC+B''*F*G'Y*+";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
    free(actual);
}

Test(infix2postfix_test, infix2postfix08, .description="Convert an infix expression with multiple parenthesis") {
    char *actual = infix2postfix_sf("(((A+C)))");
    char *expected = "AC+";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
    free(actual);
}

Test(infix2postfix_test, infix2postfix09, .description="Convert an infix expression with multiple parenthesis") {
    char *actual = infix2postfix_sf("(((A+C)*(B+D))'+(E*F))");
    char *expected = "AC+BD+*'EF*+";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
    free(actual);
}

Test(infix2postfix_test, infix2postfix10, .description="Convert an infix expression with empty parenthesis") {
    char *actual = infix2postfix_sf("(A+C)(((())))");
    char *expected = "AC+";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
    free(actual);
}

/* evaluate_expr_sf tests*/
Test(evaluate_expr_test, expr01, .description="Given root of a tree, evaluation of a expression of just one matrix") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "C", root);
    cr_expect_eq(result->name, 'R', "The new matrix did not have the expected name. Actual: %c, Expected: R", result->name);
    expect_matrices_equal(result, 1, 4, (int[]){-123,47,-4,140});
    free(root);
    free(result);
}

Test(evaluate_expr_test, expr02, .description="Given root of a tree, evaluation of a expression of just transpose") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "C'", root);
    cr_expect_eq(result->name, 'R', "The new matrix did not have the expected name. Actual: %c, Expected: R", result->name);
    expect_matrices_equal(result, 4, 1, (int[]){-123,47,-4,140});
    free(root);
    free(result);
}

Test(evaluate_expr_test, expr03, .description="Given root of a tree, evaluation of a expression of just addition") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "C+D", root);
    cr_expect_eq(result->name, 'R', "The new matrix did not have the expected name. Actual: %c, Expected: R", result->name);
    expect_matrices_equal(result, 1, 4, (int[]){-139,169,131,247});
    free(root);
    free(result);
}

Test(evaluate_expr_test, expr04, .description="Given root of a tree, evaluation of a expression of just multiplication") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "D*I", root);
    cr_expect_eq(result->name, 'R', "The new matrix did not have the expected name. Actual: %c, Expected: R", result->name);
    expect_matrices_equal(result, 1, 4, (int[]){-26856,-43106,-5829,-15767});
    free(root);
    free(result);
}

Test(evaluate_expr_test, expr05, .description="Given root of a tree, evaluation of a expression with precedence affecting the result") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "D*I'", root);
    cr_expect_eq(result->name, 'R', "The new matrix did not have the expected name. Actual: %c, Expected: R", result->name);
    expect_matrices_equal(result, 1, 4, (int[]){-14208,-14219,-40265,-3365});
    free(root);
    free(result);
}

Test(evaluate_expr_test, expr06, .description="Given root of a tree, evaluation of a expression with parentheses") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "(D*I)'", root);
    cr_expect_eq(result->name, 'R', "The new matrix did not have the expected name. Actual: %c, Expected: R", result->name);
    expect_matrices_equal(result, 4, 1, (int[]){-26856,-43106,-5829,-15767});
    free(root);
    free(result);
}

Test(evaluate_expr_test, expr07, .description="Given root of a tree, evaluation of a expression with precedence affecting the result") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "D*I'+C", root);
    cr_expect_eq(result->name, 'R', "The new matrix did not have the expected name. Actual: %c, Expected: R", result->name);
    expect_matrices_equal(result, 1, 4, (int[]){-14331,-14172,-40269,-3225});
    free(root);
    free(result);
}

Test(evaluate_expr_test, expr08, .description="Given root of a tree, evaluation of a expression with a lot of spaces") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "(D   * I   ')        +   C", root);
    cr_expect_eq(result->name, 'R', "The new matrix did not have the expected name. Actual: %c, Expected: R", result->name);
    expect_matrices_equal(result, 1, 4, (int[]){-14331,-14172,-40269,-3225});
    free(root);
    free(result);
}

Test(evaluate_expr_test, expr09, .description="Given root of a tree, evaluation of a expression with lots of parentheses that don't do anything") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "(D*((I))'+C)", root);
    cr_expect_eq(result->name, 'R', "The new matrix did not have the expected name. Actual: %c, Expected: R", result->name);
    expect_matrices_equal(result, 1, 4, (int[]){-14331,-14172,-40269,-3225});
    free(root);
    free(result);
}

Test(evaluate_expr_test, expr10, .description="Given root of a tree, evaluation of a expression with lots of tranposes") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "D*I'+C''''''", root);
    cr_expect_eq(result->name, 'R', "The new matrix did not have the expected name. Actual: %c, Expected: R", result->name);
    expect_matrices_equal(result, 1, 4, (int[]){-14331,-14172,-40269,-3225});
    free(root);
    free(result);
}

/* execute_script_sf tests */
Test(execute_test, one_matrix01){ run_script_without_valgrind("student_script01"); }
Test(execute_test_valgrind, one_matrix01) { expect_no_valgrind_errors(run_script_with_valgrind("student_script01")); }

Test(execute_test, multiple_expressions01){ run_script_without_valgrind("student_script02"); }
Test(execute_test_valgrind, multiple_expressions01) { expect_no_valgrind_errors(run_script_with_valgrind("student_script02")); }

Test(execute_test, add_matrices01){ run_script_without_valgrind("student_script03"); }
Test(execute_test_valgrind, add_matrices01) { expect_no_valgrind_errors(run_script_with_valgrind("student_script03")); }

Test(execute_test, add_matrices02){ run_script_without_valgrind("student_script04"); }
Test(execute_test_valgrind, add_matrices02) { expect_no_valgrind_errors(run_script_with_valgrind("student_script04")); }

Test(execute_test, complex_script01){ run_script_without_valgrind("student_script05"); }
Test(execute_test_valgrind, complex_script01) { expect_no_valgrind_errors(run_script_with_valgrind("student_script05")); }

Test(execute_test, multiple_same01){ run_script_without_valgrind("student_script06"); }
Test(execute_test_valgrind, multiple_same01) { expect_no_valgrind_errors(run_script_with_valgrind("student_script06")); }

Test(execute_test, multiplication01){ run_script_without_valgrind("student_script07"); }
Test(execute_test_valgrind, multiplication01) { expect_no_valgrind_errors(run_script_with_valgrind("student_script07")); }

Test(execute_test, tranpose01){ run_script_without_valgrind("student_script08"); }
Test(execute_test_valgrind, transpose01) { expect_no_valgrind_errors(run_script_with_valgrind("student_script08")); }

Test(execute_test, withParenthesis01){ run_script_without_valgrind("student_script09"); }
Test(execute_test_valgrind, withParenthesis01) { expect_no_valgrind_errors(run_script_with_valgrind("student_script09")); }

Test(execute_test, tranpose02){ run_script_without_valgrind("student_script10"); }
Test(execute_test_valgrind, tranpose02) { expect_no_valgrind_errors(run_script_with_valgrind("student_script10")); }

Test(execute_test, tranpose03){ run_script_without_valgrind("student_script11"); }
Test(execute_test_valgrind, tranpose03) { expect_no_valgrind_errors(run_script_with_valgrind("student_script11")); }

Test(execute_test, tranpose04){ run_script_without_valgrind("student_script12"); }
Test(execute_test_valgrind, tranpose04) { expect_no_valgrind_errors(run_script_with_valgrind("student_script12"));}

Test(execute_test, smallestExpression01){ run_script_without_valgrind("student_script13"); }
Test(execute_test_valgrind, smallestExpression01) { expect_no_valgrind_errors(run_script_with_valgrind("student_script13"));}