

# Visitor make file!

CC := g++

SRCDIR := src
BUILDDIR := build
SRCEXT := cc

visitor:  main.cc monster.o player.o save_file.o game_manager.o
	$(CC) -o visitor main.cc

monster.o:  monster.cc
	$(CC) -c monster.cc

player.o:  player.cc
	$(CC) -c player.cc

save_file.o:  save_file.cc
	$(CC) -c save_file.cc

game_manager.o:  game_manager.cc
	$(CC) -c game_manager.cc

test_player:  player.o test_player_to_file.cc
	$(CC) -o test_player_to_file.out test_player_to_file.cc

clean:
	rm *.o visitor

clean-test:  test_player_to_file.out
	rm test_player_to_file.out
