# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmoral-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 09:14:20 by dmoral-p          #+#    #+#              #
#    Updated: 2024/04/03 12:57:13 by dmoral-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile

NAME = so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iheaders/
SOURCE := logic/*.c
GETNEXTLINE := get_next_line/*.c
FTPRINTF := ft_printf/*.c
MAC_LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
LINUX_LIBRARY := -Lminilibx-linux -lmlx -lXext -lX11 -lm
MAC_APP := $(NAME)
LINUX_APP := $(NAME)

ifeq ($(shell uname), Darwin)
	OS := mac
	LIBRARY := $(MAC_LIBRARY)
	APP := $(MAC_APP)
else
	OS := linux
	LIBRARY := $(LINUX_LIBRARY)
	APP := $(LINUX_APP)
endif

all: $(OS)

mac: minilibx $(MAC_APP)

linux: minilibx-linux $(LINUX_APP)

$(MAC_APP) $(LINUX_APP): $(SOURCE) $(GETNEXTLINE) $(FTPRINTF)
	@echo "Compilando la versión para $(OS)..."
	@$(CC) $(CFLAGS) $^ $(LIBRARY) -o $@
	$(work)

minilibx:
	@echo "Compilando minilibx..."
	@make -C minilibx >/dev/null 2>&1

minilibx-linux:
	@echo "Compilando minilibx-linux..."
	@make -C minilibx-linux >/dev/null 2>&1

clean:
	@make clean -C minilibx >/dev/null 2>&1
	@make clean -C minilibx-linux >/dev/null 2>&1
	@rm -f $(MAC_APP) $(LINUX_APP)
	$(deleting)

fclean: clean

re: fclean all

.PHONY: all mac linux clean fclean re minilibx minilibx-linux

define work
                                                                                 
@echo  "\033[32m                @@@@@@                               @@@@@@                  \033[0m"
@echo  "\033[32m                @@@@@@                               @@@@@@                  \033[0m"
@echo  "\033[32m                      @@@@@@                   @@@@@@                        \033[0m"
@echo  "\033[32m                      @@@@@@                   @@@@@@                        \033[0m"
@echo  "\033[32m                      @@@@@@                   @@@@@@                        \033[0m"
@echo  "\033[32m                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                  \033[0m"
@echo  "\033[32m             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                \033[0m"
@echo  "\033[32m          @@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@            \033[0m"
@echo  "\033[32m          @@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@            \033[0m"
@echo  "\033[32m          @@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@            \033[0m"
@echo  "\033[32m    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      \033[0m"
@echo  "\033[32m    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      \033[0m"
@echo  "\033[32m    @@@@@@      @@@@@@@@@@@@   "$$(whoami)"   @@@@@@@@@@@@@@@@@  @@@@@@      \033[0m"
@echo  "\033[32m    @@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@      \033[0m"
@echo  "\033[32m    @@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@      \033[0m"
@echo  "\033[32m    @@@@@@      @@@@@@        $(NAME)                @@@@@@      @@@@@@      \033[0m"
@echo  "\033[32m    @@@@@@      @@@@@@   ¡¡COMPILADO CON EXITO!!     @@@@@@      @@@@@@      \033[0m"
@echo  "\033[32m                      @@@@@@@@@@@@       @@@@@@@@@@@@                        \033[0m"
@echo  "\033[32m                      @@@@@@@@@@@@       @@@@@@@@@@@@                        \033[0m"
@echo  "\033[32m                      @@@@@@@@@@@@       @@@@@@@@@@@@                        \033[0m"
                                                                                 
endef

define deleting                                                                  
                                                                                 
@echo  "\033[32m MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXKK0KKKKKXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMMMMMMMMMMMMNKkxddddddddddddddddddxOKWMMMMMMMMMMMMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMMMMMMMMNKxdoddk0XNWMMMMMMMMMWWNKOxdoodkKWMMMMMMMMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMMMMMWKdlox0NWMMMMMMMMMMMMMMN0dodkKWWXOdooxKWMMMMMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMMMNOolxKWMMMMMMMMMMMMMMMMW0:.    .oNMMMN0dloONMMMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMWOllkNWMMMMMMMMMMMMMMMMMMNc       .OMMMMMMNkllOWMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMWKocONMMMMMMMMMMMMMMMMMMMMMWx.      :KMMMMMMMMNkcoKWMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMNkcdXMMMMMMMMMMNXXXXXXXXXXKKK0x:'..,lOXWMMMMMMMMWKocOWMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMNd:kWMMMMMMMMMMWX0koc;'.................dNMMMMMMMMMNx:xWMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMWd:OWMMMMMMMMMMMMMMMWNKOxl:,...          .oNMMMMMMMMMWk:xWMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMWx:kWMMMMMMMMMMMWOodk0XXNNNNNXK0x;         .oNMMMMMMMMMWx:OWMMMMMMMMMM"
@echo  "\033[32m MMMMMMM0:dWMMMMMMMMMMMNx.   ...'',oXMMMMXc         .lNMMMMMMMMMNocKMMMMMMMMMM"
@echo  "\033[32m MMMMMMWocKMMMMMMMMMMXk:.       .,oKWMMMMMK;         .dWMMMMMMMMWO:xWMMMMMMMMM"
@echo  "\033[32m MMMMMMKcoWMMMMMMMMMMKl........,xNMMMMWWMMWo.  ...'',;xNMMMMMMMMMNlcNMMMMMMMMM"
@echo  "\033[32m MMMMMMO:xMMMMMMMMWNXXK0kxkkkOO0KXXXNWMMMMX:   .....';kWMMMMMMMMMWd:KMMMMMMMMM"
@echo  "\033[32m MMMMMMk:kMMMMMMMMXo                oXMMMMO.         .dWMMMMMMMMMMx:0MMMMMMMMM"
@echo  "\033[32m MMMMMMO:kMMMMMMMMWx                kWMMMWd.         .kMMMMMMMMMMWd:0MMMMMMMMM"
@echo  "\033[32m MMMMMM0:dWMMMMMMMM0  $(NAME)       0MMMMX:          'OMMMMMMMMMMWocXMMMMMMMMM"
@echo  "\033[32m MMMMMMNllNMMMMMMMMX   ELIMINADO    KMMMMO.          ,KMMMMMMMMMMKcoWMMMMMMMMM"
@echo  "\033[32m MMMMMMMk:kWMMMMMMMW     CON        NMMMWd     .'    :XMMMMMMMMMWx:OMMMMMMMMMM"
@echo  "\033[32m MMMMMMMNocKMMMMMMMM    EXITO       WMMMX:    'kO,   lWMMMMMMMMM0:dWMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMKclXMMMMMMM                MMMMO'   ;0WWo  .dWMMMMMMMMKclXMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMWKclXMMMMMM                MMMWd. .lXMMM0' .kMMMMMMMWKllXMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMKlc0WMMMMM              XMMMX: .dNMMMMWo 'OMMMMMMWOcoXMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMXdcxNMMMMK            dNMMM0''kWMMMMMM0,,KMMMMMXdcxNMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMW0llkNMMNx          okWMWWkl0WMMMMMMMWdoNMMMXxcoKWMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMMNOllxKWKOkkOkkOkkkOXMMMWNNMMMMMMMMMMNXWWKxlo0WMMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMMMMW0dlokKWMMMMMMMMMMMMMMMMMMMMMMMMMMWKxooxKWMMMMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMMMMMMMNOdoodkKNWMMMMMMMMMMMMMMMMWNKkdood0NMMMMMMMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMMMMMMMMMMWKkddddddxkOOOO00OkkxddddddkXWMMMMMMMMMMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMMMMMMMMMMMMMMMNX0OkxxdddddxxxkO0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
@echo  "\033[32m MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
                                                                                 
endef

define weee

@echo  " ░█▀█░█▀▄░█▀█░█▀▀░█▀▀░█▀▀░█▀█░░░░░░░░   "
@echo  " ░█▀▀░█▀▄░█░█░█░░░█▀▀░▀▀█░█░█░░░░░░░░   "
@echo  " ░▀░░░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░░░░░░░░   "
@echo  " ░█▀▄░█▀▀░█▄█░█▀█░█░█░█▀▀░░░█▀▀░█▀█░█▀█ "
@echo  " ░█▀▄░█▀▀░█░█░█▀█░█▀▄░█▀▀░░░█░░░█░█░█░█ "
@echo  " ░▀░▀░▀▀▀░▀░▀░▀░▀░▀░▀░▀▀▀░░░▀▀▀░▀▀▀░▀░▀ "
@echo  " ░░░█▀▀░█░█░▀█▀░▀█▀░█▀█                 "
@echo  " ░░░█▀▀░▄▀▄░░█░░░█░░█░█                 "
@echo  " ░░░▀▀▀░▀░▀░▀▀▀░░▀░░▀▀▀                 "


endef
