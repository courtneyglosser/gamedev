

# Visitor make file!

CC := g++

SRCDIR := src
BUILDDIR := build
SRCEXT := cc

visitor:  main.cc monster.o player.o save_file.o game_manager.o display_manager.o input_manager.o
	$(CC) main.cc -w -lSDL2 -lSDL2_ttf -o visitor 

display_manager.o:  display_manager.cc
	$(CC) -c display_manager.cc

game_manager.o:  game_manager.cc
	$(CC) -c game_manager.cc

input_manager.o:  input_manager.cc
	$(CC) -c input_manager.cc

monster.o:  monster.cc
	$(CC) -c monster.cc

player.o:  player.cc
	$(CC) -c player.cc

save_file.o:  save_file.cc
	$(CC) -c save_file.cc

test_player:  player.o test_player_to_file.cc
	$(CC) -o test_player_to_file.out test_player_to_file.cc

clean:
	rm *.o visitor

clean-test:  test_player_to_file.out
	rm test_player_to_file.out
