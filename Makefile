NAME = libft.so
CC = clang
SRCS = 	ischeck/ft_isalpha.c \
		ischeck/ft_isdigit.c \
		ischeck/ft_isalnum.c \
		ischeck/ft_isascii.c \
		ischeck/ft_isprint.c \
		str/ft_strlen.c \
		mem/ft_memset.c \
		utils/ft_bzero.c \
		mem/ft_memcpy.c \
		mem/ft_memmove.c \
		str/ft_strlcpy.c \
		str/ft_strcpy.c \
		str/ft_strlcat.c \
		utils/ft_toupper.c \
		utils/ft_tolower.c \
		str/ft_strchr.c \
		str/ft_strrchr.c \
		str/ft_strncmp.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		str/ft_strnstr.c \
		utils/ft_atoi.c \
		utils/ft_calloc.c \
		str/ft_strdup.c \
		str/ft_substr.c \
		str/ft_strjoin.c \
		str/ft_strtrim.c \
		utils/ft_split.c \
		utils/ft_itoa.c \
		str/ft_strmapi.c \
		str/ft_striteri.c \
		put/ft_putchar_fd.c \
		put/ft_putstr_fd.c \
		put/ft_putendl_fd.c \
		put/ft_putnbr_fd.c \
		printf/ft_printf.c \
		printf/ft_vdprintf.c \
		printf/ft_func.c \
		printf/ft_dprintf.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		lst/ft_lstnew_bonus.c \
		lst/ft_lstadd_front_bonus.c \
		lst/ft_lstsize_bonus.c \
		lst/ft_lstlast_bonus.c \
		lst/ft_lstadd_back_bonus.c \
		lst/ft_lstdelone_bonus.c \
		lst/ft_lstclear_bonus.c \
		lst/ft_lstiter_bonus.c \
		lst/ft_lstmap_bonus.c \
		str/clear_str.c \
		str/ft_strlentab.c \
		str/ft_strjoinsep.c \
		utils/ft_swap.c \
		str/ft_revstr.c \
		utils/ft_splitlen.c \
		str/ft_atof.c \
		str/ft_sanitize.c \
		utils/ft_freesplit.c \

OBJS = $(SRCS:%.c=$(DIROBJS)/%.o)
DIROBJS = .objs
FLAGS = -Werror -Wall -Wextra

HEADER = .

$(NAME): $(OBJS)
	$(CC) -fPIC $(FLAGS) -shared -o $@ $(OBJS) -I $(HEADER) -lm

$(DIROBJS)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(DIROBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
