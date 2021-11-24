# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgallien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 14:52:04 by hgallien          #+#    #+#              #
#    Updated: 2021/02/22 15:06:25 by hgallien         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #
SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))
DEPENDS := $(patsubst %.cpp,%.d,$(SOURCES))

# ADD MORE WARNINGS!
WARNING := -Wall -Wextra -Werror
DBFLAGS=-g3 -fsanitize=address 
# .PHONY means these rules get executed even if
# files of those names exist.
.PHONY: all clean
NAME = vector 
# The first rule is the default, ie. "make",
# "make all" and "make parking" mean the same
all: $(NAME)

clean:
	$(RM) $(OBJECTS) $(DEPENDS) 

fclean:
	$(RM) $(OBJECTS) $(DEPENDS) $(NAME)
# Linking the executable from the object files
$(NAME): $(OBJECTS)
	$(CXX) $(WARNING) $(CXXFLAGS) $^     -o $@


-include $(DEPENDS)

%.o: %.cpp Makefile
	$(CXX) $(WARNING) $(CXXFLAGS) -MMD -MP -c $< -o $@
re : fclean all

