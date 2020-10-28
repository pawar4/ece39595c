OBJS = main.o Action.o Armor.o Creature.o Displayable.o DropPack.o Dungeon.o EndGame.o Item.o Magic.o \ ObjDisplayGrid.o Passage.o Player.o Remove.o Room.o Scroll.o YouWin.o Teleport.O UpdateDisplay.o Structure.o\
       Sword.o XMLHandler.o ObjDisplayGrid.o ChangeDisplayedType.o
CC = g++
INCLUDE = 
LIBS = 
CFLAGS = -Wall -g -std=c++11 -Wall -Wextra -pedantic-errors
EXECUTABLE = XMLHandler
COMMANDLINE = xmlFiles/dungeon.xml

.PHONY : run
	run : $(EXECUTABLE)
		./$(EXECUTABLE) $(COMMANDLINE)

cleanmake : clean XMLHandler

.PHONY : $(EXECUTABLE)
	$(EXECUTABLE) :  $(OBJS)
		$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) $(INCLUDE) $(LIBS)


%.o : %.c 
	$(CC) $(CFLAGS) -c $@. $(INCLUDE) $(LIBS)

clean :
		rm $(EXECUTABLE) ${OBJS} 


