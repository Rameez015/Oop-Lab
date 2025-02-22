//Fitness Tracker class
#include <iostream>
#include <string>

class FitnessTracker
{
private:
    std::string userName;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;

public:
    FitnessTracker(std::string name, int goal) : userName(name), dailyStepGoal(goal), stepsTaken(0), caloriesBurned(0) {}

    void logSteps(int steps)
    {
        stepsTaken += steps;
        calculateCaloriesBurned();
    }

    void calculateCaloriesBurned()
    {
        caloriesBurned = (stepsTaken * 0.05); // Simplified formula for demonstration
    }

    void displayProgress()
    {
        std::cout << userName << " has taken " << stepsTaken << " steps and burned " << caloriesBurned << " calories." << std::endl;
    }

    bool checkFitnessGoal()
    {
        return stepsTaken >= dailyStepGoal;
    }
};

int main()
{
    FitnessTracker tracker("Laiba", 10000);
    tracker.logSteps(5000);
    tracker.displayProgress();
    std::cout << (tracker.checkFitnessGoal() ? "Goal met!" : "Goal not met.") << std::endl;
    return 0;
}