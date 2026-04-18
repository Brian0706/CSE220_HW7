#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *M = copy_matrix(4, 1, (int[]){-7,1,2,4});
    matrix_sf *G = transpose_mat_sf(M);
    free(G);
    free(M);
    return 0;
}
