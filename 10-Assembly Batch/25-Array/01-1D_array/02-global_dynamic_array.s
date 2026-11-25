.equ NULL, 0

.section .rodata
    msg_enter_value_of_iMax:
    .string "Enter value of n:\t"

    msg_scanf:
    .string "%d"

    msg_enter_value_of_element:
    .string "Enter %d value: \t"    

    msg_entered_eleemnts_are:
    .string "Entered elements are: \n"

    msg_print_index_element:
    .string "%d value is:\t%d\n"

    msg_mem_alloc_failed:
    .string "Memory allocation FAILED"

.section .data
.globl pPtr
.type pPtr, @object
.size pPtr, 4
.align 4

pPtr:
    .int NULL

.section .text
.globl main
.type main, @function

main:
    pushl  %ebp
    movl   %esp, %ebp

    # -- local vars
    subl    $8, %esp

    # -- enter iMax value
    pushl   $msg_enter_value_of_iMax
    call    printf
    addl    $4, %esp

    leal    -4(%ebp), %eax      # iMax
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    # --- Malloc ---
    movl    -4(%ebp), %eax
    movl    $4, %ecx
    mull    %ecx
    pushl   %edx
    pushl   %eax
    call    malloc
    movl    %eax, pPtr
    addl    $8, %esp

    cmpl    $NULL, pPtr
    je      label_mem_alloc_failed

    # -----loop start--------

label_scan_array_element:
    # -- 1st loop
    movl    $0, -8(%ebp)        # iCounter = 0
    jmp     label_for_cond_loop1

label_statement_loo1:
    # -- enter element value
    # movl    -8(%ebp), %eax      # iCounter
    pushl   %eax
    pushl   $msg_enter_value_of_element
    call    printf
    addl    $8, %esp

    movl    pPtr, %edx
    movl    -8(%ebp), %eax      # iCounter
    leal    (%edx, %eax, 4), %ecx
    pushl   %ecx
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    addl    $1, -8(%ebp)

label_for_cond_loop1:
    movl    -8(%ebp), %eax      # iCounter
    movl    -4(%ebp), %edx      # iMax
    cmpl    %edx, %eax
    jl      label_statement_loo1

    # -----loop end--------

label_print_entered_element:
    pushl   $msg_entered_eleemnts_are
    call    printf
    addl    $4, %esp

# -------------------------------------------------------------
    # -- 2nd loop
    movl    $0, -8(%ebp)        # iCounter = 0
    jmp     label_for_cond_loop2

label_statement_loop2:
    movl    pPtr, %edx
    # movl    -8(%ebp), %eax      # iCounter
    movl    (%edx, %eax, 4), %ecx
    pushl   %ecx
    pushl   %eax
    pushl   $msg_print_index_element
    call    printf
    addl    $12, %esp

    addl    $1, -8(%ebp)

label_for_cond_loop2:
    movl    -8(%ebp), %eax      # iCounter
    movl    -4(%ebp), %edx      # iMax
    cmpl    %edx, %eax
    jl      label_statement_loop2

    # -----loop end--------

    # -- free(pPtr) and pPtr = NULL
    movl    pPtr, %eax
    pushl   %eax
    call    free
    addl    $4, %esp

    movl    $NULL, pPtr

    pushl   $0
    call    exit

label_mem_alloc_failed:
    pushl   $msg_mem_alloc_failed
    call    printf
    addl    $4, %esp

    pushl   $-1
    call    exit
