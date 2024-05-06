Elevator Management System Report



Front Page

Title: Elevator Management System Report

Subtitle: An Efficient Approach to Elevator Operation

Author: Bernardo Dias

Date: 05/03/2024



Table of Contents

Introduction
Assumptions
UML Class Diagram
Efficiency of Algorithms
Individual Contributions
References



1. Introduction

The Elevator Management System described in this report aims to simulate the operation of an elevator, handling requests from users efficiently. The system is designed to prioritize requests based on their direction and the current position of the elevator, while also adhering to a first-come-first-served principle. The implementation includes a simulation function to calculate the waiting time for users and evaluate the performance of the system.



2. Assumptions

In the development of the Elevator Management System, the following assumptions were made:

The elevator operates in a single building with a predetermined number of floors.
Users press either the up or down button to request the elevator, and their destination floor is randomly selected.
The elevator can handle requests from both inside and outside the elevator cabin simultaneously.
The elevator system does not include features such as weight capacity restrictions or emergency stop functionality.



3. UML Class Diagram

The UML Class Diagram below illustrates the classes used in the Elevator Management System and their relationships:
-----------------------------------------
|               Elevator                |
-----------------------------------------
| - currentFloor: int                   |
| - direction: Direction                |
| - requests: set<int>                  |
-----------------------------------------
| + Elevator(startFloor: int)           |
| + handleRequest(floor: int): void     |
| + move(): void                        |
| + getCurrentFloor(): int              |
| + hasRequests(): bool                 |
| + handleRequests(): void              |
-----------------------------------------

Explanation:

Elevator: Represents the elevator system with attributes for the current floor, direction of movement, and set of requests. Includes methods to handle user requests, move the elevator, and handle pending requests.



4. Efficiency of Algorithms

The efficiency of the Elevator Management System's key functions can be evaluated in terms of their Big-O notation:

handleRequest(): This function inserts a floor request into the set of requests. Its time complexity is O(log n) for inserting into a set.
move(): This function updates the current floor of the elevator. Its time complexity is O(1).
hasRequests(): This function checks if there are any pending requests. Its time complexity is O(1).
handleRequests(): This function iterates through the set of requests and moves the elevator accordingly. Its time complexity depends on the number of pending requests, but in the worst case, it is O(n log n) due to the removal of elements from the set.
simulateElevator(): This function simulates user arrivals and elevator operation. Its time complexity depends on the number of users and floors in the simulation, but it is primarily determined by the number of users. Therefore, its time complexity is O(numUsers * log numFloors).
It is possible to optimize the handleRequests() function by using a priority queue or a different data structure to store pending requests, which could potentially reduce the time complexity to O(n).



5. Individual Contributions

As this project was developed by a single individual, all coding, designing, and documentation tasks were completed by me.


6. References

No external references were used in the development of this project.
Class Powerpoints.



Conclusion

The Elevator Management System presented in this report provides an efficient solution for handling elevator requests and simulating user interactions. Through the use of appropriate data structures and algorithms, the system prioritizes requests and minimizes user waiting times. Further optimizations could be explored to enhance the performance of the system in larger-scale simulations or real-world applications.