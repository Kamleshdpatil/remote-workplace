.section .data
    msg_choice_options:
    .string "\n 1. Addition\n 2. Substraction\n 3. Multiplication\n 4. Division\n 5. Exit\n"

    msg_enter_one_number:
    .string "Enter Number: "

    msg_enter_two__number:
    .string "Enter two numbers: "

    msg_scan_one_number:
    .string "%d"

    msg_scan_two_number:
    .string "%d%d"

    msg_enter_valid_choice:
    .string "Enter valid choice: "

    msg_answer_is:
    .string "Answer is %d\n\n"

    msg_want_to_try:
    .string "Are you want to enter more choice? (1/0): "

.section .text
.type addition, @function
addition:
    pushl   %ebp
    movl    %esp, %ebp

    movl    8(%ebp), %eax
    movl    12(%ebp), %edx
    addl    %edx, %eax

    movl    %ebp, %esp
    popl    %ebp

    ret

.type substraction, @function
substraction:
    pushl   %ebp
    movl    %esp, %ebp

    movl    8(%ebp), %eax
    movl    12(%ebp), %edx
    subl    %edx, %eax

    movl    %ebp, %esp
    popl    %ebp

    ret

.type multiplication, @function
multiplication:
    pushl   %ebp
    movl    %esp, %ebp

    movl    8(%ebp), %eax
    movl    12(%ebp), %ecx
    mull    %ecx

    movl    %ebp, %esp
    popl    %ebp

    ret

.type division, @function
division:
    pushl   %ebp
    movl    %esp, %ebp

    movl    8(%ebp), %eax   # numerator
    xorl    %edx, %edx      # empty out edx
    movl    12(%ebp), %ecx   # denominator
    divl    %ecx

    movl    %ebp, %esp
    popl    %ebp

    ret

.globl  main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # -- 4 local variables
    subl    $16, %esp

    # -- do 
label_do_section:
    # -- Print options
    pushl   $msg_choice_options
    call    printf
    addl    $4, %esp


    # -- Print enter number
    pushl   $msg_enter_one_number
    call    printf
    addl    $4, %esp

    # -- Scan a iChoice
    leal    -16(%ebp), %eax          # iChoice
    pushl   %eax
    pushl   $msg_scan_one_number
    call    scanf
    addl    $8, %esp

    # -- if(iCh > 0 && iCh < 5)
    movl    -16(%ebp), %eax         # iChoice
    cmpl    $0, %eax
    jle      label_skip_enter_two_numbers
    cmpl    $5, %eax
    jge     label_skip_enter_two_numbers

    # -- Actual skip
    pushl   $msg_enter_two__number
    call    printf
    addl    $4, %esp

    leal    -4(%ebp), %eax          # iNo1
    leal    -8(%ebp), %edx          # iNo2
    pushl   %edx
    pushl   %eax
    pushl   $msg_scan_two_number
    call    scanf
    addl    $12, %esp

label_skip_enter_two_numbers:
    # -- switch
    movl    -16(%ebp), %eax         # iChoice
    cmpl    $1, %eax
    je      label_addition          # case 1

    cmpl    $2, %eax
    je      label_substraction      # case 2

    cmpl    $3, %eax
    je      label_multiplication    # case 3

    cmpl    $4, %eax
    je      label_division          # case 4

    cmpl    $5, %eax
    je      label_exit

    jmp     label_default_to_continue          # case 5

label_addition:
    movl    -8(%ebp), %ebx      # iNo2
    movl    -4(%ebp), %eax      # iNo1
    pushl   %ebx
    pushl   %eax
    call    addition
    movl    %eax, -12(%ebp)     # iAns 
    addl    $8, %esp

    jmp     label_print_result_and_trial

label_substraction:
    movl    -8(%ebp), %ebx      # iNo2
    movl    -4(%ebp), %eax      # iNo1
    pushl   %ebx
    pushl   %eax
    call    substraction
    addl    $8, %esp

    movl    %eax, -12(%ebp)     # iAns 
    jmp     label_print_result_and_trial

label_multiplication:
    movl    -8(%ebp), %ebx      # iNo2
    movl    -4(%ebp), %eax      # iNo1
    pushl   %ebx
    pushl   %eax
    call    multiplication
    addl    $8, %esp

    movl    %eax, -12(%ebp)     # iAns 
    jmp     label_print_result_and_trial

label_division:
    movl    -8(%ebp), %ebx      # iNo2
    movl    -4(%ebp), %eax      # iNo1
    pushl   %ebx
    pushl   %eax
    call    division
    addl    $8, %esp

    movl    %eax, -12(%ebp)     # iAns 
    jmp     label_print_result_and_trial

label_default_to_continue:
    pushl   $msg_enter_valid_choice
    call    printf
    addl    $4, %esp

    movl    $1, -16(%ebp)       # iChoice = 1

    # -- to continue
    jmp     label_do_section

label_print_result_and_trial:
    # -- print answer
    pushl   %eax
    pushl   $msg_answer_is
    call    printf
    addl    $8, %esp

    # -- ask for try with more choice
    pushl   $msg_want_to_try
    call    printf
    addl    $4, %esp

    #-- scan trial choice
    leal    -16(%ebp), %eax     # iChoice
    pushl   %eax
    pushl   $msg_scan_one_number
    call    scanf
    addl    $8, %esp

    movl    -16(%ebp), %eax     # iChoice
    cmpl    $1, %eax
    je      label_do_section

label_exit:
    pushl   $0
    call    exit
