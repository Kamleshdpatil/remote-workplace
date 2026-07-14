	.file	"main.c"
	.text
	.local	g_iNo
	.comm	g_iNo,4,4
	.section	.rodata
.LC0:
	.string	"In main, Number is %d\n"
.LC1:
	.string	"In main, Address is %d\n"
	.align 4
.LC2:
	.string	"In main, after assign value inside fun Number is %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
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
	movl	g_iNo, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	pushl	$g_iNo
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	call	fun
	movl	g_iNo, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	subl	$12, %esp
	pushl	$0
	call	exit
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (GNU) 16.1.1 20260515 (Red Hat 16.1.1-2)"
	.section	.note.GNU-stack,"",@progbits
