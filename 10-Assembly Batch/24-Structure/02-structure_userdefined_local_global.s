.section .rodata
    msg_obj1_is:
    .string "Obj1 is: \n"

    msg_obj2_is:
    .string "Obj2 is: \n"

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

    msg_char_char:
    .string "%c%c"

    msg_char_int:
    .string "%c%d"

    msg_char_short_int:
    .string "%c%hd"

    msg_print_t:
    .string "t: %c\n"

.section .bss
    .comm obj1, 12, 4

.section .text
    .globl main
    .type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # struct demo obj2;
    # char t;
    subl    $16, %esp

    # -------------------------------
    # --- enter obj1 ---
    pushl   $msg_enter_obj1_values
    call    printf
    addl    $4, %esp

    # ------------------------------
    # -- enter char
    pushl   $msg_enter_chChar
    call    printf
    addl    $4, %esp

    movl    $obj1, %ebx
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

    movl    $obj1, %ebx
    leal    4(%ebx), %eax
    pushl   %eax
    pushl   $msg_scanf_int
    call    scanf
    addl    $8, %esp

    # -- enter short int
    pushl   $msg_enter_shiNo
    call    printf
    addl    $4, %esp

    movl    $obj1, %ebx
    xorl    %eax, %eax
    leal    8(%ebx), %eax
    pushl   %eax
    pushl   $msg_scanf_short_int
    call    scanf
    addl    $8, %esp
    # ------- end ------obj1---------
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

    leal    -12(%ebp), %ebx
    pushl   %ebx
    leal    -16(%ebp), %eax   # Address of t
    pushl   %eax
    pushl   $msg_char_char
    call    scanf
    addl    $12, %esp

    # -- enter int
    pushl   $msg_enter_iNo
    call    printf
    addl    $4, %esp

    leal    -12(%ebp), %ebx
    leal    4(%ebx), %ebx
    pushl   %ebx
    leal    -16(%ebp), %eax   # Address of t
    pushl   %eax
    pushl   $msg_char_int
    call    scanf
    addl    $12, %esp

    # -- enter short int
    pushl   $msg_enter_shiNo
    call    printf
    addl    $4, %esp

    leal    -12(%ebp), %ebx
    leal    8(%ebx), %ebx
    pushl   %ebx
    leal    -16(%ebp), %eax   # Address of t
    pushl   %eax
    pushl   $msg_char_short_int
    call    scanf
    addl    $12, %esp
    # ------- end ------obj1---------
    # -------------------------------
    
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

    # --- print obj2 ---
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
    # ------------------------------

    pushl   $0
    call    exit
