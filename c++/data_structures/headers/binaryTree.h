
#include <string>
#pragma once

class Node3{

    private:
        int ID;
        std::string name;
        Node3 *father;
        Node3 *left;
        Node3 *right;

    public:
        //constructor
        Node3( int ID, std::string );

        //setters and getters
        void setID( int );
        void setName( std::string );
        void setFather( Node3 *newNode );
        void setLeft( Node3 *newNode );
        void setRight( Node3 *newNode );

        int getID();
        std::string getName();
        Node3* getFather();
        Node3* getLeft();
        Node3* getRight();

        //general methods to the class or object
        void showNode();

};

class BinaryTree{

    private:
        std::string name;
        Node3 *root;

    public:
        
        //constructor
        BinaryTree( std::string name );

        //setter and getters
        void setName( std::string newName );
        void setRoot( Node3 *newNode );

        std::string getName();
        Node3* getRoot();

        //general methods to the class or object
        void addNode( Node3 *newNode, Node3 *current );
        Node3* searchNode( int ID, Node3 *current );
        void showTree( Node3 *current );
        void preOrden( Node3 *current );
        void inOrden( Node3 *current );
        void posOrden( Node3 *current );
        bool deleteNode( int );

};