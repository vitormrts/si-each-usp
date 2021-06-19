.data
	$char: .byte 'A' # caractere a ser impresso

.text
	la $a0, $char # load address
	li $v0, 4 # imprimir char ou string
	syscall
	li $v0,10
	syscall
	