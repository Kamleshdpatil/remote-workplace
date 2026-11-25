.section .rodata
    msg_enter_number:
    .string "Enter number: "

    msg_choice_options:
    .string " 1. Addition\n 2. Substraction\n 3. Multiplication\n 4. Division\n"

    msg_scanf:
    .string "%d"

    msg_addition:
    .string "Addition\n"

    msg_substraction:
    .string "Substraction\n"

    msg_multiplication:
    .string "Multiplication\n"

    msg_division:
    .string "Division\n"

    msg_invalid_input:
    .string "Invalid input\n"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    subl    $4, %esp

    pushl   $msg_choice_options
    call    printf
    addl    $4, %esp

    pushl   $msg_enter_number
    call    printf
    addl    $4, %esp

    leal    -4(%ebp), %eax
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    # -- switch(iChoice)
    movl    -4(%ebp), %eax

    cmpl    $1, %eax
    je      label_addition

    cmpl    $2, %eax
    je      label_substraction

    cmpl    $3, %eax
    je      label_multiplication

    cmpl    $4, %eax
    je      label_division
    
    # other than 1 to 4
    jmp     label_ivalid_input

label_addition:
    pushl   $msg_addition
    call    printf
    addl    $4, %esp
    jmp     label_exit

label_substraction:
    pushl   $msg_substraction
    call    printf
    addl    $4, %esp
    jmp     label_exit

label_multiplication:
    pushl   $msg_multiplication
    call    printf
    addl    $4, %esp
    jmp     label_exit

label_division:
    pushl   $msg_division
    call    printf
    addl    $4, %esp
    jmp     label_exit

label_ivalid_input:
    pushl   $msg_invalid_input
    call    printf
    addl    $4, %esp

label_exit:
    pushl   $0
    call    exit
