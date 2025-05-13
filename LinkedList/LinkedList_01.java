//import java.util.*;
public class LinkedList_01{

     static class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    };

    static class LinkedList{
        Node head;
        int size;
        LinkedList(){
            this.head = null;
            this.size = 0;
        }

      public void insert(int data){
            Node newNode = new Node(data);
            if(head == null){
                head = newNode;
            } else {
                Node current = head;
                while(current.next != null){
                    current = current.next;
                }
                current.next = newNode;
            }
            size++;
            return;
        }

        public void delete(int data){
            if(head == null){
                return;
            }
            if(head.data == data){
                head = head.next;
                size--;
                return;
            }
            Node current = head;
            while(current.next != null && current.next.data != data){
                current = current.next;
            }
            if(current.next != null){
                current.next = current.next.next;
                size--;
            }
            return;
        }

      public void display(){
            Node current = head;
            while(current != null){
                System.out.print(current.data + " ");
                current = current.next;
            }
            System.out.println();
            return;
        }

        public int getSize(){
            return size;
        }

        public int mid (int getSize){
            Node current = head;
            for(int i = 0; i < getSize()/2; i++){
                current = current.next;
            }
            return current.data;
        }
        
    };
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insert(1);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        list.display();
        list.insert(1);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        list.display();
        list.delete(3);
        list.display();
        list.delete(1);
        list.display();
        list.delete(4);
        list.insert(1);
        list.insert(8);
        list.insert(3);
        list.insert(4);
        list.insert(1);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        list.display();

        list.getSize();
        System.out.println("Size of the list: " + list.getSize());
    list.mid(list.getSize());
        System.out.println("Middle of the list: " + list.mid(list.getSize()));
    }
}