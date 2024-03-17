#include "Crossword.hpp"
#include "Cell.hpp"
#include <iostream>
using namespace std;

Crossword::Crossword(int rows, int columns){
    this->_field = new Cell[rows*columns];
    for(int i=0; i<columns; i++){
        for(int j=0; j<rows; j++){
            this->_field[j+i*rows] = '_';
        }
    }
    this->_row = rows;
    this->_column = columns;
}
Crossword::~Crossword(){}

void Crossword::printField(){
    for(int i=0; i<this->_column; i++){
        for(int j=0; j<this->_row; j++){
            cout << this->_field[j+i*this->_row] << ' ';
        }
        cout << endl;
    }
}

void Crossword::putLetter(char letter, int row, int column){
    string tmp_str = "hello";
    Cell tmp(letter, tmp_str);
    int ind = row * this->_column + column;
    this->_field[ind] = tmp;
}
Cell* Crossword::getField(){
    return this->_field;
}
bool Crossword::checkBorders(int row, int col){
    Cell tmp_cell = this->_field[row * this->_column + col];
    char tmp_char = tmp_cell.getLetter();
    if(tmp_char != ' ' || row < 0 || col < 0 || row >= this->_row || col >= this->_column){
        return true;
    }
    else{
        return false;
    }
}
Cell Crossword::getCell(int row, int col){
    Cell tmp_cell = this->_field[row * this->_column + col];
    return tmp_cell;
}
