# LBYARCH MP2 De Guzman and Guo

This is the LBYARCH machine project of De Guzman and Guo. This simulates a vector dot product calculation. Experiments are also to be done to time the kernels of both C and Assembly to finally the answer the question "Is Assembly really faster?"

## Files
1. MP2_cfile.c
2. MP2_asmfile.asm
3. run.bat

MP2_cfile contains essentially the "front-end" of the project. It also contains the external function prototype for assembly and function for calculating dot product within C. MP2_asmfile contains the "back-end" for calculating a double floating point for dot product.

## To run
Firstly, store all the files in a single directory. 
Next, run `run.bat`. This automatically runs the assembling and compiling command lines to connect C and x86 ASM. Afterwards, click on the directory address of File Explorer, type `cmd` then type `MP2_cfile.exe` and it should run automatically.

## Notes
For now, there are fixed values. If you want to change the values, open `MP2_cfile.c` then change the values accordingly. If you want to increase or decrease, please make sure the elements of the vectors correspond to the vector size. 
More comments found in the C file. 
Furthermore, if you would like to check for validity of the dot product entirely, visit this website https://www.calculatorsoup.com/calculators/algebra/dot-product-calculator.php.
Just copy paste the elements of the vectors and calculate in the site.

# Code Analysis

To reiterate, the project is about calculating the dot product. The dot product is calculated as such $$\sum_{i=1}^{n} a_i*b_i$$. In words, it means that the dot product is the summation of all elements in a Vector A multiplied with all corresponding elements in Vector B. In the scenario of the code, it was decided upon that the elements of our vector will be the same elements instead of random elements per run. As it was required, the number of elements must be from 2<sup>10</sup>, 2<sup>20</sup>, and if possible 2<sup>30</sup>. With this information, the elements of both vectors rely on the size of the vector. Vector A will consist of elements [1, 2, 3, ..., n] while Vector B will consist of elements [n, n-1, n-2, ..., 1]. With this, the initilization of necessary information such as vector size and vector elements are complete.

## Time Analysis

In this section, the time analysis will be discussed. To acquire the time it took to run the kernels of both C and ASM, the <time.h> library was utilized. Furthermore the time was given a double datatype to give further precision in the time it took to run. This was implemented in this way. 
    ```
    start = clock();
    result_asm = dot_product_asm(n, A, B);
    end = clock();
    double time_asm = (double)(end - start) / CLOCKS_PER_SEC;
    ```
The program was ran with the different vector sizes and vector elements. Furthermore, the program was ran 20 times to get the average running time. The findings come out as such.
