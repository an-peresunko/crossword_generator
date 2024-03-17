#ifndef Crossword_hpp
#define Crossword_hpp

#include <stdio.h>
#include "Cell.hpp"

class Crossword{
private:
    Cell* _field;
    int _row;
    int _column;
public:
    Crossword(int rows, int columns);
    ~Crossword();
    void printField();
    void putLetter(char letter, int row, int column);
    Cell* getField();
    bool checkBorders(int row, int col);
    Cell getCell(int row, int col);
};
#endif /* Crossword_hpp */
