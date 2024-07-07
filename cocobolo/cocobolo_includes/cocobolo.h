/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cocobolo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:27:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/07 16:52:37 by aamirkha         ###   ########.fr       */
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

#define printc(...) __unwrapped_printc__(__VA_ARGS__, NULL)

typedef void (*t_printf_option)(const char * const);


void		__exit(char const *const err) __attribute__((noreturn));
t_optional	__atoi(char const *str) __attribute__((nonnull));
void		*__malloc(size_t n) __attribute__((malloc));

// string
size_t	    __strlen(const char *str);
char	    *__strdup(const char *src);
size_t __strcmp(const char *lhv, const char *rhv);


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
