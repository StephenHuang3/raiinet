#include "ability.h"
#include "blank.h"
#include "board.h"
#include "decorator.h"
#include "mapcontroller.h"
#include "observer.h"
#include "piece.h"
#include "player.h"
#include "subject.h"

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

/*
int posOfString(char* argv[], string str){
    for(int i = 0; i < argv.length(); i++){
        if (argv[i] == str){
            return i;
        }
    }
    return -1;
}
*/

int main(int argc, char *argv[]){

    // set number of abilities players have
    int numabilities = 5;

    //creates mapcontroller and board

    Board* theBrd = new Blank;

    Mapcontroller theMap{theBrd};

    //adds observers
    std::vector<Observer*> observers;
    textObserver *obs1 = new textObserver{&theMap};
    observers.emplace_back(obs1);

    // creates player 1
    Player* p1 = new Player{};
    // creates player2
    Player* p2 = new Player{};

    for(int i = 0; i < argc; ++i) {
        if(argv[i] == "graphical") {
            graphicObserver *obs2 = new graphicObserver{theMap.board()};
            observers.emplace_back(obs2);
        } else if (argv[i] == "ability1") {
            string abilityorder = argv[i + 1];
            for(int i = 0; i < numabilities; ++i) {
                p1->setAbility(abilityorder[i], i);
            }
            ++i;
        } else if (argv[i] == "ability2") {
            string abilityorder = argv[i + 1];
            for(int i = 0; i < numabilities; ++i) {
                p2->setAbility(abilityorder[i], i);
            }
            ++i;
        } else if (argv[i] == "link1") {
            ifstream LinkFile(argv[i + 1]);
            string piecevalues;
            getline(LinkFile, piecevalues);
            stringstream ss(piecevalues);
            string singlePiece;
            for(int i = 0; i < 8; i++){
                ss >> singlePiece;

            }
            LinkFile.close();
            ++i;
        } else if (argv[i] == "link2") {
            ifstream LinkFile(argv[i + 1]);
            string piecevalues;
            getline(LinkFile, piecevalues);
            stringstream ss(piecevalues);
            string singlePiece;
            for(int i = 0; i < 8; i++){
                ss >> singlePiece;
                // do something with singlePiece[0] and singlePiece[1]
            }
            LinkFile.close();
            ++i;
        }
    };

/*
    if (posOfString(argv[], "graphical") != -1){
        graphicObserver *obs 2 = new graphicObserver{&theMap};
        observers.emplace_back(obs2);
    }



    if (posOfString(argv[], "ability1") == -1){
        string abilityorder = "LFDSPLFDSPLFDSP";
        for(int i = 0; i < numabilities; i++){
            p1.setAbility(abilityorder[i], i);
        }
    } else {
        string abilityorder = argv[posOfString(argv[], "ability1") + 1];
        for(int i = 0; i < numabilities; i++){
            p1.setAbility(abilityorder[i], i);
        }
    }

    if (posOfString(argv[], "link1") != -1){
        ifstream MyReadFile(argv[posOfString(argv[], "link1") + 1]);
        string piecevalues;
        getline(myReadFile, piecevalues);
        stringstream ss(piecevalues);
        string singlePiece;
        for(int i = 0; i < 8; i++){
            ss >> singlePiece;
            
        }
        MyReadFile.close();
    } else { //randomize values

    }


    if ((posOfString(argv[], "link2") != 0) && (posOfString(argv[], "ability2") != -1)){

    } else if (posOfString(argv[], "link2") != -1){

    } else if (posOfString(argv[], "ability2") != -1){

    } else {
        
    }
*/
    
    bool readfile = false;

    string command;

    while( cin >> command ) {
        if( command == "move" ) {
            char id, d;
            cin >> id >> d;
            // function
        } else if ( command == "abilities" ) {
            // display abilities
        } else if ( command == "ability" ) {
            int id;
            cin >> id;
            // check abilities
        } else if (command == "board" ) {
            // displays the board depending on whose turn it is
        } else if (command == "sequence" ) {
            string fileName;
            cin >> fileName;
            ifstream f(fileName);
            string fLine;
            while(getline(f, fLine)) {
                stringstream ss(fLine);
                string word;
                while(ss >> word) {
                    if( command == "move" ) {
                        char id, d;
                        cin >> id >> d;
                        // function
                    } else if ( command == "abilities" ) {
                        // display abilities
                    } else if ( command == "ability" ) {
                        int id;
                        cin >> id;
                        // check abilities
                    } else if (command == "board" ) {
                        // displays the board depending on whose turn it is
                    } else if (command == "quit") break;
                }
            }
        } else if (command == "quit") break;
    } // command loop


}
