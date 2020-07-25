#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void strassen(double **a, double **b, double **c, int tam);
void sum(double **a, double **b, double **result, int tam);
void subtract(double **a, double **b, double **result, int tam);
double **allocate_real_matrix(int tam, int random);
double **free_real_matrix(double **v, int tam);

void strassen(double **a, double **b, double **c, int tam) {

    int i, j, k;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            double sum = 0;
            for(k = 0; k < tam; k++){
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }

} // end of Strassen function

/*------------------------------------------------------------------------------*/
// function to sum two matrices
void sum(double **a, double **b, double **result, int tam) {

    int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

/*------------------------------------------------------------------------------*/
// function to subtract two matrices
void subtract(double **a, double **b, double **result, int tam) {

    int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }	
}

/*------------------------------------------------------------------------------*/
// This function allocates the matrix using malloc, and initializes it. If the variable random is passed
// as zero, it initializes the matrix with zero, if it's passed as 1, it initializes the matrix with random
// values. If it is passed with any other int value (like -1 for example) the matrix is initialized with no
// values in it. The variable tam defines the length of the matrix.
double **allocate_real_matrix(int tam, int random) {

    int i, j, n = tam, m = tam;
    double **v, a;         // pointer to the vector

    // allocates one vector of vectors (matrix)
    v = (double**) malloc(n * sizeof(double*));

    if (v == NULL) {
        printf ("** Error in matrix allocation: insufficient memory **");
        return (NULL);
    }

    // allocates each row of the matrix
    for (i = 0; i < n; i++) {
        v[i] = (double*) malloc(m * sizeof(double));

        if (v[i] == NULL) {
            printf ("** Error: Insufficient memory **");
            free_real_matrix(v, n);
            return (NULL);
        }

        // initializes the matrix with zeros
        if (random == 0) {
            for (j = 0; j < m; j++)
                v[i][j] = 0.0;
        }

        // initializes the matrix with random values between 0 and 10
        else {
            if (random == 1) {
                for (j = 0; j < m; j++) {
                    a = rand();
                    v[i][j] = ((int)a%999)+(a-(int)a);
                }
            }
        }
    }

    return (v);     // returns the pointer to the vector. 
}

/*------------------------------------------------------------------------------*/
// This function unallocated the matrix (frees memory)
double **free_real_matrix(double **v, int tam) {

    int i;

    if (v == NULL) {
        return (NULL);
    }

    for (i = 0; i < tam; i++) { 
        if (v[i]) { 
            free(v[i]); // frees a row of the matrix
            v[i] = NULL;
        } 
    } 

    free(v);         // frees the pointer /
    v = NULL;

    return (NULL);   //returns a null pointer /
}

void print_matrix(double **v, unsigned int tam){

        int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            printf(" %lf ",v[i][j]);
        }
        printf("\n");
    }
}
/*------------------------------------------------------------------------------*/

int main(){
    int kio=50;
    while(kio<1000){
        double **a; double **b; double **c;
        unsigned int tam = kio; //scanf("%d",&tam);
        a=allocate_real_matrix(tam,1);
        b=allocate_real_matrix(tam,1);
        c=allocate_real_matrix(tam,1);

        //print_matrix(a, tam); printf("\n\n");
        //print_matrix(b, tam); printf("\n\n");
    
        clock_t clock_begin = clock();
        strassen(a,b,c, tam);
        clock_t clock_end = clock();

        a=free_real_matrix(a, tam);
        b=free_real_matrix(b, tam);
        c=free_real_matrix(c, tam);

        double time_r = (double)(clock_end - clock_begin)/CLOCKS_PER_SEC;
        printf("Size: %d\tExecuted time required: %lf\n", tam, time_r);
        kio+=80;
    }

    return 0;
}
