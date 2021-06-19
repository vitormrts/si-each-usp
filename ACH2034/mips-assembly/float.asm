########## FLOAT
.text
.globl main
main:
	l.s $f12,$first_value   # carrega o float 45.1 no f12
	l.s $f13,$second_value # carrega o flotad 12.4 no f13
	add.s $f12,$f12,$f13 # soma
	li $v0,2 # imprime o float $f12
	syscall 
	li $v0,10
	syscall 
.data
$first_value: .float 45
$second_value: .float 12.4	
