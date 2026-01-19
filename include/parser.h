/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:27:04 by jiyawang          #+#    #+#             */
/*   Updated: 2026/01/19 15:31:02 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "executor.h"

typedef struct s_minishell		t_minishell;
typedef struct s_command		t_command;
typedef struct s_redir			t_redir;
typedef enum e_redirect_type	t_redirect_type;

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC
}								t_token_type;

typedef enum e_quotes
{
	NOT_IN_QUOTES,
	IN_SINGLE_QUOTES,
	IN_DOUBLE_QUOTES
}								t_quotes;

typedef struct s_token
{
	char						*value;
	t_token_type				type;
	struct s_token				*next;
}								t_token;

/* Parser */
t_token							*tokenize(char *str);
t_command						*parse_tokens(t_token *t);
t_token							*add_new_tok(char *value, t_token_type type);
void							token_add_back(t_token **lst, t_token *new);
void							free_tokens(t_token *tokens);
int								syntax_error(char *str);
int								check_syntax(t_token *t);
void							expand_cmds(t_command *cmds, t_minishell *sh);
char							*get_name_for_var(char *word, int *i);
char							*expand_word(char *word, t_minishell *shell);
void							handle_angle_brackets(char *str,
									t_token **tokens, int *i);
void							command_add_back(t_command **lst,
									t_command *new);
t_command						*new_command(void);
int								add_arg_to_cmd(t_command *cmd, char *word);
char							*delete_quotes(char *str);
int								check_quotes_balance(char *str);
int								is_quote(char c);

#endif
