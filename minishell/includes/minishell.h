/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 13:33:27 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-09 13:33:27 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ════════════════════════ 🟡 DEFINES 🟡 ════════════════════════ */
# define MAX_ARGS 1024
# define PROMPT "\001\e[1m\e[93m\002minishell$ \001\e[0m\002"

/* ════════════════════════ 🟡 INCLUDES 🟡 ════════════════════════ */
# include "../src/miniutils/miniutils.h"
# include "./libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/* ════════════════════════ 🟢 ENUMS 🟢 ════════════════════════ */
typedef enum e_quotes_type
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}						t_quotes;

/* ════════════════════════ 🔵 STRUCTURES 🔵 ════════════════════════ */
typedef struct s_cmd
{
	char				**args;
	char				*infile;
	char				*outfile;
	int					heredoc;
	char				*heredoc_delimiter;
	int					append;
	int					invalid_syntax;
}						t_cmd;

typedef struct s_cmd_node
{
	t_cmd				*cmd;
	struct s_cmd_node	*next;
}						t_cmd_node;

typedef struct s_token
{
	char				*value;
	t_quotes			quote_type;
}						t_token;

typedef struct s_parse_ctx
{
	t_cmd_node			**cmds;
	t_cmd_node			**last;
	t_cmd				*cmd;
	char				**args;
	int					arg_i;
}						t_parse_ctx;

typedef struct s_pipe_ctx
{
	t_token				**tokens;
	int					i;
	t_parse_ctx			pctx;
	char				**envp;
}						t_pipe_ctx;

typedef struct s_prompt
{
	char				*input;
	char				**envp;
	int					i;
	pid_t				pid;
}						t_prompt;

/* ════════════════════════ 🔴 CORE 🔴 ════════════════════════ */
void					command(char *input, char ***envp);
char					*get_input(t_prompt *prompt);
void					cleanup(t_prompt *prompt);
bool					it_is_path(const char *cmd);
int						helper_exec_xmd_path(char **resolved_path,
							char *save_cmd_name, bool should_free);
int						helper_handle_builtin(char **command, char ***envp);
char					*helper_resolve_path(char *cmd, char **envp,
							bool *should_free);
int						helper_exec_process(char *resolved_path, char **command,
							char **envp, bool should_free);

/* ════════════════════════ 🔴 EXECUTION 🔴 ════════════════════════ */
int						execute_command(char **command, char ***envp);
void					execute_pipeline(t_cmd_node *cmds, char ***envp);
int						execute_builtin(char **args, char ***envp);
bool					is_builtin(char *command);

/* ════════════════════════ 🔴 REDIRECTIONS 🔴 ════════════════════════ */
void					redirect_outfile(char *file, bool append);
void					redirect_infile(char *file);

/* ════════════════════════ 🟣 BUILTINS 🟣 ════════════════════════ */
int						builtin_cd(char *path, char ***envp);
int						builtin_echo(char **args);
int						builtin_env(char **envp);
int						builtin_exit(char **command);
int						builtin_export(char **command, char ***envp);
int						builtin_unset(char **command, char ***envp, int i,
							char *varname);
void					update_pwd(char ***envp);
int						builtin_pwd(void);

/* ════════════════════════ 🟢 ENV UTILS 🟢 ════════════════════════ */
int						is_in_envp(char *arg, char **envp);
char					*get_var_name(char *arg);
char					*get_env_var_value(char *var, char **envp);
int						is_var_char(char c);
void					replace_env_var(char ***envp, char *varname,
							char *value);

/* ════════════════════════ 🟡 TOKENIZATION 🟡 ════════════════════════ */
t_token					**tokenize_input(char *input);
t_token					*create_token(char *value, t_quotes quote_type);
t_quotes				get_quote_type(char c);
char					*expand_variables(const char *str, t_quotes quote_type,
							char **envp);
int						is_special(char c);
int						is_quote(char c);
char					*read_multiline_command(t_prompt *prompt);
t_token					*parse_redirection(t_prompt *data);
t_token					*parse_quote(t_prompt *data);
t_token					*parse_word(t_prompt *data);
int						is_assignment_start(t_prompt *data);

/* ════════════════════════ 🔵 PARSING & PIPES 🔵 ════════════════════════ */
t_cmd_node				*parse_pipeline_tokens(t_token **tokens, char **envp,
							t_pipe_ctx *ctx);
void					condition_while_pipe(t_pipe_ctx *ctx);
void					add_cmd_node(t_parse_ctx *pctx);
void					init_parse(t_parse_ctx *pctx);
void					process_token(t_token *token, char **args, int *arg_i,
							char **envp);
void					handle_token(t_token *token, char **args, int *arg_i,
							char **envp);
void					handle_redirection(t_token **tokens, int *i,
							t_cmd *cmd);
void					free_cmd_list(t_cmd_node *cmds);

/* ════════════════════════ 🟤 HEREDOC 🟤 ════════════════════════ */
char					*handle_heredoc(char *delimiter);
void					handle_heredoc_if_needed(t_cmd *cmd);

/* ════════════════════════ 🟣 PATH / BINARY 🟣 ════════════════════════ */
int						get_cmd_path(char **envp, char **binpath, char *cmd);
char					*get_path_variable(char **envp);
char					*ret_path_if_exists(char **list_of_paths,
							char *program_name);
bool					it_is_path(const char *cmd);

/* ════════════════════════ ⚪ MEMORY ⚪ ════════════════════════ */
void					free_double_ptr(void **ptr);
void					free_prompt(t_prompt *prompt);

/* ════════════════════════ 🔴 SIGNALS 🔴 ════════════════════════ */

void					set_signals_interactive(void);
void					set_signals_noninteractive(void);
void					signal_reset_prompt(int signo);

/* ════════════════════════ 🟡 TILDES 🟡 ════════════════════════ */
void					expand_tildes_in_tokens(t_token **tokens, char **envp);
char					*expand_tilde(char *path, char **envp, char *home);

/* ════════════════════════ ⚫ HELPERS ⚫ ════════════════════════ */
char					*append_str(char *base, const char *add);
char					*is_var_name(const char *str, int *len);

#endif
