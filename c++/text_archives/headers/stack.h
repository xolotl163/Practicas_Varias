
#include <string>
using namespace std;
#pragma once

class Node2{

    private:
        string nombre;
        Node2 *up;
        Node2 *down;

    public:
        
        //constructor
        Node2( string name );

        //setters y getters
        void setNombre( string newName );
        void setUp( Node2 *newNode );
        void setDown( Node2 *newNode );

        string getNombre();
        Node2* getUp();
        Node2* getDown();

};

class Pila{

    private:
        string nombre;
        Node2 *bottom;
        Node2 *top;

    public:

        //constructor
        Pila( string nombre );

        //setters y getters
        void setNombre( string newName );
        void setBottom( Node2 *newNode );
        void setTop( Node2 *newNode );

        string getNombre();
        Node2* getBottom();
        Node2* getTop();

        //metodos generales a la clase u objeto
        void addNode( Node2* newNode );
        void deleteNode();
        void showStack();

};