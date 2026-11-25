.section    .rodata
    msg_enter_three_number:
    .string "Enter three number: \t"

    msg_scanf_three:
    .string "%d%d%d"

    msg_answer:
    .string "\niNo1 = %d iNo2 = %d iNo3 = %d iAns = %d\n"

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

    # -- iAns =  iNo1 && ++iNo2 && ++iNo3;
    movl    -4(%ebp), %eax              # iNo1
    cmpl    $0, %eax                    # check if iNo1 is 0
    je      label_first_and_result      # jump if iNo1 == 0

    addl    $1, -8(%ebp)                # if iNo1 != 0, then increment iNo2
    movl    -8(%ebp), %eax              # iNo2

    cmpl    $0, %eax                    # check if iNo2 is 0
    je      label_first_and_result      # jump if iNo2 == 0
    movl    $1, %eax                    # if iNo1 != 0, then store true(1) into eax reg

label_first_and_result:
    cmpl    $0, %eax                    # check if iNo2 is 0
    je      label_second_ans_result     # jump if iNo2 == 0

    addl    $1, -12(%ebp)               # if iNo2 != 0, then then increment iNo3
    movl    -12(%ebp), %eax             # iNo3

    cmpl    $0, %eax                    # check if iNo3 is 0
    je      label_second_ans_result     # jump if iNo3 == 0
    movl    $1, %eax                    # if iNo3 != 0, then store true(1) into eax reg

label_second_ans_result:
    movl    %eax, -16(%ebp)             # store %eax value to iAns
    movl    -4(%ebp), %edx              # keep iNo1 value into %edx reg 
    movl    -8(%ebp), %ecx              # keep iNo2 value into %ecx reg
    # movl    -12(%ebp), %ebx             # keep iNo3 value into %ebx reg

    # -- push registers to print answer 
    pushl   %eax
    # pushl   %ebx
    pushl   -12(%ebp)
    pushl   %ecx
    pushl   %edx
    pushl   $msg_answer
    call    printf
    addl    $20, %esp                   # clean up

    pushl   $0
    call    exit
