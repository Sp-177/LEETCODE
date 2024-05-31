class Node {
    public Node[] arr = new Node[10];
    public boolean end;

    public Node() {
        end = false;
        for (int i = 0; i < 10; i++) {
            arr[i] = null;
        }
    }

    public Node getNode(char c) {
        return arr[c - '0'];
    }
}

class Trie {
    public Node root;

    public Trie() {
        root = new Node();
    }

    public void insert(String s) {
        Node node = root;
        for (char i : s.toCharArray()) {
            if (node.getNode(i) == null) {
                Node new_node = new Node();
                node.arr[i - '0'] = new_node;
            }
            node = node.getNode(i);
        }
        node.end = true;
    }

    public int search(String s) {
        Node node = root;
        int len = 0;
        for (char i : s.toCharArray()) {
            if (node.getNode(i) == null) {
                return len;
            }
            node = node.getNode(i);
            len++;
        }
        return len;
    }
}

class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Trie obj = new Trie();
        for (int i : arr1) {
            obj.insert(Integer.toString(i));
        }
        int ans = 0;
        for (int i : arr2) {
            ans = Math.max(ans, obj.search(Integer.toString(i)));
        }
        return ans;
    }
}
