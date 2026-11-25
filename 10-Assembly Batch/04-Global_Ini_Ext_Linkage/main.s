.section .rodata
    msg_print_g_value:
    .string "In main, Number is %d\n"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl   %esp, %ebp

    # -- Print value of g_iNo in main
    movl    g_iNo, %eax
    pushl   %eax
    pushl   $msg_print_g_value
    call    printf
    addl    $8, %esp

    call    fun

    # -- exit
    pushl   $0
    call    exit

