#include"StudentGrade.h"
#include<string>

StudentGrade::StudentGrade()
{
    name = "jane doe";
    id = "";
    numTests = 0;
}

StudentGrade::StudentGrade(string nm, string nid, int nTests)
{
    name = nm;
    id = nid;
    numTests = nTests;
    tests = new double[numTests];
    setTests(tests,numTests);
}

StudentGrade::~StudentGrade()
{
    delete [] tests;
}

StudentGrade::calculateAverage(double *tsts, int nTests)
{
    double total = 0.0;
    for(int index =0; index < nTests; index++)
    {
        total += tsts[index]; //you can use pointer notation if you want
    }
}
