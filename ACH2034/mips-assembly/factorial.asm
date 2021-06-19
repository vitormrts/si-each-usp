########## SUBROUTINE

.text
.globl main
main:
        li $a0,4                        # inicia o total
        jal fatorial                # chama o fatorial
        li $v0,1                        # imprime o resultado
        syscall
        li $v0,10                        # termina
        syscall
        
fatorial: 
        bgt $a0,1,fat_exec        # verifica se chegou no final
        li $a0,1                        # coloca 1 no $a0
        j fat_fim                        # vai para o final
        
fat_exec:
        subu $sp,$sp,8                # Abre um espaco na pilha
        sw $a0,4($sp)                # Salva o $a0
        sw $ra,0($sp)                # Salva o endereco de retorno
        subu $a0,$a0,1                # subtrai 1 do fatorial
        jal fatorial                # chama o fatorial
        lw $ra,0($sp)                # recupera o valor original do $a0 em $a1
        lw $a1,4($sp)                # recupera o valor original do $a0 em $a1
        addu $sp,$sp,8                # retira o espaco ocupado na pilha
        mul $a0,$a0,$a1                # multiplica

fat_fim: 
        jr $ra                                # retorna

