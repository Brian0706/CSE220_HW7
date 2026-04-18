#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *A = copy_matrix(3, 1, (int[]){1,2,3});
    matrix_sf *B = copy_matrix(3, 1, (int[]){1,2,3});
    matrix_sf *C = add_mats_sf(A, B);
    free(A);
    free(B);
    free(C);
    return 0;
}
