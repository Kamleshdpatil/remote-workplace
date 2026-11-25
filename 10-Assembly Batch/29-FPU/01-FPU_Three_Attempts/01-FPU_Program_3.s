# ----------- RODATA Section -------------
.section .rodata
    msg_print_float:
    .string "fNo1 = %f\tfNo2 = %f\n"

    msg_print_double:
    .string "dNo1 = %lf\tdNo2 = %lf\n"

    msg_after_load_stor:
    .string "\nAfter Load & store... \n"


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
    # Attemp 3
    #

    # print fNo1 & fNo2
    movl    $msg_print_float, (%esp)
    # dNo1
    flds    (fNo2)
    flds    (fNo1)
    fstpl   4(%esp)
    fstpl   12(%esp)
    call    printf

    # ------------------------
    
    # print dNo1 & dNo2
    movl    $msg_print_double, (%esp)
    # dNo1
    fldl    (dNo2)
    fldl    (dNo1)
    fstpl   4(%esp)
    fstpl   12(%esp)

    call    printf

    # ------------------------
    # ------------------------
    # fNo2 = fNo1
    flds    (fNo1)
    fsts    (fNo2) 

    # dNo2 = dNo1
    fldl    (dNo1)
    fstl    (dNo2) 
    # ------------------------
    # ------------------------

    movl    $msg_after_load_stor, (%esp)
    call    printf

    # print fNo1 & fNo2
    movl    $msg_print_float, (%esp)
    # dNo1
    flds    (fNo2)
    flds    (fNo1)
    fstpl   4(%esp)
    fstpl   12(%esp)
    call    printfS

    # ------------------------
    
    # print dNo1 & dNo2
    movl    $msg_print_double, (%esp)
    # dNo1
    fldl    (dNo2)
    fldl    (dNo1)
    fstpl   4(%esp)
    fstpl   12(%esp)

    call    printf


    movl    $-1, (%esp)
    call    exit
