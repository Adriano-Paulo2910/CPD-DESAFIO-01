# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -g -Wall

# Ficheiros objeto
OBJ = main.o list.o

# Executável final
EXEC = gestor_tarefas

# Regras para compilar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Regras para compilar main.c
main.o: main.c list.h
	$(CC) $(CFLAGS) -c main.c

# Regras para compilar list.c
list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

# Limpeza dos ficheiros compilados
clean:
	rm -f $(OBJ) $(EXEC)
