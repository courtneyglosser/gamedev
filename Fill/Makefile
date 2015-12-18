#OBJS specifies which files to compile as part of the project
OBJS = learn_SDL.cc

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = fill

#This is the target that compiles our executable
all : $(OBJS) game_manager.o
	g++ $(OBJS) -w -lSDL2 -o $(OBJ_NAME)

game_manager.o:  game_manager.cc
	g++ -c game_manager.cc

#Don't forget to clean up after yourself
clean:
	rm *.o $(OBJ_NAME)
