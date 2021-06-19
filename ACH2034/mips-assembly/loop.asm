########## LOOP

.text
.globl main
main:
        li $a0,0                        # inicia o total
        li $a1,1                        # inicia o contador
loop:
        add $a0,$a0,$a1                # adiciona o contador no total
        addi $a1,$a1,1                # incrementa o contador
        ble $a1,10,loop                #verifica se eh menor ou igual a 10. caso sim, continua o loop
        li $v0,1                        # imprime o resultado
        syscall
        li $v0,10                        # termina
        syscall