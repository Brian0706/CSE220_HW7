#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *M = copy_matrix(1, 3, (int[]){-7,1,2});
    matrix_sf *G = transpose_mat_sf(M);
    free(G);
    free(M);
    return 0;
}
