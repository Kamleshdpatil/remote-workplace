.section .data
    msg_print_operand_1:
    .string "Enter Operand 1: "
    msg_print_operand_2:
    .string "Enter Operand 2: "
    msg_answer:
    .string "\nMultiplication is: %d\n"
    msg_scanf:
    .string "%d"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # -- Local variables -> 3
    subl    $16, %esp

    # -- Print Enter operand 1
    pushl   $msg_print_operand_1
    call    printf
    addl    $4, %esp

    # -- Scan operand 1
    leal    -4(%ebp), %eax
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    # -- Print Enter operand 2
    pushl   $msg_print_operand_2
    call    printf
    addl    $4, %esp

    # -- Scan operand 2
    leal    -8(%ebp), %eax
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    # -- Multiplication
    movl    -4(%ebp), %eax
    movl    -8(%ebp), %ecx
    mull    %ecx
    movl    %eax, -16(%ebp)     # LSB (Lower Address)
    movl    %edx, -12(%ebp)     # MSB (Higher Address)
    
    # -- Print answer
    pushl   %edx
    pushl   %eax
    pushl   $msg_answer
    call    printf
    addl    $12, %esp

    pushl   $0
    call    exit
