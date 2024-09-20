/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*     util.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:33:37 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/11 10:21:12 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Função para adicionar o nome na borda superior
static void add_name_to_top_border(char *formatted, const char *name)
{
    sprintf(formatted, "/-%s", name);
    int len = strlen(formatted);
    for (int i = len; i < MAX_WIDTH - 1; i++) {
        formatted[i] = BORDER_CHAR;
    }
    formatted[MAX_WIDTH - 1] = '\\';
    formatted[MAX_WIDTH] = '\n';
    formatted[MAX_WIDTH + 1] = '\0';
}

// Função para adicionar bordas ao redor da mensagem
static void add_borders(char *formatted)
{
    strcat(formatted, "\\");
    for (int i = 1; i < MAX_WIDTH - 1; i++) {
        strcat(formatted, "-");
    }
    strcat(formatted, "/\n");
}

// Função para quebrar o texto em linhas de até MAX_WIDTH-2 caracteres
static void wrap_text(char *formatted, const char *sms)
{
    int len = strlen(sms);
    int start = 0;
    
    while (start < len) {
        strcat(formatted, "| ");
        int end = start + MAX_WIDTH - 4; // Máximo de caracteres por linha
        if (end > len) end = len;

        // Encontrar o último espaço para garantir quebra de palavra
        while (end > start && sms[end] != ' ') {
            end--;
        }

        if (end == start) {
            end = start + MAX_WIDTH - 4; // Forçar quebra de linha
        }

        strncat(formatted, &sms[start], end - start);
        strcat(formatted, "\n");
        start = end + 1;
    }
}

// Função principal que formata a mensagem completa
char *format_message(const char *name, const char *sms)
{
    char *formatted = malloc(5000); // Alocação de espaço para a string final
    if (formatted == NULL) return NULL;

    formatted[0] = '\0'; // Inicializa string vazia
    add_name_to_top_border(formatted, name); // Adiciona borda com nome
    wrap_text(formatted, sms);              // Adiciona o corpo da mensagem
    add_borders(formatted);                 // Adiciona borda inferior
    return formatted; // Retorna a string formatada
}
