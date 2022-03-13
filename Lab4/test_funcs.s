_f1:                                    ## @f1
	pushq	%rbp
	movq	%rsp, %rbp
	leal	(%rdi,%rsi), %eax
	popq	%rbp
	retq


_f2:                                    ## @f2
	pushq	%rbp
	movq	%rsp, %rbp
	imull	%esi, %edi
	movswl	%di, %eax
	popq	%rbp
	retq

_f3:                                    ## @f3
	pushq	%rbp
	movq	%rsp, %rbp
	leaq	(%rdi,%rsi,4), %rax
	leaq	(%rdx,%rdx,2), %rcx
	leaq	1(%rax,%rcx,4), %rax
	popq	%rbp
	retq

_f4:                                    ## @f4
	pushq	%rbp						
	movq	%rsp, %rbp
	movslq	(%rdx), %rax
	movl	(%rsi,%rax,4), %eax
	movl	%eax, (%rdi)
	popq	%rbp
	retq


_should_continue:                       ## @should_continue
	pushq	%rbp
	movq	%rsp, %rbp
	xorl	%eax, %eax
	cmpl	%esi, %edi
	setl	%al
	popq	%rbp
	retq

_f5:                                    ## @f5
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r14
	pushq	%rbx
	movl	%esi, %r14d
	xorl	%ebx, %ebx
LBB5_1:                                 ## =>This Inner Loop Header: Depth=1
	incl	%ebx
	movl	%ebx, %edi
	movl	%r14d, %esi
	callq	_should_continue
	testl	%eax, %eax
	jne	LBB5_1
## %bb.2:
	movl	%ebx, %eax
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
