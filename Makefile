flags = -pedantic-errors -std=c++11
print_text.o: print_text.cpp print_text.h
	g++ $(flags) -c $<
blackjack.o: blackjack.cpp blackjack.h
	g++ $(flags) -c $<
login.o: login.cpp login.h
	g++ $(flags) -c $<
ranking.o: ranking.cpp ranking.h
	g++ $(flags) -c $<
slot_machine.o: slot_machine.cpp slot_machine.h
	g++ $(flags) -c $<
roulette.o: roulette.cpp roulette.h
	g++ $(flags) -c $<
soccer.o: soccer.cpp soccer.h
	g++ $(flags) -c $<
earn.o: earn.cpp earn.h
	g++ $(flags) -c $<
main.o: main.cpp print_text.h 
	g++ $(flags) -c $<
game: main.o print_text.o blackjack.o login.o ranking.o slot_machine.o roulette.o soccer.o earn.o
	g++ $(flags) $^ -o $@
clean:
	rm -f game print_text.o main.o blackjack.o login.o ranking.o slot_machine.o roulette.o soccer.o earn.o
.PHONY: clean
