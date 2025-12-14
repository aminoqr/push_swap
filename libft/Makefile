# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoqr <aminoqr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/05 18:49:07 by aasylbye          #+#    #+#              #
#    Updated: 2025/12/09 12:50:24 by aminoqr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =		ft_atoi.c ft_memchr.c ft_split.c ft_strncmp.c ft_bzero.c \
		ft_memcmp.c ft_strchr.c ft_strnstr.c ft_calloc.c ft_memcpy.c \
		ft_strdup.c ft_strrchr.c ft_isalnum.c ft_memmove.c  ft_striteri.c \
		ft_strtrim.c ft_isalpha.c ft_memset.c ft_strjoin.c ft_substr.c \
		ft_isascii.c ft_putchar_fd.c ft_strlcat.c ft_tolower.c ft_isdigit.c \
		ft_putendl_fd.c ft_strlcpy.c ft_toupper.c ft_isprint.c ft_putnbr_fd.c \
		ft_strlen.c ft_itoa.c ft_putstr_fd.c ft_strmapi.c ft_abs.c ft_isspace.c

OBJS =		ft_atoi.o ft_memchr.o ft_split.o ft_strncmp.o ft_bzero.o \
		ft_memcmp.o ft_strchr.o ft_strnstr.o ft_calloc.o ft_memcpy.o \
		ft_strdup.o ft_strrchr.o ft_isalnum.o ft_memmove.o  ft_striteri.o \
		ft_strtrim.o ft_isalpha.o ft_memset.o ft_strjoin.o ft_substr.o \
		ft_isascii.o ft_putchar_fd.o ft_strlcat.o ft_tolower.o ft_isdigit.o \
		ft_putendl_fd.o ft_strlcpy.o ft_toupper.o ft_isprint.o ft_putnbr_fd.o \
		ft_strlen.o ft_itoa.o ft_putstr_fd.o ft_strmapi.o ft_abs.o ft_isspace.o


BONUS_SRCS =	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
		ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
		
BONUS_OBJS =	ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o ft_lstdelone.o ft_lstiter.o \
		ft_lstlast.o ft_lstmap.o ft_lstnew.o ft_lstsize.o 

INCLUDES =./

all: $(NAME) 

$(NAME): $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME) libft.so

re: fclean all

.PHONY: all clean fclean re
