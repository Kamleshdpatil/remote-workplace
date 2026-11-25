# ----------- RODATA Section -------------
.section .rodata
    msg_print_no1_no2:
    .string "fNo1 = %f\tfNo2 = %f\n"

    msg_print_ans1:
    .string "fAns1 = %f\n"

    msg_print_ans2:
    .string "fAns2 = %f\n"

    msg_print_ans3:
    .string "fAns3 = %f\n"

    int_data_2:
    .int 2

# ----------- Data Section -------------

.section .data
.globl fNo1
.align 4
.type fNo1, @object
fNo1:
    .float 10.22

.globl fNo2
.align 4
.type fNo2, @object
fNo2:
    .float 20.22

# ----------- BSS Section -------------

.section .bss
.comm fAns1, 4, 4
.comm fAns2, 4, 4
.comm fAns3, 4, 4

# ----------- Text Section -------------

.section .text
.globl main
.type main, @function
main:
    push    %ebp
    movl    %esp, %ebp

    subl    $32, %esp             # printf param

    # ------------------------
    movl    $msg_print_no1_no2, (%esp)
    flds    fNo2
    flds    fNo1

    fstpl   4(%esp)
    fstpl   12(%esp)
    call    printf
    # ------------------------

    # fAns1 = fNo2 / fNo1;
    flds    fNo1
    flds    fNo2

    fdivp 
    fstps   (fAns1)

    # fAns2 = fNo1 / fNo2;
    flds    fNo2
    flds    fNo1

    fdivp
    fstps   (fAns2)

    # fAns3 = fNo1 / 2;
    flds    fNo1
    fidivl  int_data_2
    fstps   (fAns3)

    # ------------------------

    movl    $msg_print_ans1, (%esp)
    flds    fAns1
    fstpl   4(%esp)
    call    printf

    movl    $msg_print_ans2, (%esp)
    flds    fAns2
    fstpl   4(%esp)
    call    printf

    movl    $msg_print_ans3, (%esp)
    flds    fAns3
    fstpl   4(%esp)
    call    printf

    # ------------------------
    movl    $0, (%esp)
    call    exit
