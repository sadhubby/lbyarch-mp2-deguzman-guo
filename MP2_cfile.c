#include <stdio.h>
#include <stdlib.h>
#include <time.h> //we will use this later. from how I understood specs, we need to time and experiment.


extern double dot_product_asm(size_t n, const double *A, const double *B);

// C is our "sanity check" this should be correct naman kasi its like element of A[1] * B[1] which gets added into result. it will sum it up agad. 
double dot_product_c(size_t n, const double *A, const double *B) {
    double result = 0.0;
    for (size_t i = 0; i < n; i++) {
        result += A[i] * B[i]; 
    }
    return result;
}

int main() {
	
	// constant size muna for now, just to test it out.
	
	// i think this will be randomized later? It feels kinda hard kasi to input values 
	// when they ask for a vector size of 2^20. 
    const size_t n = 8; 
    double A[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0}; 
    double B[] = {8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 3.0};
    double result_c, result_asm;


    result_c = dot_product_c(n, A, B);


    result_asm = dot_product_asm(n, A, B);

    printf("Vector Size: %zu\n", n);
    printf("Vector A: ");
    for (size_t i = 0; i < n; i++) {
        printf("%f ", A[i]);
    }
    printf("\n");

    printf("Vector B: ");
    for (size_t i = 0; i < n; i++) {
        printf("%f ", B[i]);
    }
    printf("\n");

    printf("Dot Product (C): %f\n", result_c);
    printf("Dot Product (ASM): %f\n", result_asm);

    return 0;
}
