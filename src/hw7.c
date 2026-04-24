#include "hw7.h"
/*
    Name: Brian Chau
    SBU ID: 116125954
*/

/*This function clears the stack for evaluate_expr*/
void clearStack(matrix_sf** stackPointer, matrix_sf** stack){
    while(stackPointer >= stack){
        if((*stackPointer)->name == '?'){
            free(*stackPointer);
        }
        stackPointer--;
    }
}

bst_sf* insert_bst_sf(matrix_sf *mat, bst_sf *root) {
    /*Allocate space for the pointer*/
    bst_sf* newNode = malloc(sizeof(bst_sf));
    /*If malloc fails just return the root and do nothing*/
    if(newNode == NULL){
        return root;
    }
    /*Set the values for the new node*/
    (newNode->mat) = mat;
    (newNode->left_child)=NULL;
    (newNode->right_child)=NULL;
    if(root == NULL){
        return newNode;
    }
    /*Pointers used to navigate the bst*/
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
    /*Based on the direction, set the left or right child*/
    if(direction == 1){
        prev->left_child = newNode;
    }
    else{
        prev->right_child=newNode;
    }
    return root;
}

matrix_sf* find_bst_sf(char name, bst_sf *root) {
    /*If the bst is null just return null*/
    if(root == NULL){
        return NULL;
    }
    bst_sf* cur = root;
    /*Keep navigating the tree until you reach a null*/
    while(cur != NULL){
        /*Navigate the bst by checking the name*/
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
    /*Reaching here means that the matrix is not in the bst*/
    return NULL;
}

/*Recursively frees the free*/
void free_bst_sf(bst_sf *root) {
    /*Base case for the recursion*/
    if(root == NULL){
        return;
    }
    /*Free the children, then the matrix in root, then the root*/
    free_bst_sf(root->left_child);
    free_bst_sf(root->right_child);
    free(root->mat);
    free(root);
}

matrix_sf* add_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    /*Check if you can do addition
    * This is not necessary but only done because it is easy to check
    */
    if(mat1->num_rows != mat2->num_rows || mat1->num_cols != mat2->num_cols){
        return NULL;
    }
    /*Use copy to set values of the array*/
    matrix_sf* result = copy_matrix(mat1->num_rows, mat1->num_cols, mat1->values);
    /*Check if copy matrix fails, this means that that memory allocation failed*/
    if(result == NULL){
        return result;
    }
    /*Loop to do matrix addition*/
    for(unsigned int i = 0; i < (mat1->num_rows)*(mat1->num_cols);i++){
        *(result->values + i) += *(mat2->values + i);
    }
    return result;
}

matrix_sf* mult_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    /*Check if you can do multiplication
    * This is not necessary but only done because it is easy to check
    */
    if(mat1->num_cols != mat2->num_rows){
        return NULL;
    }
    matrix_sf* result = malloc(sizeof(matrix_sf)+mat1->num_rows*mat2->num_cols*sizeof(int));
    /*Check if memory allocation fails*/
    if(result == NULL){
        return NULL;
    }
    /*Set the values of result that do not need to be calculated*/
    result->name = '?';
    result->num_rows = mat1->num_rows;
    result->num_cols = mat2->num_cols;
    /*Initalize the values array to 0*/
    memset(result->values, 0, mat1->num_rows*mat2->num_cols*sizeof(int));
    /*Performs matrix multiplication*/
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
    /*Check if memory allocation fails*/
    if(result == NULL){
        return NULL;
    }
    /*Set the values of result that do not need to be calculated*/
    result->name = '?';
    result->num_rows = mat->num_cols;
    result->num_cols = mat->num_rows;
    /*Initalize the values array to 0*/
    memset(result->values, 0, mat->num_rows*mat->num_cols*sizeof(int));
    /*Tranpose the matrix mat*/
    for(unsigned int i = 0; i < mat->num_rows; i++){
        for(unsigned int j = 0; j < mat->num_cols;j++){
            *(result->values+j*result->num_cols+i) = *(mat->values+i*mat->num_cols+j);
        }
    }
    return result;
}

matrix_sf* create_matrix_sf(char name, const char *expr) {
    /*Create a pointer so that we can use strtol*/
    const char* pointer = expr;
    /*
    * Use strtol to read the num_rows, value has to be type casted since strtol returns a long
    */
    unsigned int num_rows = (unsigned int) strtol(expr, (char **) &pointer, 10);
    expr = pointer;
    /*This loop is used to skip past the spaces*/
    while(*expr == ' '){
        expr++;
    };
    pointer = expr;
    unsigned int num_cols = (unsigned int) strtol(expr, (char **) &pointer, 10);
    expr = pointer;
    matrix_sf* matrix = malloc(sizeof(matrix_sf)+num_rows*num_cols*sizeof(int));
    /*Check if memory allocation has failed*/
    if(matrix == NULL){
        return NULL;
    }
    /*Set the values of matrix that we know*/
    (matrix->name) = name;
    (matrix->num_rows) = num_rows;
    (matrix->num_cols) = num_cols;
    /*
    *Find where the values array is
    *The values will start one after [ so add in a 1 to compensate
    */
    expr = strchr(expr, '[') + 1;
    /*There can be more spaces so we check*/
    while(*expr == ' '){
        expr++;
    };
    pointer = expr;
    for(unsigned int i = 0; i < num_rows * num_cols; i++){
        /*Read a number then set the corresponding value in values array*/
        int num = (int) strtol(expr, (char **) &pointer, 10);
        *(matrix->values+i) = num;
        expr = pointer;
        while(*expr == ' ' || *expr == ';'){
            expr++;
        };
        pointer = expr;
    }
    return matrix;
}

char* infix2postfix_sf(char *infix) {
    /*Create the stack*/
    char operations[strlen(infix) + 1];
    /*
    This pointer lets us navigate the stack.
    When operationPointer < operations, this indicates the stack is empty
    */
    char *operationPointer = operations-1;
    char *result = calloc(strlen(infix) + 1,1);
    /*Check if memory allocation has failed.*/
    if(result == NULL){
        return NULL;
    }
    /*Create a pointer to go through the string and write to it*/
    char *pointer = result;
    /*Goes left to right through expression since it has left associativity*/
    while(*infix){
        switch(*infix){
            /*Goes through each possible operator*/
            case '\'':
                /*Pops out operations with higher precedence that are in the stack*/
                while(operationPointer >= operations && *operationPointer == '\''){
                    *pointer++ = *operationPointer--;
                }
                /*Add operator to operator stack*/
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
                /*This ensures that the ( is not written to the expression*/
                operationPointer--;
                infix++;
                break;
            case '(':
                *++operationPointer = *infix++;
                break;
            /*These two cases ensure that ' ' and \n are not written into the postfix expression*/
            case ' ':
                infix++;
                break;
            case '\n':
                infix++;
                break;
            default:
                /*Ensures that operands are written in the correct order*/
                *pointer++ = *infix++;
        }
    }
    /*Pops every remaining operand out of the stack and writes it to the expression*/
    while(operationPointer >= operations){
        *pointer++ = *operationPointer--;
    }
    /*Add null terminator to end of the postfix expression.*/
    *pointer = '\0';
    return result;
}

matrix_sf* evaluate_expr_sf(char name, char *expr, bst_sf *root) {
    /*Convert the expression to postfix*/
    char* postfix = infix2postfix_sf(expr);
    /*Checks if the function failed*/
    if(postfix == NULL){
        return NULL;
    }
    /*Saved so that I can free the string later*/
    char* expression = postfix;
    /*Stack of operands*/
    matrix_sf* matrices[strlen(expr) + 1];
    /*Pointer to navigate stack*/
    matrix_sf** matrixPointer = matrices - 1;
    matrix_sf* operand1;
    matrix_sf* operand2;
    matrix_sf* matrix;
    /*Go through and evaluate the expression*/
    while(*postfix){
        /*Checks if the character is an operand*/
        if(isalpha(*postfix)){
            matrix = find_bst_sf(*postfix, root);
            if(matrix == NULL){
                clearStack(matrixPointer, matrices);
                free(expression);
                return NULL;
            }
            *++matrixPointer = matrix;
        }else{
            /*Check if the character is an operator then perform that operation*/
            switch(*postfix){
                case '\'':
                    matrix = transpose_mat_sf(*matrixPointer);
                    /*If the function failed, free memory then immediately exit.*/
                    if(matrix == NULL){
                        clearStack(matrixPointer, matrices);
                        free(expression);
                        return NULL;
                    }
                    //This is an else statement to prevent double freeing
                    else if((*matrixPointer)->name == '?'){
                        free(*matrixPointer);
                    }
                    *matrixPointer = matrix;
                    break;
                case '+':
                    operand1 = *matrixPointer--;
                    operand2 = *matrixPointer;
                    matrix = add_mats_sf(operand1, operand2);
                    /*This is done first as matrixPointer is before operand1*/
                    if((operand1)->name == '?')free(operand1);
                    if(matrix == NULL){
                        clearStack(matrixPointer, matrices);
                        free(expression);
                        return NULL;
                    }
                    else if((operand2)->name == '?'){
                        free(operand2);
                    }
                    *matrixPointer = matrix;
                    break;
                case '*':
                    operand1 = *matrixPointer--;
                    operand2 = *matrixPointer;
                    matrix = mult_mats_sf(operand2, operand1);
                    if((operand1)->name == '?')free(operand1);
                    if(matrix == NULL){
                        clearStack(matrixPointer, matrices);
                        free(expression);
                        return NULL;
                    }
                    else if((operand2)->name == '?'){
                        free(operand2);
                    }
                    *matrixPointer = matrix;
                    break;
                default:
                    break;
            }
        }
        postfix++;
    }
    /*Copy the top of the stack into answers*/
    matrix_sf* ans = copy_matrix((*matrixPointer)->num_rows,(*matrixPointer)->num_cols,(*matrixPointer)->values);
    clearStack(matrixPointer, matrices);
    free(expression);
    /*Check if the copy failed*/
    if(ans == NULL){
        return NULL;
    }
    ans->name=name;
    return ans;
}

matrix_sf *execute_script_sf(char *filename) {
    FILE * script = fopen(filename,"r");
    /*Check if fopen failed*/
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
    /*Reads a line and checks if eof has been reached*/
    while(getline(&line,&max_line_size, script) != EOF){
        name = line[0];
        /*Check the right side of the statement to see what to do*/
        rightSide = strchr(line, '=');
        rightSide++;
        /*Go past starting spaces*/
        while(*rightSide == ' '){
            rightSide++;
        }
        /*If there is a digit, indicates that we are creating a matrix*/
        if(isdigit(*rightSide)){
            result = create_matrix_sf(name, rightSide);
        }
        else{
            result = evaluate_expr_sf(name, rightSide, root);
        }
        /*If the operation failed, immediately close the file, free memory and exit*/
        if(result == NULL){
            fclose(script);
            free_bst_sf(root);
            free(line);
            return NULL;
        }
        /*Insert the new matrix into the bst*/
        root = insert_bst_sf(result, root);
        /*Check if bst added in node successfully*/
        if(!find_bst_sf(result->name,root)){
            /*If insert failed, free memory then exit*/
            fclose(script);
            free_bst_sf(root);
            free(result);
            free(line);
            return NULL;
        }
    }
    fclose(script);
    /*Get the matrix that was last created and return it*/
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