.section .data
    msg_print:
    .string "iNo1 = %d, iNo2 = %d\niAns1 = %d, iAns2 = %d\n"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # -- Local variables - 4
    subl    $16, %esp

    # -- assign value to iNo1
    movl    $10, -4(%ebp)       # iNo1
    movl    $20, -8(%ebp)       # iNo2

    # ++iNo1
    addl    $1, -4(%ebp)
    movl    -4(%ebp), %eax
    movl    %eax, -12(%ebp)     # iAns1 = ++iNo1

    # iAns2 = iNo2++;
    movl    -8(%ebp), %eax
    movl    %eax, -16(%ebp)
    addl    $1, -8(%ebp)

    # Read values from memory address to push
    movl    -4(%ebp), %eax
    movl    -8(%ebp), %edx
    movl    -12(%ebp), %ecx
    movl    -16(%ebp), %ebx

    # Push values from register to print
    pushl   %ebx
    pushl   %ecx
    pushl   %edx
    pushl   %eax
    pushl   $msg_print
    call    printf
    addl    $20, %esp

    pushl   $0
    call    exit
