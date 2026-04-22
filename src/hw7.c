#include "hw7.h"

bst_sf* insert_bst_sf(matrix_sf *mat, bst_sf *root) {
    bst_sf* newNode = malloc(sizeof(bst_sf));
    if(newNode == NULL){
        return root;
    }
    (newNode->mat) = mat;
    (newNode->left_child)=NULL;
    (newNode->right_child)=NULL;
    if(root == NULL){
        return newNode;
    }
    bst_sf* current = root;
    bst_sf* prev = NULL;
    /*Indicates whether or not the last move was to the left or right*/
    int direction = -1;
    while(current != NULL){
        prev = current;
        if((current->mat)->name < mat->name){
            current=(current->right_child);
            direction = 0;
        }
        else{
            current=(current->left_child);
            direction = 1;
        }
    }
    if(direction == 1){
        prev->left_child = newNode;
    }
    else{
        prev->right_child=newNode;
    }
    return root;
}

matrix_sf* find_bst_sf(char name, bst_sf *root) {
    if(root == NULL){
        return NULL;
    }
    bst_sf* cur = root;
    while(cur != NULL){
        if((cur->mat)->name < name){
            cur=(cur->right_child);
        }
        else if((cur->mat)->name > name){
            cur=(cur->left_child);
        }
        else{
            return cur->mat;
        }
    }
    return NULL;
}

void free_bst_sf(bst_sf *root) {
    if(root == NULL){
        return;
    }
    free_bst_sf(root->left_child);
    free_bst_sf(root->right_child);
    free(root->mat);
    free(root);
}

matrix_sf* add_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    if(mat1->num_rows != mat2->num_rows || mat1->num_cols != mat2->num_cols){
        return NULL;
    }
    matrix_sf* result = copy_matrix(mat1->num_rows, mat1->num_cols, mat1->values);
    if(result == NULL){
        return result;
    }
    for(unsigned int i = 0; i < (mat1->num_rows)*(mat1->num_cols);i++){
        *(result->values + i) += *(mat2->values + i);
    }
    return result;
}

matrix_sf* mult_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    if(mat1->num_cols != mat2->num_rows){
        return NULL;
    }
    matrix_sf* result = malloc(sizeof(matrix_sf)+mat1->num_rows*mat2->num_cols*sizeof(int));
    if(result == NULL){
        return NULL;
    }
    result->name = '?';
    result->num_rows = mat1->num_rows;
    result->num_cols = mat2->num_cols;
    memset(result->values, 0, mat1->num_rows*mat2->num_cols*sizeof(int));
    for(unsigned int i = 0; i < mat1->num_rows; i++){
        for(unsigned int j = 0; j < mat2->num_cols; j++){
            for(unsigned int k = 0; k < mat1->num_cols;k++){
                int mat1Val = *(mat1->values + i*mat1->num_cols + k);
                int mat2Val = *(mat2->values + k * mat2->num_cols + j);
                *(result->values + i * mat2->num_cols + j) += mat1Val * mat2Val;
            }
        }
    }
    return result;
}

matrix_sf* transpose_mat_sf(const matrix_sf *mat) {
    matrix_sf* result = malloc(sizeof(matrix_sf)+mat->num_rows*mat->num_cols*sizeof(int));
    if(result == NULL){
        return NULL;
    }
    result->name = '?';
    result->num_rows = mat->num_cols;
    result->num_cols = mat->num_rows;
    memset(result->values, 0, mat->num_rows*mat->num_cols*sizeof(int));
    for(unsigned int i = 0; i < mat->num_rows; i++){
        for(unsigned int j = 0; j < mat->num_cols;j++){
            *(result->values+j*result->num_cols+i) = *(mat->values+i*mat->num_cols+j);
        }
    }
    return result;
}

matrix_sf* create_matrix_sf(char name, const char *expr) {
    const char* pointer = expr;
    unsigned int num_rows = strtol(expr, (char **) &pointer, 10);
    expr = pointer;
    while(*expr == ' '){
        expr++;
    };
    pointer = expr;
    unsigned int num_cols = strtol(expr, (char **) &pointer, 10);
    expr = pointer;
    matrix_sf* matrix = malloc(sizeof(matrix_sf)+num_rows*num_cols*sizeof(int));
    if(matrix == NULL){
        return NULL;
    }
    (matrix->name) = name;
    (matrix->num_rows) = num_rows;
    (matrix->num_cols) = num_cols;
    expr = strchr(expr, '[') + 1;
    while(*expr == ' '){
        expr++;
    };
    pointer = expr;
    for(unsigned int i = 0; i < num_rows * num_cols; i++){
        long num = strtol(expr, (char **) &pointer, 10);
        *(matrix->values+i) = (int) num;
        expr = pointer;
        while(*expr == ' ' || *expr == ';'){
            expr++;
        };
        pointer = expr;
    }
    return matrix;
}

char* infix2postfix_sf(char *infix) {
    char operations[strlen(infix) + 1];
    char *operationPointer = operations-1;
    char *result = calloc(strlen(infix) + 1,1);
    if(result == NULL){
        return NULL;
    }
    char *pointer = result;
    while(*infix){
        switch(*infix){
            case '\'':
                while(operationPointer >= operations && *operationPointer == '\''){
                    *pointer++ = *operationPointer--;
                }
                *++operationPointer = *infix++;
                break;
            case '+':
                while(operationPointer >= operations && *operationPointer != '('){
                    *pointer++ = *operationPointer--;
                }
                *++operationPointer = *infix++;
                break;
            case '*':
                while(operationPointer >= operations && *operationPointer != '+' && *operationPointer != '('){
                    *pointer++ = *operationPointer--;
                }
                *++operationPointer = *infix++;
                break;
            case ')':
                while(operationPointer >= operations && *operationPointer != '('){
                    *pointer++ = *operationPointer--;
                }
                operationPointer--;
                infix++;
                break;
            case '(':
                *++operationPointer = *infix++;
                break;
            case ' ':
                infix++;
                break;
            case '\n':
                infix++;
                break;
            default:
                *pointer++ = *infix++;
        }
    }
    while(operationPointer >= operations){
        *pointer++ = *operationPointer--;
    }
    *pointer = '\0';
    return result;
}

matrix_sf* evaluate_expr_sf(char name, char *expr, bst_sf *root) {
    char* postfix = infix2postfix_sf(expr);
    /*Saved so that I can free the string later*/
    char* expression = postfix;
    matrix_sf* matrices[strlen(expr) + 1];
    matrix_sf** matrixPointer = matrices - 1;
    matrix_sf* operand1;
    matrix_sf* operand2;
    matrix_sf* transposed;
    matrix_sf* matrix;
    while(*postfix){
        switch(*postfix){
            case '\'':
                transposed = transpose_mat_sf(*matrixPointer);
                if((*matrixPointer)->name == '?')free(*matrixPointer);
                *matrixPointer = transposed;
                break;
            case '+':
                operand1 = *matrixPointer--;
                operand2 = *matrixPointer;
                matrix_sf* sum = add_mats_sf(operand1, operand2);
                if((operand1)->name == '?')free(operand1);
                if((operand2)->name == '?')free(operand2);
                *matrixPointer = sum;
                break;
            case '*':
                operand1 = *matrixPointer--;
                operand2 = *matrixPointer;
                matrix_sf* product = mult_mats_sf(operand2, operand1);
                if((operand1)->name == '?')free(operand1);
                if((operand2)->name == '?')free(operand2);
                *matrixPointer = product;
                break;
            case '\n':
                break;
            default:
                matrix = find_bst_sf(*postfix, root);
                *++matrixPointer = matrix;
                break;
        }
        postfix++;
    }
    matrix_sf* ans = copy_matrix((*matrices)->num_rows,(*matrices)->num_cols,(*matrices)->values);
    if(ans == NULL){
        return NULL;
    }
    ans->name=name;
    if((*matrices)->name=='?'){
        free(*matrices);
    }
    free(expression);
    return ans;
}

matrix_sf *execute_script_sf(char *filename) {
    FILE * script = fopen(filename,"r");
    if(script == NULL){
        return NULL;
    }
    char *line = NULL;
    size_t max_line_size = MAX_LINE_LEN;
    char* rightSide;
    char name;
    matrix_sf* result = NULL;
    bst_sf* root = NULL;
    matrix_sf* ans;
    while(getline(&line,&max_line_size, script) != EOF){
        name = line[0];
        rightSide = strchr(line, '=');
        if(rightSide == NULL){
            continue;
        }
        rightSide++;
        while(*rightSide == ' '){
            rightSide++;
        };
        if(isdigit(*rightSide)){
            result = create_matrix_sf(name, rightSide);
        }
        else{
            result = evaluate_expr_sf(name, rightSide, root);
        }
        if(result == NULL){
            fclose(script);
            free_bst_sf(root);
            free(line);
            return NULL;
        }
        root = insert_bst_sf(result, root);
    }
    fclose(script);
    ans = copy_matrix(result->num_rows,result->num_cols,result->values);
    if(ans != NULL){
        ans->name = result->name;
    }
    free_bst_sf(root);
    free(line);
    return ans;
}

// This is a utility function used during testing. Feel free to adapt the code to implement some of
// the assignment. Feel equally free to ignore it.
matrix_sf *copy_matrix(unsigned int num_rows, unsigned int num_cols, const int values[]) {
    matrix_sf *m = malloc(sizeof(matrix_sf)+num_rows*num_cols*sizeof(int));
    if(m == NULL){
        return NULL;
    }
    m->name = '?';
    m->num_rows = num_rows;
    m->num_cols = num_cols;
    memcpy(m->values, values, num_rows*num_cols*sizeof(int));
    return m;
}

// Don't touch this function. It's used by the testing framework.
// It's been left here in case it helps you debug and test your code.
void print_matrix_sf(matrix_sf *mat) {
    assert(mat != NULL);
    assert(mat->num_rows <= 1000);
    assert(mat->num_cols <= 1000);
    printf("%d %d ", mat->num_rows, mat->num_cols);
    for (unsigned int i = 0; i < mat->num_rows*mat->num_cols; i++) {
        printf("%d", mat->values[i]);
        if (i < mat->num_rows*mat->num_cols-1)
            printf(" ");
    }
    printf("\n");
}