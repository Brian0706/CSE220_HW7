#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *M = copy_matrix(5, 3, (int[]){1,2,3,4,5,6,7,8,9,0,1,2,3,4,5});
    matrix_sf *G = transpose_mat_sf(M);
    free(M);
    free(G);
    return 0;
}
