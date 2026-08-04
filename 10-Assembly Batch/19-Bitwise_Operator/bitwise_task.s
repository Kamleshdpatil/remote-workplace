.section .rodata
    msg_enter_two_number:
    .string "Enter two numbers: "

    msg_scanf:
    .string "%d%d"

    msg_and_result:
    .string "iNo1 AND iNo2 : %d\n"

    msg_or_result:
    .string "iNo1 OR iNo2 : %d\n"

    msg_xor_result:
    .string "iNo1 XOR iNo2 : %d\n"

    msg_not_result:
    .string "~iNo2 : %d\n"

    msg_left_shift_result:
    .string "iNo1 << 2 : %d\n"

    msg_right_shift_result:
    .string "iNo1 >> 2 : %d\n"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # -- Two Local variables
    subl    $8, %esp

    # -- print enter number
    pushl   $msg_enter_two_number
    call    printf
    addl    $4, %esp

    # -- scan two numbers
    leal    -4(%ebp), %eax
    leal    -8(%ebp), %edx
    pushl   %edx
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $12, %esp

    # printf("iNo1 AND iNo2 : %d\n", iNo1 & iNo2);
    movl    -4(%ebp), %eax
    movl    -8(%ebp), %edx
    andl    %eax, %edx
    pushl   %edx
    pushl   $msg_and_result
    call    printf
    addl    $8, %esp

    # printf("iNo1 OR iNo2 : %d\n", iNo1 | iNo2);
    movl    -4(%ebp), %eax
    movl    -8(%ebp), %edx
    orl     %eax, %edx
    pushl   %edx
    pushl   $msg_or_result
    call    printf
    addl    $8, %esp

    # printf("iNo1 XOR iNo2 : %d\n", iNo1 ^ iNo2);
    movl    -4(%ebp), %eax
    movl    -8(%ebp), %edx
    xorl     %eax, %edx
    pushl   %edx
    pushl   $msg_xor_result
    call    printf
    addl    $8, %esp
    
    # printf("~iNo2 : %d\n", ~iNo2);
    movl    -8(%ebp), %eax
    notl    %eax
    pushl   %eax
    pushl   $msg_not_result
    call    printf
    addl    $8, %esp

    # printf("iNo1 << 2 : %d\n", iNo1 << 2);
    movl    -4(%ebp), %eax
    sall    $2, %eax
    pushl   %eax
    pushl   $msg_left_shift_result
    call    printf
    addl    $8, %esp

    # printf("iNo1 >> 2 : %d\n", iNo1 >> 2);
    movl    -4(%ebp), %eax
    sarl    $2, %eax
    pushl   %eax
    pushl   $msg_right_shift_result
    call    printf
    addl    $8, %esp

    pushl   $0
    call    exit

