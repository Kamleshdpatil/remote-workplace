	.file	"Assembly.c"
	.text
	.globl	name
	.data
	.type	name, @object
	.size	name, 5
name:
	.string	"file"
	.section	.rodata
.LC0:
	.string	"creat failed"
.LC1:
	.string	"created"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$438, %esi
	movl	$name, %edi
	call	creat
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L2
	movl	$.LC0, %edi
	call	puts
	jmp	.L3
.L2:
	movl	$.LC1, %edi
	call	puts
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.2.1 20260123 (Red Hat 15.2.1-7)"
	.section	.note.GNU-stack,"",@progbits
