#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *A = copy_matrix(4, 3, (int[]){1,2,3,4,5,6,7,8,9,10,11,12});
    matrix_sf *B = copy_matrix(4, 3, (int[]){1,2,3,4,5,6,7,8,9,10,11,12});
    matrix_sf *C = add_mats_sf(A, B);
    free(C);
    C = add_mats_sf(B, A);
    free(A);
    free(B);
    free(C);
    return 0;
}
