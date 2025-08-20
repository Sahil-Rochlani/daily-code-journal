### 📜 Day 43 – August 20, 2025

---

#### ✅ Questions Practiced:

1. **Longest Common Subsequence (LCS)**
   - **Topic**: DP / String / Subsequence  
   - **Approach**:  
     - **Recursion**: Compare `text1[i]` and `text2[j]`, add 1 if equal; else take max of advancing either pointer.  
     - **Memoization**: Store `dp[i][j]` to avoid recomputation.  
     - **Tabulation**: Bottom-up DP over `i` and `j`.  
     - **Space Optimization #1**: Use two 1D arrays (`curr` and `next`).  
     - **Space Optimization #2**: Further reduce to one 1D array using `prevDiagonal`.  
   - **Complexity**:  
     - Recursion: Exponential  
     - DP / Tabulation: `O(n*m)` time, `O(n*m)` space  
     - Space Optimized: `O(n*m)` time, `O(min(n,m))` space  
   - **Status**: ✅ Completed all approaches first try  
   - **Learning**: Solidified understanding of **string DP patterns** and **space optimization tricks**.

2. **Unique Binary Search Trees (NumTrees / Catalan Number)**  
   - **Topic**: DP / Combinatorics / BST counting  
   - **Approach**:  
     - **Recursion**: Pick each `i` as root → left count * right count → sum.  
     - **Memoization**: Store `dp[s][e]` to avoid recomputation.  
     - **Tabulation #1**: Bottom-up, fill `dp[s][e]` using start index.  
     - **Tabulation #2**: Bottom-up by interval length.  
   - **Complexity**:  
     - Recursion: Exponential  
     - DP / Tabulation: `O(n^3)` time, `O(n^2)` space  
   - **Status**: ✅ Completed all approaches first try  
   - **Learning**: Interval DP counting patterns; saw relation to **Catalan numbers**.

3. **Longest Palindromic Subsequence (LPS)**  
   - **Topic**: DP / String / Palindromes  
   - **Approach**:  
     - **Recursion / Interval DP**: Treat substring `[i..j]` as a state. If `s[i] == s[j]`, include both and recurse inward; else take max of skipping either end.  
     - **Memoization**: Store `dp[i][j]` to avoid recomputation.  
     - **Tabulation**: Bottom-up DP filling smaller intervals first.  
     - **Space Optimization #1**: Two 1D arrays (`curr`, `next`).  
     - **Space Optimization #2**: One 1D array with `diagonal` variable.  
   - **Complexity**:  
     - Recursion: Exponential  
     - DP / Tabulation: `O(n^2)` time, `O(n^2)` space  
     - Space Optimized: `O(n^2)` time, `O(n)` space  
   - **Status**: ✅ Completed all approaches first try  
   - **Learning**: Fully understood recursion → memoization → tabulation → space optimization flow; boosted confidence in interval/string DP.  

---

#### 🧠 Reflection / Notes:

- Today was **insanely productive**: 3 major DP problems, all multiple approaches, **first try completion**.  
- Key patterns:  
  - Recursion → Memoization → Tabulation → Space Optimization is a repeatable flow.  
  - Interval DP (LPS, NumTrees) and 2-string DP (LCS) share structural similarities.  
  - Space optimization often boils down to **storing only what’s immediately needed**.  
- **Intuition for interval DP (“shrinking inwards”)**:  
  - Treat each substring `[i..j]` as a state.  
  - If the ends match, include both and recurse inward; otherwise, pick the best by skipping either end.  
  - This systematically checks all possibilities and naturally leads to memoization/tabulation.  
- Feeling confident tackling **more complex string/interval/tree DP problems** next.

---

### 📜 Day 42 – August 18, 2025

---

#### ✅ Questions Practiced:

1. **Guess Number Higher or Lower II**
   - **Topic**: Interval DP / Minimax
   - **Approach**:
     - Started with a **midpoint assumption** → realized it fails when multiple pivots matter.
     - Recursion: try **all possible pivots `[s..e]`** → compute `max(costLeft, costRight)` → take `min`.
     - Memoization: store computed intervals to avoid recomputation.
     - Tabulation: bottom-up, fill smaller intervals first to satisfy dependencies.
   - **Complexity**:
     - Recursion: exponential
     - Memoization / DP: `O(n^3)`
   - **Status**: ✅ Working
   - **Learning**: Understanding that **all splits must be considered**, not just midpoint; interval DP and min-max reasoning; filling DP table bottom-up ensures dependencies are solved first.

2. **Minimum Cost Tree From Leaf Values**
   - **Topic**: Interval DP / Tree merge
   - **Approach**:
     - Precompute **maxVal[s][e]** for every interval `[s..e]`.
     - Recursion: for each split, cost = `max(left interval) * max(right interval) + leftCost + rightCost`.
     - Memoization to store subinterval results.
     - Tabulation: bottom-up over interval length → fill smaller intervals first.
   - **Complexity**:
     - Recursion: exponential
     - DP / Tabulation: `O(n^3)`
   - **Status**: ✅ Working
   - **Learning**: Realized why **interval max is needed**, not just merging adjacent elements; top-down recursion captures left/right merges correctly; bottom-up tabulation reinforces dependencies.

---

#### 🧠 Reflection / Notes:

- These two problems were **mentally heavy**, requiring deep interval DP and min-max reasoning.
- Biggest gains:
  - Stronger intuition for **interval-based DP**.
  - Clear understanding of **top-down recursion vs bottom-up tabulation**.
  - Learned the importance of **tracking aggregate info per interval** (like max leaf values) for tree merge problems.
- Even though I got very close initially, **nudges were needed to spot full interval handling**, which highlighted the subtle edge cases and merge logic.


### 📜 Day 41 – August 17, 2025

---

#### ✅ Questions Practiced:

1. **Painting Fence (k colors, no two adjacent same)**
   - **Topic**: Dynamic Programming / Recursion & Optimization
   - **Approach**:
     - Implemented in:
       - Recursion
       - Memoization (top-down)
       - Tabulation (bottom-up)
       - Space Optimization (2 variables)
     - Extended logic to **at most k consecutive pillars**.
   - **Complexity**:
     - Recursion: exponential
     - DP: `O(n)`
   - **Status**: ✅ Working
   - **Learning**: Recognized the pattern of “same vs different last color” and how to generalize it; mastered stepwise DP optimization.

2. **0/1 Knapsack**
   - **Topic**: Dynamic Programming / Optimization
   - **Approach**:
     - Implemented in:
       - Recursion
       - Memoization
       - Tabulation
       - Space-Optimized 1D
     - Carefully handled **reverse iteration** for 1D optimization.
   - **Complexity**:
     - Recursion: `O(2^n)`
     - DP: `O(n*W)`
     - Space-Optimized: `O(W)`
   - **Status**: ✅ Working
   - **Learning**: Gained full clarity on 2D → 1D space optimization; understood why reverse iteration is necessary.

3. **Longest Increasing Subsequence (DP tabulation)**
   - **Topic**: DP / LIS
   - **Approach**:
     - Started from recursion → memoization → tabulation
     - Built a 2D `dp[i][prev_index]` table.
   - **Complexity**: `O(n^2)`
   - **Status**: ✅ Working
   - **Learning**: Learned how tabulation fills from smaller subproblems up, and how dependencies map to `i+1` row; able to optimize to 1D in simple LIS variants.

4. **Number of Dice Rolls to Target (n dice, k faces)**
   - **Topic**: DP / Counting / Space Optimization
   - **Approach**:
     - 2D DP (`dp[i][target]`) → 1D DP (`prev` + `curr`) → single 1D vector
     - Applied **backwards iteration** in 1D to prevent overwriting.
   - **Complexity**: `O(n*target*k)`
   - **Status**: ✅ Working
   - **Learning**: Understood table boundaries; mastered progression from tabulation → 1D space optimization.

5. **Partition Equal Subset Sum**
   - **Topic**: DP / Subset Sum / Space Optimization
   - **Approach**:
     - Recursion → Memoization → Tabulation → 2D → 1D space optimization
     - Handled `sum == 0` without extra initialization loop using inline check
     - Single 1D array optimized with **reverse iteration**.
   - **Complexity**: `O(n*sum)`
   - **Status**: ✅ Working
   - **Learning**: Fully internalized DP transitions and space optimization tricks; flexibility in handling base cases inline.

---

#### 🧠 Reflection / Notes:

- Today was a **DP masterclass session**: recursion → memoization → tabulation → 1D / 2D space optimization for **5 different problems**.
- Biggest gains:
  - Visualizing **dependencies in DP tables**
  - Confidently doing **2D → 1D → 1D single vector** optimizations
  - Generalizing patterns (Painting Fence → k consecutive colors)
- Feeling **much more comfortable with boundaries, base cases, and optimization order**.

---

### 📜 Day 40 – August 12, 2025

---

#### ✅ Questions Practiced:

1. **Minimum Time to Infect a Tree**
   - **Topic**: Binary Tree / DFS
   - **Approach**:
     - Recursive DFS returning depth and distance from start node.
     - Used distances from subtrees to compute infection time.
   - **Complexity**: `O(N)`
   - **Status**: ✅ Working
   - **Learning**: Understanding how to propagate time across branches sharpened my tree recursion logic.

2. **Find Duplicate Subtrees**
   - **Topic**: Binary Tree / Hashing
   - **Approach**:
     - Serialized subtrees into strings.
     - Used hashmap to track frequency.
     - Collected roots when frequency reached 2.
   - **Complexity**: `O(N^2)` (string concat) → optimized with hashing.
   - **Status**: ✅ Working
   - **Learning**: Serialization + hashing is a powerful combo for subtree identification.

3. **Fibonacci Number**
   - **Topic**: Dynamic Programming
   - **Approach**:
     - Implemented in:
       - Recursion
       - Memoization
       - Tabulation
       - Space Optimization
   - **Complexity**:
     - Recursion: `O(2^N)`
     - Memoization / Tabulation / Space Optimized: `O(N)`
   - **Status**: ✅ Working
   - **Learning**: Moving from recursion to space optimization clarified the step-by-step DP optimization flow.

4. **Climbing Stairs**
   - **Topic**: Dynamic Programming
   - **Approach**:
     - Implemented in:
       - Recursion
       - Memoization
       - Tabulation
       - Space Optimization
   - **Complexity**:
     - Recursion: `O(2^N)`
     - Memoization / Tabulation / Space Optimized: `O(N)`
   - **Status**: ✅ Working
   - **Learning**: Recognized the direct mapping to Fibonacci logic — same recurrence, different story.

5. **House Robber**
   - **Topic**: Dynamic Programming
   - **Approach**:
     - Implemented in:
       - Recursion
       - Memoization
       - Tabulation
       - Space Optimization
     - In memoization, initialized `dp` with `-1` since `0` is a valid result.
   - **Complexity**:
     - Recursion: `O(2^N)`
     - Memoization / Tabulation / Space Optimized: `O(N)`
   - **Status**: ✅ Working
   - **Learning**: Always choose a sentinel value that can’t be a valid output — using `0` caused wrong results until I switched to `-1`.

6. **Frog Jump (1D DP)(Also Generalized it for k jumps)**
   - **Topic**: Dynamic Programming
   - **Approach**:
     - Implemented in:
       - Recursion
       - Memoization
       - Tabulation
       - Space Optimization
     - Jump cost based on height difference; choices of jumping 1 or 2 steps.
   - **Complexity**:
     - Recursion: Exponential  
     - Memoization / Tabulation / Space Optimized: `O(N)`
   - **Status**: ✅ Working
   - **Learning**: The space-optimized approach condenses the DP array into two variables — a neat trick that boosts efficiency and sharpens understanding of DP state dependencies.

   7. **Coin Change (Minimum Coins)**
   - **Topic**: Dynamic Programming / Tabulation
   - **Approach**:
     - Bottom-up DP building from amount 0 to target amount.
     - For each amount, tries all coin options and takes minimum.
   - **Complexity**: `O(amount * number_of_coins)`
   - **Status**: ✅ Working (tabulation)
   - **Learning**: Tabulation provides a clear iterative pattern that’s often easier to debug and optimize than recursion.


---

#### 🛠 Bugs & Fixes:

1. **Memoization Sentinel Value Pitfall**  
   - Bug: Used `0` as "uncomputed" marker in House Robber’s `dp`, but `0` is a valid answer.  
   - Fix: Changed to `-1` so I can differentiate between "uncomputed" and actual `0`.

---

#### 🔥 Summary:

**Day 40 — Kickstarted DP track after finishing some solid binary tree problems.  
Felt great to implement multiple approaches (recursion → space optimization) for DP basics.  
Strong groundwork for tougher DP problems ahead.**


### 📜 Day 40 – August 12, 2025

---

#### ✅ Questions Practiced:

1. **Minimum Time to Infect a Tree**
   - **Topic**: Binary Tree / DFS
   - **Approach**:
     - Recursive DFS returning depth and distance from start node.
     - Used distances from subtrees to compute infection time.
   - **Complexity**: `O(N)`
   - **Status**: ✅ Working
   - **Learning**: Understanding how to propagate time across branches sharpened my tree recursion logic.

2. **Find Duplicate Subtrees**
   - **Topic**: Binary Tree / Hashing
   - **Approach**:
     - Serialized subtrees into strings.
     - Used hashmap to track frequency.
     - Collected roots when frequency reached 2.
   - **Complexity**: `O(N^2)` (string concat) → optimized with hashing.
   - **Status**: ✅ Working
   - **Learning**: Serialization + hashing is a powerful combo for subtree identification.

3. **Fibonacci Number**
   - **Topic**: Dynamic Programming
   - **Approach**:
     - Implemented in:
       - Recursion
       - Memoization
       - Tabulation
       - Space Optimization
   - **Complexity**:
     - Recursion: `O(2^N)`
     - Memoization / Tabulation / Space Optimized: `O(N)`
   - **Status**: ✅ Working
   - **Learning**: Moving from recursion to space optimization clarified the step-by-step DP optimization flow.

4. **Climbing Stairs**
   - **Topic**: Dynamic Programming
   - **Approach**:
     - Implemented in:
       - Recursion
       - Memoization
       - Tabulation
       - Space Optimization
   - **Complexity**:
     - Recursion: `O(2^N)`
     - Memoization / Tabulation / Space Optimized: `O(N)`
   - **Status**: ✅ Working
   - **Learning**: Recognized the direct mapping to Fibonacci logic — same recurrence, different story.

---

#### 🔥 Summary:

**Day 40 — Kickstarted DP track after finishing some solid binary tree problems.  
Felt great to implement multiple approaches (recursion → space optimization) for DP basics.  
Strong groundwork for tougher DP problems ahead.**

---

### 📜 Day 39 Log – August 5, 2025

---

#### ✅ Questions Practiced:

1. **Binary Tree Cameras**  
   - Learned to apply **greedy DFS with 3 states**:
     - `0` → Has a camera  
     - `1` → Covered (no camera)  
     - `2` → Not covered  
   - If any child is `2` → place camera at current node  
   - If any child is `0` → current node is covered  
   - If both children are `1` → current node is not covered  
   - Place an extra camera at root if needed  
   - Core Greedy Insight:  
     > Place a camera only when necessary. Let parent cover the node if both children are already covered.

---

#### 🧠 Key Takeaway:
Greedy + DFS state representation in trees is a powerful technique. Think in **states** not just positions.

---

#### ⏭️ Next Up:
Continue more Leetcode Tree Mediums + revisit a few core greedy patterns.

---




### 📜 Day 38 – August 4, 2025

---

#### ✅ Questions Practiced:

1. **Merge K Sorted Arrays**
   - **Topic**: Heaps / Priority Queue
   - **Approach**:
     - Used min-heap with custom `Info` class.
     - Tracked value, row, and column for each element.
     - Inserted the first element of each array into the heap.
     - Extracted the smallest and inserted the next from the same row.
   - **Fix Noted**: Made comparator's `operator()` public to avoid compilation error.
   - **Complexity**: `O(N log K)`
   - **Status**: ✅ Working

2. **Merge K Sorted Linked Lists**
   - **Topic**: Heaps / Linked List
   - **Approach**:
     - Min-heap storing pointers to current heads.
     - Maintained a running merged list by popping smallest and pushing its `next`.
   - **Edge Handling**: Checked for nulls and linked nodes in-place.
   - **Complexity**: `O(N log K)`
   - **Status**: ✅ Working

3. **Smallest Range Covering K Lists**
   - **Topic**: Heaps / Sliding Window
   - **Approach**:
     - Min-heap for smallest element, tracked max manually.
     - Updated range `[min, max]` at each step.
     - Pushed next element from same row into heap.
   - **Complexity**: `O(N log K)`
   - **Status**: ✅ Working
   - **Note**: Had a minor logic typo — `(ansMax - ansMax)` should be `(ansMax - ansMin)`.

4. **Median from Data Stream**
   - **Topic**: Heaps / Two Heaps
   - **Approach**:
     - Used maxHeap (lower half) and minHeap (upper half).
     - Maintained balance between heaps after every insertion.
     - `findMedian()` calculated based on size balance.
   - **Complexity**: `addNum: O(log N)`, `findMedian: O(1)`
   - **Status**: ✅ Working

---

#### 🔥 Summary:

**Insane day. All 4 problems were heap-based but each with unique patterns.  
From multi-way merges to real-time medians — built deep intuition today.  
Definitely need a revision cycle.**

---

### 📜 Day 37 Log – August 3, 2025

---

#### ✅ Questions Practiced:

1. **Convert BST to a Balanced BST**
   - Learned to convert an unbalanced BST into a height-balanced BST by:
     - Inorder traversal to get sorted elements
     - Recursively building the balanced BST using middle elements
   - Implemented both recursive and iterative approaches.
   - Understood why BSTs are used: efficient search + insert (O(log n) average).

2. **Least Greater Element on the Right**
   - Solved using a `set` as a BST:
     - Traversed array from right to left.
     - Used `upper_bound` to find least greater element.
     - Inserted each element in the BST (`set`) while moving backward.
   - Time: O(n log n), Space: O(n)
   - Clean, efficient, and standard approach.

3. **Insert & Search in BST with Successor Tracking**
   - Built a function to:
     - Search in BST
     - Insert if not found
     - Track inorder successor during insertion
   - Key lesson: using references (`int& ans`) to return extra info from functions.
   - Also spotted and fixed a bug: loop condition was `while (!curr)` instead of `while (curr)`.

4. **Minimum Difference in BST**
   - Used **inorder traversal** for accessing sorted values.
   - Tracked previous node to compute differences.
   - Maintained minimum difference using `mini`.

5. **Recover Binary Search Tree**
   - Detected violation of BST order during inorder traversal.
   - Captured `first` and `second` misplaced nodes.
   - Swapped their values to restore BST.
   - Understood both **adjacent** and **non-adjacent** swap cases.

---

#### 💪 Notes:
- All 5 questions done with focus despite health issues.
- Balanced efficiency and correctness.
- Didn't overpush beyond capacity; gave 1-hour rest between sessions.
- Executed with clarity and intention.

---

#### 🎯 Next Up (Plan):
- Complete 3 pending Binary Tree problems from pre-intern phase.
- Dive deep into **Morris Traversal** (threaded tree traversal).
- Revise:
  - 🔁 Binary Tree patterns
  - 📚 BST problems (all key techniques)

---

Tight execution today, Sahil. You’re stitching concepts together like a true problem solver. Let’s close out trees strong. 🌳🔥



### 📜 Day 36 Log – August 2, 2025

### 🧠 Topics Covered:
- ✅ **BST Validation Techniques**:
  - Top-down approach using `min` and `max` bounds (`isValidBST` with `leftMax` and `rightMin`)
  - Inorder traversal validation (checking strictly increasing order using a reference variable)
- ✅ Compared and understood the three core BST validation strategies:
  1. Top-down bounds passing
  2. Bottom-up postorder info return (recall from `Max Sum BST`)
  3. Inorder traversal increasing property
- 🧠 Understood deeper BST intuition through traversal-based and value-bound reasoning

---

### ✅ Questions Practiced:

1. **Validate Binary Search Tree**
   - Implemented using:
     - Bounds-check method (top-down recursion with limits)
     - Inorder traversal method (sorted property using `prev` reference)

2. **Construct BST from Preorder Traversal**
   - Completed to build foundational understanding before validation
   - 🧠 **Insight**: Understood why the **inorder trick doesn't work here** —  
     Preorder traversal is **unique for BSTs** because the first element is always the root,  
     and subsequent elements naturally divide into left and right subtrees based on value boundaries.  
     Unlike inorder which is sorted and ambiguous, preorder directly encodes tree structure.

---

### 💭 Reflection:
> The bottom-up approach felt instinctive after solving `Max Sum BST in Binary Tree`.  
> Today’s validation problem helped me internalize the rules and traversal-based reasoning for BSTs.  
> I now feel confident in approaching BST-related problems using multiple methods.  
> Also loved realizing **why preorder allows unique BST construction** while inorder does not.

---

### 🌞 Afternoon Session – August 2, 2025

### ✅ Q1. Can Represent BST from Preorder Traversal

#### 🔹 Approaches Covered:

1. **My Approach (Recursive Bound Checking):**
   - Maintain an index `i` to track current node in preorder traversal.
   - Use `min` and `max` bounds to validate BST properties.
   - At each step:
     - If `preorder[i] <= min` or `>= max`, return false.
     - Otherwise, take `preorder[i]` as root and increment `i`.
     - Recur for left and right subtrees with updated bounds.
   - Finally, if `i == preorder.size()`, the preorder is a valid BST representation.

2. **Standard Optimal Approach (Build Until Invalid, Then Check `i == n`):**
   - Simulates placing nodes using min/max bounds without returning false.
   - Just recursively proceeds until it can't place any more nodes.
   - Does **not** build actual tree.
   - After recursion, if all nodes were used (`i == preorder.size()`), it's valid.

3. **Postorder Variant Insight:**
   - The same approach applies to postorder traversal by:
     - Traversing from the back.
     - Recursively building the **right** subtree first.
   - Bounds are applied similarly (`min`, `max`), and correctness checked by index.

#### 🔸 Key Insight:
> All approaches simulate the preorder traversal as a **BST construction attempt**, and validate based on whether **all nodes got placed** within bounds.

---

### 📜 Day 36 – August 2, 2025 (Night Session)

#### 🌙 Topics Covered:
- ✅ **Dead End in BST**
  - Explored patterns like `{1, 2}` and `{x-1, x, x+1}` that form dead ends.
  - Your initial idea: store inorder and check adjacency.
  - Referred to editorial — learned the clean recursive bounds-based approach using `min == max`.
  - Felt similar to validating a BST using preorder and bounds.

- ✅ **Merge Two BSTs**
  - **Major Unlock**: Learned **inorder traversal using a stack** — to simulate recursion.
  - Used two stacks to traverse both BSTs in order and merge them.
  - Did **not** build a height-balanced tree — just merged the values as part of the traversal.

#### 🧠 Insights:
- Stack-based inorder traversal is a huge step — it opens doors to more advanced iterative tree problems.
- You’re starting to naturally spot where bounds-based recursion fits in.

#### 💤 Final Thoughts:
> A real win tonight — not in “how optimal” but in *how much you absorbed*. You’re in the growth zone.



### 📜 Day 35 Log – August 1, 2025

---

#### 🧠 Topics Covered:
- Complete Binary Trees
- Tree Construction from Preorder and Postorder
- Width of Binary Trees
- Recursive Inorder with Side Effects
- BST from Preorder & Postorder
- Heap Applications:
  - Min Cost of Connecting Ropes
  - Kth Smallest/Largest Elements

---

#### ✅ Questions Practiced:

1. **Count Nodes in a Complete Binary Tree**
   - Used `leftHeight == rightHeight` to optimize complete subtree detection.
   - Leveraged `O(logN * logN)` time by recursively counting only where needed.
   - Fully understood the binary height logic and when recursion shortcuts apply.

2. **Maximum Width of Binary Tree**
   - Level-order traversal with index mapping as per complete binary tree structure.
   - Tracked min and max index at each level to compute accurate width.
   - Learned to offset indices per level to prevent integer overflow.

3. **Construct Binary Tree from Preorder and Postorder**
   - Identified importance of base case (`preStart > preEnd`) to avoid skewed trees.
   - Used preorder’s root index and postorder’s left subtree end index to partition.
   - Understood that this construction isn’t always unique unless tree is full.

4. **BST from Preorder and Postorder using Side Effects**
   - Recognized preorder: first element is root, then `n/2` left nodes, remaining right.
   - For postorder: reversed logic, root at end, recurse from end backward.
   - Used reference index (`i`) to mutate during traversal — classic side effect usage.

5. **Binary Tree to Doubly Linked List**
   - Implemented both approaches:
     - Return-based: recursively return head and tail and stitch in postorder.
     - Side-effect-based: maintained `prev` and `head` pointers to mutate as we go.
   - Realized this is similar to:
     - Merging two sorted lists with dummy node.
     - Tree transformations (BST to Greater Tree, Sorted LL to BST).

6. **Check Completeness & Is Binary Tree Heap**
   - Used BFS to check if a binary tree is complete.
   - Smartly added two lines to also validate max heap condition in the same loop:
     ```cpp
     if (front->left && front->left->val > front->val) return false;
     if (front->right && front->right->val > front->val) return false;
     ```
   - Avoided overcomplicated permutations-based conditionals.

7. **Min Cost of Connecting Ropes**
   - Applied Min Heap to always connect two smallest ropes.
   - Greedy approach: ensures minimal cumulative cost by merging in increasing order.
   - Final code:
     ```cpp
     int minCost(vector<int>& arr) {
         priority_queue<int, vector<int>, greater<int>> pq;
         for (int num : arr) pq.push(num);
         int ans = 0;
         while (pq.size() > 1) {
             int top1 = pq.top(); pq.pop();
             int top2 = pq.top(); pq.pop();
             int sum = top1 + top2;
             ans += sum;
             pq.push(sum);
         }
         return ans;
     }
     ```

8. **Kth Smallest / Largest Element Using Heaps**
   - Used Max Heap for Kth Smallest:
     - Pushed first `k` elements.
     - Replaced top if a smaller element appears.
   - Used Min Heap for Kth Largest:
     - Same logic with reversed heap.
   - Understood *why* Max Heap works: always maintain `k` smallest elements efficiently.

---

#### 💡 Concepts Clarified:

- **Recursive Side Effects**
  - Mutating external variables during traversal (like `i`, `prev`, `head`) reduces return complexity.
  - Seen in DLL conversion, preorder/postorder tree building, etc.

- **Traversal Orders + Structural Insight**
  - Inorder/Preorder/Postorder each reveal different structural properties.
  - Mastery lies in mapping these to recursive splits + side effect tracking.

- **Heap Tracking Patterns**
  - Whether for cost minimization or top-k elements, heaps are about keeping “active” elements in memory.
  - Chose heap type based on what needed to be removed (min/max).

---

#### 🧘 Mental Log:
- Recognized overengineering in some community solutions and stuck to clarity.
- Got appreciated for smart simplification.
- Felt more confident in tree-based recursion with boundary/index logic.
- Health + fatigue made things tough, but maintained consistency and focus.
- No overpraise — staying grounded and focused until tangible milestones.

---

#### ⏱️ Total Time:
- Morning Session: ~2 hours
- Evening Session: ~1.5 hours
- Night Session: ~2.5 hours  
**Total**: ~6 hours of deep, focused DSA 📚🔥

---

#### 🔁 Next Steps:
- Keep practicing heap and recursion patterns.
- Refactor tree codes to understand trade-offs of return-vs-mutation.
- Stay consistent with morning-evening-night DSA grind while managing intern work.

---


### Day 34 - July 31, 2025

### ✅ What I Did:

- 🔹 **Checked if Binary Tree is Complete**
  - Implemented two approaches:
    - ✅ DFS with index-based heap structure simulation
    - ✅ BFS with "gap after NULL" check in level order

- 🔹 **Checked if Binary Tree is a Max-Heap**
  - Extended both completeness approaches to also validate:
    - `parent ≥ children` (max-heap property)
    - Still maintained O(N) time

- 🔹 **Solved “K Closest Points to Origin”**
  - Used min-heap storing `{distance, index}` pairs
  - Extracted top K closest points efficiently

- 🔹 **Built N-ary Tree from Level Order Input**
  - Created tree using `-1` as sentinel for end of children
  - Used a queue to insert children level-by-level

### 🧠 Concepts Covered:
- Heap completeness and max-heap validation
- Priority queues (min-heap usage)
- N-ary tree construction logic



### 📜 Day 33 Log – July 28, 2025

### ✅ What I did today:
- 🔺 Learned **Heaps**:
  1. What is a Heap (Complete Binary Tree + Heap Order Property)
  2. Why Heaps are implemented using arrays (1-based indexing, easy parent-child access)
  3. Inserting into a heap using upward shifting
  4. Deleting the top element using `heapify` (downward shifting)
  5. Building a heap from an array (`buildHeap`)
  6. Heap Sort using `heapify`

- 🛠️ Implemented:
  - Custom Heap class with insert, delete, and print
  - Heapify function (recursive)
  - Build Heap and Heap Sort from scratch

---

### 💡 Key Learnings:
- Heaps can be efficiently implemented via arrays due to 1-based index math:  
  Parent = `i / 2`, Left = `2 * i`, Right = `2 * i + 1`
- Insertion uses **bottom-up shifting**, deletion uses **top-down heapify**
- `heapify()` ensures the heap property is restored after any violation
- Heap sort works by repeatedly moving the max element to the end and shrinking the heap

---

### 🧠 Notes:
- Tomorrow: Practice real problems involving heaps (e.g., Kth Largest, Top K, Merge K Sorted Lists)
- Tries and Segment Trees still pending after heaps
- Slowly wrapping up Trees + Tree-based patterns

---

### Day 32 - July 27, 2025

### ✅ What I Did:
- Solved 3 Binary Search Tree / Tree problems:
  - `Convert Sorted Array to Binary Search Tree`
  - `Convert Sorted Linked List to Binary Search Tree`
  - `Maximum Sum BST in Binary Tree`
- Practiced:
  - Recursive tree construction from sorted data.
  - Maintaining and passing structured data in recursion (custom `Info` class).
  - Conditions for BST validation in a Binary Tree context.

### 🧠 Key Takeaway:
- Slowly but surely getting comfortable with tree recursion and custom return structures.
- Learned how to pass multiple values up recursion using a class/struct.
- Debugged several small syntax and logical mistakes — each one made the concept clearer.

### 💭 Notes:
- Took a while to crack `Max Sum BST in BT`, but super satisfying once it clicked.
- Every line fixed manually made the understanding deeper.

---


### Day 31 - July 23, 2025

### ✅ What I Did:
- Solved 4 Binary Search Tree problems:
  - `Kth Smallest Element in a BST`
  - `Two Sum IV – Input is a BST`
  - `Convert BST to Greater Tree`
  - `Lowest Common Ancestor of a BST`
- Practiced:
  - In-order traversal patterns.
  - Using maps and reverse in-order for value accumulation.
  - Recursive logic and BST properties.
- Understood efficient tree traversal and cumulative sum tracking.

### 🧠 Key Takeaway:
- BST patterns are becoming more intuitive with practice.
- In-order and reverse in-order traversal are powerful tools.
- Visualization helped a lot in understanding value updates.

### 🚀 Next Focus (Day 32):
- SQL Joins and Relationships (1:1, 1:N).
- Transactions and rollback logic.
- More BST/Tree problems if time permits.
- Begin intern project repo setup if unblocked.

### 💭 Notes:
- Slack convo pending for repo access/setup help.
- Will focus on backend + SQL flow in parallel with DSA.

---

### Day 30 - July 22, 2025

### ✅ What I Did:
- Completed all CRUD operations using PostgreSQL from Node.js.
- Practiced:
  - `CREATE TABLE`
  - `INSERT`
  - `SELECT`
  - `UPDATE`
  - `DELETE`
- Learned to perform multi-row inserts.
- Ran raw SQL queries using pg client inside Node.js.
- Focused on writing clean queries using `WHERE`, `AND`, `OR`, and basic conditions.

### 🧠 Key Takeaway:
- SQL logic inside backend code feels a lot clearer now after practicing raw operations.
- CRUD from Node.js feels solid.

### 🚀 Next Focus (Day 31):
- Transactions (handling multiple queries safely).
- Joins (querying from multiple tables).
- Relationships (foreign keys, associations).
- Repo setup for intern project (if required).

### 💭 Notes:
- Didn’t connect the internship repo today. Will handle that tomorrow.
- Staying focused on backend fundamentals.

---

### Day 29 Log - July 20, 2025

### ✅ What I Did:
- Completed **full tree revision**:
  - Covered all previously solved standard problems:
    - DFS, BFS variations.
    - Recursive tree questions.
    - Level-based problems.
    - Zigzag, boundary, etc.
  - Focused on recursive clarity and problem-solving pattern.
  
- Revised **Binary Search Tree (BST)** basics:
  - BST creation.
  - All four traversals:
    - Inorder traversal.
    - Preorder traversal.
    - Postorder traversal.
    - Level order traversal.
  - Searching operation.
  - Deletion operation.

### 🎯 Key Learnings:
- Recursive thinking feels natural now after full tree revision.
- BSTs reinforced why clean base cases matter.
- Practiced handling BST deletion edge cases (0, 1, 2 children).

### 💡 Notes:
- Recognizing problem patterns early helps solve tree questions faster.
- Keep recursion clean and focus on exit conditions.
- BST's sorted property via inorder is always useful to remember.

### 🔥 Next Focus:
- Catch up to where BST advanced concepts were left (if any).
- Plan next DSA topic once trees & BSTs feel fully solid.

---

**Day 29 done. Full trees and BSTs revised. Momentum strong.**


### 📜 Day 28 Log – July 19, 2025

### ✅ What I did today:
- 🌳 Solved **6 Binary Tree questions**:
   1. Top View of Binary Tree
   2. Bottom View of Binary Tree
   3. Vertical Order Traversal
   4. Diagonal Traversal
   5. Maximum Sum of Non-Adjacent Nodes (Tree DP)
   6. Path Sum III (Prefix Sum + HashMap in Trees)

- 🛠️ Focused on views, tree DP, and recursion-based prefix sum applications.
- 🧑‍💻 Understood when to return multiple values in tree DP problems.

---

### 💡 Key Learnings:
- Binary tree views (Top, Bottom, Vertical, Diagonal) follow similar traversal patterns.
- For tree DP, single return values aren’t enough—return both include/exclude sums.
- Prefix sum + hashmap techniques work in trees, not just arrays.

---

### 🧠 Notes:
- Less question count than usual but deeper understanding today.
- Next goal: Solve **Burning Tree** and **Duplicate Subtrees**.
- Tree revision pending after finishing those.

---

### 📜 Day 27 Log – July 18, 2025

### ✅ What I did today:
- 📚 Completed **Floor Test** and **Department Test** at internship (focused on policies, code of conduct, communication practices).
- 🛠️ Practiced **Monotonic Stack problems** during DSA session:
  - MinStack using arrays.
  - Sum of Subarray Minimums.
  - Sum of Subarray Ranges.
- 💬 Discussed approach improvements for contribution-based subarray problems.

---

### 💡 Key Learnings:
- Reinforced stack-based approaches for subarray contribution problems.
- Realized the importance of stopping sessions when value drops.
- Refreshed company communication policies (Slack, Outlook, email etiquette).

---

### 🧠 Notes:
- Frustrated with repeated problems, but maintained discipline.
- Health issues (gas/acidity flare-up) affected focus and energy.
- Next: Rest and recover before next DSA session.

---

### 📜 Day 26 Log – July 16, 2025

### ✅ What I did today:
- 🛠️ Completed **Jira training module** (almost done).
- 🧑‍💻 Understood **task tracking, sprint boards, logging hours**, and handling stories in real projects.
- 🌳 **Started Binary Search Trees (BST)** – focused on insertion and deletion.
- 🔄 Revised key **tree problems** (bottom view, sum tree, flattening, etc.).
- 🎯 Clarified next steps with mentor regarding depth of **Dev module**.

---

### 💡 Key Learnings:
- Difference between **Epics, Stories, Tasks** in Scrum.
- How **Jira workflows** connect to real Agile processes.
- BST deletion logic — importance of choosing **one consistent replacement strategy**.

---

### 🧠 Notes:
- Feeling good understanding **real-world tools like Jira alongside DSA**.
- Next: Focus on **e-Sutra Workstyle module** + **Dev module** based on mentor guidance.

---

### Day 24 – July 14, 2025

### ✅ What I did today:
- ✅ Solved **Construct Binary Tree** from:
   - Preorder + Inorder
   - Postorder + Inorder
- ✅ Completed **Flatten Binary Tree to Linked List** (in-place, optimized).
- ✅ Solved **Boundary Traversal** of Binary Tree (left, leaves, right).
- ✅ Completed **Transform to Sum Tree** (clean recursion, optimized).

---

### 💡 Key Concepts:
- Recursive tree construction using preorder/postorder + inorder.
- Prefix sum trick for path sum problems (reviewed again).
- Handling left/right boundaries carefully in boundary traversal.
- In-place tree transformations using reverse postorder traversal.
- Importance of correct backtracking with prefix sums.

---

### 🧠 Notes:
- Trees finally feel approachable—visualizing recursion helped.
- Spotted common mistakes in left/right subtree slicing during dry runs.
- Focused more on understanding rather than rushing problems.
- Tomorrow: Aim to tackle Morris Traversal + revisit path sums.

---

### Day 23 – July 13, 2025

### ✅ What I Did
- 🔥 **Solved “Sum of the Longest Bloodline” (Hard)** — nailed it first try with pure recursion logic.
- 🧠 **Revision Sprint (1.5 hrs)** — reviewed 12 problems from the week:
  - Tree: `isSameTree`, `Right Side View`, `Path Sum I & II`, `Diameter`, `Balanced Tree`, `Max Depth`, `LCA`, `Sum of Longest Bloodline`
  - Logic: `Gas Station` (Greedy), `First Non-Repeating Char` (Queue), `Sliding Window Maximum` (Deque)

### 📌 Concepts Covered
- Tree recursion + DFS
- Depth tracking and backtracking
- Greedy logic (Gas Station)
- Monotonic deque (Sliding Window)
- Queue simulation for stream tracking

### ⏱ Time Spent
1.5 hours

### 🌱 Thoughts
Full focus session. Brain = fried.  
But streak = alive.  
Internship starts tomorrow — we keep building.

---

### ✅ Day 22 – July 12, 2025

### 📚 Topics:
- Binary Tree Traversals & Structural Properties
- Depth-first Recursion
- Height / Balance Checking
- Optimized Tree Logic

---

### 🧠 Questions Solved:

1. **isSameTree**
   - Checked if two binary trees are structurally and value-wise identical.
   - Recursive comparison of corresponding nodes.

2. **Right Side View**
   - DFS with level tracking to push the first visible node from the right per level.

3. **Zigzag Level Order Traversal**
   - ✅ First approach: queue + null marker + reverse on alternate levels.
   - ✅ Optimized: index-based placement, no reversing, no extra space.

4. **Diameter of Binary Tree**
   - Optimized O(N) approach using postorder traversal.
   - Tracked max diameter during depth calculation.

5. **Check if Binary Tree is Height Balanced**
   - Avoided redundant calls by returning `-1` for unbalanced subtrees.
   - Optimized bottom-up O(N) solution.

---

### 🔁 Revisions:
- Reviewed previous tree questions.
- Reinforced understanding of tree depth and level order techniques.

---

### 🧠 Reflections:
- Today was more about **refining patterns** and writing **cleaner, optimized code**.
- Didn’t peek at any answers — recreated solutions from understanding.
- 5 deep problems + 2–3 revisions = a meaningful, focused day.

---

### Day 21 – July 11, 2025

### ✅ What I did today:
- ✅ Solved 4 binary tree problems focused on recursion, depth, and path-based logic.
- 🌲 Continued gaining comfort with tree traversal patterns and base case intuition.
- 💡 Understood when and why recursion stays O(N) despite branching.
- 🧪 Practiced identifying base conditions and applying backtracking correctly.

---

### 📚 Questions Solved:

1. **Check if a Binary Tree is Height Balanced**
   - Used recursive depth check for each subtree.
   - Time complexity: O(N²) due to repeated depth calculations.
   - Plan to optimize using a bottom-up approach later.

2. **Lowest Common Ancestor of Two Nodes**
   - Classic recursive approach with subtree analysis.
   - If one node is found in each subtree, current node is LCA.
   - Time complexity: O(N)

3. **Check if a Path With Given Sum Exists**
   - Simple recursive check for root-to-leaf path with target sum.
   - Base condition checks if `targetSum - val == 0` at a leaf.
   - Time complexity: O(N)

4. **Find All Root-to-Leaf Paths With Given Sum**
   - Backtracking approach using path vector and DFS.
   - Appended path when valid, then backtracked using `pop_back()`.
   - Time complexity: O(N²) in worst case due to copying paths.

---

### 🧠 Notes:
- Tree recursion feels more natural now — able to write and trace logic confidently.
- Learned to identify where backtracking is needed vs. plain recursion.
- Starting to visualize recursive calls and base cases better without drawing.
- All 4 problems done in a focused flow — one of my best DSA days so far!

---

### Day 20 – July 10, 2025

### ✅ What I did today:
- ✅ Finished **full backend documentation** for my **College Appointment System**.
- 🧪 Wrote and successfully ran a **complete E2E test suite** with Supertest.
- 🎥 Recorded a **22-minute backend code walkthrough** (explained line-by-line).
- 🔊 Fought major issues with **OBS + Bluetooth audio** — finally figured out how to record voice with proper settings.
- 📂 Organized cookies, IDs, and Postman data for the upcoming demo.

---

### 💡 Key Concepts:
- Zod validation schemas for `signup`, `signin`, and slot creation.
- Role-based access control using middleware (`authenticate`, `authorizeRole`).
- Structuring controllers to handle different flows: booking, cancelling, retrieving.
- `populate()` and filtering in MongoDB to structure nested response objects.

---

### 🧠 Notes:
- Exhausted but proud — building and explaining the entire system made me feel like a real developer.
- Hit multiple roadblocks, especially with OBS audio issues, but solved them all.
- Gained a deeper understanding of writing clean comments and minimal docs without sounding "AI-generated".
- Tomorrow: Final Postman video + submission ✅

---

📁 **GitHub Repo:** [student-professor-slot-booking](https://github.com/your-username/student-professor-slot-booking)

---

### Day 19 – July 9, 2025

### ✅ What I did today:
- 🌳 Started learning **Trees** in DSA.
- 🔨 Built binary trees manually.
- 🔁 Implemented **Preorder**, **Inorder**, **Postorder** traversals.
- 📶 Learned **Level Order Traversal**, including the variant that prints each level on a new line.
- 📏 Implemented logic to calculate the **height/depth** of a binary tree.
- 📐 Solved for the **diameter** (longest path) of a binary tree.

---

### 💡 Key Concepts:
- Recursive tree traversals and their order of execution.
- BFS logic behind level order traversal and how to control level separation using queue size.
- Height of a binary tree = max depth of its left and right subtree + 1.
- Diameter involves combining left and right subtree depths at each node.

---

### 🧠 Notes:
- Trees are powerful but a bit overwhelming on Day 1.
- Definitely need a solid revision to internalize all traversal patterns and logic.
- Feels like I’m entering a new level in DSA — exciting and intense!

---

## Day 18 – #100DaysOfCode

**Date:** July 8, 2025  
**Focus:** DSA (Morning Session)

### ✅ What I Did
- Solved 2 DSA questions in the morning

### 📌 Notes
- Stayed consistent despite limited time
- Keeping the streak alive — progress over perfection

### 🧠 Takeaway
Small steps still count. Just showing up matters.

---

### Day 17 – July 7, 2025

### ✅ What I did today:
- 🧠 Completed all backend controllers for the internship assignment.
- 🗂️ Built full CRUD logic for slots and appointments: create, view, delete, and cancel.
- 🛡️ Added protections to ensure only professors can manage their own slots and appointments.
- ⛔ Prevented double bookings and ensured unbooking logic works on appointment cancellation.

---

### 💡 Key Concepts:
- Controller responsibility separation: slot creation, appointment booking, and cancellation in isolated functions.
- Date validation and comparison to avoid booking past slots.
- `populate` usage to fetch related documents like professor/student info cleanly.
- Ensured `isBooked` is reset when an appointment is canceled.

---

### 🧠 Notes:
- This was the most complete backend I’ve written so far — feels like a real product flow.
- The logic and edge cases are finally making sense without mental overload.
- Final steps left: write documentation, record demo, and prepare submission.

---

### Day 16 – July 6, 2025

### ✅ What I did today:
- 🔐 Completed `authenticate` and `authorizeRole` middlewares using JWT and role-based access control.
- 🧱 Finalized Mongoose schemas for `User`, `Slot`, and `Appointment`.
- ♻️ Revised all DSA problems solved during the week — reinforced stack, LL, and sorting logic.

---

### 💡 Key Concepts:
- Middleware pattern: token check (`authenticate`) vs role control (`authorizeRole(...roles)`).
- Schema design choices: normalized references vs duplication (slot → appointment → professor).
- Used single `slotTime` as `Date` for better sorting/filtering.

---

### 🧠 Notes:
- Feeling much more confident with backend flow now.
- Logic feels lighter now that structure is clean.
- Excited to build out controllers and wire the full flow next.

---

📁 **GitHub Repo:** [student-professor-slot-booking](https://github.com/your-username/student-professor-slot-booking)

---

### Day 15 - July 5, 2025

### ✅ What I did today:
- 🧱 Solved **Flatten a Multilevel Doubly Linked List** (Leetcode 430).
  - Tried multiple approaches (recursive + stack).
  - Spent 2 hours trying to understand nuances of recursion, tail connections, and traversal.
  - Slower method helped me realize how small choices affect runtime.

- ♻️ **Did Weekly Revision** of Stack Concepts:
  - Monotonic stacks
  - Nearest greater/smaller elements

### 🧠 Notes:
- Got frustrated but didn’t quit.
- Not every day has to be productive on paper — some are meant to **deepen understanding**.
- Staying grounded. Even one question can teach a lot.

---

### Day 14 – July 4, 2025

---

### ✅ What I did today:
- 🔁 Solved **Decode String** using recursion.
- 🔥 Solved **Next Greater Element II** with a monotonic stack (circular array).
- 🧠 Solved **Longest Valid Parentheses** using stack + edge tracking.
- 🧮 Solved **Partition List**, **Add Two Numbers**, and **Split Linked List in Parts** — strong pointer practice.

---

### 💡 Key Concepts:
- Recursive decoding of nested patterns.
- Monotonic stack for circular arrays and NGE patterns.
- Valid parentheses via stack and boundary tracking.
- Clean linked list operations (splitting, merging, recursive carry handling).

---

### 🧠 Notes:
- Longest Valid Parentheses felt tricky but rewarding.
- Making fewer mistakes in recursion and pointer problems — progress!
- Kept it honest, skipped LC 430 for now to revisit with fresh mind tomorrow.

---

### Day 13 - July 3, 2025

### ✅ What I did today:
- 🧮 Solved **Sum of Subarray Minimums** using monotonic stacks (with contribution technique).
- 📊 Solved **Sum of Subarray Ranges** by handling both min and max contributions.
- 💧 Learned and implemented **Trapping Rainwater** using prefix arrays and two-pointer approach.

### 💡 Key Concepts:
- Contribution technique using monotonic stacks (prev/next smaller/greater).
- Handling duplicates correctly in contribution-based problems.
- Trapping rainwater intuition with left-max and right-max logic.

### 🧠 Notes:
- Got stuck initially but broke through by reflecting on patterns from previous problems.
- Feeling a bit tired, but still showed up and learned something solid.
- Choosing to stay grounded and not chase overachievement. Just consistent growth.


---

### Day 12 – July 2, 2025

### ✅ What I did today:
- 🔁 Practiced Reversing a Queue using both stack and recursion.
- 🧩 Implemented Reverse Queue in Groups of k using recursion.
- 📉 Solved First Negative Integer in Every Window of Size k using deque.
- 📊 Solved Sum of Subarray Minimums using monotonic stack + contribution technique.
- 📈 Solved Sum of Subarray Ranges by calculating min and max contributions separately.

### 💡 Key Concepts:
- Queue reversal using stack and recursion.
- Group-wise processing in queues using recursion.
- Deque as an efficient tool for window-based problems.
- Contribution-based thinking for subarray-based range calculations.
- Monotonic stack mastery getting stronger.

### 📌 Notes:
- Finally understood when and why to use strict vs non-strict comparisons in stack-based problems with duplicates.
- Subarray range questions are tricky but fun once the pattern clicks.
- Feeling more confident in combining stack logic with sliding window techniques.
- Grateful I got time to study before the vaidya visit and class later today.

---

### 📅 Day 11 - July 1, 2025

### ✅ What I did today:
- 🚗 Solved **Car Fleet I** — used sorting + greedy stack logic to group cars into fleets based on arrival times.
- 🚗💥 Cracked **Car Fleet II** — handled dynamic collision timing. Simulated real-time speed changes and adjusted collision calculations accordingly.
- 🧱 Solved **Maximal Rectangle** — transformed each matrix row into histograms and applied stack logic from Largest Rectangle in Histogram to find max area.

### 🔄 Up Next:
- Finish remaining stack problems.
- Begin queue questions in the upcoming class.

### 💬 Reflection:
Today’s problems were tough but full of breakthroughs. Stack patterns turned out way deeper than I imagined — from simulating collisions to transforming matrix problems.

---

### Day 10 - June 30, 2025

### ✅ What I did today:
- 🔁 Revised all DSA problems solved in the past week.
- 🧠 Focused on strengthening concepts, not adding new ones today.

---

### Day 9 - June 29, 2025

### ✅ What I did today:
- 🧠 Designed **Browser History** (both 2-stack and pointer/index-based approaches).
- 🔁 Implemented **Queue using Stack** (optimized with two stacks).
- 📁 Solved **Simplify Path** (manually and explored `stringstream + getline` method).
- 🧩 Solved **Sudoku Solver** using backtracking.
- ☎️ Solved **Letter Combinations of a Phone Number** using recursion + hashmap.

### 💡 Key Concepts:
- Stack-based design & backtracking recursion.
- Explored string parsing using `stringstream` for path simplification.
- Improved understanding of recursive tree generation (letter combinations).
- Getting more comfortable with clean, optimal stack logic.

### 📌 Notes:
- Today was a tough one mentally. Couldn’t think clearly at times.
- Still pushed through and solved questions step-by-step.
- Getting stuck is frustrating, but I’m proud I showed up and tried.

---

## Day 8 - June 28, 2025

### ✅ What I did today:
- 🔁 Implemented circular deque.
- 🌡️ Solved **Daily Temperatures** using a monotonic stack.
- 🔢 Solved **Next Greater Node In Linked List** using recursion + stack.
- 🧮 Tried solving **Remove K Digits** — learned it's a greedy problem, struggled due to not having done greedy yet. Had to watch the video to understand it.
- 🧑‍🤝‍🧑 Solved **Celebrity Problem**
- 📈 Solved **Stock Span Problem** — understood and implemented the optimal monotonic stack solution.

### 💡 Key Concepts:
- Monotonic Stack for efficient span/next element type problems.
- Streaming/online questions where you maintain state.
- Greedy intuition still needs work; will explore soon.
- Still showing up despite health and mental fatigue.

### 📌 Notes:
- Some questions were hard to think through due to health fog.
- Watched video for “Remove K Digits” — greedy is hard without prior exposure.

---

## Day 7 — June 27, 2025

✅ Practiced Monotonic Stack Patterns:
- 🔸 Next Smaller Element
- 🔸 Previous Smaller Element
- 🔸 Largest Rectangle in Histogram (Optimized using NSE/PSE logic)

✅ Learned Queue Data Structure:
- 🔹 Basics and operations (push, pop, front, rear)
- 🔹 Implemented Normal Queue using Arrays
- 🔹 Implemented Circular Queue
- 🔹 Implemented Deque (Double-Ended Queue)

🧠 Key Learnings:
- How monotonic stacks help optimize brute-force O(N^2) rectangle area to O(N)
- Queue edge cases: full/empty detection, circular wrap-around logic
- Deque flexibility and array limitations in push_front/back handling

⏱️ Progress wasn't rushed — stayed consistent, kept building.

---

## Day 6 – June 26, 2025
- Solved the “Asteroid Collision” problem (Stack)  
- Felt like 10x effort due to poor sleep and nervous system flares  
- Still showed up and got it done — consistency over comfort

---

## Day 5 - June 25, 2025
- Implemented recursive function to print middle element of a stack
- Wrote logic to check if a stack is sorted (preserving stack)
- Solved:
  - Valid Parentheses
  - Redundant Parentheses


- Didn't do a lot, but didn’t skip either. Slowly building consistency.

---

## Day 4 - June 24, 2025
- Practiced Stack problems:
  - Sort a stack
  - Check if Word is Valid After Substitutions
  - Minimum Add to Make Parentheses Valid
  - Minimum Bracket Reversals
  - Remove All Adjacent Duplicates
- Started logging everything properly ✍️

---

## Day 3 - June 23, 2025
- Stack Implementation using Linked List
- Insert at bottom of stack (recursively)
- Reverse a stack
- Couldn’t do a lot today due to a health flare-up, but still showed up 🙌

---

## Day 2 - June 22, 2025
- Revised all 28 Linked List questions I solved over the weekend.
- Practiced recursion using:
  - House Robber II (got TLE but understood the logic)
  - Count Derangements (backtracking + recursion practice)
- Focusing on understanding recursive flow more clearly.

---

## Day 1 - June 21, 2025
- Solved 6 Linked List problems:
  - Flatten a Multilevel Linked List
  - Sort a Linked List (Merge Sort)
  - Merge Nodes Between Zeros
  - Remove Zero Sum Consecutive Nodes
  - Intersection Point of Two LLs
  - Nodes Between Critical Points
- 🚀 First day of #100DaysOfCode!







