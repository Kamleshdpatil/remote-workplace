.section .rodata
    msg_print_g_value:
    .string "g is %d\n"

    msg_print_g_address:
    .string "&g is %d\n"

.section .data
.globl g
.type g, @object
.size g, 4
.align 4
g:
    .int 10

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # -- Print value of g --
    movl    g, %eax
    pushl   %eax
    pushl   $msg_print_g_value
    call    printf
    addl    $8, %esp    #clean up 8 bytes(4 bytes of g, 4 bytes of string)

    # -- Print Address of g --
    movl    $g,  %ebx
    pushl   %ebx
    pushl   $msg_print_g_address
    call    printf
    addl    $8, %esp    #clean up 8 bytes(4 bytes of g, 4 bytes of string)

    # -- Exit
    pushl   $0
    call    exit
