############### IF
.text
.globl main
	main:
		ld $a1,$age # carrega idade da memoria
		blt $a1,18,smaller # verifica se a idade eh menor que 18, caso sim, vai para smaller
		la $a0,$text1 # idade maior, carrega text1
		j end # jump para o fim
	smaller:
		la $a0,$text2
	end:
		li $v0,4
		syscall
		li $v0,10
		syscall
.data
	$age: .word 16
	$text1: .asciiz "Y"
	$text2: .asciiz "N"