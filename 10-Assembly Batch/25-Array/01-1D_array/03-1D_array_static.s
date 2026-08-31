.equ MAX, 10

.section .rodata
    msg_enter_value_of_iMax:
    .string "Enter value of n(< %d):\t"

    msg_scanf:
    .string "%d"

    msg_enter_value_of_element:
    .string "Enter %d value: \t"    

    msg_entered_eleemnts_are:
    .string "Entered elements are: \n"

    msg_print_index_element:
    .string "%d value is:\t%d\n"

.section .text
.globl main
.type main, @function

main:
    pushl  %ebp
    movl   %esp, %ebp

    # -- local vars
    subl    $48, %esp           # iMax, iCounter, arr

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

    # -- 1st loop
    movl    $0, -8(%ebp)        # iCounter = 0
    jmp     label_for_cond_loop1

label_statement_loop1:
    # -- enter element value
    # movl    -8(%ebp), %eax      # iCounter
    pushl   %eax
    pushl   $msg_enter_value_of_element
    call    printf
    addl    $8, %esp

    movl    -8(%ebp), %eax       # iCounter
    leal    -40(%ebp, %eax, 4), %ebx
    pushl   %ebx
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    addl    $1, -8(%ebp)

label_for_cond_loop1:
    movl    -8(%ebp), %eax      # iCounter
    movl    -4(%ebp), %edx      # iMax
    cmpl    %edx, %eax
    jl      label_statement_loop1

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
    # movl    -8(%ebp), %eax      # iCounter
    movl    -40(%ebp, %eax, 4), %edx
    pushl   %edx
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

    pushl   $0
    call    exit
