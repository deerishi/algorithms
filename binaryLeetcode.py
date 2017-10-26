# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        if !root or root==p or root==q:
            return root
        TreeNode left=self.lowestCommonAncestor(root->left,p,q);

        TreeNode right=self.lowestCommonAncestor(root->right,p,q);
        return right if !left else (left if !right else root)
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
