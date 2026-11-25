.section .rodata
    msg_enter_number:
    .string "Enter number: \t"

    msg_scanf:
    .string "%d"

    msg_number_less_than_2:
    .string "Number is less than 2\n"

    msg_number_greater_than_2:
    .string "Number is greater than 2\n"

    msg_number_is_2:
    .string "Number is  2\n"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    subl    $4, %esp

    pushl   $msg_enter_number
    call    printf
    addl    $4, %esp

    leal    -4(%ebp), %eax
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    # -- if_else_if
    movl    -4(%ebp), %eax
    cmpl    $2, %eax

    jge     label_is_2    
    pushl   $msg_number_less_than_2
    call    printf
    addl    $4, %esp
    jmp     label_exit

label_greater_than_2:
    pushl   $msg_number_greater_than_2
    call    printf
    addl    $4, %esp
    jmp     label_exit

label_is_2:
    jg      label_greater_than_2      
    pushl   $msg_number_is_2
    call    printf
    addl    $4, %esp

label_exit:
    pushl   $0
    call    exit
