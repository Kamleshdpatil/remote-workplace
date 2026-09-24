
.equ NULL, 0
.equ INT_SIZE, 4
.equ INT_POINTER_SIZE, 4

.section .rodata
    msg_enter_planes_row_and_columns:
    .string "Enter value of planes, rows & columns:\t"

    msg_scanf:
    .string "%d"

    msg_scanf_three:
    .string "%d%d%d"

    msg_enter_value_of_element:
    .string "Enter [%d][%d][%d] value:\t"

    msg_entered_elements_are:
    .string "Entered elements are: \n"

    msg_print_index_element:
    .string "[%d][%d][%d] value is:\t%d\n"

    msg_mem_alloc_failed:
    .string "Memory allocation FAILED"

.section .text
.globl main
.type main, @function

main:
    pushl  %ebp
    movl   %esp, %ebp

    andl    $-16, %esp

    # -- local vars
    subl    $48, %esp             # local size * max param size * 2D arr size

    # -- enter iPlanes, iRows, iColumns value
    movl    $msg_enter_planes_row_and_columns, (%esp)
    call    printf

    leal    -4(%ebp), %eax          # iPlanes
    leal    -8(%ebp), %edx          # iRows
    leal    -12(%ebp), %ebx         # iColumns
    movl    $msg_scanf_three, (%esp)
    movl    %eax, 4(%esp)
    movl    %edx, 8(%esp)
    movl    %ebx, 12(%esp)
    call    scanf

# -------------------------- MALLOC  pppPtr -----------------------------------
    movl    -4(%ebp), %eax              # iPlanes
    movl    $INT_POINTER_SIZE, %ecx     # sizeof(int**)
    mull    %ecx

    movl    %eax, (%esp)
    call    malloc
    movl    %eax, -28(%ebp)             # ***pppPtr

    cmpl    $NULL, -28(%ebp)
    je      label_mem_alloc_failed


# -------------------------------------------------------------
    # -- 1st loop -- Planes
    movl    $0, -16(%ebp)           # iCounter1
    jmp     label_planes_condition_loop1

label_planes_statement_loop1:
    # -- malloc for ppPtr[iCounter1]
    movl    -8(%ebp), %eax              # iRows
    movl    $INT_POINTER_SIZE, %ecx     # sizeof(int*)
    mull    %ecx

    movl    %eax, (%esp)
    call    malloc

    movl    -16(%ebp), %edx         # iCounter1
    movl    -28(%ebp), %ebx         # ***pppPtr
    movl    %eax, (%ebx, %edx, 4)

    cmpl    $NULL, %eax
    je      label_mem_alloc_failed
    # --------------------------------

    movl    $0, -20(%ebp)                   # iCounter2
    jmp     label_rows_condition_loop1

    # -- 2nd loop -- Rows
    label_rows_statement_loop1:

        # -- malloc for ppPtr[iCounter1][iCounter2]
        movl    -12(%ebp), %eax                      # iColumns
        movl    $INT_POINTER_SIZE, %ecx              # sizeof(int*)
        mull    %ecx

        movl    %eax, (%esp)
        call    malloc

        movl    -16(%ebp), %edx                     # iCounter1
        movl    -28(%ebp), %ebx                     # ***pppPtr
        movl    (%ebx, %edx, 4), %ebx

        movl    -20(%ebp), %edx                     # iCounter2
        movl    %eax, (%ebx, %edx, 4)               # ppPtr[iCounter1]

        cmpl    $NULL, %eax
        je      label_mem_alloc_failed
        # --------------------------------

        movl    $0, -24(%ebp)           # iCounter3
        jmp     label_columns_condition_loop1

        # -- 3rd loop -- Columns
        label_columns_statement_loop1:
            movl    -16(%ebp), %eax          # iCounter1
            movl    -20(%ebp), %edx          # iCounter2
            movl    -24(%ebp), %ebx          # iCounter3    
            movl    $msg_enter_value_of_element, (%esp)
            movl    %eax, 4(%esp)
            movl    %edx, 8(%esp)
            movl    %ebx, 12(%esp)
            call    printf

            # &pppPtr[iCounter1][iCounter2][iCounter3]
            movl    -16(%ebp), %edx                     # iCounter1
            movl    -28(%ebp), %ebx                     # ***pppPtr
            movl    (%ebx, %edx, 4), %ebx

            movl    -20(%ebp), %edx                     # iCounter2
            movl    (%ebx, %edx, 4), %ebx

            movl    -24(%ebp), %edx                     # iCounter3
            leal    (%ebx, %edx, 4), %ebx

            movl    $msg_scanf, (%esp)
            movl    %ebx, 4(%esp)
            call scanf
            # -------------------------------------

            addl    $1, -24(%ebp)           # iCounter3++

        label_columns_condition_loop1:
            movl    -24(%ebp), %eax         # iCounter3
            movl    -12(%ebp), %edx         # iColumns
            cmpl    %edx, %eax
            jl      label_columns_statement_loop1

        addl    $1, -20(%ebp)               # iCounter2++

        # -----------------------------
    label_rows_condition_loop1:
        movl    -20(%ebp), %eax             # iCounter2
        movl    -8(%ebp), %edx              # iRows
        cmpl    %edx, %eax
        jl      label_rows_statement_loop1

    addl    $1, -16(%ebp)                   # iCounter1++

label_planes_condition_loop1:
    movl    -16(%ebp), %eax                 # iCounter1
    movl    -4(%ebp), %edx                  # iPlanes
    cmpl    %edx, %eax
    jl      label_planes_statement_loop1
# -------------------------------------------------------------

    # -- Entered elements are: 
    movl   $msg_entered_elements_are, (%esp)
    call    printf    

# -------------------- Print Elements -----------------------------------------
    # -- 1st loop -- Planes
    movl    $0, -16(%ebp)           # iCounter1
    jmp     label_planes_condition_loop2

label_planes_statement_loop2:
    movl    $0, -20(%ebp)           # iCounter2
    jmp     label_rows_condition_loop2

    # -- 2nd loop -- Rows
    label_rows_statement_loop2:
        movl    $0, -24(%ebp)           # iCounter3
        jmp     label_columns_condition_loop2

        # -- 3rd loop -- Columns
        label_columns_statement_loop2:
            # pppPtr[iCounter1][iCounter2][iCounter3]
            movl    -16(%ebp), %edx                     # iCounter1
            movl    -28(%ebp), %ebx                     # ***pppPtr
            movl    (%ebx, %edx, 4), %ebx

            movl    -20(%ebp), %edx                     # iCounter2
            movl    (%ebx, %edx, 4), %ebx

            movl    -24(%ebp), %edx                     # iCounter3
            movl    (%ebx, %edx, 4), %ebx
            
            movl    -16(%ebp), %eax          # iCounter1
            movl    -20(%ebp), %edx          # iCounter2
            movl    -24(%ebp), %ecx          # iCounter3    
            movl    $msg_print_index_element, (%esp)
            movl    %eax, 4(%esp)
            movl    %edx, 8(%esp)
            movl    %ecx, 12(%esp)
            movl    %ebx, 16(%esp)
            call    printf
            # -------------------------------------

            addl    $1, -24(%ebp)           # iCounter3++

        label_columns_condition_loop2:
            movl    -24(%ebp), %eax         # iCounter3
            movl    -12(%ebp), %edx         # iColumns
            cmpl    %edx, %eax
            jl      label_columns_statement_loop2

        addl    $1, -20(%ebp)               # iCounter2++

        # -----------------------------
    label_rows_condition_loop2:
        movl    -20(%ebp), %eax             # iCounter2
        movl    -8(%ebp), %edx              # iRows
        cmpl    %edx, %eax
        jl      label_rows_statement_loop2

    addl    $1, -16(%ebp)                   # iCounter1++

label_planes_condition_loop2:
    movl    -16(%ebp), %eax                 # iCounter1
    movl    -4(%ebp), %edx                  # iPlanes
    cmpl    %edx, %eax
    jl      label_planes_statement_loop2
    
# -----------------------------------------------
# --------------- Free loop ---------------------

    movl    $0, -16(%ebp)           # iCounter1
    jmp     label_planes_condition_loop3

label_planes_statement_loop3:
    movl    $0, -20(%ebp)           # iCounter2
    jmp     label_rows_condition_loop3

    # -- 3rd loop -- Rows
    label_rows_statement_loop3:
        
        movl    -16(%ebp), %edx                     # iCounter1
        movl    -28(%ebp), %ebx                     # ***pppPtr
        movl    (%ebx, %edx, 4), %ebx               # pppPtr[iCounter1]

        movl    -20(%ebp), %edx                     # iCounter2
        movl    (%ebx, %edx, 4), %eax               # pppPtr[iCounter1][iCounter2]
        movl    %eax, (%esp)
        call    free

        movl    -16(%ebp), %edx                     # iCounter1
        movl    -28(%ebp), %ebx                     # ***pppPtr
        movl    (%ebx, %edx, 4), %ebx

        movl    -20(%ebp), %edx                     # iCounter2
        movl    $NULL, (%ebx, %edx, 4)              # pppPtr[iCounter1][iCounter2] = NULL;

        addl    $1, -20(%ebp)                       # iCounter2++

        # -----------------------------
    label_rows_condition_loop3:
        movl    -20(%ebp), %eax                     # iCounter2
        movl    -8(%ebp), %edx                      # iRows
        cmpl    %edx, %eax
        jl      label_rows_statement_loop3

        movl    -16(%ebp), %edx                     # iCounter1
        movl    -28(%ebp), %ebx                     # ***pppPtr
        movl    (%ebx, %edx, 4), %eax
        
        movl    %eax, (%esp)
        call    free

        movl    -16(%ebp), %edx                     # iCounter1
        movl    -28(%ebp), %ebx                     # ***pppPtr
        movl    $NULL, (%ebx, %edx, 4)              # pppPtr[iCounter1] = NULL;

    addl    $1, -16(%ebp)                   # iCounter1++

label_planes_condition_loop3:
    movl    -16(%ebp), %eax                 # iCounter1
    movl    -4(%ebp), %edx                  # iPlanes
    cmpl    %edx, %eax
    jl      label_planes_statement_loop3

    movl    -28(%ebp), %ebx                 # pppPtr
    movl    %ebx, (%esp)
    call    free

    movl    $NULL, -20(%ebp)                # pppPtr = NULL

# -- exit
    movl    $0, (%esp)
    call    exit


label_mem_alloc_failed:
    movl   $msg_mem_alloc_failed, (%esp)
    call    printf

    movl    $-1, (%esp)
    call    exit
