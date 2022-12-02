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

using namespace std;

int posOfString(char* argv[], string str){
    for(int i = 0; i < argv.length(); i++){
        if (argv[i] == str){
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[]){

    // set number of abilities players have
    int numabilities = 5;

    //creates mapcontroller and board

    Board* theBrd = new Blank;

    Mapcontroller theMap{theBrd}

    //adds observers

    std::vector<Observer*> observers;
    textObserver *obs1 = new textObserver{&theMap};
    observers.emplace_back(obs1);

    if (posOfString(argv[], "graphical") != -1){
        graphicObserver *obs 2 = new graphicObserver{&theMap};
        observers.emplace_back(obs2);
    }

    //creates the player 1
    Player p1 = new Player{};

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



    //creates player 2
    Player p2 = new Player{};

    if ((posOfString(argv[], "link2") != 0) && (posOfString(argv[], "ability2") != -1)){

    } else if (posOfString(argv[], "link2") != -1){

    } else if (posOfString(argv[], "ability2") != -1){

    } else {
        
    }

    bool readfile = false;

    string command;

    while(true){


    } // command loop


}