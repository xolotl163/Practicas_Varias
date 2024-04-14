
#include <string>
#pragma once

class Game{

    private:
        std::string name;
        std::string genere;
        std::string ID;
        std::string region;
        float cost;
        int unitsStock;

    public:

        //constructor
        Game(std::string name, std::string genere, std::string ID, std::string region, float cost, int unitsStock);

        //setters and getters
        void setName( std::string newName );
        void setGenere( std::string newGenere );
        void setID( std::string newID );
        void setRegion( std::string newRegion );
        void setCost( float newCost );
        void setUnitsStock( int newUnitsStock );

        std::string getName();
        std::string getGenere();
        std::string getID();
        std::string getRegion();
        float getCost();
        int getUnitsStock();

        //general methods to the class or object
        void printGame();

};

class Node1{

    private:
        Game *game;
        Node1 *next;
        Node1 *prev;
              
    public:
        //constructor
        Node1( Game *game );

        //setters y getters
        void setGame( Game *newGame );
        void setNext( Node1 *newNext );
        void setPrev( Node1 *newPrev );

        Game* getGame();
        Node1* getNext();
        Node1* gettPrev();

};

class Queue{

    private:
        std::string name;
        Node1 *first;
        Node1 *last;

    public:
        //constructor
        Queue( std::string name );

        //getters y setters
        void setName( std::string newName );
        void setFirst( Node1 *newNode );
        void setLast( Node1 *newNode );

        std::string getName();
        Node1* getFirst();
        Node1* getLast();

        //general methods to the class or object
        void addNode( Node1 *newNode );
        int deleteNode( );
        void showList();

};