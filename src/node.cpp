#include "Includes/node.hpp" //take file hpp for use it

using namespace std;


void insert_node(int val, int value){
    if (val > value){
        if( right == nullptr){ 
            right = new Node(val); //on insert a l'enfant droit le nouveau node
        }
        else{
            //rappel la fonction pour faire recursive 
        }
    }
    else{
        if (left == nullptr){
            left == ; // on insère à l'enfant gauche le nouveau node
        }
        else{
            //rappel la fonction pour faire une récursive
        }
    }

}


void display_value(){
    
}