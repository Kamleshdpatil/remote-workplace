.equ MAX, 10

.section .rodata
    msg_enter_value_of_iMax:
    .string "Enter value of n(< %d):\t"

    msg_scanf:
    .string "%d"

    msg_enter_value_of_element:
    .string "Enter %d value: \t"    

    msg_print_array1_is:
    .string "arr1 is: \n"

    msg_print_array2_is:
    .string "arr2 is: \n"

    msg_print_index_element:
    .string "%d value is:\t%d\n"


.section .data
.globl arr1
.type arr1, @object
.size arr1, 12
.align 4

arr1:
    .int 10, 20, 30

.section .bss
.comm arr2, 40, 4

.section .text
.globl main
.type main, @function

main:
    pushl  %ebp
    movl   %esp, %ebp

    # -- local vars
    subl    $8, %esp

    # -- enter iMax value
    pushl   $MAX
    pushl   $msg_enter_value_of_iMax
    call    printf
    addl    $8, %esp

    leal    -4(%ebp), %eax      # iMax
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    # -----loop start--------
    # -- 1st loop
    movl    $0, -8(%ebp)        # iCounter = 0
    jmp     label_for_cond_loop1

label_statement_loo1:
    # -- enter element value
    # movl    -8(%ebp), %eax      # iCounter  // Optimized
    pushl   %eax
    pushl   $msg_enter_value_of_element
    call    printf
    addl    $8, %esp

    # leal    arr2, %ebx
    movl    -8(%ebp), %eax      # iCounter
    leal    arr2(, %eax, 4), %edx
    pushl   %edx
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    addl    $1, -8(%ebp)        # iCounter++

label_for_cond_loop1:
    movl    -8(%ebp), %eax      # iCounter
    movl    -4(%ebp), %edx      # iMax
    cmpl    %edx, %eax
    jl      label_statement_loo1

    # -----loop end--------

label_print_array1:
    pushl   $msg_print_array1_is
    call    printf
    addl    $4, %esp

    # -- 2nd loop
    movl    $0, -8(%ebp)        # iCounter = 0
    jmp     label_for_cond_loop2

label_statement_loop2:
    # -- enter element value
    # movl    -8(%ebp), %eax      # iCounter // Optimized
    movl    arr1(, %eax, 4), %edx
    pushl   %edx
    pushl   %eax
    pushl   $msg_print_index_element
    call    printf
    addl    $12, %esp

    addl    $1, -8(%ebp)        # iCounter++

label_for_cond_loop2:
    movl    -8(%ebp), %eax      # iCounter
    cmpl    $3, %eax
    jl      label_statement_loop2

    # -----loop end--------

label_print_array2:
    pushl   $msg_print_array2_is
    call    printf
    addl    $4, %esp

    # -- 3rd loop
    movl    $0, -8(%ebp)        # iCounter = 0
    jmp     label_for_cond_loop3

label_statement_loop3:
    # -- enter element value
    # movl    -8(%ebp), %eax      # iCounter // Optimized
    movl    arr2(, %eax, 4), %edx
    pushl   %edx
    pushl   %eax
    pushl   $msg_print_index_element
    call    printf
    addl    $12, %esp

    addl    $1, -8(%ebp)

label_for_cond_loop3:
    movl    -8(%ebp), %eax      # iCounter
    movl    -4(%ebp), %edx      # iMax
    cmpl    %edx, %eax
    jl      label_statement_loop3

    # -----loop end--------

    pushl   $0
    call    exit
