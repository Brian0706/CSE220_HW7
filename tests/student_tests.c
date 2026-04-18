#include "unit_tests.h"

TestSuite(operators_test, .timeout=TEST_TIMEOUT, .disabled=false); // return value of add, mult, transpose
TestSuite(operators_valgrind, .timeout=TEST_TIMEOUT, .disabled=false); 

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