.section .rodata
    msg_print:
    .string "%d\n"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # -- Local variable
    subl    $4, %esp

    # -- assign 10 value
    movl    $10, -4(%ebp)

    # -- print -100
    movl    $100, %eax
    negl    %eax
    pushl   %eax
    pushl   $msg_print
    call    printf
    addl    $8, %esp

    # -- print iNo1
    movl   -4(%ebp), %eax
    pushl   %eax
    pushl   $msg_print
    call    printf
    addl    $8, %esp

    # -- print -iNo1
    movl   -4(%ebp), %eax
    negl    %eax
    pushl   %eax
    pushl   $msg_print
    call    printf
    addl    $8, %esp

    # -- print after unary minus value: iNo1
    movl   -4(%ebp), %eax
    pushl   %eax
    pushl   $msg_print
    call    printf
    addl    $8, %esp

    pushl   $0
    call    exit
