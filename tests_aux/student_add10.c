#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *A = copy_matrix(3, 3, (int[]){1,2,3,4,5,6,7,8,9});
    matrix_sf *B = copy_matrix(3, 3, (int[]){1,2,3,4,5,6,7,8,9});
    matrix_sf *C = copy_matrix(3, 3, (int[]){2,3,4,5,6,7,8,9,10});
    matrix_sf *D = add_mats_sf(A,C);
    matrix_sf *store = D;
    D = add_mats_sf(D,B);
    free(A);
    free(B);
    free(C);
    free(D);
    free(store);
    return 0;
}
