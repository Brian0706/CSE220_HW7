#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *G = copy_matrix(1, 3, (int[]){1,2,3});
    matrix_sf *D = copy_matrix(3, 1, (int[]){-1,-2,-3});
    matrix_sf *Z = mult_mats_sf(G, D);
    free(G);
    free(D);
    free(Z);
    return 0;
}
