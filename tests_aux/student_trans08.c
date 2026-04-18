#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *M = copy_matrix(3, 3, (int[]){0,0,0,0,0,0,0,0,0});
    matrix_sf *G = transpose_mat_sf(M);
    free(M);
    free(G);
    return 0;
}
