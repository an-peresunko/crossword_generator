// Custom include //
#include "Crossword.hpp"
#include "Cell.hpp"
#include "Tree.hpp"

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

map<int, string> Dictionary;
int dict_init();
void dict_print(map<int, string> Dictionary);

// START OF MAIN //
int main(int argc, const char * argv[]) {
    int R, C = 0;
    cout << "Height:";
    cin >> R;
    cout << "Width:";
    cin >> C;
    cout << endl;
    
    if(dict_init() == 1){ exit(0); }
    dict_print(Dictionary);
    
    Tree* root = new Tree('0'); // prepare tree of letters
    map<int, string>::iterator iter = Dictionary.begin();
    int i = 0;
    for(const auto& pair : Dictionary){
        root->insert(pair.second.data(), pair.second.substr(0, pair.second.size() - 1));
    }
    root->printTree();
    Crossword Board(R, C);
    Board.printField();
    
    
//    int count = 0;
//    int count_def = 0;
//    int flag = 0;
//    int k = 0;
//    int word = 0;
//    int its_okay = 0;
//    int start = 0, end = 0;
//    i = R / 2;
//    srand((unsigned int)time(NULL));
//    int r1 = rand();
//    Treelist* first_lst = root->getList();
//    lst = first_lst;
//    start = (r1 % (C/2));
//    while (flag == 0){
//        tmp_base->defineFirstWord(first_lst->getLetterTree());
//        if(tmp_base != nullptr){
//            end = start + (int)strlen(tmp_base->getWords());
//        }
//        if(start < 0 || end - 1 >= C){
//            word++;
//            tmp_base->setUsed(-1);
//            if (first_lst->getList() != NULL){
//                first_lst = first_lst->getList();
//            }
//        }
//        else{
//            for(int j = start; j < end; j++){
//                if(Board.checkBorders(i, j)){
//                    word++;
//                    its_okay = 1;
//                    if (first_lst->getList() != NULL){
//                        first_lst = first_lst->getList();
//                    }
//                    else{
//                        cout << "ERROR" << endl;
//                    }
//                    break;
//                }
//            }
//            if (its_okay == 0) {
//                k = 0;
//                for (int j = start; j < end; j++){
//                    Board.putLetter(tmp_base->getWords()[k], i, j);
//                    k++;
//                }
//                tmp_base->setUsed(1);
//                flag = 1;
//                int int_iter = 0;
//                iter = Dictionary.begin();
//                while (int_iter < count_def) {
//                    int_iter++;
//                    iter++;
//                }
//                iter->second = tmp_base->getDef();
//                count_def++;
//                root->deleteWord(tmp_base->getWords());
//                break;
//            }
//        }
//        if (word == Dictionary.size()){ break; }
//    }
//    if(flag == 0){
//        cout << "ERROR. TRY AGAIN" << endl;
//        return 0;
//    }
//    for(count = 0; count < Dictionary.size(); count++){
//        for(int I = 0; I < R; i++){
//            for( int J = 0; J < C; J++){
//                if(Board.getCell(I, J).getLetter() != ' '){
//                    -----------
//                }
//            }
//        }
//    }
    return 0;
}
// END OF MAIN //

int sumChar(string str){
    int sum = 0;
    for(int i = 0; i < str.size(); i++){
        sum += str.c_str()[i];
    }
    return sum;
}

int dict_init(){
    ifstream inputfile;
    string input = "/Users/anastasia/Uni/Xcode_prj/OOP_L2/OOP_L2/dict.txt";
    inputfile.open(input);
    
    while(!inputfile){ // check for valid file; if not valid, prompt for valid file or exit
        cout << "\nInvalid file name. Please enter valid file, ";
        cout << "or type 'quit' to exit the program: " << endl;
        getline(cin, input);
        if(input=="quit"||input=="Quit"||input=="QUIT"){
            return 1;
        }
        inputfile.open(input);
    }
    string tmp;
    string word;
    int i = 0;
    while (getline(inputfile, tmp)){
        if(i%2 == 0){
            word = tmp + '_';
        }
        else{
            Dictionary.insert(pair<int, string>(sumChar(word), word));
        }
        i++;
    }
    return 0;
}

void dict_print(map<int, string> Dictionary){
    std::for_each(Dictionary.begin(), Dictionary.end(), [](auto&& pair) {
            std::cout << pair.first << ": " << pair.second << std::endl;
    });
}
