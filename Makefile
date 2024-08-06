# Definições de compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

# Nomes dos arquivos de saída e fonte
TARGET = programa
SOURCES = main.c lista_encadeada.c
HEADERS = lista_encadeada.h
OBJECTS = $(SOURCES:.c=.o)

# Regra padrão para construir o alvo
all: $(TARGET)

# Regra para compilar o alvo
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para compilar os arquivos objeto
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJECTS) $(TARGET)

# Execução do programa
run: $(TARGET)
	./$(TARGET)

# Recompilar e rodar
rebuild: clean all run
