# Zoho---Elevator-Management-System
Elevator Management System Application developed using C++

## Question
You are given a task of implementing the elevator(lift) system using the CLI

### Level 1
 - Get the details, such as **lift count** and **current floor** of each lift, from the user.
 - Display the details after getting the input.

> [!NOTE]
> - 1 <= *liftcount* <= 20
> - 0 <= *floors* <= 100

#### Sample Output
```
ABC Elevator Corp.
=================

Lifts: L1 L2 L3 L4 L5
Floor: 0  0  0  0  0 
```

### Level 2
 - Get the **current floor** and **destination floor** from the user.
 - Assign the lift which is nearest to the person.
 - If more than one lift is available at the nearest floor, pick a random one.
 - Display the position of the lifts after the person has travelled.

#### Sample Output
```
Input: 0 4
Output: L2 has been assigned

Lifts: L1 L2 L3 L4 L5
Floor: 0  4  0  0  0 
```

### Level 3
 - Repeat the previous process until the user exits the program.
 - Make sure to store the current floor of the lifts and display them in each iteration.
 - Additionally, display the direction of the lift movement.
   - (+) if the lift moved up
   - (-) if the lift moved down
   - () if the lift hasn't moved

#### Sample Output
```
Input: 0 5
Output: L1 has been assigned

Lifts: L1(+) L2(+)  L3()  L4()  L5()
Floor: 5     4      0     0     0

Input: 3 2
Output: L2 has been assigned

Lifts: L1(+) L2(-)  L3()  L4()  L5()
Floor: 5     2      0     0     0
```

### Level 4
- If more than one lift is nearest to the user, use the below constraints to pick a lift.
  - Assign the lift, which moved in the same direction as the user's destination.
  - Assign odd numbered lifts to the odd floors and even numbered lifts to even floors.
  - If more than one lift exists after the above constraints, pick a random one.
 
### Level 5
- Ge the **lifetime** of the lifts from the user at the beginning of the program. The **lifetime** denotes the number of times the lift can be operated without maintenance.
- Once the lift has been operated the **lifetime** number of times, it should be marked as maintenance mode and should not be assigned for one cycle.
- In the next cycle, the lift will resume operation from the ground floor, and the last known direction of the lift should be cleared.

```
Lifts: L1(+) L2(M)  L3(+)  L4()  L5()
Floor: 1     2      2     0     0

Input: 2 5
Output: L3 has been assigned

Lifts: L1(+) L2()  L3(+)  L4()  L5()
Floor: 1     0      5     0     0

Input: 2 5
Output: L1 has been assigned

Lifts: L1(+) L2()  L3(+)  L4()  L5()
Floor: 5     0      5     0     0
```




