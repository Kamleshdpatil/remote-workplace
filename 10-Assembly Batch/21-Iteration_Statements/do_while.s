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

    leal    -4(%ebp), %eax      # iNo = number
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    movl    $0, -8(%ebp)        # iCounter = 0
    movl    -8(%ebp), %eax

    # -- do
label_do:
    pushl   %eax
    pushl   $msg_printf
    call    printf
    addl    $8, %esp

    addl    $1, -8(%ebp)
    
    movl    -4(%ebp), %edx
    movl    -8(%ebp), %eax
    cmpl    %edx, %eax
    jl      label_do

    pushl   $0
    call    exit
