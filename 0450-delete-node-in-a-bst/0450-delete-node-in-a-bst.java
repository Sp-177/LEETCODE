public class Solution {
    public TreeNode extR(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode ext = root;
        while (ext.right != null) {
            ext = ext.right;
        }
        return ext;
    }

    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        }
        TreeNode node = root;
        while (node != null) {
            if (node.val == key || (node.left != null && node.left.val == key) || (node.right != null && node.right.val == key)) {
                if (node.val == key) {
                    root = (node.left != null ? node.left : node.right);
                    if (node.left != null) {
                        TreeNode ext = extR(node.left);
                        ext.right = node.right;
                    }
                    break;
                } else if (node.left != null && node.left.val == key) {
                    if (node.left.left != null) {
                        TreeNode ext = extR(node.left.left);
                        ext.right = node.left.right;
                        node.left = node.left.left;
                    } else {
                        node.left = node.left.right;
                    }
                    break;
                } else if (node.right != null && node.right.val == key) {
                    if (node.right.left != null) {
                        TreeNode ext = extR(node.right.left);
                        ext.right = node.right.right;
                        node.right = node.right.left;
                    } else {
                        node.right = node.right.right;
                    }
                    break;
                }
            } else if (node.val > key) {
                node = node.left;
            } else {
                node = node.right;
            }
        }
        return root;
    }
}