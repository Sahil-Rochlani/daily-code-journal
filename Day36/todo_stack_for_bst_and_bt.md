Here’s a list of must-know interview patterns and tricks involving stacks when dealing with trees and BSTs:

✅ 1. Iterative Tree Traversals (Inorder, Preorder, Postorder)
Using a stack instead of recursion:

Inorder: Left → Root → Right (explained above)

Preorder: Root → Left → Right
→ push root, then push right, then left

Postorder: Left → Right → Root
→ trickier, often uses two stacks or reverse preorder

You should practice all three iteratively.

✅ 2. Simultaneous Inorder Traversal (Two BST Merge)
As you’re working on:
Use two stacks to simulate two inorder traversals at once and merge them.

✅ 3. Flatten Binary Tree to Linked List (Leetcode 114)
This is basically preorder traversal, done with a stack and pointer rewiring.
👉 Convert tree into a "right-skewed" list in-place using stack.

✅ 4. Valid BST Iterator (Leetcode 173)
Design a class that uses a stack internally to do lazy inorder traversal:

cpp
Copy
Edit
BSTIterator it(root);
it.next(); it.hasNext();
You're expected to manage the stack manually and return elements one-by-one in sorted order (inorder).

✅ 5. Postorder Using One Stack
A famous interview follow-up is:
👉 "Can you do postorder traversal with just one stack?"

This requires tracking the last visited node and carefully controlling when to push or pop.

✅ 6. Recover BST (Leetcode 99)
Two nodes in a BST are swapped by mistake.
Inorder should be sorted — use inorder + stack to spot the two misplaced nodes and recover them.

✅ 7. Morris Traversal (Advanced, O(1) space)
Not stack-based, but a follow-up to iterative traversal questions.
It threads the tree temporarily to avoid recursion/stack and uses O(1) space.

✅ 8. Next Greater Element in Tree
Some problems ask you to find the next greater node for each node — similar to next greater element in array, but now with tree structure — and stack-based logic is reused.

