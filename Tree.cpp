#include "Tree.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <cstring>
using namespace std;

Tree::Tree(char let){
    this->_letter = let;
    this->_fullword = "";
    this->_usedword = false;
}

void Tree::setLetter(char letter){
    this->_letter = letter;
}

Tree* Tree::existLetter(char letter){
    map<char, Tree*>::iterator iter;
    iter = this->_map.begin();
    while(iter != this->_map.end()){
        if(iter->first == letter){
            return iter->second;
        }
        iter++;
    }
    return nullptr;
}

Tree* Tree::insert(const string curword, const string fullword){
    if(curword.size() == 1){
        this->_letter = curword.c_str()[0];
        this->_fullword = fullword;
        this->_usedword = false;
        return this;
    }
    if(curword.size() > 0){
        char letter = curword.c_str()[curword.size() - 1]; // get last letter
        string partword = curword.substr(0, curword.size() - 1); // get string w/o last letter
        
        this->_letter = letter;
        this->_fullword = "";
        this->_usedword = false;
        
        char nextLetter = partword.c_str()[partword.size() - 1];
        Tree* tmp = this->existLetter(nextLetter);
        if(tmp != nullptr){
            tmp->insert(partword, fullword);
        }
        else{
            Tree* newLetter = new Tree('0');
            newLetter->insert(partword, fullword);
            this->_map.insert(pair<char, Tree*>(nextLetter, newLetter));
        }
        return this;
    }
    return this;
}

void Tree::printTree(){
    cout << "[  _letter: " << this->_letter << "\n  _fullword: " << this->_fullword << "\n  _usedword: " << this->_usedword << "\n  _map: ";
    for(const auto& pair : this->_map){
        cout << "|" << pair.first << "|";
    }
    cout << "\n ]" << endl;
    if(!this->_map.empty()){
        for(const auto& pair : this->_map){
            pair.second->printTree();
        }
    }
}
