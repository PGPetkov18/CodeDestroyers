#include <iostream>
#include <fstream>
using namespace std;


struct Student
{
 string name;
 string surname;
 string clas;
 string role;
 string email;
 string status;
};

struct Teacher
{
 string name;
 string surname;
 string email;
};

struct School
{
 string city;
 string name;
 string list1;
 string list2;
};

struct Team
{
  string name;
  string description;
  int DateOfSetUp;
  Teacher mentor;
  Student scrumTrainer;
  Student frontend;
  Student backend;
  Student qualityEng;
};

int main() 
{
  Student student[150];
  int n;


  ofstream myFile1;
  myFile1.open("students.txt");
  if (!myFile1)
  {
    cout << "File couldn't be opened!\n";
    return 0;
  }
  myFile1.close();

  ofstream myFile2;
  myFile2.open("teachers.txt");
  if (!myFile2)
  {
    cout << "File couldn't be opened!\n";
    return 0;
  }
  myFile2.close();

}