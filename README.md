# EDCare:

## Funcionamento do programa:
O programa consiste em três pastas principais:
- include/ -> possui os headers de todas as bibliotecas implementadas
- src/ -> possui os arquivos-fonte de todas as bibliotecas implementadas e o arquivo principal (main.c)
- Entrada/ -> possui os arquivos fornecidos pelo cliente

Toda a utilização do programa é feita através de um makefile, onde seus principais comandos são:
- "make" -> cria as pastas temporárias obj/ (com os arquivos objeto de cada arquivo-fonte), bin/ (com o arquivo executável) e Saida/ (pasta vazia por enquanto)
- "make run r=x" ('x' deve ser substituído pela quantidade de leituras que o programa deve fazer dos arquivos de entrada) -> executa o arquivo final.exe e gera todos os arquivos-saida na pasta Saida/
- "make clean" -> exclui todas as pastas temporárias


