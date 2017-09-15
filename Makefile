CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = cc3k
OBJECTS = main.o floor.o cell.o chamber.o info.o enemy.o human.o dwarf.o elf.o orc.o merchant.o dragon.o halfling.o character.o player.o shade.o drow.o vampire.o troll.o goblin.o item.o gold.o potion.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
