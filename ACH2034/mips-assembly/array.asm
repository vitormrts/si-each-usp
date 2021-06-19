########## VECTOR

.text

.globl main
main:
        li $a0,0                        # inicia o total
        la $a1,$vetor                # aponta para o vetor
        la $a2,0                        # inicia o contador

loop:
        ld $a3,($a1)                # carrega o valor apontado pelo a1 para dentro do $a3
        add $a0,$a0,$a3                # adiciona o $a3 no total $a0
        addi $a1,$a1,4                # incrementa o apontador, indo para a proxima posicao
        addi $a2,$a2,1                # incrementa o contador
        blt $a2,5,loop                # verifica se terminou (percorreu os 5 elementos do vetor) e faz o loop
        li $v0,1                        # imprime o resultado
        syscall
        li $v0,10                        # termina
        syscall
.data
$vetor: .word 20, 21, 22, 23, 24