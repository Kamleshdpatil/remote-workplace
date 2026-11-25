.section .rodata
    msg_print_g_value_uninitilized:
    .string "In fun, Number is %d\n"

    msg_print_g_address:
    .string "In fun, Address is %d\n"

    msg_print_g_value_after_assign_value:
    .string "In fun, after assign value Number is %d\n"

.section .data
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

    # --  Print Address of g_iNo inside fun
    movl    $g_iNo, %eax
    pushl   %eax
    pushl   $msg_print_g_address
    call    printf
    addl    $8, %esp    #clean up

    # --  Print value of g_iNo inside fun after initilized
    movl    g_iNo, %eax
    movl    $300, %eax
    pushl   %eax
    pushl   $msg_print_g_value_after_assign_value
    call    printf
    addl    $8, %esp    #clean up

    movl    %ebp, %esp
    popl    %ebp
    ret
