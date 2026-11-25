
.equ MAX1, 5
.equ MAX2, 10
.equ INT_SIZE, 4

.section .rodata
    msg_enter_planes_row_and_columns:
    .string "Enter value of planes, rows & columns(< %d, %d, %d):\t"

    msg_scanf:
    .string "%d"

    msg_scanf_three:
    .string "%d%d%d"

    msg_enter_value_of_element:
    .string "Enter [%d][%d][%d] value:\t"

    msg_entered_eleemnts_are:
    .string "Entered elements are: \n"

    msg_print_index_element:
    .string "[%d][%d][%d] value is:\t%d\n"

.section .text
.globl main
.type main, @function

main:
    pushl  %ebp
    movl   %esp, %ebp

    andl    $-16, %esp

    # -- local vars
    subl    $2096, %esp             # local size * max param size * 2D arr size

    # -- enter iRows value
    movl    $msg_enter_planes_row_and_columns, (%esp)
    movl    $MAX1, 4(%esp)
    movl    $MAX2, 8(%esp)
    movl    $MAX2, 12(%esp)
    call    printf

    leal    -4(%ebp), %eax          # iPlanes
    leal    -8(%ebp), %edx          # iRows
    leal    -12(%ebp), %ebx         # iColumns
    movl    $msg_scanf_three, (%esp)
    movl    %eax, 4(%esp)
    movl    %edx, 8(%esp)
    movl    %ebx, 12(%esp)
    call    scanf

# -------------------------------------------------------------
    # -- 1st loop -- Planes
    movl    $0, -16(%ebp)           # iCounter1
    jmp     label_planes_condition_loop1

label_planes_statement_loop1:
    movl    $0, -20(%ebp)           # iCounter2
    jmp     label_rows_condition_loop1

    # -- 2nd loop -- Rows
    label_rows_statement_loop1:
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

            # &arr[iCounter1][iCounter2][iCounter3]
            movl    $MAX1, %eax
            movl    -16(%ebp), %ecx         # iCounter1
            mull    %ecx                    

            addl    -20(%ebp),%eax          # iCounter2
            movl    $MAX1, %ecx             
            mull    %ecx

            addl    -24(%ebp), %eax         # iCounter3
            
            leal    -2048(%ebp), %ebx       # arr
            leal    (%ebx, %eax, 4), %ebx
            
            movl    $msg_scanf, (%esp)
            movl    %ebx, 4(%esp)
            call    scanf
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
    movl   $msg_entered_eleemnts_are, (%esp)
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
            # arr[iCounter1][iCounter2][iCounter3]
            movl    $MAX1, %eax
            movl    -16(%ebp), %ecx         # iCounter1
            mull    %ecx                    

            addl    -20(%ebp),%eax
            movl    $MAX1, %ecx             # iCounter2
            mull    %ecx

            addl    -24(%ebp), %eax         # iCounter3
            
            leal    -2048(%ebp), %ebx       # arr
            movl    (%ebx, %eax, 4), %ecx
            
            movl    -16(%ebp), %eax          # iCounter1
            movl    -20(%ebp), %edx          # iCounter2
            movl    -24(%ebp), %ebx          # iCounter3    
            movl    $msg_print_index_element, (%esp)
            movl    %eax, 4(%esp)
            movl    %edx, 8(%esp)
            movl    %ebx, 12(%esp)
            movl    %ecx, 16(%esp)
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
    
    movl    $0, (%esp)
    call    exit
