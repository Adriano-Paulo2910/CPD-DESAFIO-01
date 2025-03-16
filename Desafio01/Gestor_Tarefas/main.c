#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_ID_LENGTH 100

typedef struct
{
    char id[MAX_ID_LENGTH];
    int prioridade;
    time_t data_criacao;
} Tarefa;

Tarefa lista_tarefas[MAX_TASKS];
int total_tarefas = 0;

void adicionar_tarefa(int prioridade, char id[])
{
    if (total_tarefas >= MAX_TASKS)
    {
        printf("Lista de tarefas cheia.\n");
        return;
    }

    strcpy(lista_tarefas[total_tarefas].id, id);
    lista_tarefas[total_tarefas].prioridade = prioridade;
    lista_tarefas[total_tarefas].data_criacao = time(NULL);
    total_tarefas++;

    printf("Tarefa '%s' adicionada com sucesso.\n", id);
}

void listar_tarefas(int prioridade_minima)
{
    printf("Tarefas com prioridade >= %d:\n", prioridade_minima);
    for (int i = 0; i < total_tarefas; i++)
    {
        if (lista_tarefas[i].prioridade >= prioridade_minima)
        {
            printf("Tarefa: %s, Prioridade: %d\n", lista_tarefas[i].id, lista_tarefas[i].prioridade);
        }
    }
}

void remover_tarefa(char id[])
{
    int encontrada = 0;
    for (int i = 0; i < total_tarefas; i++)
    {
        if (strcmp(lista_tarefas[i].id, id) == 0)
        {
            encontrada = 1;
            // Remover tarefa deslocando as seguintes
            for (int j = i; j < total_tarefas - 1; j++)
            {
                lista_tarefas[j] = lista_tarefas[j + 1];
            }
            total_tarefas--;
            printf("Tarefa '%s' completada e removida.\n", id);
            break;
        }
    }
    if (!encontrada)
    {
        printf("TAREFA INEXISTENTE.\n");
    }
}

int main()
{
    char comando[50];
    char id[MAX_ID_LENGTH];
    int prioridade;

    while (1)
    {
        printf("\nDigite o comando: ");
        scanf("%s", comando);

        if (strcmp(comando, "new") == 0)
        {
            scanf("%d %s", &prioridade, id);
            adicionar_tarefa(prioridade, id);
        }
        else if (strcmp(comando, "list") == 0)
        {
            scanf("%d", &prioridade);
            listar_tarefas(prioridade);
        }
        else if (strcmp(comando, "complete") == 0)
        {
            scanf("%s", id);
            remover_tarefa(id);
        }
        else if (strcmp(comando, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("Comando inválido.\n");
        }
    }

    return 0;
}
