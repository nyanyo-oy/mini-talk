# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 14:09:34 by kenakamu          #+#    #+#              #
#    Updated: 2025/09/09 14:10:10 by kenakamu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		=	server
CLIENT		=	client

SV_SRCS		=	server.c	\
				signal_utils.c
CL_SRCS		=	client.c	\
				signal_utils.c

OBJDIR		=	OBJS
SV_OBJDIR	=	$(OBJDIR)/SV_OBJS
CL_OBJDIR	=	$(OBJDIR)/CL_OBJS

SV_OBJS		=	$(SV_SRCS:%.c=$(SV_OBJDIR)/%.o)
CL_OBJS		=	$(CL_SRCS:%.c=$(CL_OBJDIR)/%.o)


SERVER_BONUS=	server_bonus
CLIENT_BONUS=	client_bonus

SV_BONUS_SRCS=	server_bonus.c	\
				signal_utils_bonus.c
CL_BONUS_SRCS=	client_bonus.c	\
				signal_utils_bonus.c

SV_BONUS_OBJDIR	=	$(OBJDIR)/SV_BONUS_OBJS
CL_BONUS_OBJDIR	=	$(OBJDIR)/CL_BONUS_OBJS
				
SV_BONUS_OBJS=	$(SV_BONUS_SRCS:%.c=$(SV_BONUS_OBJDIR)/%.o)
CL_BONUS_OBJS=	$(CL_BONUS_SRCS:%.c=$(CL_BONUS_OBJDIR)/%.o)



LIBFT_DIR	=	./libft
LIBFT_LIB	=	$(LIBFT_DIR)/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

all: $(SERVER) $(CLIENT)
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(SERVER):	$(SV_OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(SV_OBJS) $(LIBFT_LIB) -o $(SERVER)
$(CLIENT):	$(CL_OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(CL_OBJS) $(LIBFT_LIB) -o $(CLIENT)
	
$(SV_OBJDIR)/%.o: %.c minitalk.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@
$(CL_OBJDIR)/%.o: %.c minitalk.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@
		
$(SERVER_BONUS):	$(SV_BONUS_OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(SV_BONUS_OBJS) $(LIBFT_LIB) -o $(SERVER_BONUS)
$(CLIENT_BONUS):	$(CL_BONUS_OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(CL_BONUS_OBJS) $(LIBFT_LIB) -o $(CLIENT_BONUS)

$(SV_BONUS_OBJDIR)/%.o: %.c minitalk_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@
$(CL_BONUS_OBJDIR)/%.o: %.c minitalk_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@
		
clean:
	$(RM) $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT) 
	$(RM) $(SERVER_BONUS) $(CLIENT_BONUS) 
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all bonus clean fclean re
