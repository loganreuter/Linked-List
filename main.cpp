#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class LinkedList{
    private:
        node* head;
    public:
        LinkedList(int val){
            head = new node;
            head->data = val;
            head->next=NULL;
        }

        //Adds a new node to the beginning of the list.
        void push(int val){
            node* newNode = new node;
            newNode->data = val;
            newNode->next = head;
            head = newNode;
        }

        //Adds a new node to the end of the list.
        void append(int val){
            node* newNode = new node;
            newNode->data = val;
            newNode->next = NULL;

            node* tmp = head;
            while(tmp->next != NULL){
                tmp = tmp->next;
            };
            tmp->next = newNode;
        }

        //Deletes all of the nodes with a specific value.
        //Currently an issue with removing back to back numbers.
        void removeAll(int val){
            node* tmp = head;
            while(tmp != NULL){
                node* next = tmp->next;
                if(next != NULL)
                {
                    if(head->data == val){
                        head = head->next;
                    }
                    if (next->data == val)
                    {
                        tmp->next = next->next;
                    };
                }
                tmp = tmp->next;
            };
        }

        //Prints all of the nodes of the current list.
        void print(){
           node* tmp = head;
            while(tmp != NULL){
                cout << tmp->data << endl;
                tmp = tmp->next;
            }
        }
};

int main(){
    LinkedList list = LinkedList(0);
    list.push(1); //adds node with value 1 to the beginning of the list
    list.append(1);
    list.append(1);
    list.append(1);
    list.append(1);
    list.append(0);
    list.append(2);
    list.push(5);
    list.print();
    cout << "----" << endl;
    list.removeAll(1);
    list.print();
    return 0;
}