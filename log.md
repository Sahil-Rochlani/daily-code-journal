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







