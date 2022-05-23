#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>
using namespace std;

int main() {

int arr[100];
int temp;
int i = 0; 

while (cin >> temp){
    arr[i]= temp;
    i++;
}

cin.clear();

string str;

int input1, input2;
cin >> str;
cin >> input1 >> input2;


LinkedList List_one(arr, i);

if(str == "AF") {

    List_one.addFront(input1);
}
else if (str == "AE") {

    List_one.addEnd(input1);
}
else if(str == "AP"){

    List_one.addAtPosition(input1, input2);
}
else if(str == "S") {

    List_one.search(input1);
}

else if(str == "DF") {

    List_one.deleteFront();
}

else if(str == "DE") {

    List_one.deleteEnd();
}

else if(str == "DP") {

    List_one.deletePosition(input1);
}

else{
    
    List_one.getItem(input1);
}

List_one.printItems();

}