# FifoPageReplacement

Este projeto usa um `Makefile` para compilar e executar o programa em C. Para utilizar o Makefile, você precisará de uma ferramenta compatível com comandos Unix-like, como Git Bash, Windows Subsystem for Linux (WSL), ou um ambiente Linux nativo. Siga os passos abaixo para executar o programa:

## Compilar e Executar

Para compilar e executar o programa, use o seguinte comando:

```bash
make run
```

Esse comando irá:
1. **Compilar o código-fonte** (se necessário).
2. **Executar o programa**.

## Observações
- Certifique-se de que você tem o make e o compilador gcc instalados no seu sistema.
- O executável será gerado no diretório build/bin/.

## Limpar Arquivos Gerados
Para limpar os arquivos gerados pela compilação, use:
```bash
make clean
```
Esse comando irá limpar o diretório build/ e remover todos os arquivos gerados.
