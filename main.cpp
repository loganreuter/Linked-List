#include <iostream>
#include "LinkedLists.h"
using namespace std;

int main()
{
    LinkedList<int> list = LinkedList<int>(1);
    list.push(2); //adds node with value 1 to the beginning of the list
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.removeIndex(0);
    cout << "Length: " << list.length << endl;
    list.print();

    return 0;
}