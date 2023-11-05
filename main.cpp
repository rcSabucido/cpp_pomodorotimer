//user gets prompt to start 25-minute timer
//if user enters y, start 25-minute timer; if user enters n, terminate program
//once 25 min ends; immediately start the 5-minute break timer
//once break timer ends; prompt the user if they want to start the pomodoro timer again

#include <iostream>
#include <thread>

//void function that works as the timer for the program,
//it receives the arguments workMinutes and breakMinutes to
//dictate how many minutes it should wait
void startPomodoro(int workMinutes, int breakMinutes) {
    std::cout << "Pomodoro Started" << std::endl;

    //loops workMinutes until it reaches a value lesser than 0
    while (workMinutes > 0) {
        std::cout << "Work: " << workMinutes << " minutes remaining" << std::endl;

        //temporarily stops code execution for exactly 1 minute; once 1 minute passes by,
        //the next line gets executed which is the workMinute decrement line.
        //this is done to emulate a minute timer in which every loop iteration it waits for
        //1 minute until decrementing the value of workMinutes.
        std::this_thread::sleep_for(std::chrono::minutes(1));

        //decrements value of workMinutes by 1; this is done to reduce
        //the value of workMinutes until it reaches a number that is less than 0
        workMinutes--;
    }

    std::cout << "Take a " << breakMinutes << " minute break" << std::endl;

    //temporarily stops code execution for 5 minutes,
    //which is the default value of breakMinutes
    std::this_thread::sleep_for(std::chrono::minutes(breakMinutes));
    std::cout << "Break time's over! Back to work." << std::endl; //prompts user that 5 minutes has passed
}

int main() {
    int workMinutes{25}; // Default work time
    int breakMinutes{5}; // Default break time

    std::string choice;

    std::cout << "Welcome to the Pomodoro Timer!" << std::endl;

    while (true) {
        std::cout << "Start Pomodoro Timer? (y/n)" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == "y") {
            startPomodoro(workMinutes, breakMinutes);
        } else if (choice == "n") {
            std::cout << "Goodbye!" << std::endl;
            return 0;
        } else {
            std::cout << "Invalid choice, try again." << std::endl;
        }

    }

}