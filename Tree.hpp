#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

class Tree{
    char _letter;
    string _fullword;
    bool _usedword;
    map<char, Tree*> _map;
public:
    Tree(char let);
    void setLetter(char letter);
    Tree* existLetter(char letter);
    Tree* insert(const string curword, const string fullword);
    void printTree();
};

#endif /* Tree_hpp */
