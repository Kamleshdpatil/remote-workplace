.section .data
    msg_print:
    .string "iNo1 = %d, iNo2 = %d\niAns1 = %d, iAns2 = %d\n"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # -- Local variables -> 4
    subl    $16, %esp

    # -- assign value to iNo1 and iNo2
    movl    $10, -4(%ebp)       # iNo1
    movl    $20, -8(%ebp)       # iNo2

    # --iNo1
    subl    $1, -4(%ebp)
    movl    -4(%ebp), %eax
    movl    %eax, -12(%ebp)     # iAns1 = --iNo1

    # iAns2 = iNo2--;
    movl    -8(%ebp), %edx
    movl    %edx, -16(%ebp)
    subl    $1, -8(%ebp)        # iNo2--

    # Read values from memory address to push
    movl    -8(%ebp), %ecx      # iNo2

    # Push values from register to print
    pushl   %edx                # iAns2
    pushl   %eax                # iAns1
    pushl   %ecx                # iNo2
    pushl   %eax                # iNo1
    pushl   $msg_print
    call    printf
    addl    $20, %esp

    pushl   $0
    call    exit
