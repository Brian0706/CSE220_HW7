#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *A = copy_matrix(5, 5, (int[]){1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5});
    matrix_sf *B = copy_matrix(5, 5, (int[]){-1,-2,-3,-4,-5,-1,-2,-3,-4,-5,-1,-2,-3,-4,-5,-1,-2,-3,-4,-5,-1,-2,-3,-4,-5});
    matrix_sf *C = add_mats_sf(A, B);
    free(A);
    free(B);
    free(C);
    return 0;
}
