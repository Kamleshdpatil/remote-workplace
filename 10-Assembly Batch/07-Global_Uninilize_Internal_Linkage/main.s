.section .rodata
    msg_print_g_value:
    .string "In main, Number is %d\n"

    msg_print_g_address:
    .string "In main, Address is %d\n"

    msg_print_g_value_initilized_in_fun:
    .string "In main, after assign value inside fun Number is %d\n"

.section .text
.globl main
.type main, @function

.section .bss
.align 4
.type g_iNo, @object

main:
    pushl  %ebp
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

    # -- Print value of g_iNo in main after initilize in fun()
    movl    g_iNo, %eax
    pushl   %eax
    pushl   $msg_print_g_value_initilized_in_fun
    call    printf
    addl    $8, %esp

    # -- exit
    pushl   $0
    call    exit

