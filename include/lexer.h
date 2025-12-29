/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:54:15 by jiyawang          #+#    #+#             */
/*   Updated: 2025/12/29 15:55:03 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "minishell.h"
typedef enum e_token_type
{
    WORD,
    PIPE,
    REDIR_IN,
    REDIR_OUT,
    REDIR_APPEND,
    HEREDOC,
}				t_token_type;
typedef struct s_token
{
    t_token_type        type;
    char               *value;
    struct s_token     *next;
}                   t_token;

t_token *lexer(const char *input);
t_token *create_token(t_token_type type, const char *value);
void    free_tokens(t_token *head);
int     is_operator_char(char c);
int     get_operator_length(const char *input);
int     is_whitespace(char c);
int     skip_whitespaces(const char *input, int start);
int     get_word_length(const char *input);
char    *extract_word(const char *input, int length);
char    *extract_operator(const char *input, int length);
int     handle_quotes(const char *input, int *index, char **buffer);
int     append_char_to_buffer(char **buffer, char c);
int     append_str_to_buffer(char **buffer, const char *str);
int     process_word_token(const char *input, int *index, t_token **token_list);
int     process_operator_token(const char *input, int *index, t_token **token_list);
int     add_token_to_list(t_token **head, t_token *new_token);
#endif