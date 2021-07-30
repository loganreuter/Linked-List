using System;

namespace linkedlist
{
    class Program
    {
        static void Main(string[] args)
        {
            LinkedList list = new LinkedList("A");
            list.append(1);
            list.print();
        }
    }

    class LinkedList
    {
        private class Node
        {
            public object data = null;
            public Node next = null;
            public Node(object info, Node nextNode){
                data = info;
                next = nextNode;
            }
        }
        private Node head = null;

        public LinkedList(object data){
            head = new Node(data, null);
        }
        public void append(object data){
            head.next = new Node(data, null);
        }

        public void print(){
            Node tmp = head;
            while(tmp != null){
                Console.WriteLine(tmp.data);
                tmp = tmp.next;
            }

        }
    }
}
