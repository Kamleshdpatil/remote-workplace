.section .rodata
    msg_print_float:
    .string "fNo1 = %f\tfNo2 = %f\n"

    msg_print_double:
    .string "dNo1 = %lf\tdNo2 = %lf\n"


# ----------- Data Section -------------
.section .data
.globl fNo1
.align 4
.type fNo1, @object
fNo1:
    .float 57.33

.globl dNo1
.type dNo1, @object
.align 4
dNo1:
    .double 58963.546

# ----------- BSS Section -------------
.section .bss
.comm fNo2, 4, 4
.comm dNo2, 8, 4

# ----------- Text Section -------------
.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # -- local variables
    subl    $32, %esp

    #
    # Attemp 1 (Failure)
    #

    # print fNo1 & fNo2
    # fNo1
    movl    $msg_print_float, (%esp)
    movl    fNo1, %eax
    movl    %eax, 4(%esp)

    # fNo2
    movl    fNo2, %edx
    movl    %edx, 8(%esp)
    call    printf

    # ------------------------

    # print dNo1 & dNo2
    movl    $msg_print_double, (%esp)
    # dNo1
    movl    (dNo1), %eax
    movl    (dNo1)+4, %edx

    movl    %eax, 4(%esp)
    movl    %edx, 8(%esp)

    # dNo1
    movl    (dNo2), %eax
    movl    (dNo2)+4, %edx

    movl    %eax, 12(%esp)
    movl    %edx, 16(%esp)
    call    printf

    movl    $-1, (%esp)
    call    exit
