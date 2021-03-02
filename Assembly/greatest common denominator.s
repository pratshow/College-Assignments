.data

var:	.word

prompt1:	.asciz	"Please enter your first number.\n"
prompt2:	.asciz	"Please enter your second number.\n"
input:	.asciz	"%d"
output:	.asciz	"The greatist common denominater of %d and %d is %d.\n"

.align 2
.text
.align 2

.global main
.global gcd

.func main
main:

	push	{fp, lr}
	add	fp, sp, #4


	sub	sp, sp, #8	@ Prompt 1: [fp, #-8]
				@ Prompt 2: [fp, #-12]

	ldr	r0, =prompt1
	bl	printf

	ldr	r0, =input
	sub	r1, fp, #8
	bl	scanf


	ldr	r0, =prompt2
	bl	printf

	ldr	r0, =input
	sub	r1, fp, #12
	bl	scanf


	ldr	r0, [fp, #-8]	@ Loading user values into registers so
	ldr	r1, [fp, #-12]	@ I can pass them to the gcd function.
	bl	gcd

	sub	sp, fp, #4
	pop	{fp, pc}

.endfunc

.func gcd
gcd:

	push	{fp, lr}
	add	fp, sp, #4

	sub	sp, sp, #8 	@[fp, #-8], [fp, #-12]


				@ Storing inputs into stack for new function 
	str	r0, [fp, #-8]	@ User input 1 - [fp, #-8]
	str	r1, [fp, #-12]	@ User input 2 - [fp, #-12]
			
				@loading inputs into registers
	ldr	r0, [fp, #-8]	@ Input 1 stored into r0
	ldr	r1, [fp, #-12]	@ Input 2 stored into r1

	bl	gcd_check

gcd_check:
	
	mov	r3, #0	@ Using r3 as 0 comparison
	cmp	r3, r1
	beq	if_zero
	bl	if_remainder

if_remainder:

	mov	r2, r1		@ 'Save' the second parameter for the next cycle
	bl	__aeabi_idivmod	@ R0 is dividor
				@ R1 is remainder
	mov	r0, r2	@ Put the 'saved' second parameter back into r0 to use as parameter 1 for the next modulus.
	bl	gcd_check

if_zero:

	mov	r3, r0		@ Organizing registers for printing
	ldr	r1, [fp, #-8]
	ldr	r2, [fp, #-12]
	ldr	r0, =output
	bl	printf	
		

	sub	sp, fp, #4
	pop	{fp, pc}
.endfunc
