class Solution {
    public TreeNode sol(int[] inorder, int[] postorder, int start, int end, int ind_post) {
        if (start < end || start < 0 || end < 0 || ind_post < 0) {
            return null;
        }
        TreeNode root = new TreeNode();
        for (int i = start; i >= end; i--) {
            if (postorder[ind_post] == inorder[i]) {
                root.val = inorder[i];
                root.right = sol(inorder, postorder, start, i + 1, ind_post - 1);
                root.left = sol(inorder, postorder, i - 1, end, ind_post - (start - i) - 1);
                break;
            }
        }
        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return sol(inorder, postorder, inorder.length - 1, 0, postorder.length - 1);
    }
}