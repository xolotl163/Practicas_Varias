
/*
    Pila en c++ utilizando objetos
*/

#include <iostream>
#include "stack.h"

using namespace std;

//constructor: Node
Node2::Node2( string name ){
    this->nombre = name;
    this->up = NULL;
    this->down = NULL;
}

//setters y getters: Node
void Node2::setNombre( string newName ){ this->nombre = newName; }
void Node2::setUp( Node2 *newNode ){ this->up = newNode; }
void Node2::setDown( Node2 *newNode ){ this->down = newNode; }

string Node2::getNombre(){ return this->nombre; }
Node2*  Node2::getUp(){ return this->up; }
Node2*  Node2::getDown(){ return this->down; }

//constructor: Pila
Pila::Pila( string nombre ){
            this->nombre = nombre;
            this->bottom = NULL;
            this->top = NULL;
}

//setters y getters: Pila
void Pila::setNombre( string newName ){ this->nombre = newName; }
void Pila::setBottom( Node2 *newNode ){ this->bottom = newNode; }
void Pila::setTop( Node2 *newNode ){ this->top = newNode; }

string Pila::getNombre(){ return this->nombre; }
Node2*  Pila::getBottom(){ return this->bottom; }
Node2*  Pila::getTop(){ return this->top; }

//metodos generales a la clase u objeto: Pila
void Pila::addNode( Node2* newNode ){

    if( this->getBottom() == NULL ){
                
        this->setBottom( newNode );
        this->getBottom()->setDown( NULL );
        this->setTop( newNode );
        this->getTop()->setUp( NULL );
            
    }else{

        this->getTop()->setUp( newNode );
        this->getTop()->getUp()->setDown( this->getTop() );
        this->setTop( this->getTop()->getUp() );
        this->getTop()->setUp( NULL );
            
    }

}

void Pila::deleteNode(){

    Node2 *bessel = this->getTop();

    if( this->getBottom() == NULL ){

        cout << "La pila está vacia" << endl;

    }else{

        this->setTop( this->getTop()->getDown() );
        this->getTop()->setUp( NULL );
    
    }

    delete bessel;

}

void Pila::showStack(){

    Node2 *current = this->getTop();

    cout << "\n--------------------" << endl;

    while( current != NULL ){
                
        cout << "Nodo ID: " << current->getNombre() << endl;
        current = current->getDown();

        }

    cout << "--------------------" << endl;

}