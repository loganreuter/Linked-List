using System;

namespace linkedlist
{
    class Program
    {
        static void Main(string[] args)
        {
            LinkedList<int> list = new LinkedList<int>();
            int[] array = {0, 1, 2, 3, 4, 5};
            list.fromArray(array);
            list.visualize();
        }
    }

    class LinkedList<T>
    {
        private class Node
        {
            public T data = default(T);
            public Node next = null;
            public Node(T info, Node nextNode){
                data = info;
                next = nextNode;
            }
        }
        private Node head = null;
        public int Length = 0;

        public LinkedList(T data = default(T)){
            head = new Node(data, null);
            if(data != null){
                Length++;
            }
            Console.WriteLine(Length);
        }
        public void append(T data){
            Node tmp = head;
            while(tmp.next != null){
                tmp = tmp.next;
            }
            tmp.next = new Node(data, null);
            Length++;
        }
        public void unshift(T data){
            Node tmp = head;
            head = new Node(data, tmp);
            Length++;
        }

        public T shift(){
            Node tmp = head;
            head = tmp.next;
            Length--;
            return tmp.data;
        }

        public void pop(){
            Node tmp = head;
            for(int i = 0; i < Length - 2; i++){
                tmp = tmp.next;
            }
            tmp.next = null;
        }

        public T[] toArray(){
            T[] array = new T[Length];
            Node tmp = head;
            for(int i = 0; i < Length; i++){
                array[i] = tmp.data;
                tmp = tmp.next;
            }
            return array;
        }

        /// <summary>method <c>fromArray</c> takes an array and converts it to a linked list. The array must be of the same type as the list</summary>
        public void fromArray(T[] array){
            
            int x;
            if(head.data == null){
                head = new Node(array[0], null);
                Length++;
                x = 1;
            } else {
                x = 0;
            }

            Node tmp = head;

            for(int i = x; i < array.Length; i++){
                tmp.next = new Node(array[i], null);
                tmp = tmp.next;
                Length++;
            }
        }

        public void print(){
            Node tmp = head;
            while(tmp != null){
                Console.WriteLine(tmp.data);
                tmp = tmp.next;
            }
            Console.WriteLine("-------------------------");
        }

        public void visualize(){
            Node tmp = head;
            while (tmp != null)
            {
                Console.Write(tmp.data);
                if(tmp.next != null){
                    Console.Write(" -> ");
                }
                tmp = tmp.next;
            }
            Console.WriteLine("");
        }
    }
}
