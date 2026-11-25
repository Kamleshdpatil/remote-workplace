	.file	"incement.c"
	.text
	.section	.rodata
	.align 4
.LC0:
	.string	"iNo1 = %d, iNo2 = %d\niAns1 = %d, iAns2 = %d\n"
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
	subl	$20, %esp
	movl	$10, -12(%ebp)
	movl	$20, -16(%ebp)
	addl	$1, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-16(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -16(%ebp)
	movl	%eax, -24(%ebp)
	subl	$12, %esp
	pushl	-24(%ebp)
	pushl	-20(%ebp)
	pushl	-16(%ebp)
	pushl	-12(%ebp)
	pushl	$.LC0
	call	printf
	addl	$32, %esp
	subl	$12, %esp
	pushl	$0
	call	exit
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (GNU) 16.1.1 20260515 (Red Hat 16.1.1-2)"
	.section	.note.GNU-stack,"",@progbits
