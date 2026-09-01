.equ MAX, 10
.equ INT_SIZE, 4

.section .rodata
    msg_enter_row_and_columns:
    .string "Enter value of rows & columns(< %d):\t"

    msg_scanf:
    .string "%d"

    msg_scanf_two:
    .string "%d%d"

    msg_enter_value_of_element:
    .string "Enter [%d][%d] value:\t"

    msg_entered_eleemnts_are:
    .string "Entered elements are: \n"

    msg_print_index_element:
    .string "[%d][%d] value is:\t%d\n"

.section .text
.globl main
.type main, @function

main:
    pushl  %ebp
    movl   %esp, %ebp

    # -- local vars
    subl    $416, %esp           # iRows, iColumns, iCounter1, iCounter2, arr

    # -- enter iRows value
    pushl   $MAX
    pushl   $msg_enter_row_and_columns
    call    printf
    addl    $8, %esp

    leal    -4(%ebp), %eax      # iRows
    leal    -8(%ebp), %edx      # iColumns
    pushl   %edx
    pushl   %eax
    pushl   $msg_scanf_two
    call    scanf
    addl    $12, %esp

# -------------------------------------------------------------
    # -- 1st loop -- Outer
    movl    $0, -12(%ebp)           # iCounter1
    jmp     label_for_outer_loop_cond_loop1

label_for_outer_loop_statement_loop1:
    movl    $0, -16(%ebp)           # iCounter2
    jmp     label_for_inner_loop_cond_loop1

    # -- 1st loop -- Inner
    label_for_inner_loop_statement_loop1:
        pushl   %eax                # iCounter2
        movl    -12(%ebp), %edx
        pushl   %edx                # iCounter1
        pushl   $msg_enter_value_of_element
        call    printf
        addl    $12, %esp

        # -- &arr[iCounter1][iCounter2]
        movl    $INT_SIZE, %eax
        movl    $MAX, %ecx
        mull    %ecx
        movl    %eax, %ecx

        movl    -12(%ebp), %eax     # iCounter1
        mull    %ecx

        leal    -416(%ebp), %ebx    # arr
        addl    %eax, %ebx

        movl    -16(%ebp), %eax     # iCounter2
        leal    (%ebx, %eax, 4), %ebx

        pushl   %ebx
        pushl   $msg_scanf
        call    scanf
        addl    $8, %esp

        addl    $1, -16(%ebp)     # iCounter2++

        # -----------------------------
    label_for_inner_loop_cond_loop1:
        movl    -16(%ebp), %eax     # iCounter2
        movl    -8(%ebp), %edx      # iColumns
        cmpl    %edx, %eax
        jl      label_for_inner_loop_statement_loop1

        addl    $1, -12(%ebp)     # iCounter1++

label_for_outer_loop_cond_loop1:
    movl    -12(%ebp), %eax     # iCounter1
    movl    -4(%ebp), %edx      # iRows
    cmpl    %edx, %eax
    jl      label_for_outer_loop_statement_loop1

    # -- Entered elements are: 
    pushl   $msg_entered_eleemnts_are
    call    printf
    addl    $4, %esp
    
# -------------------------------------------------------------
    # -- 2nd loop -- Outer
    movl    $0, -12(%ebp)           # iCounter1
    jmp     label_for_outer_loop_cond_loop2

label_for_outer_loop_statement_loop2:
    movl    $0, -16(%ebp)           # iCounter2
    jmp     label_for_inner_loop_cond_loop2

    # -- 2nd loop -- Inner
    label_for_inner_loop_statement_loop2:

        # -- print arr[iCounter1][iCounter2]
        movl    $INT_SIZE, %eax
        movl    $MAX, %ecx
        mull    %ecx
        movl    %eax, %ecx

        movl    -12(%ebp), %eax     # iCounter1
        mull    %ecx

        leal    -416(%ebp), %ebx    # arr
        addl    %eax, %ebx

        movl    -16(%ebp), %eax     # iCounter2
        movl    (%ebx, %eax, 4), %edx

        movl    -12(%ebp), %ebx     # iCounter1

        pushl   %edx
        pushl   %eax                # iCounter2
        pushl   %ebx
        pushl   $msg_print_index_element
        call    printf
        addl    $16, %esp

        addl    $1, -16(%ebp)     # iCounter2++

        # -----------------------------
    label_for_inner_loop_cond_loop2:
        movl    -16(%ebp), %eax     # iCounter2
        movl    -8(%ebp), %edx      # iColumns
        cmpl    %edx, %eax
        jl      label_for_inner_loop_statement_loop2

        addl    $1, -12(%ebp)     # iCounter1++

label_for_outer_loop_cond_loop2:
    movl    -12(%ebp), %eax     # iCounter1
    movl    -4(%ebp), %edx      # iRows
    cmpl    %edx, %eax
    jl      label_for_outer_loop_statement_loop2

    # -----loop end--------

    pushl   $0
    call    exit
