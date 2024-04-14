
#include <iostream>
#include "../headers/linkedList.h"

using namespace std;

//constructor: Node
Node::Node(){
    this->ID = -1;
    this->next = NULL;
    this->prev = NULL;
}

//setters y getters: Node
void Node::setID   ( int newID ){ this->ID = newID; }
void Node::setNext ( Node *newNext ){ this->next = newNext; }
void Node::setPrev ( Node *newPrev ){ this->prev = newPrev; }

int Node::getID() { return this->ID; }
Node* Node::getNext() { return this->next; }
Node* Node::getPrev() { return this->prev; }

//general methods to the class or object: Node


//constructor: Lista
Lista::Lista( std::string nombre ){
    this->nombre = nombre;
    this->size= -1;
    this->first = NULL;
    this->last = NULL;
}

//setters y getters: Lista
void Lista::setNombre ( std::string newName ){ this->nombre = newName; }
void Lista::setFirst ( Node *newFirst ){ this->first = newFirst; }
void Lista::setLast ( Node *newLast ){ this->last = newLast; }
void Lista::setSize ( int newSize ){ this->size = newSize; }

std::string Lista::getNombre() { return this->nombre; }
Node* Lista::getFirst() { return this->first; }
Node* Lista::getLast() { return this->last; }
int Lista::getSize() { return this->size; }

//general methods to the class or object: Lista
void Lista::showList(){
    
    Node *current = this->getFirst();
    std::cout << "\n-------------------------\n";
    while( current != NULL ){
        std::cout << "Identificador Nodo: " << current->getID() << std::endl;
        current = current->getNext();
    }
    std::cout << "-------------------------\n";
}

void Lista::addNode( Node *newNode ){
    
    this->setSize( this->getSize()+1 );     //the size value is increased by 1
    newNode->setID( this->getSize() );      //the ID of the node is setted
        
    if( this->getFirst() == NULL ){
                
        //the head of the list is setted, with its connections
        this->setFirst( newNode );
        this->getFirst()->setPrev( NULL );

        //the tail of the list is setted, with its connections
        this->setLast( newNode );
        this->getLast()->setNext( NULL );
            
    }else{

        this->getLast()->setNext( newNode );    //the next node to the last is placed
        this->getLast()->getNext()->setPrev( this->getLast() );     //the previous' node of the last's next node is placed
        this->setLast( this->getLast()->getNext() );    //the "final" last node is setted
        this->getLast()->setNext( NULL );               //the next node to the last is setted with a null value

    }

}

Node* Lista::searchNode( int ID ){
    
    Node *current = this->getFirst();
    Node *bessel;
    int found = 0;
            
    //this part checks if the seeked node is in the list
    if( ID > this->getSize() ){
        std::cout << "El nodo" << ID << " no existe" << std::endl;
        return NULL;
    }else if( this->getSize() < ID ){
        std::cout << "La lista está vacia" << std::endl;
        return NULL;
    }else if( ID < 0 ){
        std::cout << "El nodo" << ID << " no existe" << std::endl;
        return NULL;
    }else{
        
        //if the seeked is in the list, this part gets the node
        while( found == 0 ){

            if( current->getID() == ID ){
                found = 1;
                bessel = current;
            }

                    current = current->getNext();
        }
    }

    std::cout << "Bessel Prev: " << bessel->getPrev()->getID() << std::endl;
    std::cout << "Bessel Next: " << bessel->getNext()->getID() << std::endl;
    return bessel;
}

void Lista::deleteNode( int ID ){

    Node *toDelete = this->searchNode( ID );  //The node to delete is obtained

    if( toDelete == this->getFirst() ){       //case, the node to delete is the first of the list
        this->setFirst( toDelete->getNext() );
        this->getFirst()->setPrev( NULL );
        delete toDelete;
    }else if( toDelete == this->getLast() ){  //case, the node to delete is the last of the list
        this->setLast( toDelete->getPrev() );
        this->getLast()->setNext( NULL );
        delete toDelete;
    }else{      //if the node isn't the first or the last of the list
        toDelete->getPrev()->setNext( toDelete->getNext() );
        delete toDelete;
    }

}