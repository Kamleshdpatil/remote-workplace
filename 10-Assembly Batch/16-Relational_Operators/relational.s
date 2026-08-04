.section    .rodata
    msg_enter_three_number:
    .string "Enter three number: \t"

    msg_scanf_three:
    .string "%d%d%d"

    msg_answer:
    .string "Answer is: %d\n"

.section    .text
.globl  main
.type   main, @function

main:

    pushl   %ebp
    movl    %esp, %ebp

    # -- Local variables
    subl    $16, %esp

    # -- Print Enter message
    pushl   $msg_enter_three_number
    call    printf
    addl    $4, %esp

    # -- Scan numbers
    leal    -4(%ebp), %eax
    leal    -8(%ebp), %edx
    leal    -12(%ebp), %ecx
    pushl   %ecx
    pushl   %edx
    pushl   %eax
    pushl   $msg_scanf_three
    call    scanf
    addl    $16, %esp

    # -- Logic of relational operation
    movl    -4(%ebp), %eax
    movl    -8(%ebp), %edx
    cmpl    %edx, %eax                  # -- Dusra pahilyashi compare 
    jl      label_less_than_iNo2
    movl    $0, %eax                    # Jar jl label la gela nahi tr
    jmp     label_not_less_than_iNo2

label_less_than_iNo2:
    movl    $1, %eax

label_not_less_than_iNo2:
    movl    -12(%ebp), %edx
    cmpl    %edx, %eax
    jne     label_not_equal_to_true
    movl    $0, %eax
    jmp     label_result

label_not_equal_to_true:
    movl    $1, %eax

label_result:
    movl    %eax, -16(%ebp)
    pushl   %eax
    pushl   $msg_answer
    call    printf
    addl    $8, %esp

    pushl   $0
    call    exit
