#include "Node.h"
#include "LinkedList.h"
#include <iostream>
#include <limits>


LinkedList::LinkedList() {
    head = nullptr; 
}

LinkedList::LinkedList(int* arr, int size) {
    head = nullptr; 
    for(int i = size-1; i >= 0; i--) {
        LinkedList::addFront(arr[i]);
    }

}

void LinkedList::addFront(int newItem) { 
    Node* newNode = new Node();
    newNode->set_data(newItem);
    newNode->set_Next(head);
    head = newNode;
}


void LinkedList::addEnd(int newItem) {
    Node* newNode = new Node();
    newNode->set_data(newItem);

    Node* temp = head;

    while(temp->get_next() != NULL) {
        temp = temp->get_next();
    }

    temp->set_Next(newNode);
}

void LinkedList::addAtPosition(int position, int newItem) {

    Node* newNode = new Node();
    newNode->set_data(newItem);

    Node* temp = head;

    if(position <1 || head == NULL) {
        LinkedList::addFront(newItem);
        return;
    }

    for (int i = 1; i < position -1; i++) {
        if(temp->get_next() == NULL) {
            break;
        }
        temp = temp->get_next();
    }   

    newNode->set_Next(temp->get_next());
    temp->set_Next(newNode);

}
int LinkedList::search(int item) {

    if(head == NULL) {

        std::cout << "0 ";

        return 0;
    }

    int position = 1;
    Node* temp = head;

    while(temp != NULL) {

        if(temp->get_data() == item) {
           std::cout << position << " ";
            return position;
        }

        position++;
        temp = temp->get_next();
    }
    std::cout <<"0 ";
    return 0;
}

void LinkedList::deleteFront() {
    Node* temp = new Node();
    temp = head;
    head = head->get_next();
    delete temp;
}

void LinkedList::deleteEnd() {
    Node* temp = head;

    while((temp ->get_next())->get_next()) {
        temp = temp->get_next();
    }

    delete temp->get_next();
    temp->set_Next(NULL);
}


void LinkedList::deletePosition(int position) {
     
    if(position < 1 || head == NULL) {
         
        std::cout <<"outside range!!" <<std::endl;
    }

    Node* current_node = head;
    Node* previous = current_node;

    for(int i = 1; i < (position-1); i++) {

        previous = current_node;
        current_node = current_node->get_next();
    }

    previous= current_node->get_next();
    current_node->set_Next(previous->get_next());

    delete previous;

}

int LinkedList::getItem(int position) {
    Node* temp = head;  
    
    if(head == NULL) {
        std::cout <<std::numeric_limits < int >::max() << " ";
        return std::numeric_limits< int >::max();
    }

    for(int i = 1; i < position; i++) {   
        if((temp->get_next()) == NULL) {

                std::cout <<std::numeric_limits < int >::max() << " ";
                return std::numeric_limits< int >::max();
            } 

        temp= temp->get_next();
    }
    std::cout << temp->get_data() << " ";

    return temp->get_data();

}

void LinkedList::printItems() {

Node* temp = head; 
    while(temp != NULL) {
    
    if (temp->get_data() < 100 || temp->get_data() > 100) {
    std::cout << temp->get_data() << " ";
    }
    temp = temp->get_next();

    } 

    std::cout << std::endl;
}

LinkedList::~LinkedList() {}
