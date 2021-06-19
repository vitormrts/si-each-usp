############### INTEGER
.text
.globl main
main:
	ld $a0,$valor        # obtem valor da memoria
	addi $a0,$a0,20
	li $v0,1	    # imprime o inteiro $a0
	syscall
	li $v0,10	    # exit
	syscall
.data
$valor: .word 45