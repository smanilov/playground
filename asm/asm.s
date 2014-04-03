	.text
	.globl	myasmfunc
myasmfunc:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	popq	%rbp
	ret
