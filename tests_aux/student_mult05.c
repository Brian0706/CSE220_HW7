#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *G = copy_matrix(3, 4, (int[]){1,2,3,4,5,6,7,8,9,-1,-2,-3});
    matrix_sf *D = copy_matrix(4, 3, (int[]){-1,-2,-3,-4,-5,-6,-7,-8,-9,1,2,3});
    matrix_sf *Z = mult_mats_sf(G, D);
    free(G);
    free(D);
    free(Z);
    return 0;
}
