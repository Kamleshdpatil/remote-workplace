.section .rodata
    msg_obj1_is:
    .string "Obj1 is: \n"

    msg_obj2_is:
    .string "Obj2 is: \n"

    msg_obj3_is:
    .string "Obj3 is: \n"

    msg_equal:
    .string "Euqal\n"

    msg_not_equal:
    .string "Not euqal\n"

    msg_obj1_and_obj2_comp:
    .string "obj1 & obj2 comparision is: "

    msg_obj3_and_obj2_comp:
    .string "obj3 & obj2 comparision is: "

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

    subl    $24, %esp

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
    movb    $'B', -24(%ebp) # chChar = 'B'
    movl    $30, -20(%ebp)
    movw    $40, -16(%ebp)

    pushl   $msg_obj2_is
    call    printf
    addl    $4, %esp

    leal    -24(%ebp), %ebx
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

    # --- obj3 ---
    movb    $'B', -12(%ebp) # chChar = 'B'
    movl    $30, -8(%ebp)
    movw    $40, -4(%ebp)

    pushl   $msg_obj3_is
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

    # --- obj1 & obj2 ---
    pushl   $msg_obj1_and_obj2_comp
    call    printf
    addl    $4, %esp

    movl    $obj1, %ebx     # obj1
    xorl    %eax, %eax
    movb    (%ebx), %al     # chChar
    
    leal    -24(%ebp), %ebx # obj2
    xorl    %edx, %edx
    movb    (%ebx), %dl     # chChar

    cmpl    %eax, %edx
    jne     label_not_equal1
    movl    $obj1, %ebx     # obj1
    movl    4(%ebx), %eax   # iNo
    
    leal    -24(%ebp), %ebx # obj2
    movl    4(%ebx), %edx   # iNo
    cmpl    %eax, %edx
    jne     label_not_equal1

    movl    $obj1, %ebx     # obj1
    xorl    %eax, %eax
    movw    8(%ebx), %cx    # shiNo
    
    leal    -24(%ebp), %ebx # obj2
    xorl    %edx, %edx
    movw    8(%ebx), %dx    # shiNo
    cmpl    %eax, %edx
    jne     label_not_equal1  # not euqal msg

    pushl   $msg_equal      # euqal msg
    call    printf
    addl    $4, %esp
    jmp     label_obj3_obj2_comparision

label_not_equal1:            # not euqal msg
    pushl   $msg_not_equal
    call    printf
    addl    $4, %esp
    # -------------------------------

    # --- obj3 & obj2 ---
label_obj3_obj2_comparision:
    pushl   $msg_obj3_and_obj2_comp
    call    printf
    addl    $4, %esp

    leal    -12(%ebp), %ebx # obj3
    xorl    %eax, %eax
    movb    (%ebx), %al     # chChar

    leal    -24(%ebp), %ebx # obj2
    xorl    %edx, %edx
    movb    (%ebx), %dl     # chChar
    cmpl    %eax, %edx
    jne     label_not_equal

    leal    -12(%ebp), %ebx # obj3
    movl    4(%ebx), %eax   # iNo

    leal    -24(%ebp), %ebx # obj2
    movl    4(%ebx), %edx   # iNo
    cmpl    %eax, %edx
    jne     label_not_equal

    leal    -12(%ebp), %ebx # obj3
    xorl    %eax, %eax
    movw    8(%ebx), %ax    # shiNo

    leal    -24(%ebp), %ebx # obj2
    xorl    %edx, %edx
    movw    8(%ebx), %dx    # shiNo

    cmpl    %eax, %edx
    jne     label_not_equal

    pushl   $msg_equal      # euqal msg
    call    printf
    addl    $4, %esp

    jmp     label_exit
    # -------------------------------

label_not_equal:            # not euqal msg
    pushl   $msg_not_equal
    call    printf
    addl    $4, %esp
    # -------------------------------

label_exit:
    pushl   $0
    call    exit
