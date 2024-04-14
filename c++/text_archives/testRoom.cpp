
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

//header files, they are in the same directory
#include "stack.h"
#include "queue.h"
#include "linkedList.h"
#include "binaryTree.h"

using namespace std;

#define binarytree

int main(){

    BinaryTree *arbol = new BinaryTree( "Arbol 1" );
    ifstream nombres0;
    nombres0.open( "nodos/nombres.txt", ios::in );

    if( nombres0.fail() ){
        cout << "No se puedo abrir el archivo 'Nombres' " << endl;
        cout << "Se creara desde cero la lista\n\n" << endl;

        arbol->addNode( new Node3( 20, "Diana" ), arbol->getRoot() );
        arbol->addNode( new Node3( 29, "Cesar" ), arbol->getRoot() );
        arbol->addNode( new Node3( 31, "Jocabed" ), arbol->getRoot() );
        arbol->addNode( new Node3( 21, "Samantha" ), arbol->getRoot() );
        arbol->addNode( new Node3( 23, "Efren" ), arbol->getRoot() );
        arbol->addNode( new Node3( 22, "Erik" ), arbol->getRoot() );
        arbol->addNode( new Node3( 19, "Tania" ), arbol->getRoot() );

    }else{

        string name1;
        while( !nombres0.eof() ){
            getline( nombres0, name1 );

            ifstream nodo1;
            string datos[2];
            int i=0;
            nodo1.open( "nodos/"+name1+".txt", ios::in );
            while( i < 2 ){
                getline( nodo1, datos[i] );
                i++;
            }

            cout << datos[0] << endl;
            cout << datos[1] << endl;
            
            int id;
            istringstream( datos[0] ) >> id;

            arbol->addNode( new Node3( id , datos[1] ), arbol->getRoot()) ;

            nodo1.close();
            name1 = "";

        }

        nombres0.close();

    }

    arbol->showTree( arbol->getRoot() );

    Lista *nombres = new Lista( "Nombres" );
    arbol->saveNodes( arbol->getRoot(), nombres );
    nombres->showList();

    ofstream names;
    names.open( "nodos/nombres.txt", ios::out );
    if( names.fail() ){
        cout << "No se pudieron guardar los nombres" << endl;
    }else{

        Node *actual = nombres->getFirst();

        while( actual != NULL ){

            names << actual->getNombre() << endl;
            actual = actual->getNext();
        }

        names.close();

    }


return 0;
}