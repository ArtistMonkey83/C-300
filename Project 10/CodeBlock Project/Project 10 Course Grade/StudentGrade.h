#include<string>
using namespace std;

#ifndef STUDENTGRADE_H
#define STUDENTGRADE_H


    class StudentGrade
    {
    private:
        string name;
        string id;
        int numTests;
        double *test;
        double average;
        char grade;

    public:
        StudentGrade();            // overloaded constructor functions one accepting no arguments
        StudentGrade(string, string,int)
        ~StudentGrade();
        void setName(string);
        void setId(string);         // these mutators access the private attributes of the StudentGrade class
        void setTestNums(int);
        void setTests (double *);
        string getName() const
        {
            return name;
        }
        string getId() const
        {
            return id;
        }
        int getTestNums() const
        {
            return numTests;
        }        // we dont want any of these pre set values to change when the accessor function runs
        double getAverage() const;
        char getGrade() const;

    private:
        void calculateAverage(double*,int); //pointer to test scores and number of tests
        void calculateGrade(double);        //takes in average
    };



#endif // STUDENTGRADE_H
