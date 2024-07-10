/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cocobolo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:27:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 17:49:37 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COCOBOLO_H
# define COCOBOLO_H

# include "optional.h"
# include "list.h"
# include <errno.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"
#define ITALIC_ON "\e[3m"
#define ITALIC_OFF "\e[23m"

typedef struct s_list t_list;

// usage : str = __strappend(str, s1, s2, ...)
# define __strappend(s, ...) __unwrapped_strappend__(s, __VA_ARGS__, NULL);
# define printc(...) __unwrapped_printc__(__VA_ARGS__, NULL)

typedef void (*t_printf_option)(const char * const);
typedef char ** t_matrix;

void		__exit(char const *const err) __attribute__((noreturn));
t_optional	__atoi(char const *str);
void		*__malloc(size_t n) __attribute__((malloc)) __attribute__((warn_unused_result));
pid_t 		__fork(void);

// string
char 		*__make_string_empty() __attribute__((malloc)) __attribute__((warn_unused_result));
char 		*__make_string_from_list(t_list *list) __attribute__((malloc)) __attribute__((warn_unused_result)) ;
char 		*__attribute__((sentinel)) __attribute__((warn_unused_result)) __unwrapped_strappend__(char *s, ...);
char		*__single_strappend__(char *lhv, char *rhv) __attribute__((warn_unused_result));
size_t	    __strlen(const char *str);
char	    *__strdup(const char *src) __attribute__((warn_unused_result));
char		*__strdup_until(const char *src, const char end) __attribute__((warn_unused_result));
char	    *__strstr(char *haystack, char *needle);
size_t      __strcmp(const char *lhv, const char *rhv);
bool        __strcmp_weak__(const char *lhv, const char *rhv);
t_matrix    __split(char const *s, char c) __attribute__((warn_unused_result));
void        __matrix_clear(t_matrix *arrptr);

// colors
void  __attribute__((sentinel)) __unwrapped_printc__(const char * const message, ...);
void __italic__(const char * const message);
void __purple__(const char * const message);
void __cyan__(const char * const message);
void __blue__(const char * const message);
void __yellow__(const char * const message);
void __green__(const char * const message);
void __red__(const char * const message);
void __reset__(const char * const message);

#endif // COCOBOLO_H
