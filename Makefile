NAME = libasm.a

SRCS = 	ft_strlen.s \
				ft_strcpy.s

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.s=.o))

NASM = nasm
NASMFLAGS = -f elf64 -g -F dwarf

AR = ar
ARFLAGS = rcs

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJDIR)/%.o: src/%.s | $(OBJDIR)
	$(NASM) $(NASMFLAGS) $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
