.section    .rodata
    msg_enter_number:
    .string "Enter a number: \t"

    msg_scanf:
    .string "%d"

    msg_answer_odd:
    .string "\nNumber is odd !!\n"

    msg_answer_even:
    .string "\nNumber is even !!\n"

.section    .text
.globl  main
.type   main, @function

main:

    pushl   %ebp
    movl    %esp, %ebp

    # -- Local variables
    subl    $4, %esp

    # -- Print Enter message
    pushl   $msg_enter_number
    call    printf
    addl    $4, %esp

    # -- Scan numbers
    leal    -4(%ebp), %eax
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp
    
    # if(number % 2 == 0)
    movl    -4(%ebp), %eax
    xorl    %edx, %edx
    movl    $2, %ecx
    divl    %ecx
    cmpl    $0, %edx
    je      label_even
    pushl   $msg_answer_odd
    call    printf
    addl    $4, %esp
    jmp     label_exit

label_even:
    pushl   $msg_answer_even
    call    printf
    addl    $4, %esp

label_exit:
    pushl   $0
    call    exit
