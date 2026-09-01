.equ NULL, 0
.equ INT_SIZE, 4
.equ INT_POINTER_SIZE, 4

.section .rodata
    msg_enter_row_and_columns:
    .string "Enter value of rows & columns:\t"

    msg_scanf:
    .string "%d"

    msg_scanf_two:
    .string "%d%d"

    msg_enter_value_of_element:
    .string "Enter [%d][%d] value:\t"

    msg_entered_elements_are:
    .string "Entered elements are: \n"

    msg_print_index_element:
    .string "[%d][%d] value is:\t%d\n"

    msg_mem_alloc_failed:
    .string "Memory allocation FAILED"

.section .text
.globl main
.type main, @function

main:
    pushl  %ebp
    movl   %esp, %ebp

    # -- local vars
    subl    $20, %esp           # iRows, iColumns, iCounter1, iCounter2, ppPtr

    movl    $NULL, -20(%ebp)    # **ppPtr = NULL;

    # -- enter iRows value & column
    pushl   $msg_enter_row_and_columns
    call    printf
    addl    $4, %esp

    leal    -4(%ebp), %eax      # iRows
    leal    -8(%ebp), %edx      # iColumns
    pushl   %edx
    pushl   %eax
    pushl   $msg_scanf_two
    call    scanf
    addl    $12, %esp

    # -- malloc for ppPtr
    movl    -4(%ebp), %eax      # iRows
    movl    $INT_POINTER_SIZE, %ecx
    mull    %ecx

    pushl   %eax
    call    malloc
    movl    %eax, -20(%ebp)
    addl    $4, %esp

    cmpl    $NULL, -20(%ebp)
    je      label_mem_alloc_failed

# -------------------------------------------------------------
    # -- 1st loop -- Outer
    movl    $0, -12(%ebp)           # iCounter1
    jmp     label_for_outer_loop_cond_loop1

label_for_outer_loop_statement_loop1:

    # -- malloc for ppPtr[iCounter1]
    movl    -4(%ebp), %eax      # iRows
    movl    $INT_SIZE, %ecx
    mull    %ecx

    pushl   %eax
    call    malloc

    movl    -12(%ebp), %edx     # iCounter1
    movl    -20(%ebp), %ebx
    movl    %eax, (%ebx, %edx, 4)

    addl    $4, %esp

    cmpl    $NULL, -20(%ebp)
    je      label_mem_alloc_failed
    # --------------------------------
    
    movl    $0, -16(%ebp)           # iCounter2
    jmp     label_for_inner_loop_cond_loop1

    # -- 1st loop -- Inner
    label_for_inner_loop_statement_loop1:


        movl    -16(%ebp), %eax
        pushl   %eax                # iCounter2
        movl    -12(%ebp), %edx
        pushl   %edx                # iCounter1
        pushl   $msg_enter_value_of_element
        call    printf
        addl    $12, %esp

        # -- &ppPtr[iCounter1][iCounter2]
        movl    -12(%ebp), %edx     # iCounter1
        movl    -20(%ebp), %ebx
        movl    (%ebx, %edx, 4), %ebx

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
    pushl   $msg_entered_elements_are
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

        # -- print ppPtr[iCounter1][iCounter2]
        movl    -12(%ebp), %edx     # iCounter1
        movl    -20(%ebp), %ebx
        movl    (%ebx, %edx, 4), %ebx

        # movl    -16(%ebp), %eax     # iCounter2
        movl    (%ebx, %eax, 4), %ebx

        pushl   %ebx                # ppPtr[iCounter1][iCounter2]
        pushl   %eax                # iCounter2
        pushl   %edx                # iCounter1
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

# -----------------------------------------------
# --------------- Free loop ---------------------
    movl    $0, -12(%ebp)           # iCounter1
    jmp     label_for_loop_free_condition

label_for_loop_free_statement:
    # -- free(ppPtr[iCounter1]);
    movl    -20(%ebp), %ebx
    movl    (%ebx, %eax, 4), %ebx
    pushl   %ebx
    call    free
    addl    $4, %esp

    # -- ppPtr[iCounter1] = NULL;
    movl    -12(%ebp), %eax     # iCounter1
    movl    -20(%ebp), %ebx
    movl    (%ebx, %eax, 4), %ebx
    movl    $NULL, %ebx

    addl    $1, -12(%ebp)     # iCounter1++

label_for_loop_free_condition:
    movl    -12(%ebp), %eax     # iCounter1
    movl    -4(%ebp), %edx      # iRows
    cmpl    %edx, %eax
    jl      label_for_loop_free_statement

    movl    -20(%ebp), %ebx
    pushl   %ebx
    call    free
    addl    $4, %esp

    movl    $NULL, -20(%ebp)

    # -- exit
    pushl   $0
    call    exit

label_mem_alloc_failed:
    pushl   $msg_mem_alloc_failed
    call    printf
    addl    $4, %esp

    pushl   $-1
    call    exit
