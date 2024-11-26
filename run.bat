nasm -f win64 MP2_asmfile.asm
gcc -c MP2_cfile.c -o MP2_cfile.obj -m64
gcc MP2_cfile.obj MP2_asmfile.obj -o MP2_cfile.exe -m64