# LBYARCH MP2 De Guzman and Guo

This is the LBYARCH machine project of De Guzman and Guo. This simulates a vector dot product calculation. Experiments are also to be done to time the kernels of both C and Assembly to finally the answer the question "Is Assembly really faster?"

## Files
1. MP2_cfile.c
2. MP2_asmfile.asm
3. run.bat

MP2_cfile contains essentially the "front-end" of the project. It also contains the external function prototype for assembly, function for calculating dot product within C and main
MP2_asmfile contains the "back-end" for calculating a double floating point for dot product.

## To run
Firstly, store all the files in a single directory. 
Next, run `run.bat`. This automatically runs the assembling and compiling command lines to connect C and x86 ASM. Afterwards, click on the directory address of File Explorer, type `cmd` then type `MP2_cfile.exe` and it should run automatically.

## Notes
For now, there are fixed values. If you want to change the values, open `MP2_cfile.c` then change the values accordingly. If you want to increase or decrease, please make sure the elements of the vectors correspond to the vector size. 
More comments found in the C file. 
Furthermore, if you would like to check for validity of the dot product entirely, visit this website https://www.calculatorsoup.com/calculators/algebra/dot-product-calculator.php.
Just copy paste the elements of the vectors and calculate in the site.
