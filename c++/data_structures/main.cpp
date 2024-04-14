
#include <iostream>
#include <string>

//header files, they are in the same directory
#include "./headers/stack.h"
#include "./headers/queue.h"
#include "./headers/linkedList.h"
#include "./headers/binaryTree.h"

using namespace std;

int main(){


    #ifdef others
    Lista *lista = new Lista( "Lista 1" );
    Queue *cola = new Queue( "Cola 1" );
    Pila  *pila = new Pila( "Pila 1" );

    std::cout << lista->getNombre() << std::endl;
    for( int i=0; i<5; i++ ){ lista->addNode( new Node() ); }
    lista->showList();

    Game *game1 = new Game(
        "Gear of War",
        "accion",
        "AM406A",
        "America",
        59.99,
        100
    );

    Game *game2 = new Game(
        "Final Fantasy XX",
        "JRPG",
        "JA407J",
        "Japon",
        59.99,
        75
    );

    Game *game3 = new Game(
        "Civilization VI",
        "Turn Based Strategy",
        "AA406TBS",
        "America",
        59.99,
        50
    );

    cola->addNode( new Node1( game1 ) );
    cola->addNode( new Node1( game2 ) );
    cola->addNode( new Node1( game3 ) );

    std::cout << cola->getName() << std::endl;
    cola->showList();
    for( int i=0; i<2; i++ ){
        cola->deleteNode();
        cola->showList();
    }

    Node2 *nodo1 = new Node2( "Diana" );
    Node2 *nodo2 = new Node2( "Cesar" );
    Node2 *nodo3 = new Node2( "Joca" );
    Node2 *nodo4 = new Node2( "Sam" );
    Node2 *nodo5 = new Node2( "Tania" );
    Node2 *nodo6 = new Node2( "Erik" );
    Node2 *nodo7 = new Node2( "Efren" );

    pila->addNode( nodo7 );
    pila->addNode( nodo6 );
    pila->addNode( nodo5 );
    pila->addNode( nodo4 );
    pila->addNode( nodo3 );
    pila->addNode( nodo2 );
    pila->addNode( nodo1 );

    std::cout << pila->getNombre() << std::endl;
    pila->showStack();
    for(int j=0; j<6; j++){
        pila->deleteNode();
        pila->showStack();
    }
    #endif

    #ifdef binarytree
    BinaryTree *arbol = new BinaryTree( "Arbol 1" );

    arbol->addNode( new Node3( 20, "Diana" ), arbol->getRoot() );
    arbol->addNode( new Node3( 29, "Cesar" ), arbol->getRoot() );
    arbol->addNode( new Node3( 31, "Jocabed" ), arbol->getRoot() );
    arbol->addNode( new Node3( 21, "Samantha" ), arbol->getRoot() );
    arbol->addNode( new Node3( 23, "Efren" ), arbol->getRoot() );
    arbol->addNode( new Node3( 22, "Erik" ), arbol->getRoot() );
    arbol->addNode( new Node3( 19, "Tania" ), arbol->getRoot() );

    arbol->showTree( arbol->getRoot() );

    cout << "\n\nPre Orden: " << endl;
    arbol->preOrden( arbol->getRoot() );
    cout << "\n";
    cout << "En Orden" << endl;
    arbol->inOrden( arbol->getRoot() );
    cout << "\n";
    cout << "Pos Orden" << endl;  
    arbol->posOrden( arbol->getRoot() );

    cout << "\n\n";

    arbol->deleteNode( 29 ); 
    arbol->showTree( arbol->getRoot() );

    #endif


return 0;
}