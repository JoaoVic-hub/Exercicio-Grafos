# Compilação do projeto
CC = gcc
CFLAGS = -Wall -g
TARGET = grafo

# Objetivos padrão de compilação
all: $(TARGET)

$(TARGET): main.o grafo.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o grafo.o

main.o: main.c grafo.h
	$(CC) $(CFLAGS) -c main.c

grafo.o: grafo.c grafo.h
	$(CC) $(CFLAGS) -c grafo.c

# Limpa arquivos objetos e binários
clean:
	rm -f *.o $(TARGET)
