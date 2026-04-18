#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *M = copy_matrix(2, 4, (int[]){1,2,3,4,5,6,7,8});
    matrix_sf *G = transpose_mat_sf(M);
    free(G);
    free(M);
    return 0;
}
