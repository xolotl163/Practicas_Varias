
#include <iostream>
#include "queue.h"

using namespace std;

//constructor: Game
Game::Game(std::string name, std::string genere, std::string ID, std::string region, float cost, int unitsStock){
    this->name = name;
    this->genere = genere;
    this->ID = ID;
    this->region = region;
    this->cost = cost;
    this->unitsStock = unitsStock;
}

//setters and getters: Game
void Game::setName( std::string newName ){ this->name = newName; }
void Game::setGenere( std::string newGenere ){ this->genere = newGenere; }
void Game::setID( std::string newID ){ this->ID = newID; }
void Game::setRegion( std::string newRegion ){ this->region = newRegion; }
void Game::setCost( float newCost ){ this->cost = newCost; }
void Game::setUnitsStock( int newUnitsStock ){ this->unitsStock = newUnitsStock; }

std::string Game::getName(){ return this->name; }
std::string Game::getGenere(){ return this->genere; }
std::string Game::getID(){ return this->ID; }
std::string Game::getRegion(){ return this->region; }
float Game::getCost(){ return this->cost; }
int   Game::getUnitsStock(){ return this->unitsStock; }

//general methods to the class or object: game
void Game::printGame(){
    std::cout << "\nName: " << this->name << std::endl;
    std::cout << "Genere: " << this->genere << std::endl;
    std::cout << "ID: " << this->ID << std::endl;
    std::cout << "Region: " << this->region << std::endl;
    std::cout << "Cost: " << this->cost << std::endl;
    std::cout << "Units in stock: " << this->unitsStock << "\n" << std::endl;
}

//constructor: Node
Node1::Node1( Game *game ){
    this->game = game;
    this->next = NULL;
    this->prev = NULL;
}

//setters y getters: Node
void Node1::setGame( Game *newGame ){ this->game = newGame; }
void Node1::setNext( Node1 *newNext ){ this->next = newNext; }
void Node1::setPrev( Node1 *newPrev ){ this->prev = newPrev; }

Game* Node1::getGame(){ return this->game; }
Node1* Node1::getNext(){ return this->next; }
Node1* Node1::gettPrev(){ return this->prev; }

//constructor: queue
Queue::Queue( std::string name ){
    this->first = NULL;
    this->last = NULL;
}

//getters y setters: queue
void Queue::setName( std::string newName ){ this->name = newName; }
void Queue::setFirst( Node1 *newNode ){ this->first = newNode; }
void Queue::setLast( Node1 *newNode ){ this->last = newNode; }

std::string Queue::getName(){ return this->name; }
Node1* Queue::getFirst(){ return this->first; }
Node1* Queue::getLast(){ return this->last; }

//general methods to the class or object: Queue
void Queue::addNode( Node1 *newNode ){

    if( this->getFirst() == NULL ){

        this->setFirst( newNode );
        this->getFirst()->setPrev( NULL );
        this->setLast( newNode );
        this->getLast()->setNext( NULL );

    }else{

        this->getLast()->setNext( newNode );
        this->getLast()->getNext()->setPrev( this->getLast() );
        this->setLast( this->getLast()->getNext() );
        this->getLast()->setNext( NULL );

    }

}

int Queue::deleteNode( ){

    Node1* bessel = this->getFirst();

    if( this->getFirst() == NULL ){
        std::cout << "This list is empty" << std::endl;
        return 0;  
    }else{

        this->setFirst( this->getFirst()->getNext() );
        this->getFirst()->setPrev( NULL );
        return 1;
    }

}

void Queue::showList(){

    Node1 *current = this->first;
    std::cout << "\n------------------------" << std::endl;
    while( current != NULL ){
        current->getGame()->printGame();
        current = current->getNext();
    }
    std::cout << "------------------------\n" << std::endl;

}