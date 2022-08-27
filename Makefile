EXECUTABLE := square
BIN_DIR := build
OBJECTS := test_equation.o useful_functions.o equation_io.o equation.o main.o

OBJECTS := $(addprefix $(BIN_DIR)/, $(OBJECTS))

$(BIN_DIR)/$(EXECUTABLE): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	g++ $(OBJECTS) -o $(BIN_DIR)/$(EXECUTABLE)

$(BIN_DIR)/%.o: %.cpp
	mkdir -p $(BIN_DIR)
	g++ -c $< -o $@

clean:
	rm -rf $(BIN_DIR)
