/* 
    Day - 01 of learning Binary Tree by Shraddha Khapra from Apna College 
*/

// Building Binary Tree without using an extra BinaryTree Class same as C++ code
// I like this a little much rather than using an extra class

// public class BinaryTree_01 {
// Node class to represent each node in the binary tree
//     static class Node {
//         int data;
//         Node left;
//         Node right;
// Constructor to initialize the node with data and set left and right children to null
//         Node(int data) {
//             this.data = data;
//             left = right = null;
//         }
//     }

// 
// // Index to keep track of the current position in the array
//         static int index = -1;
// A recursive function to build the binary tree from an array representation
//         public static Node buildTree(int nodes[]) {
//             index++;
//             if (nodes[index] == -1) {
//                 return null;
//             }
//             Most Important Lines
//             Node newNode = new Node(nodes[index]);
//             newNode.left = buildTree(nodes);
//             newNode.right = buildTree(nodes);
//             return newNode;
//         }

 // Function to count the number of nodes in the binary tree
        public static int countNodes(Node root) {
            if (root == null) {
                return 0;
            }
            return countNodes(root.left) + countNodes(root.right) + 1;
        }
//     
// // Main function to test the binary tree construction
//     public static void main(String[] args) {
//         int nodes[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 }; // Array representation of the binary tree, where -1 indicates a null node
//     
//         Node root = buildTree(nodes); // Build the binary tree using the array representation
//         // Print the data of the root node
//         System.out.println(root.data);
           System.out.println(tree.countNodes(root));
//     }
// }








// Building Binary Tree using an extra BinaryTree Class as per the course
import java.util.*;
import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree_01 {
    // Node class to represent each node in the binary tree
    static class Node {
        int data;
        Node left;
        Node right;

        // Constructor to initialize the node with data and set left and right children to null
        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    // BinaryTree class to build and traverse the binary tree
    static class BinaryTree {
        static int index = -1; // Index to keep track of the current position in the array
        // A recursive function to build the binary tree from an array representation
        public static Node buildTree(int nodes[]) {
            index++;
            if (index >= nodes.length || nodes[index] == -1) {
                return null;
            }
            Node newNode = new Node(nodes[index]);
            newNode.left = buildTree(nodes);
            newNode.right = buildTree(nodes);
            return newNode;
        }

        // Pre-order Traversal of the Binary Tree
        public static void printBinaryTree(Node root) {
            if (root == null) {
                return;
            }
            System.out.print(root.data + " ");
            printBinaryTree(root.left);
            printBinaryTree(root.right);
        }

        // In-order Traversal of the Binary Tree
        public static void inOrder(Node root) {
            if (root == null) {
                return;
            }
            inOrder(root.left);
            System.out.print(root.data + " ");
            inOrder(root.right);
        }

        // Post-order Traversal of the Binary Tree
        public static void postOrder(Node root) {
            if (root == null) {
                return;
            }
            postOrder(root.left);
            postOrder(root.right);
            System.out.print(root.data + " ");
        }

        // Level-order Traversal of the Binary Tree
        public static void levelOrder(Node root) {
            if (root == null) {
                return;
            }
            Queue<Node> queue = new LinkedList<>();
            queue.add(root);
            queue.add(null);

            while (!queue.isEmpty()) {
                Node currNode = queue.remove();
                if (currNode == null) {
                    System.out.println();
                    if (!queue.isEmpty()) {
                        queue.add(null);
                    }
                } else {
                    System.out.print(currNode.data + " ");
                    if (currNode.left != null) {
                        queue.add(currNode.left);
                    }
                    if (currNode.right != null) {
                        queue.add(currNode.right);
                    }
                }
            }
        }


        // Function to find the height of the binary tree
        public static int height(Node root) {
            if (root == null) {
                return 0;
            }
            return Math.max(height(root.left), height(root.right)) + 1;
        }

        // Function to count the number of nodes in the binary tree
        public static int countNodes(Node root) {
            if (root == null) {
                return 0;
            }
            return countNodes(root.left) + countNodes(root.right) + 1;
        }

        // Function to find the sum of all nodes in the binary tree
        public static int sumOfNodes(Node root){
            if (root == null) {
                return 0; // Base case: if the node is null, return 0
            }
            int leftSum = sumOfNodes(root.left); // Sum of left subtree
            int rightSum = sumOfNodes(root.right); // Sum of right subtree
            int sum = leftSum + rightSum + root.data; // Sum of current node and its subtrees
            return sum; // Return the total sum
        } 


        // Function to find the maximum value in the binary tree
        public static int maximum(Node root) {
            if (root == null) {
                return Integer.MIN_VALUE; // Base case: if the node is null, return minimum integer value
            }
            int leftMax = maximum(root.left); // Maximum value in left subtree
            int rightMax = maximum(root.right); // Maximum value in right subtree
            return Math.max(root.data, Math.max(leftMax, rightMax)); // Return the maximum of current node and its subtrees
        }

    }

    public static void main(String[] args) {
        // Array representation of the binary tree, where -1 indicates a null node
        int nodes[] = {1, 2, 4, -1, -1, 52, -1, -1, 3, -1, 6, -1, -1};
         // Node a = new Node(1);
         //    Node b = new Node(2);
         //    Node c = new Node(3);
         //    Node d = new Node(4);
         //    Node e = new Node(5);
         //    Node f = new Node(6);
         //    Node g = new Node(7);
         //    Node h = new Node(8);
         //    Node i = new Node(9);
         //    Node j = new Node(10);
    
         //    a.left = b;
         //    a.right = c;
         //    b.left = d;
         //    b.right = e;
         //    c.left = f;
         //    c.right = g;
         //    d.left = h;
         //    d.right = i;
         //    e.left = j;
            

        BinaryTree tree = new BinaryTree(); // Create an instance of BinaryTree
        Node root = tree.buildTree(nodes); // Build the binary tree using the array representation

        // Perform and print different traversals
        System.out.println("Pre-order Traversal:");
        tree.printBinaryTree(root);
        System.out.println();

        System.out.println("In-order Traversal:");
        tree.inOrder(root);
        System.out.println();

        System.out.println("Post-order Traversal:");
        tree.postOrder(root);
        System.out.println();

        System.out.println("Level-order Traversal:");
        tree.levelOrder(root);

        System.out.println();
        System.out.println();
        System.out.println();

        System.out.println(tree.sumOfNodes(root));
        System.out.println(); // Print the sum of all nodes in the binary tree
        System.out.println(tree.countNodes(root));
        System.out.println(); // Print the number of nodes in the binary tree
        System.out.println(tree.height(root)); // Print the height of the binary tree
        System.out.println(); // Print the height of the binary tree
        System.out.println(tree.maximum(root)); // Print the maximum value in the binary tree

    }
}
