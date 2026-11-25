.section .rodata
    msg_before_scan:
    .string "Before Scanning, g is %d\n"

    msg_after_scan:
    .string "After Scanning, g is %d\n"

    msg_scan_g:
    .string "Enter number: "

    scna_g:
    .string "%d"

.section .bss
    .comm g, 4, 4

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    # -- Print value of g before scanning --
    movl    g, %eax
    pushl   %eax
    pushl   $msg_before_scan
    call    printf
    addl    $8, %esp    #clean up 8 bytes(4 bytes of g, 4 bytes of string)

    # -- Ask for number --
    pushl   $msg_scan_g
    call    printf
    addl    $4, %esp

    # -- Scan number to store in g
    pushl   $g
    pushl   $scna_g
    call    scanf
    addl    $8, %esp

    # -- Print value of g after scanning --
    movl    g, %eax
    pushl   %eax
    pushl   $msg_after_scan
    call    printf
    addl    $8, %esp    #clean up 8 bytes(4 bytes of g, 4 bytes of string)

    # -- Exit
    pushl   $0
    call    exit
