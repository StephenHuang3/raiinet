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

int main(int argc, char *argv[]) {

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

    //add serverport decorators
    theBrd = new Serverport{theBrd, 4};
    theMap.board() = theBrd;

    theBrd = new Serverport{theBrd, 5};
    theMap.board() = theBrd;

    theBrd = new Serverport{theBrd, 60};
    theMap.board() = theBrd;

    theBrd = new Serverport{theBrd, 61};
    theMap.board() = theBrd;

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
            ifstream myReadFile(argv[i + 1]);
            string piecevalues;
            getline(myReadFile, piecevalues);
            stringstream ss(piecevalues);
            string singlePiece;
            for(int i = 0; i < 8; i++){
                ss >> singlePiece;
                string kind;
                int position;
                if (singlePiece[0] == 'V'){
                    kind = "virus";
                } else {
                    kind = "data";
                }
                if (i == 4 || i == 5){
                    position = i + 8;
                } else {
                    position = i;
                }
                theBrd->setPiece(1, char(97 + i), kind, singlePiece[1] - '0', position);
            }
            myReadFile.close();
            ++i;
        } else if (argv[i] == "link2") {
            ifstream myReadFile(argv[i + 1]);
            string piecevalues;
            getline(myReadFile, piecevalues);
            stringstream ss(piecevalues);
            string singlePiece;
            for(int i = 0; i < 8; i++){
                ss >> singlePiece;
                string kind;
                int position;
                if (singlePiece[0] == 'V'){
                    kind = "virus";
                } else {
                    kind = "data";
                }
                if (i == 4 || i == 5){
                    position = i + 57 - 8;
                } else {
                    position = i + 57;
                }
                theBrd->setPiece(2, char(65 + i), kind, singlePiece[1] - '0', position);
                }
            myReadFile.close();
            ++i;
        }
    };

/*
    if (posOfString(argv[], "graphical") != -1){
        graphicObserver *obs 2 = new graphicObserver{&theMap};
        observers.emplace_back(obs2);
    }


    //creates the player 1
    Player &p1 = theBrd->getPlayer1();


    if (posOfString(argv[], "ability1", argc) == -1){
        string abilityorder = "LFDSPLFDSPLFDSP";
        for(int i = 0; i < numabilities; i++){
            p1.setAbility(abilityorder[i], i);
        }
    } else {
        string abilityorder = argv[posOfString(argv[], "ability1", argc) + 1];
        for(int i = 0; i < numabilities; i++){
            p1.setAbility(abilityorder[i], i);
        }
    }

    if (posOfString(argv[], "link1", argc) != -1){
        ifstream MyReadFile(argv[posOfString(argv, "link1", argc) + 1]);
        string piecevalues;
        getline(myReadFile, piecevalues);
        stringstream ss(piecevalues);
        string singlePiece;
        for(int i = 0; i < 8; i++){
            ss >> singlePiece;
            string kind;
            int position;
            if (singlePiece[0] == 'V'){
                kind = "virus";
            } else {
                kind = "data";
            }
            if (i == 4 || i == 5){
                position = i + 8;
            } else {
                position = i;
            }
            theBrd.setPiece(1, char(97 + i), kind, singlePiece[1] - '0', position);
        }
        MyReadFile.close();
    } else { //randomize values

    }


    if ((posOfString(argv[], "link2") != 0) && (posOfString(argv[], "ability2") != -1)){

    } else if (posOfString(argv[], "link2") != -1){

    } else if (posOfString(argv[], "ability2") != -1){

    //creates player 2
    Player &p2 = theBrd->getPlayer2();

    if (posOfString(argv[], "ability2", argc) == -1){
        string abilityorder = "LFDSPLFDSPLFDSP";
        for(int i = 0; i < numabilities; i++){
            p2.setAbility(abilityorder[i], i);
        }
    } else {
        string abilityorder = argv[posOfString(argv[], "ability2", argc) + 1];
        for(int i = 0; i < numabilities; i++){
            p2.setAbility(abilityorder[i], i);
        }
    }

    

    if (posOfString(argv[], "link2", argc) != -1){
        ifstream MyReadFile(argv[posOfString(argv[], "link2", argc) + 1]);
        string piecevalues;
        getline(myReadFile, piecevalues);
        stringstream ss(piecevalues);
        string singlePiece;
        for(int i = 0; i < 8; i++){
            ss >> singlePiece;
            string kind;
            int position;
            if (singlePiece[0] == 'V'){
                kind = "virus";
            } else {
                kind = "data";
            }
            if (i == 4 || i == 5){
                position = i + 8;
            } else {
                position = i;
            }
            theBrd.setPiece(1, char(97 + i), kind, singlePiece[1] - '0', position);
        }
        MyReadFile.close();
    } else { //randomize values

    }
*/
    int turn = 0;
    bool errorfree = true;

    bool readfile = false;

    bool usedAbility = false;

    string command;

    // render board for player 1 before game
    theMap.render(0);

    while( cin >> command ) {

        // render map before move

        if( command == "move" ) {
            char id, d;
            cin >> id >> d;
            // check valid move

            // function

            // change turn
        } else if ( command == "abilities" ) {
            // display abilities
            if(turn == 0){
                for(int i = 0; i < numabilities; i++){
                    cout << p1->getAbilityAtPos(i);
                }
            } else if (turn == 1){
                for(int i = 0; i < numabilities; i++){
                    cout << p2->getAbilityAtPos(i);
                }
            }
        } else if ( command == "ability" ) {
            int id;
            cin >> id;
            // check abilities
        } else if (command == "board" ) {
            // displays the board depending on whose turn it is
            theMap.render(turn);
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
                        theMap.render(turn);

                        //
                    } else if (command == "quit") break;
                }
            }
        } else if (command == "quit") break;
    }

/*        
    ifstream myReadFile;

    while(true){
        if (!readfile){
            cin >> command;
            if (cin.fail()) break;
        } else {
            getline(myReadFile, command);
            if (myReadFile.fail()){
                readfile = false;
                myReadFile.close();
                continue;
            }
        }

        if (command == "sequence"){
            string file;
            cin >> file;
            myReadFile(argv[posOfString(argv[], file, argc)]);
        } else if(command == "move"){
            cout << "move" << endl;
        } else if(command == "abilities"){
            cout << "abilities" << endl;
        } else if(command == "ability"){
            cout << "ability" << endl;
        } else if(command == "board"){
            cout << "board" << endl;
        } else if(command == "quit"){
            cout << "quit" << endl;
            break;
        }

    } // command loop
*/

}
