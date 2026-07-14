.section .rodata
    msg_reg1_ebx_value:
    .string "Register1 value: %d\n"

    msg_reg2_esi_value:
    .string "Register2 value: %d\n"

    msg_reg3_edi_value:
    .string "Register3 value: %d\n"

.section .text
.globl main
.type main, @function

main:
    pushl  %ebp 
    movl   %esp, %ebp

    # -- Strore and Print ebx
    movl    $100, %ebx
    pushl   %ebx
    pushl   $msg_reg1_ebx_value
    call    printf
    addl    $8, %esp

    # -- Strore and Print ebx
    movl    $200, %esi
    pushl   %esi
    pushl   $msg_reg2_esi_value
    call    printf
    addl    $8, %esp

    # -- Strore and Print ebx
    movl    $300, %edi
    pushl   %edi
    pushl   $msg_reg3_edi_value
    call    printf
    addl    $8, %esp

    pushl   $0
    call    exit
