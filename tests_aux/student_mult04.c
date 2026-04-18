#include "unit_tests.h"
#include "hw7.h"
int main() { 
    matrix_sf *G = copy_matrix(5, 4, (int[]){1,2,3,4,5,6,7,8,9,-1,-2,-3,-4,-5,-6,-7,-8,-9,0,2});
    matrix_sf *D = copy_matrix(4, 5, (int[]){-1,-2,-3,-4,-5,-6,-7,-8,-9,1,2,3,4,5,6,7,8,9,0,-2});
    matrix_sf *Z = mult_mats_sf(D, G);
    free(G);
    free(D);
    free(Z);
    return 0;
}
