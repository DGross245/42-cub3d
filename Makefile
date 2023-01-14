# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dna <dna@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 12:48:05 by dgross            #+#    #+#              #
#    Updated: 2023/01/14 12:15:08 by dna              ###   ########.fr        #
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
	@echo "                           █████╗ ██╗   ██╗██████╗ ██████╗ ██████╗"
	@echo "                          ██╔══██╗██║   ██║██╔══██╗╚════██╗██╔══██╗"
	@echo "                          ██║  ╚═╝██║   ██║██████╦╝ █████╔╝██║  ██║"
	@echo "                          ██║  ██╗██║   ██║██╔══██╗ ╚═══██╗██║  ██║"
	@echo "                          ╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝"
	@echo "                           ╚════╝  ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝"