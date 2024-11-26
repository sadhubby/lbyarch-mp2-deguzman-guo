section .text
    bits 64                    
    default rel                
    global dot_product_asm    
    extern printf
dot_product_asm:
  

    xorps xmm0, xmm0           

.loop:
    cmp rcx, 0               
    je .done                  

    movsd xmm1, qword [rdx]   
    movsd xmm2, qword [r8]    
    mulsd xmm1, xmm2           
    addsd xmm0, xmm1           

    add rdx, 8                 
    add r8, 8                 
    dec rcx                    
    jmp .loop                  

.done:
    ret
