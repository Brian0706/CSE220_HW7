#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *G = copy_matrix(2, 2, (int[]){0,0,0,0});
    matrix_sf *D = copy_matrix(2, 2, (int[]){0,0,0,0});
    matrix_sf *Z = mult_mats_sf(G, D);
    free(G);
    free(D);
    free(Z);
    return 0;
}
