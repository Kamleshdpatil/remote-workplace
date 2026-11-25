.equ NULL, 0
.equ INT_SIZE, 4
.equ INT_POINTER_SIZE, 4

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
    movl    $10, -20(%ebp)          # arr[0]
    movl    $20, -16(%ebp)          # arr[1]
    movl    $30, -12(%ebp)          # arr[2]
    movl    $40, -8(%ebp)           # arr[3]
    movl    $50, -4(%ebp)           # arr[4]
    # -----------------------------------

    # int *p[] = {arr, arr + 1, arr + 2, arr + 3, arr + 4};
    leal    -20(%ebp), %ebx         # base address of arr

    movl    %ebx, -44(%ebp)         # p[0] = arr
    
    addl    $4, %ebx
    movl    %ebx, -40(%ebp)         # p[1] = arr + 1
    
    addl    $4, %ebx
    movl    %ebx, -36(%ebp)         # p[2] = arr + 2
    
    addl    $4, %ebx
    movl    %ebx, -32(%ebp)         # p[3] = arr + 3
    
    addl    $4, %ebx
    movl    %ebx, -28(%ebp)         # p[4] = arr + 4

    # int **ptr = p;
    leal    -44(%ebp), %ebx
    movl    %ebx, -24(%ebp)         # ptr = address of p[0]

    # printf("arr = %-10d \t *arr = %-10d \t &arr = %-10d\n", arr, *arr, &arr);
    leal    -20(%ebp), %ebx

    movl    $msg_print_arr_arr_arr, (%esp)
    movl    %ebx, 4(%esp)

    movl    (%ebx), %edx
    movl    %edx, 8(%esp)

    movl    %ebx, 12(%esp)
    call    printf

    # printf("p = %-10d \t *p = %-10d \t **p = %-10d\n", p, *p, **p);
    leal    -44(%ebp), %ebx         # p
    
    movl    $msg_print_p_p_p, (%esp)
    movl    %ebx, 4(%esp)           # p

    movl    (%ebx), %ebx
    movl    %ebx, 8(%esp)           # *p

    movl    (%ebx), %edx
    movl    %edx, 12(%esp)          # **p
    call    printf

    # printf("ptr = %-10d \t *ptr = %-10d \t **ptr = %-10d\n", ptr, *ptr, **ptr);
    movl    $msg_print_ptr_ptr_ptr, (%esp)
    
    movl    -24(%ebp), %ebx             # ptr
    movl    %ebx, 4(%esp)               # ptr

    movl    (%ebx), %ebx                # *ptr
    movl    %ebx, 8(%esp)

    movl    (%ebx), %eax                # *ptr
    movl    %eax, 12(%esp)              # **ptr
    call    printf

    # -------------------------------------------------
    # *ptr++;
    movl    $1, %ecx                  # 1
    movl    $INT_SIZE, %eax           # 4
    mull    %ecx                      
    movl    -24(%ebp), %ecx           # ptr
    addl    %ecx, %eax
    movl    %eax, -24(%ebp)           # *ptr

    # printf("ptr - p = %d \t *ptr - arr = %d \t **ptr = %d\n", ptr - p, *ptr - arr, **ptr);
    movl    $msg_print_arithmetic, (%esp)

    # ptr - p
    movl    -24(%ebp), %eax         # ptr
    leal    -44(%ebp), %ebx         # p
    subl    %ebx, %eax              # ptr - p
    movl    $0, %edx
    movl    $INT_SIZE, %ecx          # 4
    idivl   %ecx
    movl    %eax, 4(%esp)

    # *ptr - arr
    movl    -24(%ebp), %ecx
    movl    (%ecx), %eax
    leal    -20(%ebp), %ebx         # arr
    subl    %ebx, %eax              # *ptr - arr
    movl    $0, %edx
    movl    $INT_SIZE, %ecx          # 4
    idivl   %ecx
    movl    %eax, 8(%esp)

    # **ptr
    movl    -24(%ebp), %ecx
    movl    (%ecx), %eax            # *ptr
    movl    (%eax), %edx            # *ptr
    movl    %edx, 12(%esp)          # **ptr
    call    printf

    # --------------------------------------------------------
    # *++ptr;
    movl    $1, %ecx                  # 1
    movl    $INT_SIZE, %eax           # 4
    mull    %ecx
    movl    -24(%ebp), %ecx         # ptr
    addl    %ecx, %eax
    movl    %eax, -24(%ebp)         # *ptr

    # printf("ptr - p = %d \t *ptr - arr = %d \t **ptr = %d\n", ptr - p, *ptr - arr, **ptr);
    movl    $msg_print_arithmetic, (%esp)

    # ptr - p
    movl    -24(%ebp), %eax         # ptr
    leal    -44(%ebp), %ebx         # p
    subl    %ebx, %eax              # ptr - p
    movl    $0, %edx
    movl    $INT_SIZE, %ecx          # 4
    idivl   %ecx
    movl    %eax, 4(%esp)

    # *ptr - arr
    movl    -24(%ebp), %ecx
    movl    (%ecx), %eax
    leal    -20(%ebp), %ebx         # arr
    subl    %ebx, %eax              # *ptr - arr
    movl    $0, %edx
    movl    $INT_SIZE, %ecx          # 4
    idivl   %ecx
    movl    %eax, 8(%esp)

    # **ptr
    movl    -24(%ebp), %ecx
    movl    (%ecx), %eax            # *ptr
    movl    (%eax), %edx            # *ptr
    movl    %edx, 12(%esp)          # **ptr
    call    printf

    # --------------------------------------------------------
    # ++*ptr;
    movl    $1, %ecx                  # 1
    movl    $INT_SIZE, %eax           # 4
    mull    %ecx

    movl    -24(%ebp), %ebx           # ptr
    movl    (%ebx), %ecx
    addl    %ecx, %eax
    movl    %eax, (%ebx)              # *ptr

    # printf("ptr - p = %d \t *ptr - arr = %d \t **ptr = %d\n", ptr - p, *ptr - arr, **ptr);
    movl    $msg_print_arithmetic, (%esp)

    # ptr - p
    movl    -24(%ebp), %eax         # ptr
    leal    -44(%ebp), %ebx         # p
    subl    %ebx, %eax              # ptr - p
    movl    $0, %edx
    movl    $INT_SIZE, %ecx          # 4
    idivl   %ecx
    movl    %eax, 4(%esp)

    # *ptr - arr
    movl    -24(%ebp), %ecx
    movl    (%ecx), %eax
    leal    -20(%ebp), %ebx         # arr
    subl    %ebx, %eax              # *ptr - arr
    movl    $0, %edx
    movl    $INT_SIZE, %ecx          # 4
    idivl   %ecx
    movl    %eax, 8(%esp)

    # **ptr
    movl    -24(%ebp), %ecx
    movl    (%ecx), %eax            # *ptr
    movl    (%eax), %edx            # *ptr
    movl    %edx, 12(%esp)          # **ptr
    call    printf

    movl    $0, (%esp)
    call    exit

