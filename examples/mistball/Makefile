BIN=../../bin
OBJ=./obj

GAME_NAME=mistball


build:
	mkdir -p $(OBJ)
	$(BIN)/gbdk-n-compile.sh mistball.c -o $(OBJ)/mistball.rel
	$(BIN)/gbdk-n-compile.sh sprite.c -o $(OBJ)/sprite.rel

	$(BIN)/gbdk-n-link.sh $(OBJ)/mistball.rel $(OBJ)/sprite.rel -o $(OBJ)/mistball.ihx
	$(BIN)/gbdk-n-make-rom.sh $(OBJ)/mistball.ihx $(GAME_NAME).gb

clean:
	rm -rf $(OBJ)
	rm -f $(GAME_NAME).gb
