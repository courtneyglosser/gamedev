visitor:  main.cc player.o save_file.o game_manager.o
	g++ -o visitor main.cc

player.o:  player.cc
	g++ -c player.cc

save_file.o:  save_file.cc
	g++ -c save_file.cc

game_manager.o:  game_manager.cc
	g++ -c game_manager.cc

test_player:  player.o test_player_to_file.cc
	g++ -o test_player_to_file.out test_player_to_file.cc

clean:
	rm *.o visitor
