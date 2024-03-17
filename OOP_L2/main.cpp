#include "Crossword.hpp"
#include "Base.hpp"
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

map<string, string> Dictionary;
Tree* root;
int dict_init();

// START OF MAIN //
int main(int argc, const char * argv[]) {
//    Crossword A(N, M);
//    A.printField();
    int SIZE_DICT = 0;
    int R, C = 0;
    char* str = (char*)(malloc(10*sizeof(char)));
    cout << "Height:";
    cin >> R;
    cout << "Width:";
    cin >> C;
    cout << endl;
    dict_init();
    cout << "Creating of field..." << endl;
    map<string, string>::iterator iter;
    iter = Dictionary.begin();
    int i = 0;
    while(iter != Dictionary.end()){
        if(i != 0){ cout << "Loading – " << (i*100/Dictionary.size()) << endl; }
        const char* tmp_str = iter->first.data();
        const char* tmp_def = iter->second.data();
        for(int i = 0; i < strlen(tmp_str); i++){
            root->insert(str, tmp_str, tmp_def);
            strncpy(str, tmp_str, strlen(tmp_str) - i - 1);
        }
        iter++;
    }
//    Treelist* lst = root->getList();
//    Base* tmp_base;
//    Crossword Board(R, C);
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
            word = tmp;
        }
        else{
            Dictionary.insert(pair<string, string>(word, tmp));
        }
        i++;
    }
//    std::for_each(Dictionary.begin(), Dictionary.end(), [](auto&& pair) {
//            std::cout << pair.first << ": " << pair.second << std::endl;
//    });
    return 0;
}

