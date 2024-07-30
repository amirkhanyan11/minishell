/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cocobolo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:27:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 18:47:24 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COCOBOLO_H
# define COCOBOLO_H

# include "optional.h"
# include "list.h"
# include "get_next_line.h"
# include <errno.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include <cdefs.h>

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

#ifdef __linux__
#if __has_attribute(noreturn)
#define __dead2 __attribute__((__noreturn__))
#else
#define __dead2
#endif //  __has_attribute(noreturn)
#endif // __linux__

# if __has_attribute(cleanup)
#define __dtor(f) __attribute__((cleanup(f)))
#else
#define __dtor(f)
#endif

#if __has_attribute(warn_unused_result)
#define __result_use_check __attribute__((__warn_unused_result__))
#else
#define __result_use_check
#endif

#if __has_attribute(__malloc__)
#define __allocs __attribute__((malloc))
#else
#define __allocs
#endif // __allocs

// usage : str = __strappend(str, s1, s2, ...)
# define __strappend(s, ...) __unwrapped_strappend__(s, __VA_ARGS__, NULL);
# define printc(...) __unwrapped_printc__(__VA_ARGS__, NULL)

#define string char * __dtor(__delete_string)
#define a_list t_list * __dtor(list_clear)
#define a_matrix t_matrix  __dtor(__matrix_clear)

typedef void (*t_printf_option)(const char * const);
typedef char ** t_matrix;

void 		__perror(char * err);
void		__exit(char const *const err) __dead2;
void		*__malloc(size_t n) __allocs __result_use_check;
pid_t 		__fork(void);
void         __pipe(int *p);
void	    __putstr_fd(char *s, int fd);

// string
void 		__delete_string(char **s);
t_optional	__atoi(char const *str);
char 		*__make_string_empty() __allocs __result_use_check;
char 		*__make_string_from_char(const char c) __allocs __result_use_check;
char		*__strtrim(char *s1, char *set) __allocs __result_use_check;
char 		*__make_string_from_list(t_list *list) __allocs __result_use_check ;
char 		*__attribute__((sentinel)) __result_use_check __unwrapped_strappend__(char *s, ...);
char		*__single_strappend__(char *lhv, char *rhv) __result_use_check;
size_t	    __strlen(const char *str);
char	    *__strdup(const char *src) __result_use_check;
char		*__strdup_until(const char *src, const char end) __result_use_check;
char	    *__strstr(char *haystack, char *needle);
size_t      __strcmp(const char *lhv, const char *rhv);
bool        __strchr(char *s, const char c);
char 		*__strchr_p(char *s, bool (*p) (char));
bool        __strcmp_weak__(const char *lhv, const char *rhv);
char		*__itoa(int n) __result_use_check;
t_matrix    __split(char const *s, char *set) __result_use_check;
t_matrix    __split_include_delimiters(char const *s, char c) __result_use_check;

// matrix
void 		__print_matrix(t_matrix arr);
void        __matrix_clear(t_matrix *arrptr);
size_t 		__matrix_size(t_matrix arr);

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
