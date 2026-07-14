.section .rodata
    msg_print_g_value_uninitilized:
    .string "In fun, Number is %d\n"

    msg_print_g_value_after_assign_value:
    .string "In fun, after assign Number is %d\n"

.section .bss
.comm g_iNo, 4, 4

.section .text
.globl fun
.type fun, @function

fun:
    pushl   %ebp
    movl   %esp, %ebp

    # --  Print value of g_iNo inside fun
    movl    g_iNo, %eax
    pushl   %eax
    pushl   $msg_print_g_value_uninitilized
    call    printf
    addl    $8, %esp    #clean up

    # --  Print value of g_iNo inside fun after assign value
    movl    $100, %eax
    movl    %eax, g_iNo
    pushl   %eax
    pushl   $msg_print_g_value_after_assign_value
    call    printf
    addl    $8, %esp    #clean up

    movl    %ebp, %esp
    popl    %ebp
    ret
