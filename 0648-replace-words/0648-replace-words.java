
class Node {
    Node[] arr;
    boolean isEnd;

    Node() {
        isEnd = false;
        arr = new Node[26];
    }

    boolean isthere(char c) {
        return arr[c - 'a'] != null;
    }

    Node give(char c) {
        return isthere(c) ? arr[c - 'a'] : null;
    }

    void put(Node node, char c) {
        arr[c - 'a'] = node;
    }
}

class Trie {
    Node root;

    Trie() {
        root = new Node();
    }

    void insert(String s) {
        Node node = root;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (node.isthere(c)) {
                node = node.give(c);
            } else {
                Node new_node = new Node();
                node.put(new_node, c);
                node = new_node;
            }
        }
        node.isEnd = true;
    }

    String search(String s) {
        Node node = root;
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (node.isthere(c)) {
                node = node.give(c);
                ans.append(c);
                if (node.isEnd) {
                    return ans.toString();
                }
            } else {
                return s;
            }
        }
        return ans.toString();
    }
}

public class Solution {
    public String replaceWords(List<String> dic, String sen) {
        Trie obj = new Trie();
        for (String i : dic) {
            obj.insert(i);
        }
        StringBuilder ans = new StringBuilder();
        String[] words = sen.split(" ");
        for (String word : words) {
            ans.append(obj.search(word)).append(" ");
        }
        return ans.toString().trim();
    }
}