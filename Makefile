# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 08:21:34 by cglavieu          #+#    #+#              #
#    Updated: 2025/01/31 16:52:48 by cglavieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG				=	true

# *** NAME ******************************************************************* #
PREDICT				=	prog_predict
TRAIN				=	prog_train
FILE				=	theta_val

# *** INCLUDELFT ************************************************************* #
LFTDIR				=	./libft/
INCLFT				=	./libft/inc
LFTBIN				=	libft.a
LFTBINFILE			=	$(addprefix $(LFTDIR),$(LFTBIN))

# *** COMPILATION ************************************************************ #
CC					=	gcc
ifeq ($(DEBUG),true)
CFLAG				=	-Wall -Wextra -Werror -g -O0 -fsanitize=address
else
CFLAG				=	-Wall -Wextra -Werror
endif
# *** HEADERS **************************************************************** #
INCDIR				=	./inc/

# *** SOURCES **************************************************************** #
SRCDIR				=	./src/
# *** FT_PREDICT		*** #
PREDICTDIRNAME		=	predict/
PREDICTDIRPATH		=	$(addprefix $(SRCDIR),$(PREDICTDIRNAME))
PREDICTSOURCES		=	main.c			parse.c			estimate.c
PREDICTFILESPATH	=	$(addprefix $(PREDICTDIRPATH),$(PREDICTSOURCES))
# *** FT_TRAIN	*** #
TRAINDIRNAME		=	train/
TRAINDIRPATH		=	$(addprefix $(SRCDIR),$(TRAINDIRNAME))
TRAINSOURCES		=	main.c			parse.c			regression.c	\
						files.c			normalisation.c
TRAINFILESPATH		=	$(addprefix $(TRAINDIRPATH),$(TRAINSOURCES))

# *** BINARIES *************************************************************** #
OBJDIR				=	./obj/
# *** FT_PREDICT		*** #
PREDICTOBJDIR		=	$(addprefix $(OBJDIR),$(PREDICTDIRNAME))
PREDICTOBJECTS		=	$(PREDICTSOURCES:.c=.o)
PREDICTOBJFILES		=	$(addprefix $(PREDICTOBJDIR),$(PREDICTOBJECTS))
# *** FT_TRAIN	*** #
TRAINOBJDIR			=	$(addprefix $(OBJDIR),$(TRAINDIRNAME))
TRAINOBJECTS		=	$(TRAINSOURCES:.c=.o)
TRAINOBJFILES		=	$(addprefix $(TRAINOBJDIR),$(TRAINOBJECTS))

# *** RULES ****************************************************************** #
all					:	$(LFTBINFILE) $(PREDICT) $(TRAIN)

$(LFTBINFILE)		:
						@make -s -C $(LFTDIR)

$(PREDICT)			:	$(PREDICTOBJFILES) $(LFTBINFILE)
						$(CC) $(CFLAG) -L $(LFTDIR) -lft $^ -o $@

$(TRAIN)			:	$(TRAINOBJFILES) $(LFTBINFILE)
						$(CC) $(CFLAG) -L $(LFTDIR) -lft $^ -o $@ -lm

# *** FT_PREDICT		*** #
$(PREDICTOBJDIR)%.o	:	$(PREDICTDIRPATH)%.c
						@mkdir -p $(OBJDIR) $(PREDICTOBJDIR)
						@$(CC) $(CFLAG) -I $(INCDIR) -I $(INCLFT) -c $< -o $@
# *** FT_TRAIN	*** #
$(TRAINOBJDIR)%.o	:	$(TRAINDIRPATH)%.c
						@mkdir -p $(OBJDIR) $(TRAINOBJDIR)
						@$(CC) $(CFLAG) -I $(INCDIR) -I $(INCLFT) -c $< -o $@

clean				:
						@rm -rf $(OBJDIR)
						@make -s -C $(LFTDIR) clean

fclean				:	clean
						@rm -f $(PREDICT)
						@rm -f $(TRAIN)
						@rm -f $(FILE)
						@make -s -C $(LFTDIR) fclean

re					:	fclean all
