.section .rodata
    msg_obj1_is:
    .string "Obj1 is: \n"

    msg_obj2_is:
    .string "Obj2 is: \n"

    msg_obj3_is:
    .string "Obj3 is: \n"

    msg_print_struct_data:
    .string "chChar = %c, iNo = %d, shiNo = %hd\n\n" 

    msg_enter_obj1_values:
    .string "Enter obj1 values:--> \n"

    msg_enter_obj2_values:
    .string "Enter obj2 values:--> \n"

    msg_enter_chChar:
    .string "Enter chChar\t: "

    msg_enter_iNo:
    .string "Enter iNo\t: "

    msg_enter_shiNo:
    .string "Enter shiNo\t: "

    msg_scanf_char:
    .string "%c"

    msg_scanf_int:
    .string "%d"

    msg_scanf_short_int:
    .string "%hd"

.section .bss
    .comm obj1, 12, 4

.section .text
    .globl main
    .type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # struct demo obj2 -24
    # struct demo obj3 -12
    subl    $24, %esp

    # -------------------------------
    # --- enter obj2 ---
    pushl   $msg_enter_obj2_values
    call    printf
    addl    $4, %esp

   # -------------------------------
    # -- enter char
    pushl   $msg_enter_chChar
    call    printf
    addl    $4, %esp

    leal    -24(%ebp), %ebx
    xorl    %eax, %eax
    movl    %ebx, %eax
    pushl   %eax
    pushl   $msg_scanf_char
    call    scanf
    addl    $8, %esp

    # -- enter int
    pushl   $msg_enter_iNo
    call    printf
    addl    $4, %esp

    leal    -24(%ebp), %ebx
    leal    4(%ebx), %ebx
    pushl   %ebx
    pushl   $msg_scanf_int
    call    scanf
    addl    $8, %esp

    # -- enter short int
    pushl   $msg_enter_shiNo
    call    printf
    addl    $4, %esp

    leal    -24(%ebp), %ebx
    xorl    %eax, %eax
    leal    8(%ebx), %eax
    pushl   %eax
    pushl   $msg_scanf_short_int
    call    scanf
    addl    $8, %esp
    # -------------------------------
    
    # --- print obj2 ---
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
    # ------------------------------

    #-- Assign obj2 to obj1
    leal    -24(%ebp), %ebx  # obj2.chChar
    xorl    %eax, %eax
    movb    (%ebx), %al

    movl    $obj1, %ecx      # obj1.chChar
    movl    %eax, (%ecx)     # obj1.chChar = obj2.chChar

    movl    4(%ebx), %eax    # obj2.iNo
    movl    %eax, 4(%ecx)    # obj1.iNo = obj2.iNo

    xorl    %eax, %eax
    movw    8(%ebx), %ax     # obj2.shiNo
    movl    %eax, 8(%ecx)    # obj1.shiNo = obj2.shiNo
    # ------------------------------

    #-- Assign obj2 to obj3
    xorl    %eax, %eax
    movb    (%ebx), %al      # obj2.chChar

    leal    -12(%ebp), %ecx  # obj3.chChar
    movl    %eax, (%ecx)     # obj3.chChar = obj2.chChar

    movl    4(%ebx), %eax    # obj2.iNo
    movl    %eax, 4(%ecx)    # obj3.iNo = obj2.iNo

    xorl    %eax, %eax
    movw    8(%ebx), %ax     # obj2.shiNo
    movl    %eax, 8(%ecx)    # obj3.shiNo = obj2.shiNo
    # ------------------------------

    # --- print obj1 ---
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
    # ------------------------------

    # --- print obj3 ---
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
    # ------------------------------

    pushl   $0
    call    exit
