

#include <string>
#pragma once

class Node{

    private:
        
        int ID;
        std::string nombre;
        Node *next;  
        Node *prev;

    public:

        //constructor        
        Node( std::string );

        //setters y getters
        void setID   ( int newID );
        void setNombre( std::string nombre );
        void setNext ( Node *newNext );
        void setPrev ( Node *newPrev );

        int getID();
        Node* getNext();
        Node* getPrev();
        std::string getNombre();

        //general methods to the class or object

};

class Lista{

    private:
        std::string nombre;
        int size;
        Node *first;
        Node *last;

    public:

        //constructor
        Lista( std::string nombre );

        //setters y getters
        void setNombre ( std::string newName );
        void setFirst ( Node *newFirst );
        void setLast ( Node *newLast );
        void setSize ( int newSize );

        std::string getNombre();
        Node* getFirst();
        Node* getLast();
        int getSize();

        //general methods to the class or object
        void showList();
        void addNode( Node *newNode );
        void deleteNode( int ID );
        Node* searchNode( int ID );

};