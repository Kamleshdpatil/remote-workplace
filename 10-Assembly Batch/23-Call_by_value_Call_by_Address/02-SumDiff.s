.section .rodata
    msg_enter_two__number:
    .string "Enter two numbers: "

    msg_scanf_two:
    .string "%d%d"

    msg_sum_is:
    .string "Sum is: %d\n"

    msg_diff_is:
    .string "Difference is: %d\n"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    subl    $16, %esp

    pushl   $msg_enter_two__number
    call    printf
    addl    $4, %esp

    leal    -4(%ebp), %eax
    leal    -8(%ebp), %edx
    pushl   %edx
    pushl   %eax
    pushl   $msg_scanf_two
    call    scanf
    addl    $12, %esp

    movl    -4(%ebp), %eax
    movl    -8(%ebp), %edx

    leal    -12(%ebp), %ebx
    # movl   $0, %edx

    leal   -16(%ebp), %ecx 
    # movl   $0, %ecx

    pushl   %ecx
    pushl   %ebx
    pushl   %edx
    pushl   %eax
    call    sum_diff
    addl    $16, %esp

    movl    -12(%ebp), %eax
    pushl   %eax
    pushl   $msg_sum_is
    call    printf
    addl    $8, %esp

    movl    -16(%ebp), %eax
    pushl   %eax
    pushl   $msg_diff_is
    call    printf
    addl    $8, %esp

    pushl   $0
    call    exit

.globl sum_diff
.type sum_diff, @function

sum_diff:
    pushl   %ebp
    movl    %esp, %ebp

    movl    8(%ebp), %eax       # iNo1
    movl    12(%ebp), %edx      # iNo2

    # ------- Sum -------
    movl    16(%ebp), %ebx      # *piSumm
    addl    %edx, %eax          # iNo1 + iNo2
    movl    %eax, (%ebx)

    # ------- Diff -------
    movl    8(%ebp), %eax       # iNo1
    movl    20(%ebp), %ebx      # *piDiff
    subl    %edx, %eax          # iNo1 - iNo2
    movl    %eax, (%ebx)

    # --------------
    movl    %ebp, %esp
    popl    %ebp

    ret   
