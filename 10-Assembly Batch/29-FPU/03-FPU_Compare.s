.section .rodata
    msg_enter_two_float_numbers:
    .string "Enter two floating point numbers: \t"

    msg_scanf:
    .string "%f%f"

    msg_less_than:
    .string "fNo1 is less than fNo2"

    msg_greater_than:
    .string "fNo1 is greater than fNo2"

    msg_equal:
    .string "Values are equal"

    msg_print_numbers:
    .string "Numbers: %f, %f\n"

.section .text
.globl Compare
.type Compare, @function

Compare:
    pushl   %ebp
    movl    %esp, %ebp

    flds    12(%ebp)            # st(1)
    flds    8(%ebp)             # st(0)

    fcompp                      # compare and pop

    # FPU kdun compare kelela flag anaycha ahe
    # full form status write
    fstsw                       # store/retrive floating point status register from FPU to AX

    # store AH to flags
    sahf

    jb      label_less

    ja      label_greater

    movl    $0, %eax
    jmp     label_comp_exit

label_greater:
    movl    $1, %eax
    jmp     label_comp_exit

label_less:
    movl    $-1, %eax

label_comp_exit:
    movl    %ebp, %esp
    popl    %ebp
    ret

.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    subl    $32, %esp           # iRet, fNo1, fNo2

    movl    $msg_enter_two_float_numbers, (%esp)
    call    printf

    # scanf
    movl    $msg_scanf, (%esp)
    leal    -4(%ebp), %eax      # fNo1
    leal    -8(%ebp), %edx      # fNo2
    movl    %eax, 4(%esp)
    movl    %edx, 8(%esp)
    call    scanf

    # checking
    movl    $msg_print_numbers, (%esp)
    flds    -8(%ebp)
    fstpl   12(%esp)             # fNo2

    flds    -4(%ebp)
    fstpl   4(%esp)             # fNo1
    call    printf

    # call compare
    movl    -4(%ebp), %eax      # fNo1
    movl    -8(%ebp), %edx      # fNo2
    movl    %eax, (%esp)
    movl    %edx, 4(%esp)
    call    Compare

    movl    %eax, -12(%ebp)     # iRet = Compare(fNo1, fNo2);

    # if(iRet == -1)
    cmpl    $-1, %eax
    jne     label_equal_one
    movl    $msg_less_than, (%esp)
    call    puts
    jmp     label_exit

    # else if(iRet == 1)
label_equal_one:
    cmpl    $1, %eax
    jne     label_equal
    movl    $msg_greater_than, (%esp)
    call    puts
    jmp     label_exit

    # else
label_equal:
    movl    $msg_equal, (%esp)
    call    puts

label_exit:
    movl    $0, (%esp)
    call    exit

