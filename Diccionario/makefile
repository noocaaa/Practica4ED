SRC = src
INC = include
OBJ = obj
BIN = bin
DOC = doc
CXX = g++
CPPFLAGS = -g

$(BIN)/usodiccionario: $(SRC)/usodiccionario.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usodiccionario.cpp -o $(BIN)/usodiccionario

#********************************* GENERACIÓN DE DOCUMENTACIÓN ************************************
documentacion: 
	@doxygen $(DOC)/Doxyfile

clean:
	echo Limpiando.
	-rm $(BIN)/*
	-rm -r $(DOC)/html

