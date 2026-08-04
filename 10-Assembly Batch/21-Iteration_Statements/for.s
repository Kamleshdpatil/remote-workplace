.section .data
    msg_enter_number:
    .string "Enter Number: "

    msg_scanf:
    .string "%d"

    msg_printf:
    .string "%d\n"

.section .text
.globl  main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    subl    $8, %esp

    pushl   $msg_enter_number
    call    printf
    addl    $4, %esp

    leal    -4(%ebp), %eax
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    # -- for loop
    movl    $0, -8(%ebp)
    jmp     label_for_cond

label_for_statement:
    pushl   %eax
    pushl   $msg_printf
    call    printf
    addl    $8, %esp

    addl    $1, -8(%ebp)

label_for_cond:
    movl    -8(%ebp), %eax
    movl    -4(%ebp), %edx
    cmpl    %edx, %eax
    jl      label_for_statement

    pushl   $0
    call    exit
