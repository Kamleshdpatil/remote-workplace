.section .rodata
    msg_enter_numerator:
    .string "Enter Numerator: "

    msg_scanf_qd:
    .string "%qd"

    msg_enter_denomerator:
    .string "Enter Denominator: "

    msg_scanf:
    .string "%d"

    msg_print_qoutient:
    .string "\nQoutient is: %d\n"

    msg_print_reminder:
    .string "Reminder is: %d\n"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # -- local variables
    subl    $20, %esp

    # -- Enter nummerator
    pushl   $msg_enter_numerator
    call    printf
    addl    $4, %esp

    # -- Scan numerator
    leal    -8(%ebp), %eax # Address of long long int
    pushl   %eax
    pushl   $msg_scanf_qd
    call    scanf
    addl    $8, %esp

    # -- Enter denominator
    pushl   $msg_enter_denomerator
    call    printf
    addl    $4, %esp

    # -- Scan denominator
    leal    -12(%ebp), %eax
    pushl   %eax
    pushl   $msg_scanf
    call    scanf
    addl    $8, %esp

    movl    -8(%ebp), %eax      # Numerator(LSB)
    movl    -4(%ebp), %edx      # Numerator(MSB)
    movl    -12(%ebp), %ecx     # Denominator
    #divl    %ecx               # divl works only with unsigned
    
    movl    %eax, -16(%ebp)     # Qoutient
    movl    %edx, -20(%ebp)     # Reminder

    # -- Print Qoutient
    pushl   %eax
    pushl   $msg_print_qoutient
    call    printf
    addl    $8, %esp

    # -- Print Reminder
    movl    -20(%ebp), %eax
    pushl   %eax
    pushl   $msg_print_reminder
    call    printf
    addl    $8, %esp

    pushl   $0
    call    exit

