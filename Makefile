# Nome do executável
TARGET = myProgram

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Arquivos fonte e objetos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Opções do compilador
CC = gcc
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra

# Regra principal
all: $(BIN_DIR) $(BIN_DIR)/$(TARGET)

# Regra para criar os diretórios de build
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Regra para criar o executável
$(BIN_DIR)/$(TARGET): $(OBJS)
	@$(CC) -o $@ $(OBJS)

# Regra para compilar arquivos .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	@rm -rf $(BUILD_DIR)

# Regra para executar o programa
run: all
	@$(BIN_DIR)/$(TARGET)

.PHONY: all clean run
