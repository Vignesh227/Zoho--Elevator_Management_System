# Zoho -- Elevator-Management-System
Elevator Management System Application developed using `C++`

## Question
You are given a task of implementing the elevator(lift) system using the CLI

### Level 1
 - Get the details, such as **_lift count_** and **_current floor_** of each lift, from the user.
 - Display the details after getting the input.

> [!NOTE]
> - 1 <= *liftcount* <= 20
> - 0 <= *floors* <= 100

#### Expected Sample Output
```
ABC Elevator Corp.
=================

Lifts: L1 L2 L3 L4 L5
Floor: 0  0  0  0  0 
```

### Level 2
 - Get the **_current floor_** and **_destination floor_** from the user.
 - Assign the lift which is nearest to the person.
 - If more than one lift is available at the nearest floor, pick a random one.
 - Display the position of the lifts after the person has travelled.

#### Expected Sample Output
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

#### Expected Sample Output
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
- Get the **_lifetime_** of the lifts from the user at the beginning of the program. The **_lifetime_** denotes the number of times the lift can be operated without maintenance.
- Once the lift has been operated the **lifetime** number of times, it should be marked as maintenance mode and should not be assigned for one cycle.
- In the next cycle, the lift will resume operation from the ground floor, and the last known direction of the lift should be cleared.

#### Expected Sample Output
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

## Solution
The Elevator Management System has been implemented to address all five levels of functionality as outlined.

### Level 1: Basic Lift Information
The program prompts the user to input the number of lifts and the current floor for each lift. It then displays these details in a formatted output to provide a clear view of the lift system's status.

### Level 2: Lift Assignment Based on Proximity (Distance)
The system calculates the distance of each lift from the user's current floor and assigns the nearest lift. The updated positions of the lifts are then displayed.

### Level 3: Continuous Operation with Direction Display
The program continually processes user requests until an exit command is given. It keeps track of each lift's current floor, updates their positions based on user input, and displays their movement direction (+ for up, - for down, and () for no movement).

### Level 4: Advanced Lift Assignment Constraints
- Prefer lifts moving in the same direction as the user's destination.
- Assign odd-numbered lifts to odd floors and even-numbered lifts to even floors.
- In case of further ties, a random lift is chosen.

### Level 5: Lifetime and Maintenance Mode
The system includes functionality to track the number of operations for each lift. Once a lift reaches its operational limit (lifetime), it is marked for maintenance and excluded from assignment until it resets in the next cycle. Maintenance lifts resume operation from the ground floor, and their last known direction is cleared.

## Output Screenshots

![image](https://github.com/user-attachments/assets/950052a3-b0b3-4187-9982-dbb1d50b536e)
![image](https://github.com/user-attachments/assets/c44a704e-a7c1-45cc-a8a6-81b4b2a452a1)
![image](https://github.com/user-attachments/assets/2e3ee928-76cc-4755-a9bb-cacfb27c95d1)
![image](https://github.com/user-attachments/assets/9c48fa4f-9208-4a3f-8570-fca89c9e7333)
![image](https://github.com/user-attachments/assets/d9254ad9-1590-419c-95f3-987d87c57ffe)





