    Minha ideia inicial do trabalho foi criar as pecas do tetris, 
sendo um array dinamico de arrays dinamicos seguindo o padrao da tela do jogo. 
Entao, na funcao de rotacionar a peca eu literalmente coloco os caracteres da peca 
referente, ja na posicao mais a esquerda e a cima possivel da "matriz" de cada peca, 
dai verifico se da para inserir no jogo, utilizando a funcao isalpha da Biblioteca
cctype , se der, insere. Na funcao de remover linhas completas utilizei  ao identificar 
a linha que esta completa, eu removi todos os caracteres colocando um " " no lugar deles 
e depois trocando as posicoes das mesmas com os caracteres da frente caso tiver, até o final
da coluna e depois redimenciona o jogo alocando as alturas novamente.

Fontes de consultas:
 .Biblioteca cctype - cplusplus.com
 .Rotacao de pecas - Aulas Sincronas gravadas
 .Funcao de removeLinhasCompletas - Aulas Sincronas gravadas e materias das praticas(MyVec)
