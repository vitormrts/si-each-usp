########## HELLO WORLD

.text # instrucoes do programa
.globl main
main:
        la $a0,$texto                # load address => indica o endereco em que esta o texto
        li $v0,4                     # load imediate => instrucao para impressao da string
        syscall			     # faz a chamada de impressao
        
        li $v0,10                        # termina o programa
        syscall
.data # area para dados na memoria principal
	$texto:
   .asciiz "Hello World" # texto a ser exibido