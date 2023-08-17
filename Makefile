CPPFLAGS= -ansi -pedantic -Wall -std=c++11 -g
EXE = main
OBJETS = main.o lexer.o symbole.o etat.o automate.o


$(EXE) : $(OBJETS) $(EXE).o
	@echo "Édition des liens de sejours"
	g++ -o $@ $^

%.o : %.cpp
	@echo "Compilation de $<"
	g++ -c $< $(CPPFLAGS)

clean:
	@echo "Suppresion des fichiers compilés"
	rm *.o main

memoryCheck:
	make clean
	@echo "Vérification de la gestion de mémoire"
	make CPPFLAGS='$(CPPFLAGS) -DMAP -g'
	valgrind ./main --track-origins=yes

