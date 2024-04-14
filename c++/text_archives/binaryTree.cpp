
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 

#include "binaryTree.h"
#include "linkedList.h"

using namespace std;

 //constructor Node3
 Node3::Node3( int ID, std::string name ){
    this->ID = ID;
    this->name = name;
    this->father = NULL;
    this->left = NULL;
    this->right = NULL; 
 }

//setters and getters Node3
void Node3::setID( int newID ){ this->ID = newID; }
void Node3::setName( std::string newName ){ this->name = newName; }
void Node3::setFather( Node3 *newNode ){ this->father = newNode; }
void Node3::setLeft( Node3 *newNode ){ this->left = newNode; }
void Node3::setRight( Node3 *newNode ){ this->right = newNode; }

int Node3::getID(){ return this->ID; }
std::string Node3::getName(){ return this->name; }
Node3* Node3::getFather(){ return this->father; }
Node3* Node3::getLeft(){ return this->left; }
Node3* Node3::getRight(){ return this->right; }

//general methods to the class or object Node3
void Node3::showNode( ){

    cout << "Node: " << this->getName() << endl;

    if( this->getLeft() != NULL ){
        cout << "   Left: " << this->getLeft()->getName() << endl;
    }else{
        cout << "   Left: " << this->getLeft() << endl;
    }

    if( this->getRight() != NULL ){
        cout << "   Right: " << this->getRight()->getName() << endl;
    }else{
        cout << "   Right: " << this->getRight() << endl;
    }
}

bool Node3::recordaData(){

    ofstream archivo;

    archivo.open( "nodos/"+this->getName()+".txt", ios::out );

    if( archivo.fail() ){

        cout << "No se pudo abrir el archivo" << endl;
        return false;

    }else{

        archivo << to_string( this->getID() ) << endl; //identificador del nodo
        archivo << this->getName() << endl; //nombre del nodo

        if( this->getLeft() == NULL ){
            archivo << "NULL" << endl;
        }else{
            archivo << this->getLeft()->getName() << endl; //nombre del hijo izq
        }

        if( this->getRight() == NULL ){
            archivo << "NULL" << endl;
        }else{
            archivo << this->getRight()->getName() << endl; //nombre del derecho
        }

        archivo.close();

        return true;

    }

}

//constructor  árbol
BinaryTree::BinaryTree( std::string name ){
    this->name = name;
    this->root = NULL;
}

//setter and getters
void BinaryTree::setName( std::string newName ){ this->name = newName; }
void BinaryTree::setRoot( Node3 *newNode ){ this->root = newNode; }

std::string BinaryTree::getName(){ return this->name; }
Node3* BinaryTree::getRoot(){ return this->root; }

//general methods to the class or object
void BinaryTree::addNode( Node3 *newNode, Node3 *current ){

    /*
        el argumento "current", se refiere al nodo padre, empezando por el
        nodo raiz del arbol y recorriendo el mismo por recursividad. En cada iteración se
        ingresa un nodo hoja que pasa a ser el nodo raiz referenciado
    */

    if( this->getRoot() == NULL ){

        //si la raiz está vacía

        this->setRoot( newNode );
        this->getRoot()->setFather( NULL );
        return; 
    }

    if( newNode->getID() < current->getID() ){
        
        if( current->getLeft() == NULL ){
            current->setLeft( newNode );
            current->getLeft()->setFather( current );
        }else{
            this->addNode( newNode, current->getLeft() );
        }

    }else if( newNode->getID() > current->getID() ){

        if( current->getRight() == NULL ){
            current->setRight( newNode );
            current->getRight()->setFather( current );
        }else{
            this->addNode( newNode, current->getRight() );
        }

    }

}

Node3* BinaryTree::searchNode( int ID, Node3 *current ){

    if( this->getRoot()->getID() == ID ){
        return this->getRoot();
    }

    if( ID < current->getID() ){
        this->searchNode( ID, current->getLeft() );
    }else if( ID > current->getID() ){
        this->searchNode( ID, current->getRight() );
    }else if( ID == current->getID() ){
        return current;
    }else{
        cout << "No existe el Nodo" << endl;
        return NULL;
    }

}

void BinaryTree::showTree( Node3 *current ){

    if( current != NULL ){
        current->showNode();
        this->showTree( current->getLeft() );   //izquierda
        this->showTree( current->getRight() );  //derecha
    }

}

void BinaryTree::preOrden( Node3 *current ){

    if( current != NULL ){
        cout << current->getID() << " ";
        this->preOrden( current->getLeft() );
        this->preOrden( current->getRight() );
    }

}

void BinaryTree::inOrden( Node3 *current ){
    
    if( current != NULL ){
        this->inOrden( current->getLeft() );
        cout << current->getID() << " ";
        this->inOrden( current->getRight() );
    }
}

void BinaryTree::posOrden( Node3 *current ){
    
    if( current != NULL ){
        this->posOrden( current->getLeft() );
        this->posOrden( current->getRight() );
        cout << current->getID() << " ";
    }
}

bool BinaryTree::deleteNode( int ID ){

    if( this->getRoot() == NULL){
        cout << "El arbol esta vacio" << endl;
        return false;
    }

    Node3 *node = this->searchNode( ID, this->getRoot() );

    if( node->getLeft() == NULL && node->getRight() == NULL ){
        //si el nodo es una hoja

        if( node == node->getFather()->getLeft() ){
            node->getFather()->setLeft( NULL );
        }else if( node == node->getFather()->getRight() ){
            node->getFather()->setRight( NULL );
        }

        delete node;
        return true;

    }else if( node->getLeft() != NULL && node->getRight() != NULL ){
        //si el nodo tiene dos hijos

        Node3 *bessel = node->getRight();

        bool flag = false;
        while( flag != true ){
            if(bessel->getLeft() == NULL){
                flag = true;
            }else{
                bessel = bessel->getLeft();
            }
        }

        node->setID( bessel->getID() );
        node->setName( bessel->getName() );

        if( bessel == bessel->getFather()->getLeft() ){
            bessel->getFather()->setLeft( NULL );
        }else if( bessel == bessel->getFather()->getRight() ){
            bessel->getFather()->setRight( NULL );
        }

        bessel->setFather( NULL );
        bessel->setLeft( NULL );
        bessel->setRight( NULL );

        delete bessel;
        return true;
    
    }else{ 
    
        if( node->getLeft() != NULL ){
        //si el nodo tiene un hijo

            if( node->getFather() != NULL ){

                Node3 *bessel = node->getLeft();
                bessel->setFather( node->getFather() );
                bessel->getFather()->setRight( bessel );

                node->setFather( NULL );
                node->setLeft( NULL );
                node->setRight( NULL );

                delete node;
                return true;

            }

            return false;

        }else if( node->getRight() != NULL ){

            if( node->getFather() != NULL ){
                Node3 *bessel = node->getRight();
                bessel->setFather( node->getFather() );
                node->getFather()->setLeft( bessel );

                node->setFather( NULL );
                node->setLeft( NULL );
                node->setRight( NULL );

                delete node;
                return true;
            }
            
            return false;
        }

    }
}

bool BinaryTree::saveNodes( Node3 *current, Lista *listaN ){

    if( this->getRoot() == NULL ){
        cout << "El arbol esta vacio" << endl;
        return false;
    }

    if( current != NULL ){
        
        this->saveNodes( current->getLeft(), listaN );
        current->recordaData();
        listaN->addNode( new Node( current->getName() ) );
        this->saveNodes( current->getRight(), listaN );

    }
   
    return true;

}