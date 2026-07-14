.section .rodata
    msg_enter_two_number:
    .string "Enter two numbers: \t"

    msg_scanf:
    .string "%d%d"

    msg_main_print_values:
    .string "In main, iNo1: %d iNo2: %d iNo3: %d\n"

.section .data
.globl iNo1
.align 4
.type iNo1, @object
iNo1:
    .int 10
    
.section .bss
.comm   iNo2, 4, 4

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # -- Local variable 
    subl    $4, %esp

    # -- Print: Enter two numbers
    pushl   $msg_enter_two_number
    call    printf
    addl    $4, %esp

    # -- Scanf
    leal    -4(%ebp), %eax
    pushl   %eax
    pushl   $iNo2
    pushl   $msg_scanf
    call    scanf
    addl    $12, %esp

    # -- Print values
    pushl   -4(%ebp)    
    pushl   iNo2
    pushl   iNo1
    pushl   $msg_main_print_values
    call    printf
    addl    $16, %esp

    # -- call fun1
    call fun1

    pushl   $0
    call    exit

