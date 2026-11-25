# ----------- RODATA Section -------------
.section .rodata
    msg_print_ans:
    .string "Answer is %f\n"

    int_data_22:
    .int 22

    int_data_6:
    .int 6

    float_data_43:
    .float 43.65

    float_data_76:
    .float 76.34

    float_data_3:
    .float 3.1

    float_data_12:
    .float 12.43

    float_data_140:
    .float 140.2

    float_data_94:
    .float 94.21

# ----------- Text Section -------------

.section .text
.globl main
.type main, @function
main:
    push    %ebp
    movl    %esp, %ebp

    subl    $20, %esp             # printf param

    # ------------------------
    # (43.65 / 22)
    fildl   int_data_22
    flds    float_data_43

    fdivp                         # (43.65 / 22)
    # st(0) = (43.65 / 22)

    # (76.34 * 3.1)
    flds   float_data_3
    flds   float_data_76

    fmulp                         # (76.34 * 3.1)

    faddp                         # ((43.65 / 22) + (76.34 * 3.1))
    # st(0) = ((43.65 / 22) + (76.34 * 3.1))

    # (12.43 * 6)
    fildl  int_data_6
    flds   float_data_12

    fmulp                         # (12.43 * 6)
    # st(0) = (12.43 * 6)
    # st(1) = ((43.65 / 22) + (76.34 * 3.1))

    # (140.2 / 94.21)
    flds   float_data_94
    flds   float_data_140

    fdivp                         # (140.2 / 94.21)
    # st(0) = (140.2 / 94.21)
    # st(1) = (12.43 * 6)
    # st(2) = ((43.65 / 22) + (76.34 * 3.1))

    fsubrp                         # ((12.43 * 6) - (140.2 / 94.21))
    # st(0) = ((12.43 * 6) - (140.2 / 94.21))
    # st(1) = ((43.65 / 22) + (76.34 * 3.1))

    # final
    fdivrp                         # ((43.65 / 22) + (76.34 * 3.1)) / ((12.43 * 6) - (140.2 / 94.21))
    # st(0) = ((43.65 / 22) + (76.34 * 3.1)) / ((12.43 * 6) - (140.2 / 94.21))

    movl    $msg_print_ans, (%esp)
    fstpl   4(%esp)
    call    printf

    # ------------------------
    movl    $0, (%esp)
    call    exit
