#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *M = copy_matrix(3, 3, (int[]){1,0,0,0,2,0,0,0,3});
    matrix_sf *G = transpose_mat_sf(M);
    free(G);
    free(M);
    return 0;
}
