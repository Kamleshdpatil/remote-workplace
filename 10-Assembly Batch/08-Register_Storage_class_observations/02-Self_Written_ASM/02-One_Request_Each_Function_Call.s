	.file	"02-One_Request_Each_Function_Call.c"
	.text
	.section	.rodata
.LC0:
	.string	"Request number: %d\n"
.LC1:
	.string	"Value of reg_var1: %d\n\n"
	.text
	.globl	fun
	.type	fun, @function
fun:
.LFB6:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	subl	$8, %esp
	pushl	8(%ebp)
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %ebx
	subl	$8, %esp
	pushl	%ebx
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE6:
	.size	fun, .-fun
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$4, %esp
	subl	$12, %esp
	pushl	$1
	call	fun
	addl	$16, %esp
	subl	$12, %esp
	pushl	$2
	call	fun
	addl	$16, %esp
	subl	$12, %esp
	pushl	$3
	call	fun
	addl	$16, %esp
	subl	$12, %esp
	pushl	$4
	call	fun
	addl	$16, %esp
	subl	$12, %esp
	pushl	$0
	call	exit
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (GNU) 16.1.1 20260515 (Red Hat 16.1.1-2)"
	.section	.note.GNU-stack,"",@progbits
