#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Cell {
private:
    char _letter;
    bool _edge;
    bool _crossed;
    string* _word;
public:
    Cell(void);
    Cell(char letter, string &word);
    char data();
    string* link();
    void operator=(char cur_let);
    void operator=(Cell &another);
    friend std::ostream& operator<<(std::ostream& out, Cell& another);
    char getLetter();
};

#endif /* Cell_hpp */
