.section .rodata
    msg_enter_number:
    .string "Enter number: \t"

    msg_scanf:
    .string "%d"

    msg_print_values_in_fun:
    .string "In fun1, iNo1 is %d & iNo2 is %d\n"

    msg_print_static_fun2:
    .string "In static fun2"

.section .bss
    .lcomm  iNo1, 4

.section .data
    .align 4
    .type iNo2, @object
    iNo2:
    .int 40

.section .text
.globl fun1
.type fun1, @function

fun1:
    pushl   %ebp
    movl    %esp, %ebp

    # -- Print Enter number
    pushl   $msg_enter_number
    call    printf
    addl    $4, %esp

    # -- Scanf
    pushl   $iNo1
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    # -- Print Values
    # movl    iNo1, %eax
    # movl    iNo2, %edx
    pushl   iNo2
    pushl   iNo1
    pushl   $msg_print_values_in_fun
    call    printf
    addl    $12, %esp

    # -- Call fun2
    call    fun2
    
    # -- No need this two instructions when local variables are not there 
    movl    %ebp, %esp
    popl    %ebp

    ret

.type fun2, @function

fun2:
    pushl   %ebp
    movl    %esp, %ebp

    # -- Print Message
    pushl   $msg_print_static_fun2
    call    printf
    addl    $4, %esp

    # -- No need this two instructions when local variables are not there
    movl    %ebp, %esp
    popl    %ebp

    ret

