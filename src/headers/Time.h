#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <vector>
#include <functional>

class Time {
private:
    int currentTime;            // Current time in minutes
    int currentSeason;          // Current season (0 = Spring, 1 = Summer, 2 = Autumn, 3 = Winter)
    int currentYear;            // Current year
    int dayLength;              // Length of a day in minutes
    int seasonLength;           // Length of a season in days
    int yearLength;             // Length of a year in seasons
    int currentDay;             // Current day within the current season
    int daysInCurrentSeason;    // Total days in the current season
    int seasonsInCurrentYear;   // Total seasons in the current year

    std::vector<std::pair<int, std::function<void()>>> scheduledEvents;  // Vector to store scheduled events

public:
    Time();
    ~Time();

    // Time Progression Methods
    void advanceTime(int minutes);
    void advanceDay();
    void advanceSeason();
    void advanceYear();

    // Time Query Methods
    int getCurrentTime() const;
    int getCurrentSeason() const;
    int getCurrentYear() const;
    int getDaysInMonth(int month) const;

    // Time Management Methods
    void setDayLength(int minutes);
    void setSeasonLength(int days);
    void setYearLength(int seasons);

    // Event Handling Methods
    void scheduleEvent(int time, std::function<void()> eventCallback);
    void checkForEvents();
};

#endif // TIME_H

inline Time::Time()
{
}

inline Time::~Time()
{
}

// Implementation of Time Progression Methods
void Time::advanceTime(int minutes) {
    currentTime += minutes;
    // Additional logic to handle day, season, and year changes based on currentTime
    // Call advanceDay(), advanceSeason(), advanceYear() as needed
    
    // Check if a day has passed    
    while (currentTime >= dayLength) {
        currentTime -= dayLength;
        advanceDay();
    }

    // Check if a season has passed
    while (currentSeason < seasonLength && currentTime >= seasonLength) {
        currentTime -= seasonLength;
        advanceSeason();
    }

    // Check if a year has passed
    while (currentYear < yearLength && currentSeason >= seasonLength) {
        currentSeason -= seasonLength;
        advanceYear();
    }
}

// Implementation of advanceDay method
void Time::advanceDay() {
    // Increment the current day
    currentDay++;

    // Check if we have exceeded the number of days in the current season
    if (currentDay >= daysInCurrentSeason) {
        currentDay = 0; // Reset day counter

        // Increment the current season
        currentSeason++;

        // Check if we have exceeded the number of seasons in the current year
        if (currentSeason >= seasonsInCurrentYear) {
            currentSeason = 0; // Reset season counter

            // Increment the current year
            currentYear++;
        }
    }
}


// Implementation of advanceSeason method
void Time::advanceSeason() {
    // Increment the current season
    currentSeason++;

    // Check if we have exceeded the number of seasons in the current year
    if (currentSeason >= seasonsInCurrentYear) {
        currentSeason = 0; // Reset season counter

        // Increment the current year
        currentYear++;
    }

    // Reset day and time within season if necessary
    currentDay = 0;
    currentTime = 0; // You may adjust or reset other time-related variables as needed
}

// Implementation of advanceYear method
void Time::advanceYear() {
    // Increment the current year
    currentYear++;

    // Reset the current season and day if necessary
    currentSeason = 0;
    currentDay = 0;

    // Example: Check for special events or changes that occur at the start of a new year
    // This could include resetting global variables, updating resource availability, etc.
    // Example: Resetting resources or performing yearly maintenance
    // resetResources();

    // Example: Triggering global events or updates
    // triggerGlobalEvent();
}

// void Time::thisYear(){

//     // Additional logic for handling year transitions or events
//     // Example: Print a message indicating the start of a new year
//     std::cout << "Starting Year " << getCurrentYear() << "..." << std::endl;

// }

// Implementation of Time Query Methods
int Time::getCurrentTime() const {
    return currentTime;
}

int Time::getCurrentSeason() const {
    return currentSeason;
}

int Time::getCurrentYear() const {
    return currentYear;
}

// Implementation of Time Query Methods

int Time::getDaysInMonth(int month) const {
    // Adjust for zero-based month index to one-based month number
    switch (month) {
        case 1:  // January
        case 3:  // March
        case 5:  // May
        case 7:  // July
        case 8:  // August
        case 10: // October
        case 12: // December
            return 31;
        case 4:  // April
        case 6:  // June
        case 9:  // September
        case 11: // November
            return 30;
        case 2:  // February
            if (currentYear % 4 == 0 && (currentYear % 100 != 0 || currentYear % 400 == 0)) {
                // Leap year logic for February
                return 29;
            } else {
                return 28;
            }
        default:
            return 0;  // Invalid month
    }
}


// Implementation of Time Management Methods
void Time::setDayLength(int minutes) {
    dayLength = minutes;
}

void Time::setSeasonLength(int days) {
    seasonLength = days;
}

void Time::setYearLength(int seasons) {
    yearLength = seasons;
}

// Implementation of Event Handling Methods
void Time::scheduleEvent(int time, std::function<void()> eventCallback) {
    scheduledEvents.push_back(std::make_pair(time, eventCallback));
}

void Time::checkForEvents() {
    // Iterate through scheduledEvents and trigger events if currentTime matches scheduled time
    for (auto& event : scheduledEvents) {
        if (currentTime == event.first) {
            event.second(); // Invoke the event callback function
        }
    }
}

// int main() {
//     Time gameClock;

//     // Example usage:
//     gameClock.advanceTime(60);  // Advance time by 1 hour (60 minutes)
//     gameClock.advanceDay();     // Advance to the next day
//     gameClock.advanceSeason();  // Advance to the next season
//     gameClock.advanceYear();    // Advance to the next year

//     // Example: Schedule an event after 3 days
//     gameClock.scheduleEvent(3 * gameClock.getSeasonLength(), [](){
//         std::cout << "Event triggered after 3 days!\n";
//     });

//     // Example: Check for scheduled events
//     gameClock.checkForEvents();

//     // Example: Retrieve current time details
//     std::cout << "Current Time: " << gameClock.getCurrentTime() << " minutes\n";
//     std::cout << "Current Season: " << gameClock.getCurrentSeason() << "\n";
//     std::cout << "Current Year: " << gameClock.getCurrentYear() << "\n";

//     return 0;
// }
