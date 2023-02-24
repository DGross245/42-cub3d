# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 12:48:05 by dgross            #+#    #+#              #
#    Updated: 2023/02/23 14:00:15 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D
BONUS			= cub3D_bonus

LIBFT			= libft/libft.a
MLX				= MLX42/libmlx42.a

VPATH			= src:\
				  src_bonus:\
				  src/trash_can:\
				  src_bonus/trash_can_bonus:\
				  src/parser:\
				  src_bonus/parser_bonus:\
				  src/execution:\
				  src_bonus/execution_bonus:\
				  includes/mandatory:\
				  includes/bonus:

HEADERS			= cub3d.h\
				  execution.h\
				  parser.h\
				  trash.h

HEADERS_BONUS	= cub3d_bonus.h\
				  execution_bonus.h\
				  parser_bonus.h\
				  trash_bonus.h

SRC				= main.c\
				  parser.c\
				  error.c\
				  dump.c\
				  garbage_truck.c\
				  init.c\
				  checker.c\
				  get_info.c\
				  utils.c\
				  calculator.c\
				  events.c\
				  painter.c\
				  search_wall.c\
				  go.c\
				  turn.c\
				  split.c

SRC_BONUS		= main_bonus.c\
				  parser_bonus.c\
				  error_bonus.c\
				  dump_bonus.c\
				  garbage_truck_bonus.c\
				  init_bonus.c\
				  checker_bonus.c\
				  get_info_bonus.c\
				  utils_bonus.c\
				  calculator_bonus.c\
				  events_bonus.c\
				  painter_bonus.c\
				  search_wall_bonus.c\
				  go_bonus.c\
				  turn_bonus.c\
				  open_bonus.c\
				  split_bonus.c
		  
OBJ_DIR			= ./obj/
OBJ_DIR_BONUS	= ./obj_bonus/
OBJ				= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
OBJ_BONUS		= $(addprefix $(OBJ_DIR_BONUS),$(SRC_BONUS:.c=.o))
DEPS			= $(addprefix $(OBJ_DIR),$(SRC:.c=.d))
DEPS_BONUS		= $(addprefix $(OBJ_DIR_BONUS),$(SRC_BONUS:.c=.d))

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g

INCLUDES_BONUS  = -I./includes/bonus -I./libft/includes -I./MLX42/include/MLX42
INCLUDES		= -I./includes/mandatory -I./libft/includes -I./MLX42/include/MLX42
LDINCLUDES		= -L./libft -lft

GOINFRE_DIR 	= /Users/$(USER)/goinfre/.brew/opt/glfw/lib
BREW_DIR 		= /Users/$(USER)/.brew/opt/glfw/lib

ifneq (,$(shell [ -d $(GOINFRE_DIR) ] && echo 1))
    LDINCLUDES	+= -L$(GOINFRE_DIR) -lglfw
else ifneq (,$(shell [ -d $(BREW_DIR) ] && echo 1))
    LDINCLUDES	+= -L$(BREW_DIR) -lglfw
endif

LDINCLUDES 		+= -L./MLX42 -lmlx42

#-~color-codes~-#

left			= \033[1;93m
right			= \033[1;91m
bottom			= \033[1;96m
white			= \033[1;37m
green			= \033[0;92m
g				= \033[32;1m
de				= \033[0m

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

obj_bonus:
	@mkdir -p $(OBJ_DIR_BONUS)

mlx:
	@$(MAKE) -C ./MLX42

obj/%.o: %.c $(HEADERS)
	@echo "$(g)Compiling: $(white)$<$(de)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

obj_bonus/%.o: %.c $(HEADERS_BONUS)
	@echo "$(left)Compiling: $(white)$<$(de)"
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

$(NAME): --cub3d_img mlx obj $(OBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) $(MLX) $(LIBFT) $(LDINCLUDES) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
	@echo "$(g)Compiling: Done ✓$(de)"

bonus: --cub3d_img mlx obj_bonus $(OBJ_BONUS)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJ_BONUS) $(CFLAGS) $(INCLUDES_BONUS) $(MLX) $(LIBFT) $(LDINCLUDES) -framework Cocoa -framework OpenGL -framework IOKit -o $(BONUS)
	@echo "$(left)Compiling: Done ✓$(de)"

clean:
	@$(MAKE) clean -C libft/
	@$(MAKE) clean -C MLX42/
	@$(RM) -rf obj obj_bonus

fclean: clean
	@$(MAKE) fclean -C libft/
	@$(MAKE) fclean -C MLX42/
	@$(RM) -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re

--cub3d_img:
	@echo ""
	@echo "                                          $(left)Y$(right)B?.$(de)"
	@echo "                                        $(left)~&$(right)&&&#P7.$(de)"                            
	@echo "                                      $(left).B@@$(right)&&&&&&#G7.$(de)"                           
	@echo "                                     $(left)Y@@@$(right)B#&&&&##&&#G7.$(de)"                          
	@echo "                                   $(left)!&@@#5$(right)J?YG#&&&####&#.$(de)"                         
	@echo "                                  $(left)!@@&PB&$(right)&#PYJYG#&&####  !P7.$(de)"                        
	@echo "                               $(left).?Y@&PP&@$(right)&&&&&#GYJYPB#&B~5P###P7.$(de)"                       
	@echo "                              $(left)7&B&BP&@@@$(right)&&&&&&&&#G5YYPPJJ5######P7.$(de)"                      
	@echo "                            $(left):#@#PP#@@@@$(right)@&&&&&&&&&&&#B5!!7Y#########P7$(de)"                     
	@echo "                          $(left).P@@&P&@@@@#J$(right)YB&&&&&&&&&&&&&7~?YYPB########~ ..$(de)"                    
	@echo "                         $(left):&@@G7B@@@&55G$(right)Y77YG#&&&&&&&&#?J5GBP5Y5GB####J~YBP7.$(de)"                   
	@echo "                       $(left):!&@BPGG@@&55&@$(right)@@&B5J?JPB&&&&&#55PB&##BG5Y5GB#G?YG##BP7.$(de)"              
	@echo "                     $(left).P#@&P#&G@@PY#@@@$(right)&&@@@&#PY?J5B#&B?J5#&#####BG5Y5Y7JG#BBB#BP7.$(de)"            
	@echo "                    $(left)?@&GGB@@BBGYB@@@@$(right)&&&&&&&@@&&B5JJY?!7J#&########BP?!?5BBBBBBB##:$(de)"          
	@echo "                  $(left)^&@&PB&@@&PPB@@@@@@$(right)&&&&&&&&&&&&&&BJ:^!?B#&&########B?JYY5PGBBBB#?$(de)"         
	@echo "                 $(left)!@@BY&@@@#5#@@@@@@@$(right)&@&&&&&&&&&&&&&&&^~?YYY5G########BY5PGP5YYPGBBP$(de)"        
	@echo "                $(left):@&PY#@@&57Y@@@@@@$(bottom)&B$(right)#&&&@@&&&&&&&&&&#JY5G#BPYY5GB#####YY5GGGGP5YY5G.$(de)"       
	@echo "               $(left).#GB##@&PPB?&@@@@$(bottom)&BBBBBB$(right)##&&&@@&&&&&&#JJJG&&&#BPYYYPB##??JGGGGGGGGP!$(de)"      
	@echo "               $(left)?G&&B&G5#@YG@@@$(bottom)&BBBBBBBBBBBB$(right)##&&@@&&@5~7?B&&&&&&&#G5YYJ!!7PGGGGGGGGGJ$(de)"     
	@echo "              $(left)^#@@GPYB@@BJ@@$(bottom)&BBBBBBBBBBBBBBBBBB$(right)#&&&@?~7?#&&&&&&&&&##G7^~75GGGGGGGGGG$(de)"    
	@echo "             $(left)!@@@BG#@@@&Y#$(bottom)&BBBBBBBBBBBBBBBBBBBBBBB$(right)#G!!7J&&&&&&&&&&##&&Y?JYYY5PGGGGGB^$(de)"   
	@echo "            $(left):@@#JY@@@@@G$(bottom)Y5PGBBBBBBBBBBBBBBBBBBBBGY7~!7?5$(right)&&&&&&&&&&&##&PJJG#G5YYYPGGB?$(de)"   
	@echo "           $(left).&&P5J&@@@@$(bottom)#GPY?77J5GBBBBBBBBBBBBBBGJ!~~!?YPGBB$(right)##&&&&&&&&&&57?5####GPYYYP5$(de)"   
	@echo "           $(left)GGP&P#@@@$(bottom)#BBBBBGPY?!~!?5GBBBBBBBB5J!~!7?5GBGGGGGGGB$(right)##&&&&&&P!?Y#######BPJ.$(de)"  
	@echo "          $(left):P#@GG@@$(bottom)&BBBBBBBBBBBGPJ7!~7YGPBGJ^:777JPGGGGGGGGGGGGGGGB$(right)##&&G!7J#########BG~$(de)" 
	@echo "         $(left):G@@#5&$(bottom)&BBBBBBBBBBBBBBBBBGPY5J:~^::^Y5GGGGGGGGGGGGGGPPPPPPPGB$(right)5!?J###########P$(de)"
	@echo "        $(left)^@@@&5$(bottom)GBGBBBBBGGGGGGGGGGGGGBG5^:::^^~?5PGGGGGPPPPPPPPPPPPPPY?!!7?Y$(right)B##########B.$(de)"
	@echo "       $(left).&@@@$(bottom)GYJ??Y5PGBBGGGGGGGGGGGPJ!^^^!JYJ7~~~!?Y5PPPPPPPPPPPPY?!~~!?JY555PGB$(right)#######~$(de)"
	@echo "       $(left)B@@$(bottom)&BGGP5YJ777?YPGGGGGGGGY?7!!!?YPGPPP5YJ7!!!7JY5PPPP5Y?!~~!7?YYYYYYYYYY5PGB$(right)###5$(de)"
	@echo "      $(left)5@$(bottom)&BGGGGGGGGP5YJ77?Y55PPJ~.7JJY5PPPPPPPPPP55YJ???J7!?7^:^7??JYYYYYYJJJJJJJ??JYPB$(right)B$(de)"
	@echo "     $(left)?$(bottom)&BGGGGGGGGGGGGGPPP5Y5~^~^:^55PPPP555555555555555YY^::::.^JYYYJJJJJJJ??????????7~^$(de)"
	@echo "     $(bottom)?YPGGGGGPPPPPPPPPPPP57~~~!!~!?JY55555555YYYYYYYJ?!^^^^77!~^^~7????????777777!^.$(de)"
	@echo "        $(bottom).~7YPPPPPPPPPPY?Y????J55YJ7!!!7?JYYYYYYYYJ?!~^^~!7??????7!~^~!7777777!~:$(de)"
	@echo "             $(bottom).~7Y5PPJ^ 7PP5555YYYYYYYJ?77?JY??J7^~!~~!7????7777777777777.:^:.$(de)"
	@echo "                  $(bottom):.  .GP5YYYYYJJJJJJJJJJJYY::::.~777777777!!!!!!!!!!!!~$(de)"
	@echo "                       $(bottom):~7?JJJJJJ????????!~:.:^!~^^^~~!!!!~~~~~~~~~^:.$(de)"
	@echo "                           $(bottom).:^!7???777!!:..:^~!!!!!~~^^^^~~~^^^^:.$(de)"
	@echo "                                $(bottom).:^~: .^:^~~~~~~~~^^~~~~~!7. ..$(de)"
	@echo "                                      $(bottom).:^~~~^^^^^^:::::::::$(de)"
	@echo "                                           $(bottom)..::::::::..$(de)"
	@echo "                                                $(bottom)....$(de)"
	@echo ""
	@echo ""
	@echo "                           $(white)█████╗ ██╗   ██╗██████╗ ██████╗ ██████╗$(de)"
	@echo "                          $(white)██╔══██╗██║   ██║██╔══██╗╚════██╗██╔══██╗$(de)"
	@echo "                          $(white)██║  ╚═╝██║   ██║██████╦╝ █████╔╝██║  ██║$(de)"
	@echo "                          $(white)██║  ██╗██║   ██║██╔══██╗ ╚═══██╗██║  ██║$(de)"
	@echo "                          $(white)╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝$(de)"
	@echo "                           $(white)╚════╝  ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝$(de)"
	@echo ""
	@echo "╚═════════════════════════════════════════════════════════════════════════════════════════════╝ "
	@echo ""
