### ✅ Day 22 – July 9, 2025

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







