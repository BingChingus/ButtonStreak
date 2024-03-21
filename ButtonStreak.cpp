#include <iostream>
#include <random>
#include <chrono>
#include <locale>

// 3/20/24 - max streak acheived: 55 after 1,706,758,892 runs

//stolen from some website whose name I frogor :skull:, makes the numbers actually readable
struct space_out : std::numpunct<char>
{
    char do_thousands_sep()   const { return ','; }  // separate with commas
    std::string do_grouping() const { return "\3"; } // groups of 3 digits
};

int main()
{
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution rNum{1, 100}; 

    std::cout.imbue(std::locale(std::cout.getloc(), new space_out)); //idk what this does also copied from the site-who-will-not-be-named

    int chance {0};
    int streak{0};
    int maxStreak {0};
    int runs {0};

    int i {0};
    while(true)
    {
        int error {rNum(mt)};
        ++chance;

        if (error > chance) //increase the streak if random num clears the failure rate, reset streak + failure rate otherwise
            ++streak;
        else 
        {
            chance = 0;
            streak = 0;
        }

        if (streak > maxStreak) //check if theres a new max streak, if so, print the new streak + how many runs it took
        {
            maxStreak = streak;
            std::cout << "Max streak: " << maxStreak << " after " << runs << " runs" << '\n';
        }
        
        ++runs;
    }
}