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
	
	// when they ask for a vector size of 2^20. 
	//size_t is unsigned data type 
    const size_t n = 1 << 20; //saying from 1 to 20. if this was 1 << 10 then itll be 1024 elements
	
    double *A = (double *)malloc(n * sizeof(double));
    double *B = (double *)malloc(n * sizeof(double));

    //fixed values but just looping the input into array
    for (size_t i = 0; i < n; i++) {
        A[i] = (double)(i + 1);       //1, 2, 3, ... , n
        B[i] = (double)(n - i);       //n, n-1, n-2, ..., 1
    }

    double result_c, result_asm;
	//clock_t is processing time done by a process
    clock_t start, end;

    //C kernel, uses the dot_product_c function so it only happens here
    start = clock();
    result_c = dot_product_c(n, A, B);
    end = clock();
	//CLOCKS_PER_SEC defines number of clockticks per second. So kind of like the signaling in microprogramming. Kinda.
    double time_c = (double)(end - start) / CLOCKS_PER_SEC;

    //ASM kernel, uses the dot_product_asm extern function
    start = clock();
    result_asm = dot_product_asm(n, A, B);
    end = clock();
    double time_asm = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("Vector Size: %zu\n", n);
    printf("Dot Product (C): %f\n", result_c);
    printf("Dot Product (ASM): %f\n", result_asm);
    printf("Execution Time (C): %f seconds\n", time_c);
    printf("Execution Time (ASM): %f seconds\n", time_asm);

    // Free allocated memory
    free(A);
    free(B);

    return 0;

}
