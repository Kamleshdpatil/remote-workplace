.section .rodata
    msg_main_print1:
    .string "Enter two numbers: \t"

    msg_main_scan:
    .string "%d %d"

    msg_main_print2:
    .string "Addition: %d\n"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp                #backup of prev bp
    movl    %esp, %ebp          #bp la khali anal

    subl    $12, %esp           #local variable sp khali ghetal

    pushl   $msg_main_print1
    call    printf
    addl    $4, %esp

    leal    -4(%ebp), %eax      #&no1
    leal    -8(%ebp), %ebx      #&no2
    pushl   %ebx                #address of no2
    pushl   %eax                #address of no1
    pushl   $msg_main_scan
    call    scanf
    addl    $12, %esp

    movl    -8(%ebp), %ebx      #no2
    movl    -4(%ebp), %eax      #no1
    pushl   %ebx                #value of no2
    pushl   %eax                #value of no1
    call    addition
    addl    $8, %esp
    movl    %eax, -12(%ebp)     #return value store to ans

    pushl   %eax
    pushl   $msg_main_print2
    call    printf
    addl    $8, %esp

    pushl   $0
    call    exit

.globl  addition
.type   addition, @function

addition:
    pushl   %ebp
    movl    %esp, %ebp

    subl    $4, %esp            #ans <-- -4(%ebp)  (Allocated by 'subl $4, %esp') <-- Current %esp

    movl    8(%ebp), %eax        #1st param
    movl    12(%ebp), %edx       #2nd param
    addl    %edx, %eax
    movl    %eax, -4(%ebp)

    movl    %ebp, %esp
    popl    %ebp
    ret
