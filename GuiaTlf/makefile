SRC = src
INC = include
OBJ = obj
BIN = bin
DOC = doc
CXX = g++
CPPFLAGS = -g

$(BIN)/usoguia: $(SRC)/usoguia.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usoguia.cpp -o $(BIN)/usoguia

#********************************* GENERACIÓN DE DOCUMENTACIÓN ************************************
documentacion: 
	@doxygen $(DOC)/Doxyfile

clean:
	echo Limpiando.
	-rm $(BIN)/*
	-rm -r $(DOC)/html

