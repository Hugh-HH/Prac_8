#ifndef NODE_H
#define NODE_H

class Node{

private:

    int data;
    Node* next;

public:

    Node();
    int get_data();
    void set_data(int info);
    Node* get_next();
    void set_Next(Node* info);
    
};
#endif