
SERVER		=		server
CLIENT		=		client

SV_SRCS		=	server.c	\
				signal_utils.c	
CL_SRCS		=	client.c	\
				signal_utils.c

OBJDIR		=	OBJS
SV_OBJDIR	=	$(OBJDIR)/SV_OBJS
CL_OBJDIR	=	$(OBJDIR)/CL_OBJS

SV_OBJS		=	$(SV_SRCS:%.c=$(SV_OBJDIR)/%.o)
CL_OBJS		=	$(CL_SRCS:%.c=$(CL_OBJDIR)/%.o)

LIBFT_DIR		=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

CC			=		cc
CFLAGS		=		-Wall -Wextra -Werror
RM			=		rm -rf

all:	$(SERVER) $(CLIENT)
	
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(SERVER):	$(SV_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SV_OBJS) $(LIBFT_DIR) -o $(SERVER)
	
$(CLIENT):	$(CL_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CL_OBJS) $(LIBFT_DIR) -o $(CLIENT)

$(SV_OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@
	
$(CL_OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@
	
clean:
	$(RM) $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	
re:	fclean all