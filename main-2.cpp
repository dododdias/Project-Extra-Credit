#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdlib>

// Enum to represent the direction of elevator movement
enum class Direction { UP, DOWN, NONE };

// Class representing the Elevator
class Elevator {
private:
    int currentFloor; // Current floor of the elevator
    Direction direction; // Direction of elevator movement
    std::set<int> requests; // Set of requested floors

public:
    // Constructor to initialize the elevator with a starting floor
    Elevator(int startFloor = 1) : currentFloor(startFloor), direction(Direction::NONE) {}

    // Method to handle a new request for a floor
    void handleRequest(int floor) {
        requests.insert(floor);
        // If elevator is idle, determine the direction based on the new request
        if (direction == Direction::NONE) {
            if (floor > currentFloor) direction = Direction::UP;
            else if (floor < currentFloor) direction = Direction::DOWN;
        }
    }

    // Method to move the elevator to the next floor
    void move() {
        if (direction == Direction::UP) currentFloor++;
        else if (direction == Direction::DOWN) currentFloor--;
    }

    // Method to get the current floor of the elevator
    int getCurrentFloor() const {
        return currentFloor;
    }

    // Method to check if there are any pending requests
    bool hasRequests() const {
        return !requests.empty();
    }

    // Method to handle all pending requests
    void handleRequests() {
        while (!requests.empty()) {
            int nextFloor = getNextFloor();
            std::cout << "Moving to floor " << nextFloor << std::endl;
            move();
            requests.erase(nextFloor);
        }
        direction = Direction::NONE;
    }

private:
    // Method to determine the next floor to visit based on the direction
    int getNextFloor() {
        if (direction == Direction::UP) {
            auto it = requests.upper_bound(currentFloor);
            if (it != requests.end()) return *it;
        } else if (direction == Direction::DOWN) {
            auto it = requests.lower_bound(currentFloor);
            if (it != requests.begin()) return *(--it);
        }
        return *requests.begin();
    }
};

// Function to simulate the elevator operation and calculate total waiting time
int simulateElevator(int numUsers, int numFloors) {
    srand(time(0)); // Seed random number generator
    Elevator elevator; // Create an elevator object
    int totalTime = 0; // Total time taken by all users

    // Loop through each user
    for (int i = 0; i < numUsers; ++i) {
        // Generate random arrival time, start floor, and destination floor for the user
        int arrivalTime = rand() % 10 + 1; // Random arrival time between 1 and 10 seconds
        int startFloor = rand() % numFloors + 1; // Random start floor
        int destinationFloor = rand() % numFloors + 1; // Random destination floor

        // Display user arrival information
        std::cout << "User " << i+1 << " arrives at floor " << startFloor << " and wants to go to floor " << destinationFloor << std::endl;

        // Wait for the user to arrive
        totalTime += arrivalTime;

        // User presses button to request elevator
        elevator.handleRequest(startFloor);

        // Handle elevator requests
        elevator.handleRequests();

        // Move elevator to user's floor
        std::cout << "Elevator arrives at floor " << startFloor << std::endl;
        totalTime++; // Time taken to move to user's floor

        // User enters elevator and presses destination floor
        elevator.handleRequest(destinationFloor);
    }

    // Handle remaining elevator requests
    elevator.handleRequests();

    // Return total time taken by all users
    return totalTime;
}

int main() {
    int numUsers = 5; // Number of users in the simulation
    int numFloors = 10; // Number of floors in the building
    int totalTime = simulateElevator(numUsers, numFloors); // Simulate elevator operation
    std::cout << "Total time: " << totalTime << " seconds" << std::endl; // Display total waiting time
    return 0;
}