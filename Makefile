CC = gcc
OFILES = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libvlcb.a

.PHONY: all clean fclean re
all: $(NAME) clean

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean:
	clean rm -f $(NAME)

re: fclean $(NAME)

.PHONY: test
test:
	#TODO: add tests

.PHONY: lsp_helper
lsp_helper: clean
	bear -- make

.PHONY: gen_defs
gen_defs: update_defs
	$(MAKE) -C vendor/vlcb-defs/codegen generate_c
	cp vendor/vlcb-defs/codegen/lang/c/output/vlcb_defs.h vlcb/include/defs/vlcb_defs.h

.PHONY: update_defs
update_defs:
	git submodule update --rebase --remote
