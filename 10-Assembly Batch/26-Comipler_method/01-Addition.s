.section .rodata
    msg_enter_two_numbers:
    .string "Enter two numbers: \t"

    msg_scanf_two:
    .string "%d %d"

    msg_print_addition:
    .string "Addition: %d\n"

.section .text
.type addition, @function

addition:
    pushl   %ebp
    movl    %esp, %ebp

    # subl    $16, %esp

    movl    8(%ebp), %eax
    movl    12(%ebp), %edx
    addl    %edx, %eax

    # movl    %eax, -4(%ebp)

    movl    %ebp, %esp
    popl    %ebp
    ret

.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    andl    $-16, %esp

    subl    $32, %esp

    movl    $msg_enter_two_numbers, (%esp)
    call    printf

    leal    -4(%ebp), %eax
    leal    -8(%ebp), %edx
    movl    $msg_scanf_two, (%esp)
    movl    %eax, 4(%esp)
    movl    %edx, 8(%esp)
    call    scanf

    movl    -4(%ebp), %eax
    movl    -8(%ebp), %edx
    movl    %eax, (%esp)
    movl    %edx, 4(%esp)
    call    addition

    # movl    %eax, -12(%ebp)

    movl    $msg_print_addition, (%esp)
    movl    %eax, 4(%esp)
    call    printf

    movl    $0, (%esp)
    call    exit
