# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 18:15:26 by kensei            #+#    #+#              #
#    Updated: 2025/08/14 02:18:15 by kenakamu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a


SRCS	= 	ft_isalnum.c \
						ft_isdigit.c	\
						ft_memcmp.c		\
						ft_memset.c		\
						ft_strlcpy.c	\
						ft_strnstr.c	\
						ft_toupper.c	\
						ft_atoi.c		\
						ft_isalpha.c	\
						ft_isprint.c	\
						ft_memmove.c	\
						ft_strlcat.c	\
						ft_strncmp.c	\
						ft_tolower.c	\
						ft_strchr.c		\
						ft_strlen.c		\
						ft_strrchr.c	\
						ft_bzero.c		\
						ft_memcpy.c		\
						ft_isascii.c	\
						ft_memchr.c		\
						ft_calloc.c		\
						ft_strdup.c		\
						ft_substr.c		\
						ft_strjoin.c	\
						ft_strtrim.c	\
						ft_split.c		\
			 			ft_itoa.c		\
						ft_strmapi.c	\
						ft_striteri.c	\
						ft_putchar_fd.c	\
						ft_putstr_fd.c	\
						ft_putendl_fd.c	\
						ft_putnbr_fd.c	\
						additional/split_spht.c \
						free_ptrr.c



OBJDIR		=	OBJS
OBJS		=	$(SRCS:%.c=$(OBJDIR)/%.o)

PRINTF_DIR	=	printf/ft_printf
PRINTF_LIB	=	$(PRINTF_DIR)/libftprintf.a

HEADERS		=	libft.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

all:			$(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB)
	cp $(PRINTF_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)
	
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)
	
$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)
	$(MAKE) -C $(PRINTF_DIR) clean
	
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean 

re: fclean all

.PHONY: all clean fclean re
