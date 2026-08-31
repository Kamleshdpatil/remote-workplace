.section .rodata
    msg_print_addess:
    .string "%d\n"

    msg_print_enter_arr_value:
    .string "Enter arr[%d][%d] value:\t"

    msg_scanf:
    .string "%d"

.section .text
.globl main
.type main, @function

main:

    pushl   %ebp
    movl    %esp, %ebp

    # -- arr[3][4]
    subl    $48, %esp

    # -- printf 1
    leal    -48(%ebp), %ebx
    pushl   %ebx
    pushl   $msg_print_addess
    call    printf
    addl    $8, %esp

    # -- print &arr[2][3]
    movl    $4, %eax    # int size
    movl    $4, %ecx    # column size(element count)
    mull    %ecx        # 4 * 4

    # movl    %eax, %ecx  # size ch backup => ecx
    movl    $2, %ecx    # column 2
    mull    %ecx

    leal    -48(%ebp), %ebx
    addl    %eax, %ebx

    movl    $3, %eax    # row 3
    leal    (%ebx, %eax, 4), %ebx

    pushl   %ebx
    pushl   $msg_print_addess
    call    printf
    addl    $8, %esp

    # -------------------------------
    # -- printf enter
    pushl   $3
    pushl   $2
    pushl   $msg_print_enter_arr_value
    call    printf
    addl    $12, %esp

    # -- scanf

    # -- &arr[2][3]
    movl    $4, %eax    # int size
    movl    $4, %ecx    # column size(element count)
    mull    %ecx        # 4 * 4
    movl    %eax, %ecx  # size ch backup => edx
    movl    $2, %eax    # column 2
    mull    %ecx

    leal    -48(%ebp), %ebx
    addl    %eax, %ebx

    movl    $3, %eax    # row 3
    leal    (%ebx, %eax, 4), %ebx

    pushl   %ebx
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    # -------------------------------
    # -- printf value of arr[2][3]
    movl    $4, %eax    # int size
    movl    $4, %ecx    # column size(element count)
    mull    %ecx        # 4 * 4
    movl    %eax, %ecx  # size ch backup => edx
    movl    $2, %eax    # column 2
    mull    %ecx

    leal    -48(%ebp), %ebx
    addl    %eax, %ebx

    movl    $3, %eax    # row 3
    movl    (%ebx, %eax, 4), %eax

    pushl   %eax
    pushl   $msg_print_addess
    call    printf
    addl    $8, %esp

    pushl   $0
    call    exit
