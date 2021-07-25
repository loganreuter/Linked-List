#include <iostream>
using namespace std;

template <typename T>
struct node{
    T data;
    node *next;
};

template <typename T>
class LinkedList{
    private:
        node<T>* head;
    public:
        int length = 0;
        LinkedList(T val){
            head = new node<T>;
            length++;
            head->data = val;
            head->next=NULL;
        }

        //Adds a new node to the beginning of the list.
        void push(T val){
            node<T>* newNode = new node<T>;
            newNode->data = val;
            newNode->next = head;
            head = newNode;
            length++;
        }

        //Adds a new node to the end of the list.
        void append(T val){
            node<T>* newNode = new node<T>;
            newNode->data = val;
            newNode->next = NULL;

            node<T>* tmp = head;
            while(tmp->next != NULL){
                tmp = tmp->next;
            };
            tmp->next = newNode;
            length++;
        }

        //Deletes all of the nodes with a specific value.
        //Currently an issue with removing back to back numbers.
        void removeAll(T val){
            node<T>* tmp = head;
            while(tmp != NULL){
                node<T>* next = tmp->next;
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
                length--;
                tmp = tmp->next;
            };
        }

        void remove(T val){
            node<T>* tmp = head;
            node<T>* next = tmp->next;
            while(next->data != val && next != NULL){
                tmp = next;
                next = tmp->next;
            }
            if(next != NULL){
                tmp->next = next->next;
            }
        }

        void removeIndex(int val){
            int i = 0;
            node<T>* tmp = head;
            node<T>* next = tmp->next;
            if(i == 0){
                head = tmp->next;
            } else {
                while(i < val && next != NULL){
                    tmp = next;
                    next = tmp->next;
                    i++;
                }
                if(next != NULL){
                    cout << "Current: " << tmp->data << ", " << "Next: " << next->data << endl; 
                    tmp->next = next->next;
                }
            }
        }

        //Prints all of the nodes of the current list.
        void print(){
           node<T>* tmp = head;
            while(tmp != NULL){
                cout << tmp->data << endl;
                tmp = tmp->next;
            }
        }
};