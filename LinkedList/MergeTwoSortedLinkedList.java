// Basic Java Code to Merge two Sorted Linked Lists
import java.util.*;
public class Main {
    public static void main(String[] args) {

        LinkedList<Integer> l1 = new LinkedList<>();
        l1.add(1);
        l1.add(3);
        l1.add(5);

        LinkedList<Integer> l2 = new LinkedList<>();
        l2.add(2);
        l2.add(4);
        l2.add(6);

        System.out.println("Printing Original sorted linked lists:");
        System.out.println(l1);
        System.out.println(l2);

        ArrayList<Integer> list = new ArrayList<>();
        list.addAll(l1);
        list.addAll(l2);
        Collections.sort(list);

        LinkedList<Integer> linkedList = new LinkedList<>();
        linkedList.addAll(list);
        System.out.println("The merged linked list is:");
        System.out.println(linkedList);
    }
}
