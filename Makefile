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

# --cub3d_img:
# 	@echo "                                 $(right)...$(de)                                 "   
# 	@echo "                              $(left)   $(right)..::..$(de)                              "      
# 	@echo "                            $(left)    $(right).....:::..$(de)                           "      
# 	@echo "                $(left)           $(left)   .~$(right)J?~:...::::.$(de)                         "      
# 	@echo "                         $(left)   .^~$(right)..^!??~::.:: .^..$(de)                     "      
# 	@echo "                      $(left)   ^.:~. $(right).....^!?7~^:~7~:::..$(de)                  "      
# 	@echo "                       $(left) :~~:   $(right)........:~7J5Y!::::^::.$(de)               "      
# 	@echo "                     $(left)  .~:   ^7$(right)^..........7B5?!^::::^^: .$(de)            "      
# 	@echo "                   $(left)   :J:  :!~$(right)!JY7^.......7J7^~77!~^::^!?^:.$(de)         "      
# 	@echo "                 $(left) . :^^^ .!~   $(right).:~?J?~:...!7!:.::~!7!~~Y?^^^^:.$(de)      "      
# 	@echo "            $(left)   $(left)  :^~: ^.~~.  $(right)...  ..^7??!^5Y?:::::::~!YPJ~^^^^^^:$(de)    "      
# 	@echo "           $(left)    $(left) .~^  :!!.    $(right)..........:!PBPJ:..::::::^YJ?7~^^^^^.$(de)   "       
# 	@echo "           $(left)  $(left)  ^!   ^!.     $(right).  ..........!BY??7~^::::::77!!777!~^.$(de)   "       
# 	@echo "          $(left) $(left)  .~!. :!5:    $(bottom):^$(right)::... .......~??^.^!?7!^:::?J!~~~!777:$(de)   "       
# 	@echo "         $(left)  .^::..!^~7   $(bottom).^^^^^^^$(right):...  ...?5J^...:^!7?7~Y5?~~~~~~~:$(de)   "       
# 	@echo "        $(left) $(left)  :..~!~ .?. $(bottom).^^^^^^^^^^^^^$(right):.. .PPY:......::~YGGJ~~~~~~~~.$(de)  "       
# 	@echo "       $(left) $(left)    .~^.  !~$(bottom).^^^^^^^^^^^^^^^^^^^$(right)!G5J...........7Y???7!~~~~:$(de)  "       
# 	@echo "      $(left)  $(left)   ^Y:   $(bottom).7??!~^^^^^^^^^^^^^^~?PG5J7$(right):........:.~Y?^^!7?7!~~$(de)  "       
# 	@echo "      $(left)   ^~!~  $(bottom).:^^!7Y55J7~^^^^^^^^!JPGPY7~^~~^$(right)::......!5Y^:::^~7?~$(de)  "       
# 	@echo "     $(left)  .!:.!  $(bottom):^^^^^^^~7J5P5J~~^~?GPP5J!~~~~~~~~~~^^$(right):..~PY~::::::^:.$(de) "       
# 	@echo "      $(left)   ~$(bottom)..^^^^^^^^^^^^~~7?!GGB##J7~~~~~~~~~~~!!!!!~^!$(right)PY~.::::::^:$(de) "       
# 	@echo "      $(left)   ^$(bottom)7!~~^^^~~~~~~~~~~~75##BGGPJ7!~~~!!!!!!!!!!?YPPYJ!^$(right)::::::::$(de) "       
# 	@echo "    $(left)   $(bottom).!7JYYJ?!~~~~~~~~!?5GGPJ7!?YPPP5J77!!!!!7?YPGP5J?7??7!~$(right)^::::.$(de)"       
# 	@echo "    $(left)  $(bottom).^~~~~!7?JY5J7!!!75BYYJ?!!!!!!!7?JY5YJYJ?5BGP5Y??????JJJJJ?7~$(right)^:$(de)"       
# 	@echo "    $(bottom).^~~~~~~~~~~!7???BGB#P7!!!!77777777777?JB###&PJ??JJJJJJYYYYY555?:$(de)"       
# 	@echo "   $(bottom).^~~!!!!!!!!!!!!?5GG55P5YJ?7777??????JYPBBBPYPGGGP5YY55555PPY7^.$(de)  "      
# 	@echo "       $(bottom).:^~!7777~:!J???77?JY555YJ????J55GGGP5YYYYY55PGGPYJ5PY!:$(de)      "      
# 	@echo "           $(bottom)..^^. .77?????????JJJJ?5BG##5P55555555PPPPPPP7 ..$(de)         "    
# 	@echo "                 $(bottom).^7?JYYYYYYYYYYPG##BGBBGGPPPPGGGGBBBP?:.$(de)            "      
# 	@echo "                     $(bottom).^!?Y555?J#&#BGPPPGGGBBBGGGBG5!:$(de)                "      
# 	@echo "                         $(bottom).:^. J#BGGGGBBBBBBBBG!.:.$(de)                   "       
# 	@echo "                              $(bottom).^!YGB#####&#P?:$(de)                       "       
# 	@echo "                                   $(bottom):!YB#P!.$(de)                          "
# 	@echo "                                                                              "
# 	@echo "                 █████╗ ██╗   ██╗██████╗ ██████╗ ██████╗                    "
# 	@echo "                ██╔══██╗██║   ██║██╔══██╗╚════██╗██╔══██╗                   "
# 	@echo "                ██║  ╚═╝██║   ██║██████╦╝ █████╔╝██║  ██║          "
# 	@echo "                ██║  ██╗██║   ██║██╔══██╗ ╚═══██╗██║  ██║          "
# 	@echo "                ╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝          "
# 	@echo "                 ╚════╝  ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝           "
--cub3d_img:
	@echo "                                          YB?.                     "                              
	@echo "                                        ~&&&&#P7.                   "                            
	@echo "                                      .B@@&&&&&&#G7.                 "                           
	@echo "                                     Y@@@B#&&&&##&&#G7.               "                          
	@echo "                                   !&@@#5J?YG#&&&####&#.               "                         
	@echo "                                  !@@&PB&&#PYJYG#&&####  !P7.           "                        
	@echo "                               .?Y@&PP&@&&&&&#GYJYPB#&B~5P###P7.         "                       
	@echo "                              7&B&BP&@@@&&&&&&&&#G5YYPPJJ5######P7.       "                      
	@echo "                            :#@#PP#@@@@@&&&&&&&&&&&#B5!!7Y#########P7      "                     
	@echo "                          .P@@&P&@@@@#JYB&&&&&&&&&&&&&7~?YYPB########~ ..   "                    
	@echo "                         :&@@G7B@@@&55GY77YG#&&&&&&&&#?J5GBP5Y5GB####J~YBP7. "                   
	@echo "                       :!&@BPGG@@&55&@@@&B5J?JPB&&&&&#55PB&##BG5Y5GB#G?YG##BP7.   "              
	@echo "                     .P#@&P#&G@@PY#@@@&&@@@&#PY?J5B#&B?J5#&#####BG5Y5Y7JG#BBB#BP7.  "            
	@echo "                    ?@&GGB@@BBGYB@@@@&&&&&&&@@&&B5JJY?!7J#&########BP?!?5BBBBBBB##:   "          
	@echo "                  ^&@&PB&@@&PPB@@@@@@&&&&&&&&&&&&&&BJ:^!?B#&&########B?JYY5PGBBBB#?    "         
	@echo "                 !@@BY&@@@#5#@@@@@@@&@&&&&&&&&&&&&&&&^~?YYY5G########BY5PGP5YYPGBBP     "        
	@echo "                :@&PY#@@&57Y@@@@@@&B#&&&@@&&&&&&&&&&#JY5G#BPYY5GB#####YY5GGGGP5YY5G.     "       
	@echo "               .#GB##@&PPB?&@@@@&BBBBBB##&&&@@&&&&&&#JJJG&&&#BPYYYPB##??JGGGGGGGGP!       "      
	@echo "               ?G&&B&G5#@YG@@@&BBBBBBBBBBBB##&&@@&&@5~7?B&&&&&&&#G5YYJ!!7PGGGGGGGGGJ       "     
	@echo "              ^#@@GPYB@@BJ@@&BBBBBBBBBBBBBBBBBB#&&&@?~7?#&&&&&&&&&##G7^~75GGGGGGGGGG        "    
	@echo "             !@@@BG#@@@&Y#&BBBBBBBBBBBBBBBBBBBBBBB#G!!7J&&&&&&&&&&##&&Y?JYYY5PGGGGGB^        "   
	@echo "            :@@#JY@@@@@GY5PGBBBBBBBBBBBBBBBBBBBBGY7~!7?5&&&&&&&&&&&##&PJJG#G5YYYPGGB?        "   
	@echo "           .&&P5J&@@@@#GPY?77J5GBBBBBBBBBBBBBBGJ!~~!?YPGBB##&&&&&&&&&&57?5####GPYYYP5        "   
	@echo "           GGP&P#@@@#BBBBBGPY?!~!?5GBBBBBBBB5J!~!7?5GBGGGGGGGB##&&&&&&P!?Y#######BPJ.         "  
	@echo "          :P#@GG@@&BBBBBBBBBBBGPJ7!~7YGPBGJ^:777JPGGGGGGGGGGGGGGGB##&&G!7J#########BG~         " 
	@echo "         :G@@#5&&BBBBBBBBBBBBBBBBBGPY5J:~^::^Y5GGGGGGGGGGGGGGPPPPPPPGB5!?J###########P          "
	@echo "        ^@@@&5GBGBBBBBGGGGGGGGGGGGGBG5^:::^^~?5PGGGGGPPPPPPPPPPPPPPY?!!7?YB##########B.         "
	@echo "       .&@@@GYJ??Y5PGBBGGGGGGGGGGGPJ!^^^!JYJ7~~~!?Y5PPPPPPPPPPPPY?!~~!?JY555PGB#######~         "
	@echo "       B@@&BGGP5YJ777?YPGGGGGGGGY?7!!!?YPGPPP5YJ7!!!7JY5PPPP5Y?!~~!7?YYYYYYYYYY5PGB###5         "
	@echo "      5@&BGGGGGGGGP5YJ77?Y55PPJ~.7JJY5PPPPPPPPPP55YJ???J7!?7^:^7??JYYYYYYJJJJJJJ??JYPBB         "
	@echo "     ?&BGGGGGGGGGGGGGPPP5Y5~^~^:^55PPPP555555555555555YY^::::.^JYYYJJJJJJJ??????????7~^         "
	@echo "     ?YPGGGGGPPPPPPPPPPPP57~~~!!~!?JY55555555YYYYYYYJ?!^^^^77!~^^~7????????777777!^.            "
	@echo "        .~7YPPPPPPPPPPY?Y????J55YJ7!!!7?JYYYYYYYYJ?!~^^~!7??????7!~^~!7777777!~:                "
	@echo "             .~7Y5PPJ^ 7PP5555YYYYYYYJ?77?JY??J7^~!~~!7????7777777777777.:^:.                   "
	@echo "                  :.  .GP5YYYYYJJJJJJJJJJJYY::::.~777777777!!!!!!!!!!!!~                        "
	@echo "                       :~7?JJJJJJ????????!~:.:^!~^^^~~!!!!~~~~~~~~~^:.                          "
	@echo "                           .:^!7???777!!:..:^~!!!!!~~^^^^~~~^^^^:.                              "
	@echo "                                .:^~: .^:^~~~~~~~~^^~~~~~!7. ..                                 "
	@echo "                                      .:^~~~^^^^^^:::::::::                                     "
	@echo "                                           ..::::::::..                                         "
	@echo "                                                .... "
	@echo "                                                                              "
	@echo "                 █████╗ ██╗   ██╗██████╗ ██████╗ ██████╗                    "
	@echo "                ██╔══██╗██║   ██║██╔══██╗╚════██╗██╔══██╗                   "
	@echo "                ██║  ╚═╝██║   ██║██████╦╝ █████╔╝██║  ██║          "
	@echo "                ██║  ██╗██║   ██║██╔══██╗ ╚═══██╗██║  ██║          "
	@echo "                ╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝          "
	@echo "                 ╚════╝  ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝           "