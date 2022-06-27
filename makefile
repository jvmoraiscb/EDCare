NAME_PROGRAM   = final.exe
MAIN_FILE_NAME = main
SRC            = ./src
INCLUDE        = ./include
OBJ            = ./obj
BIN            = ./bin
SAIDA		   = ./Saida
FLAGS          = -lm -pedantic -Wall 
COMPILER       = gcc   

C_FILES        = $(wildcard $(SRC)/*.c)
OBJ_PATH_FILES = $(patsubst $(SRC)%,$(OBJ)%,$(C_FILES))
OBJ_FILES      = $(patsubst %.c,%.o,$(OBJ_PATH_FILES))

all: create_dir $(OBJ_FILES) create_final_progam

create_final_progam: $(BIN)/$(NAME_PROGRAM)

# rule for main file
$(OBJ)/$(MAIN_FILE_NAME).o: $(SRC)/$(MAIN_FILE_NAME).c
	@ $(COMPILER) -c $< -I $(INCLUDE) -o $@ $(FLAGS)

# rule for all o files
$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	@ $(COMPILER) -c $< -I $(INCLUDE) -o $@ $(FLAGS)

# rule for create_final_progam
$(BIN)/%: 
	@ echo "\033[1;32m"
	@ echo "Creating executable...\n"
	@ $(COMPILER) $< $(OBJ)/*.o -I $(INCLUDE) -o $@ $(FLAGS)
	@ echo "\033[0m"

# create all needed directories
create_dir: 
	@ echo "\033[1;32m"
	@ echo "Creating all directories..."
	@ mkdir $(OBJ)
	@ mkdir $(BIN)
	@ mkdir $(SAIDA)
	@ echo "\033[0m"

# rule to run the final program
run: 
	@ echo "\033[1;32m"
	@ echo "Running $(BIN)/$(NAME_PROGRAM)"
	@ ./$(BIN)/$(NAME_PROGRAM) $(r)
	@ echo "\033[0m"

valgrind: 
	@ echo "\033[1;32m"
	@ echo "Running valgrind on $(BIN)/$(NAME_PROGRAM)"
	@ echo "\033[0m"
	@ valgrind ./$(BIN)/$(NAME_PROGRAM) $(r)

clean:
	@ echo "\033[1;35m"
	@ echo "Removing temporary files..."
	@ rm -rf $(OBJ) $(NAME_PROGRAM) $(BIN) Saida/
	@ echo "\033[0m"