#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void strassen(double **a, double **b, double **c, int tam);
void sum(double **a, double **b, double **result, int tam);
void subtract(double **a, double **b, double **result, int tam);
double **allocate_real_matrix(int tam, int random);
double **free_real_matrix(double **v, int tam);
clock_t clock_begin, clock_end, diff=0;

void strassen(double **a, double **b, double **c, int tam) {

    // trivial case: when the matrix is 1 X 1:
    if (tam == 1) {
        c[0][0] = a[0][0] * b[0][0];
        return;
    }

    // other cases are treated here:
    else {
        int newTam = tam/2;
        double **a11, **a12, **a21, **a22;
        double **b11, **b12, **b21, **b22;
        double **c11, **c12, **c21, **c22;
        double **p1, **p2, **p3, **p4, **p5, **p6, **p7;

        // memory allocation:
        a11 = allocate_real_matrix(newTam, -1);
        a12 = allocate_real_matrix(newTam, -1);
        a21 = allocate_real_matrix(newTam, -1);
        a22 = allocate_real_matrix(newTam, -1);

        b11 = allocate_real_matrix(newTam, -1);
        b12 = allocate_real_matrix(newTam, -1);
        b21 = allocate_real_matrix(newTam, -1);
        b22 = allocate_real_matrix(newTam, -1);

        c11 = allocate_real_matrix(newTam, -1);
        c12 = allocate_real_matrix(newTam, -1);
        c21 = allocate_real_matrix(newTam, -1);
        c22 = allocate_real_matrix(newTam, -1);

        p1 = allocate_real_matrix(newTam, -1);
        p2 = allocate_real_matrix(newTam, -1);
        p3 = allocate_real_matrix(newTam, -1);
        p4 = allocate_real_matrix(newTam, -1);
        p5 = allocate_real_matrix(newTam, -1);
        p6 = allocate_real_matrix(newTam, -1);
        p7 = allocate_real_matrix(newTam, -1);

        double **aResult = allocate_real_matrix(newTam, -1);
        double **bResult = allocate_real_matrix(newTam, -1);

        int i, j;

        //dividing the matrices in 4 sub-matrices:
        for (i = 0; i < newTam; i++) {
            for (j = 0; j < newTam; j++) {
                a11[i][j] = a[i][j];
                a12[i][j] = a[i][j + newTam];
                a21[i][j] = a[i + newTam][j];
                a22[i][j] = a[i + newTam][j + newTam];

                b11[i][j] = b[i][j];
                b12[i][j] = b[i][j + newTam];
                b21[i][j] = b[i + newTam][j];
                b22[i][j] = b[i + newTam][j + newTam];
            }
        }

        // Calculating p1 to p7:
        clock_begin = clock();
        sum(a11, a22, aResult, newTam); // a11 + a22
        sum(b11, b22, bResult, newTam); // b11 + b22
        diff += clock() - clock_begin;
        strassen(aResult, bResult, p1, newTam); // p1 = (a11+a22) * (b11+b22)

        clock_begin = clock();
        sum(a21, a22, aResult, newTam); // a21 + a22
        diff += clock() - clock_begin;
        strassen(aResult, b11, p2, newTam); // p2 = (a21+a22) * (b11)

        clock_begin = clock();
        subtract(b12, b22, bResult, newTam); // b12 - b22
        diff += clock() - clock_begin;
        strassen(a11, bResult, p3, newTam); // p3 = (a11) * (b12 - b22)

        clock_begin = clock();
        subtract(b21, b11, bResult, newTam); // b21 - b11
        diff += clock() - clock_begin;
        strassen(a22, bResult, p4, newTam); // p4 = (a22) * (b21 - b11)

        clock_begin = clock();
        sum(a11, a12, aResult, newTam); // a11 + a12
        diff += clock() - clock_begin;
        strassen(aResult, b22, p5, newTam); // p5 = (a11+a12) * (b22)	

        clock_begin = clock();
        subtract(a21, a11, aResult, newTam); // a21 - a11
        sum(b11, b12, bResult, newTam); // b11 + b12
        diff += clock() - clock_begin;
        strassen(aResult, bResult, p6, newTam); // p6 = (a21-a11) * (b11+b12)

        clock_begin = clock();
        subtract(a12, a22, aResult, newTam); // a12 - a22
        sum(b21, b22, bResult, newTam); // b21 + b22
        diff += clock() - clock_begin;
        strassen(aResult, bResult, p7, newTam); // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 e c22:

        clock_begin = clock();
        sum(p3, p5, c12, newTam); // c12 = p3 + p5
        sum(p2, p4, c21, newTam); // c21 = p2 + p4

        sum(p1, p4, aResult, newTam); // p1 + p4
        sum(aResult, p7, bResult, newTam); // p1 + p4 + p7
        subtract(bResult, p5, c11, newTam); // c11 = p1 + p4 - p5 + p7

        sum(p1, p3, aResult, newTam); // p1 + p3
        sum(aResult, p6, bResult, newTam); // p1 + p3 + p6
        subtract(bResult, p2, c22, newTam); // c22 = p1 + p3 - p2 + p6

        // Grouping the results obtained in a single matrix:
        for (i = 0; i < newTam ; i++) {
            for (j = 0 ; j < newTam ; j++) {
                c[i][j] = c11[i][j];
                c[i][j + newTam] = c12[i][j];
                c[i + newTam][j] = c21[i][j];
                c[i + newTam][j + newTam] = c22[i][j];
            }
        }
        diff += clock() - clock_begin;

        // deallocating memory (free):
        a11 = free_real_matrix(a11, newTam);
        a12 = free_real_matrix(a12, newTam);
        a21 = free_real_matrix(a21, newTam);
        a22 = free_real_matrix(a22, newTam);

        b11 = free_real_matrix(b11, newTam);
        b12 = free_real_matrix(b12, newTam);
        b21 = free_real_matrix(b21, newTam);
        b22 = free_real_matrix(b22, newTam);

        c11 = free_real_matrix(c11, newTam);
        c12 = free_real_matrix(c12, newTam);
        c21 = free_real_matrix(c21, newTam);
        c22 = free_real_matrix(c22, newTam);

        p1 = free_real_matrix(p1, newTam);
        p2 = free_real_matrix(p2, newTam);
        p3 = free_real_matrix(p3, newTam);
        p4 = free_real_matrix(p4, newTam);
        p5 = free_real_matrix(p5, newTam);
        p6 = free_real_matrix(p6, newTam);
        p7 = free_real_matrix(p7, newTam);
        aResult = free_real_matrix(aResult, newTam);
        bResult = free_real_matrix(bResult, newTam);
    } // end of else

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

        double **a; double **b; double **c;
        unsigned int tam; scanf("%d",&tam);
        a=allocate_real_matrix(tam,1);
        b=allocate_real_matrix(tam,1);
        c=allocate_real_matrix(tam,1);

        //print_matrix(a, tam); printf("\n\n");
        //print_matrix(b, tam); printf("\n\n");
    
        strassen(a,b,c, tam);

        a=free_real_matrix(a, tam);
        b=free_real_matrix(b, tam);
        c=free_real_matrix(c, tam);

        //double time_r = (double)(clock_end - clock_begin)/CLOCKS_PER_SEC;
        printf("Size: %d\tExecuted time required: %lf\n", tam, (double)diff/CLOCKS_PER_SEC);


    return 0;
}
