.section .rodata
    msg_obj1_is:
    .string "Obj1 is: \n"

    msg_obj2_is:
    .string "Obj2 is: \n"

    msg_print_struct_data:
    .string "chChar = %c, iNo = %d, shiNo = %hd\n\n" 

.section .data
    .globl obj1
    .type obj1, @object
    .size obj1, 12
    .align 4

obj1:
    .ascii "A"
    .zero 3
    .int 10
    .value 20

.section .text
    .globl main
    .type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    subl    $12, %esp

    # --- obj1 ---
    pushl   $msg_obj1_is
    call    printf
    addl    $4, %esp

    movl    $obj1, %ebx
    xorl    %eax, %eax
    movb    (%ebx), %al     # chChar
    movl    4(%ebx), %edx   # iNo
    xorl    %ecx, %ecx
    movw    8(%ebx), %cx    # shiNo

    pushl   %ecx
    pushl   %edx
    pushl   %eax
    pushl   $msg_print_struct_data
    call    printf
    addl    $16, %esp
    # -------------------------------
    
    # --- obj2 ---
    movb    $'B', -12(%ebp) # chChar = 'B'
    movl    $30, -8(%ebp)
    movw    $40, -4(%ebp)

    pushl   $msg_obj2_is
    call    printf
    addl    $4, %esp

    leal    -12(%ebp), %ebx
    xorl    %eax, %eax
    movb    (%ebx), %al     # chChar
    movl    4(%ebx), %edx   # iNo
    xorl    %ecx, %ecx
    movw    8(%ebx), %cx    # shiNo

    pushl   %ecx
    pushl   %edx
    pushl   %eax
    pushl   $msg_print_struct_data
    call    printf
    addl    $16, %esp
    # -------------------------------

    pushl   $0
    call    exit
