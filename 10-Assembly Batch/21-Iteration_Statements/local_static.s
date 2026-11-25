.section .rodata
    msg_calling_fun1:
    .string "\nCalling fun1\n"

    msg_calling_fun2:
    .string "\nCalling fun2\n"

    msg_fun1_printf:
    .string "In fun1, iNo = %d\n"

    msg_fun2_printf:
    .string "In fun2, iNo = %d\n"

.section .data
    .align 4
    .type iNo_fun1, @object
    iNo_fun1:
    .int 10

.section .text
.type fun1, @function

fun1:
    pushl   %ebp
    movl    %esp, %ebp

    subl    $4, %esp

    movl    $10, -4(%ebp)
    movl    -4(%ebp), %eax
    addl    $1, %eax
    movl    %eax, -4(%ebp)

    pushl   %eax
    pushl   $msg_fun1_printf
    call    printf
    addl    $8, %esp

    movl    %ebp, %esp
    popl    %ebp

    ret


.type fun2, @function
fun2:
    pushl   %ebp
    movl    %esp, %ebp

    movl    iNo_fun1, %eax
    addl    $1, %eax
    movl    %eax, iNo_fun1

    pushl   iNo_fun1
    pushl   $msg_fun1_printf
    call    printf
    addl    $8, %esp

    movl    %ebp, %esp
    popl    %ebp

    ret

.globl  main
.type main, @function
main:
    pushl   %ebp
    movl    %esp, %ebp

    subl    $4, %esp

    # -- printf fun2
    pushl   $msg_calling_fun1
    call    printf
    addl    $4, %esp

    # -- fun1 for loop
    movl    $0, -4(%ebp)
    jmp     fun1_for_loop_cond

label_for_fun1_statement:
    call    fun1
    addl    $1, -4(%ebp)

fun1_for_loop_cond:
    movl    -4(%ebp), %eax
    cmpl    $3, %eax
    jl      label_for_fun1_statement

    # -- printf fun2
    pushl   $msg_calling_fun2
    call    printf
    addl    $4, %esp

    # -- fun2 for loop
    movl    $0, -4(%ebp)
    jmp     fun2_for_loop_cond

label_for_fun2_statement:
    call    fun2
    addl    $1, -4(%ebp)

fun2_for_loop_cond:
    movl    -4(%ebp), %eax
    cmpl    $3, %eax
    jl      label_for_fun2_statement

    pushl   $0
    call    exit
