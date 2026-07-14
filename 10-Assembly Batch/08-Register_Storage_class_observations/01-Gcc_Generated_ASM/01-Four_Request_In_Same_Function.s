	.file	"01-Four_Request_In_Same_Function.c"
	.text
	.section	.rodata
.LC0:
	.string	"Value of reg_var1: %d\n"
.LC1:
	.string	"Value of reg_var2: %d\n"
.LC2:
	.string	"Value of reg_var3: %d\n"
.LC3:
	.string	"Value of reg_var4: %d\n"
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
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x70,0x6
	.cfi_escape 0x10,0x7,0x2,0x75,0x7c
	.cfi_escape 0x10,0x6,0x2,0x75,0x78
	.cfi_escape 0x10,0x3,0x2,0x75,0x74
	subl	$8, %esp
	movl	$10, %eax
	movl	$20, %edi
	movl	$30, %esi
	movl	$40, %ebx
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	pushl	%edi
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	pushl	%esi
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	pushl	%ebx
	pushl	$.LC3
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
