# Command 
CC = cc -Wall -Wextra -Werror
RM = rm -rf 

# SRCS 
SRCS = move.c game.c  rule_r.c rule_s.c  rule_p.c rule_rr.c  stack.c stack_index.c stack_count.c
DEPS =   move.h  rules.h    stack.h

M_SRCS = $(SRCS) sort_action.c sort_calc.c sort.c main.c
B_SRCS = $(SRCS) get_next_line.c get_next_line_utils.c ft_strcmp.c checker.c

M_OBJS = $(M_SRCS:.c=.o) 
B_OBJS = $(B_SRCS:.c=.o)

# BINS
NAME = push_swap
BONUS = checker 

# RULES
all : $(NAME)
bonus : $(BONUS)

$(NAME) : $(M_OBJS)
	$(CC) $^ -o $@

$(BONUS) : $(B_OBJS)
	$(CC) $^ -o $@

%.o : %.c $(DEPS) 
	$(CC)  $< -c -o $@

clean : 
	$(RM) $(M_OBJS) $(B_OBJS)

fclean : clean
	$(RM) $(BONUS) $(NAME)

re : fclean all

.PHONY : all re fclean bonus re
.SECONDARY : $(B_OBJS) $(M_OBJS)
