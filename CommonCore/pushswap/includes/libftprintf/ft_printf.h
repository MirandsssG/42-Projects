/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:18:00 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/01/15 20:32:26 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);

int		ft_printchar(int c);

int		ft_formats(va_list args, const char format);

void	ft_putstr(char *str);

int		ft_printstr(char *str);

int		ft_printnbr(int n);

int		ft_printpercent(void);

int		ft_num_len(unsigned int num);

char	*ft_uitoa(unsigned int n);

int		ft_print_unsigned(unsigned int n);

int		ft_hex_len(unsigned int num);

void	ft_put_hex(unsigned int num, const char format);

int		ft_print_hex(unsigned int num, const char format);

int		ft_ptr_len(uintptr_t num);

void	ft_put_ptr(uintptr_t num);

int		ft_print_ptr(unsigned long long ptr);

void	ft_putchar_fd(char c, int fd);

void	*ft_memset(void *s, int c, size_t n);

char	*ft_itoa(int n);

void	*ft_calloc(size_t nelem, size_t elsize);

void	ft_bzero(void *s, size_t n);

#endif
