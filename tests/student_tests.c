#include "unit_tests.h"

TestSuite(operators_test, .timeout=TEST_TIMEOUT, .disabled=false); // return value of add, mult, transpose
TestSuite(operators_valgrind, .timeout=TEST_TIMEOUT, .disabled=false); 

TestSuite(insert_bst_test, .timeout=TEST_TIMEOUT, .disabled=false); // test insert_bst_sf for correct BST update
TestSuite(find_bst_test, .timeout=TEST_TIMEOUT, .disabled=false);
TestSuite(free_bst_test, .timeout=TEST_TIMEOUT, .disabled=false);

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
Test(operators_valgrind, add10) { expect_no_valgrind_errors(run_with_valgrind("student_add09")); }

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