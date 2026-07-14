.section .rodata
    msg_print_g_value_initilized:
    .string "In fun, Number is %d\n"

    msg_print_g_address:
    .string "In fun, Address is %d\n"

.section .data
.align 4
.type g_iNo, @object
g_iNo:
    .int 100

.section .text
.globl fun
.type fun, @function

fun:
    pushl   %ebp
    movl   %esp, %ebp

    # --  Print value of g_iNo inside fun
    movl    g_iNo, %eax
    pushl   %eax
    pushl   $msg_print_g_value_initilized
    call    printf
    addl    $8, %esp    #clean up

    movl    $g_iNo, %eax
    pushl   %eax
    pushl   $msg_print_g_address
    call    printf
    addl    $8, %esp    #clean up

    movl    %ebp, %esp
    popl    %ebp
    ret
