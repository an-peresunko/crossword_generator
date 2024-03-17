#include "Cell.hpp"
#include <string>
#include <fstream>
using namespace std;

Cell::Cell(){
    this->_letter = '0';
    this->_edge = false;
    this->_crossed = false;
}
Cell::Cell(char letter, string &word){
    this->_letter = letter;
    this->_word = &word;
}
char Cell::data(){
    return this->_letter;
}
string* Cell::link(){
    return this->_word;
}
void Cell::operator=(char cur_let){
    this->_letter = cur_let;
}
void Cell::operator=(Cell &another){
    this->_letter = another.data();
    this->_word = another.link();
}
ostream& operator<<(ostream& out, Cell& another){
    out << another.data();
    return out;
}
char Cell::getLetter(){
    return this->_letter;
}
