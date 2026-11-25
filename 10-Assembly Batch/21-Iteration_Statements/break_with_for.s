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

    leal    -4(%ebp), %eax      # iNo
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    # -- for loop
    movl    $1, -8(%ebp)        # Assignemnt
for_loop_condition:
    movl    -4(%ebp), %eax      # iNo
    movl    -8(%ebp), %edx      # iCounter
    cmpl    %eax, %edx
    jl      label_for_statement
    jmp     label_exit

label_for_statement:
    movl    -8(%ebp), %eax      # iCounter
    xorl    %edx, %edx
    movl    $2, %ecx            # denominator
    divl    %ecx

    cmpl    $0, %edx
    je      label_exit
    
    pushl   -8(%ebp)
    pushl   $msg_printf
    call    printf
    addl    $8, %esp

    addl    $1, -8(%ebp)
    jmp     for_loop_condition

label_exit:
    pushl   $0
    call    exit
