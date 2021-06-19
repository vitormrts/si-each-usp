# Conjunto de instruções do MIPS
## Operacoes no MIPS
### Aritmetica
```mips
add $s1, $s2, $s3 # $s1 = $s2 + $s3 
sub $s1, $s2, $s3 # #s1 = $s2 - $s3
addi $s1, $s2,  20 # $s2 = $s2 + 20 => somar constantes
```

### Transferencia de dados
```mips
lw $s1, 20($s2) # $s1 = Memoria[$s2 + 20] => load word, memoria para registrador
sw $s1, 20($s2) # Memoria[$s2 + 20] = $s1 => store word, registrador para memoria
lh $s1, 20($s2) # $s1 = Memoria[$s2 + 20] => load half, halfword da memoria para registrador
lhu $s1, 20($s2) # $s1 = Memoria[$s2 + 20] => load half unsigned, halfword da memoria para registrador
lb $s1, 20($s2) # $s1 = Memoria[$s2 + 20] = $s1 => load byte, byte da memoria para registrador
lbu $s1, 20($s2) # $s1 = Memoria[$s2 + 20] = $s1 => load byte unsigned, byte da memoria para registrador
sb $s1, 20($s2) # Memoria[$s2 + 20] = $s1 => store byt,e byte do registrador para memoria
ll $s1, 20($s2) # $s1 = Memoria[$s2 + 20] => load linked word, carrega word como 1metade do swap atomico
sc $s1, 20($s2) # Memoria[$s2+20] = $s1;$s1=0 or 1 => sotre condition, word, armazena word como 2 metade do swap atomico
lui $s1,20 # $s1 = 20 * 2^16 # carrega constante nos 16 bits mais altos
```

### Logica
```mips
and $s1,$s2,$s3 # $s1 = $s2 & $s3 => E
or $s1,$s2,$s3 # $s1 = $s2 |  $s3 => OU
nor $s1,$s2,$s3 # $s1 = ~($s2 |  $s3) => NAO OU
andi $s1,$s2,20 # $s1 = $s2 & 20 => E com constante
ori $s1,$s2,20 # $s1 = $s2 | 20 => OU com constante
sll $s1,$s2,10 # $s1 = #s2 << 10 => shift left logical
srl $s1,$s2,10 # $s1 = #s2 >> 10 => shift right logical
```

### Desvio condicional
```mips
beq $s1,$s2,25 # if ($s1 == $s2) go to PC + 4 + 100 => igualdade
bne $s1,$s2,25 # if ($s1 != $s2) go to PC + 4 + 100 => desigualdade
slt $s1,$s2,$s3 # if ($s2 < $s3) $s1 = 1 else $s1 = 0 => menor que com sinal
sltu $s1, $s2,$s3 # if ($s2 < $s3) $s1 = 1 else $s1 = 0 => menor que sem sinal
slti $s1,$s2,20 # if ($s2 < 20) $s1 = 1 else $s1 = 0 => menor que constante
sltiu $s1,$s2,20 # if ($s2 < 20) ... => menor que constante sem sinal
```

### Desvio incondicional
```mips
j 2500 # got o 10000 => jump, desvia para o endereco destino
jr $ra # go to $sa => jump register, para switch e retorno de procedimento
jal 2500 # $ra = PC + 4; go to 10000 => jump and link, para chamada de procedimento
```

## Compilando um if
Em C, temos:
```c
if (i==j) 
    f = g + h;
else
    f = g - h
```
Sabendo que f, g, ... equivale a $s0, $s1, ..., temos que na arquitetura MIPS:
```mips
bne $s3, $s4, Else
add $s0, $s1, $s2
j Exit

Else => sub $s0, $s1, $s2
Exit => ...
```

## Compilando um while (loop)
Em C, temos:
```c
while (save[i] == k) I += 1;
```

Ja na arquitetura MIPS, onde i esta em $s3, k em $s5 e o endereco de save em $s6:
```mips
Loop: 
sll $t1, $s3, 2 // shift logical left
add $t1, $t1, $s6
lw $t0, 0($t1)
bne $t0, $s5, Exit
addi $s3, $s3, 1
j Loop

Exit: ...
```

## Operadores condicionais
Resultado igual a 1 se condicao for verdade, 0 caso contrario
```mips
slt rd, rs, rt # if (rs < rt) rd = 1; else rd = 0
slti rt, rs, constant #if (rs < constant) rt = 1; else rt = 0;

slt $t0, $s1, $s2 # if ($s1 < $s2)
bne $t0, $zero, L # branch to L  
```

## Comparacao com e sem sinal
- Comparacao com sinal (signed): `slt`, `slti`
- Comparacao sem sinal (unsigned): `sltu`, `sltui`

Exemplo:
```mips
$s0 = 1111 1111 1111 1111 1111 1111 1111 1111 
$s1 = 0000 0000 0000 0000 0000 0000 0000 0001
slt $t0, $s0, $s1 # signed
-1 < +1 => $t0 = 1
sltu $t0, $s0, $s1 #unsigned
+4,294,967,295 > +1 => $t0 = 0
```

## Chamadas de procedimento
Normalmente fazemos usos de funcoes, classes, onde temos variaveis locais, globais, alem de poder ter a passagem de parametros de valores etc. Como implementar isso em Assembly? Precisamos seguir esses passos:

- 1. Colocar parametros nos registradores ($a0, $a1, $a2, $a3)
- 2. Transferir controle (jal) => jump and link
- 3. Salvar registradores $s que usar na pilha
- 4. Executar operacoes do procedimento
- 5. Colocar resultados nos registradores de retorno ($v0, $v1)
- 6. Restaurar registradores $s e retornar (jr $ra) => jump return

### Exemplo
Codigo em C
```c
int folha (int g, h, i, j) {
    int f;
    f = (g + h) - (i + j);
    return f;
}
```

Assumindo que:
- g, ..., j em $a0, ..., $a3
- f em $s0 -> salvar $s0
- Resultado em $v0

Codigo em MIPS

```mips
folha:
    addi $sp, $sp, -4 
    sw $s0, 0($sp)
    add $t0, $a0, $a1
    add $t1, $a2, $a3
    sub $s0, $t0, $t1
    add $v0, $s0, $zero
    lw $s0, 0($sp)
    addi $sp, $sp, 4
    jr $ra
```