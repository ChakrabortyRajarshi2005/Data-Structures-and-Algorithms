import java.util.HashMap;
public class Hashmap_01 {
    public static void main(String[] args) {
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        map.put("Alice", 25);
        map.put("Bob", 30); 
        map.put("Charlie", 35);
        map.put("Diana", 28);
        map.put("Eve", 22);
        map.put("Frank", 40);
        map.put("Grace", 32);

        System.out.println("Size of the map: " + map.size());
        System.out.println("Is the map empty? " + map.isEmpty());
        System.out.println("Map contents: " + map);
        System.out.println("Value for key 'Alice': " + map.get("Alice"));
        System.out.println("Value for key 'Bob': " + map.get("Bob"));

        map.remove("Charlie");
        System.out.println("Map after removing 'Charlie': " + map);
        System.out.println("Does the map contain key 'Diana'? " + map.containsKey("Diana"));
        System.out.println("Does the map contain value 40? " + map.containsValue(40));
        System.out.println("Keys in the map: " + map.keySet());
        System.out.println("Values in the map: " + map.values());
        System.out.println("Entries in the map: " + map.entrySet());
        map.clear();
        System.out.println("Map after clearing: " + map);
    }   
    
}




// Implementation of a simple HashMap example in Java
import java.util.*;
import java.util.LinkedList;
import java.util.HashMap;
import java.util.Map;
public class Hashmap_01 {
    static class HashMap<K, V> {
        // Node to store key-value pairs
        private class Node {
            K key;
            V value;
            public Node(K key, V value) {
                this.key = key;
                this.value = value;
            }
        }

        private int size; // number of key-value pairs
        private LinkedList<Node> arr[]; // buckets

        @SuppressWarnings("unchecked")
        public HashMap() {
            this.size = 0;
            this.arr = new LinkedList[4]; // initial bucket size
            for (int i = 0; i < arr.length; i++) {
                arr[i] = new LinkedList<>();
            }
        }
        // Hash function to get bucket index
        private int hashFunction(K key) {
            int hashCode = key.hashCode();
            return Math.abs(hashCode) % arr.length;
        }
        // Search for a node in a bucket
        private int searchInBucket(K key, LinkedList<Node> bucket) {
            for (int i = 0; i < bucket.size(); i++) {
                if (bucket.get(i).key.equals(key)) {
                    return i;
                }
            }
            return -1;
        }

        // Put method (insert or update)
        public void put(K key, V value) {
            int bi = hashFunction(key); // bucket index
            LinkedList<Node> bucket = arr[bi];
            int di = searchInBucket(key, bucket); // data index in bucket

            if (di != -1) {
                bucket.get(di).value = value; // update existing
            } else {
                bucket.add(new Node(key, value)); // insert new
                size++;
            }

            double loadFactor = (double) size / arr.length;
            if (loadFactor > 0.7) {
                rehash();
            }
        }

        // Rehashing - double bucket size and redistribute keys
        @SuppressWarnings("unchecked")
        private void rehash() {
            LinkedList<Node>[] oldArr = arr;
            arr = new LinkedList[oldArr.length * 2];
            size = 0; // reset size

            for (int i = 0; i < arr.length; i++) {
                arr[i] = new LinkedList<>();
            }

            for (LinkedList<Node> bucket : oldArr) {
                for (Node node : bucket) {
                    put(node.key, node.value);
                }
            }
        }

        // Get method
        public V get(K key) {
            int bi = hashFunction(key);
            LinkedList<Node> bucket = arr[bi];
            int di = searchInBucket(key, bucket);

            if (di != -1) {
                return bucket.get(di).value;
            }
            return null;
        }

        // Remove method
        public V remove(K key) {
            int bi = hashFunction(key);
            LinkedList<Node> bucket = arr[bi];
            int di = searchInBucket(key, bucket);

            if (di != -1) {
                V val = bucket.get(di).value;
                bucket.remove(di);
                size--;
                return val;
            }
            return null;
        }

        // Check if key exists
        public boolean containsKey(K key) {
            return get(key) != null;
        }

        // Check if map is empty
        public boolean isEmpty() {
            return size == 0;
        }

        // Return size
        public int size() {
            return size;
        }

        // Key set
        public ArrayList<K> keySet() {
            ArrayList<K> keys = new ArrayList<>();
            for (LinkedList<Node> bucket : arr) {
                for (Node node : bucket) {
                    keys.add(node.key);
                }
            }
            return keys;
        }
    }

    public static void main(String[] args) {
        HashMap<String, Integer> map = new HashMap<>();

        map.put("India", 140);
        map.put("China", 144);
        map.put("USA", 33);
        map.put("Nepal", 3);

        System.out.println("India: " + map.get("India"));
        System.out.println("Contains Nepal? " + map.containsKey("Nepal"));
        System.out.println("Removed USA: " + map.remove("USA"));
        System.out.println("USA after removal: " + map.get("USA"));
        System.out.println("Size: " + map.size());
        System.out.println("Keys: " + map.keySet());
    }
}
