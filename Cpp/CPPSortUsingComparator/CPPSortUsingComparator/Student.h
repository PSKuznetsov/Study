#include <stdio.h>
#include <string>

class Student {
private:
    std::string firstName;
    std::string lastName;
    
    int dayOfMonth;
    int numberOfMonth;

public:
    //Setters
    void setFirstName(std::string fName);
    void setLastName(std::string lName);
    void setDayOfMonth(int day);
    void setNumberOfMonth(int month);
    //Getters
    std::string getFirstName();
    std::string getLastName();
    int getDayOfMonth();
    int getNumberOfMonth();
};