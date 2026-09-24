.section .rodata
    msg_print_arr_arr_arr:
    .string "arr = %-10d \t *arr = %-10d \t &arr = %-10d\n"

    msg_print_p_p_p:
    .string "p = %-10d \t *p = %-10d \t **p = %-10d\n"

    msg_print_ptr_ptr_ptr:
    .string "ptr = %-10d \t *ptr = %-10d \t **ptr = %-10d\n"

    msg_print_arithmetic:
    .string "ptr - p = %d \t *ptr - arr = %d \t **ptr = %d\n"

.section .text
.globl main
.type main, @function

main:
    pushl   %ebp
    movl    %esp, %ebp

    subl    $64, %esp

    # int arr[] = {10, 20, 30, 40, 50};
    movl    $10, -20(%ebp)      # arr[0]
    movl    $20, -16(%ebp)      # arr[1]
    movl    $30, -12(%ebp)      # arr[2]
    movl    $40, -8(%ebp)       # arr[3]
    movl    $50, -4(%ebp)       # arr[4]

    # int *p[] = {arr, arr + 1, arr + 2, arr + 3, arr + 4};
    leal    -20(%ebp), %ebx         # *p[]

    movl    %ebx, -40(%ebp)         # arr

    addl    $4, %ebx                # arr + 1
    movl    %ebx, -36(%ebp)         # arr + 1

    addl    $4, %ebx                # arr + 2
    movl    %ebx, -32(%ebp)         # arr + 2

    addl    $4, %ebx                # arr + 3
    movl    %ebx, -28(%ebp)         # arr + 3

    addl    $4, %ebx                # arr + 4
    movl    %ebx, -24(%ebp)         # arr + 4

    # printf("arr = %-10d \t *arr = %-10d \t &arr = %-10d\n", arr, *arr, &arr);
    leal    -20(%ebp), %ebx

    movl    $msg_print_arr_arr_arr, (%esp)
    movl    %ebx, 4(%esp)

    movl    (%ebx), %edx
    movl    %edx, 8(%esp)

    movl    %ebx, 12(%esp)
    call    printf

    # printf("p = %-10d \t *p = %-10d \t **p = %-10d\n", p, *p, **p);

    movl    $0, (%esp)
    call    exit

