	.text
	.globl	entry
entry:	leal	stack, %esp
	jmp	cmain

	.data
	.space	4096		# User stack
stack:

	# System call to print a character in the kernel's window
	.globl	kputc
kputc:	pushl	%eax
	mov	8(%esp), %eax
	int	$128
	popl	%eax
	ret

	#function that tries to halt the machine while in user mode
	.globl yield
yield:	hlt		#halts machine
	jmp yield	#if halt fails, jmps to beginning of yield function
