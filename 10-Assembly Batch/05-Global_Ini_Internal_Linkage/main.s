.section .rodata
    msg_print_g_value:
    .string "In main, Number is %d\n"

    msg_print_g_address:
    .string "In main, Address is %d\n"

.section .text
.globl main
.type main, @function

.section .data
.align 4
.type g_iNo, @object
g_iNo:
    .int 500

main:
    pushl   %ebp
    movl   %esp, %ebp

    # -- Print value of g_iNo in main
    movl    g_iNo, %eax
    pushl   %eax
    pushl   $msg_print_g_value
    call    printf
    addl    $8, %esp

    # -- Print Address of g_iNo in main
    movl    $g_iNo, %eax
    pushl   %eax
    pushl   $msg_print_g_address
    call    printf
    addl    $8, %esp    #clean up

    call    fun

    # -- exit
    pushl   $0
    call    exit

