NAME = libasm.a
NAME_BONUS = bonus/libasm_bonus.a

SRCS = 	ft_strlen.s	\
				ft_strcpy.s	\
				ft_strcmp.s	\
				ft_write.s	\
				ft_read.s		\
				ft_strdup.s

SRCS_BONUS = ft_atoi_base.s 			\
						 ft_list_push_front.s \
						 ft_list_size.s				\
						 ft_list_sort.s				\
						 ft_list_remove_if.s

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.s=.o))

OBJDIR_BONUS = bonus/obj_bonus
OBJS_BONUS = $(addprefix $(OBJDIR_BONUS)/,$(SRCS_BONUS:.s=.o))

NASM = nasm
NASMFLAGS = -f elf64 -g -F dwarf

AR = ar
ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
$(OBJDIR)/%.o: src/%.s | $(OBJDIR)
	$(NASM) $(NASMFLAGS) $< -o $@
$(OBJDIR):
	mkdir -p $(OBJDIR)

bonus: ${NAME_BONUS}

$(NAME_BONUS): $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME_BONUS) $(OBJS_BONUS)
$(OBJDIR_BONUS)/%.o: bonus/src/%.s | $(OBJDIR_BONUS)
	$(NASM) $(NASMFLAGS) $< -o $@
$(OBJDIR_BONUS):
	mkdir -p $(OBJDIR_BONUS)


clean:
	rm -rf $(OBJDIR) $(OBJDIR_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all


.PHONY: all clean fclean re
