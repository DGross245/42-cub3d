# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 12:48:05 by dgross            #+#    #+#              #
#    Updated: 2023/01/13 17:41:38 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

VPATH		= src:

LIBFT		= libft/libft.a

SRC			= main.c

OBJ_DIR		= ./obj/

OBJ			= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g

INCLUDE		= -I./includes -I./libft/includes

LDINCLUDES	= -L./libft -lft

#-color-codes
left			= \033[1;93m
right			= \033[1;91m
bottom			= \033[1;96m
de				= \033[0m

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

obj/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): --cub3d_img obj $(OBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) $(LIBFT) $(LINCLUDES) -o $(NAME)

clean:
	@$(MAKE) clean -C libft/
	@rm -rf obj

fclean: clean
	@$(MAKE) fclean -C libft/
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

--cub3d_img:
	@echo "                                 $(right)...$(de)                                 "   
	@echo "                              $(left)   $(right)..::..$(de)                              "      
	@echo "                            $(left)    $(right).....:::..$(de)                           "      
	@echo "                $(left)           $(left)   .~$(right)J?~:...::::.$(de)                         "      
	@echo "                         $(left)   .^~$(right)..^!??~::.:: .^..$(de)                     "      
	@echo "                      $(left)   ^.:~. $(right).....^!?7~^:~7~:::..$(de)                  "      
	@echo "                       $(left) :~~:   $(right)........:~7J5Y!::::^::.$(de)               "      
	@echo "                     $(left)  .~:   ^7$(right)^..........7B5?!^::::^^: .$(de)            "      
	@echo "                   $(left)   :J:  :!~$(right)!JY7^.......7J7^~77!~^::^!?^:.$(de)         "      
	@echo "                 $(left) . :^^^ .!~   $(right).:~?J?~:...!7!:.::~!7!~~Y?^^^^:.$(de)      "      
	@echo "            $(left)   $(left)  :^~: ^.~~.  $(right)...  ..^7??!^5Y?:::::::~!YPJ~^^^^^^:$(de)    "      
	@echo "           $(left)    $(left) .~^  :!!.    $(right)..........:!PBPJ:..::::::^YJ?7~^^^^^.$(de)   "       
	@echo "           $(left)  $(left)  ^!   ^!.     $(right).  ..........!BY??7~^::::::77!!777!~^.$(de)   "       
	@echo "          $(left) $(left)  .~!. :!5:    $(bottom):^$(right)::... .......~??^.^!?7!^:::?J!~~~!777:$(de)   "       
	@echo "         $(left)  .^::..!^~7   $(bottom).^^^^^^^$(right):...  ...?5J^...:^!7?7~Y5?~~~~~~~:$(de)   "       
	@echo "        $(left) $(left)  :..~!~ .?. $(bottom).^^^^^^^^^^^^^$(right):.. .PPY:......::~YGGJ~~~~~~~~.$(de)  "       
	@echo "       $(left) $(left)    .~^.  !~$(bottom).^^^^^^^^^^^^^^^^^^^$(right)!G5J...........7Y???7!~~~~:$(de)  "       
	@echo "      $(left)  $(left)   ^Y:   $(bottom).7??!~^^^^^^^^^^^^^^~?PG5J7$(right):........:.~Y?^^!7?7!~~$(de)  "       
	@echo "      $(left)   ^~!~  $(bottom).:^^!7Y55J7~^^^^^^^^!JPGPY7~^~~^$(right)::......!5Y^:::^~7?~$(de)  "       
	@echo "     $(left)  .!:.!  $(bottom):^^^^^^^~7J5P5J~~^~?GPP5J!~~~~~~~~~~^^$(right):..~PY~::::::^:.$(de) "       
	@echo "      $(left)   ~$(bottom)..^^^^^^^^^^^^~~7?!GGB##J7~~~~~~~~~~~!!!!!~^!$(right)PY~.::::::^:$(de) "       
	@echo "      $(left)   ^$(bottom)7!~~^^^~~~~~~~~~~~75##BGGPJ7!~~~!!!!!!!!!!?YPPYJ!^$(right)::::::::$(de) "       
	@echo "    $(left)   $(bottom).!7JYYJ?!~~~~~~~~!?5GGPJ7!?YPPP5J77!!!!!7?YPGP5J?7??7!~$(right)^::::.$(de)"       
	@echo "    $(left)  $(bottom).^~~~~!7?JY5J7!!!75BYYJ?!!!!!!!7?JY5YJYJ?5BGP5Y??????JJJJJ?7~$(right)^:$(de)"       
	@echo "    $(bottom).^~~~~~~~~~~!7???BGB#P7!!!!77777777777?JB###&PJ??JJJJJJYYYYY555?:$(de)"       
	@echo "   $(bottom).^~~!!!!!!!!!!!!?5GG55P5YJ?7777??????JYPBBBPYPGGGP5YY55555PPY7^.$(de)  "      
	@echo "       $(bottom).:^~!7777~:!J???77?JY555YJ????J55GGGP5YYYYY55PGGPYJ5PY!:$(de)      "      
	@echo "           $(bottom)..^^. .77?????????JJJJ?5BG##5P55555555PPPPPPP7 ..$(de)         "    
	@echo "                 $(bottom).^7?JYYYYYYYYYYPG##BGBBGGPPPPGGGGBBBP?:.$(de)            "      
	@echo "                     $(bottom).^!?Y555?J#&#BGPPPGGGBBBGGGBG5!:$(de)                "      
	@echo "                         $(bottom).:^. J#BGGGGBBBBBBBBG!.:.$(de)                   "       
	@echo "                              $(bottom).^!YGB#####&#P?:$(de)                       "       
	@echo "                                   $(bottom):!YB#P!.$(de)                          "
	@echo "                                                                              "
	@echo "                 █████╗ ██╗   ██╗██████╗ ██████╗ ██████╗                    "
	@echo "                ██╔══██╗██║   ██║██╔══██╗╚════██╗██╔══██╗                   "
	@echo "                ██║  ╚═╝██║   ██║██████╦╝ █████╔╝██║  ██║          "
	@echo "                ██║  ██╗██║   ██║██╔══██╗ ╚═══██╗██║  ██║          "
	@echo "                ╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝          "
	@echo "                 ╚════╝  ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝           "
