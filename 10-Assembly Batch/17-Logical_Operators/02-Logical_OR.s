.section    .rodata
    msg_enter_three_number:
    .string "Enter three number: \t"

    msg_scanf_three:
    .string "%d%d%d"

    msg_answer:
    .string "\niNo1 = %d iNo2 = %d iNo3 = %d iAns = %d\n"

.section    .text
.globl  main
.type   main, @function

main:

    pushl   %ebp
    movl    %esp, %ebp

    # -- Local variables
    subl    $16, %esp

    # -- Print Enter message
    pushl   $msg_enter_three_number
    call    printf
    addl    $4, %esp

    # -- Scan numbers
    leal    -4(%ebp), %eax
    leal    -8(%ebp), %edx
    leal    -12(%ebp), %ecx
    pushl   %ecx
    pushl   %edx
    pushl   %eax
    pushl   $msg_scanf_three
    call    scanf
    addl    $16, %esp

    # -- iAns =  iNo1 && ++iNo2 || ++iNo3;
    movl    -4(%ebp), %eax      # iNo1
    cmpl    $0, %eax
    je      label_iNo_is_zero   # -- if iNo1 == 0

    addl    $1, -8(%ebp)        # if iNo1 != 0 then ++iNo2
    movl    -8(%ebp), %eax
    cmpl    $0, %eax           
    je      label_iNo_is_zero   # if iNo2 == 0

    movl    $1, %eax            # if iNo2 != 0
    jmp    label_result

label_iNo_is_zero:
    addl    $1, -12(%ebp)
    movl    -12(%ebp), %edx 
    # cmpl    $0, %edx
    jmp      label_result


label_result:
    pushl   %eax
    pushl   %edx
    pushl   -8(%ebp)
    pushl   -4(%ebp)
    pushl   $msg_answer
    call    printf
    addl    $20, %esp

    pushl   $0
    call    exit
