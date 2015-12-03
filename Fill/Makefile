#OBJS specifies which files to compile as part of the project
OBJS = learn_SDL.cc

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = learning

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) -w -lSDL2 -o $(OBJ_NAME)

#Don't forget to clean up after yourself
clean:
	rm *.o $(OBJ_NAME)
