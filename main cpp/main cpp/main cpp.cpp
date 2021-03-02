#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

//променливата, която ще дава стойности на id-тата
int autoNumber;
//брой на записните ученици и учители
int numberOfStudents;
int numberOfTeachers;
int numberOfTeams;

struct Student
{
    int id;
    string name;
    string surname;
    string clas;
    string role;
    string email;
};

struct Teacher
{
    int id;
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
    string status;
    int mentor;
    int scrumTrainer;
    int frontend;
    int backend;
    int qualityEng;
};

void PrintStudent(Student st)
{
    cout << "Student ID : " << st.id
        << endl << "______________________________\n";
    cout << right << setw(10) << "Name : "
        << left << st.name << endl
        << right << setw(10) << "Surname : "
        << left << st.surname << endl
        << right << setw(10) << "Class : "
        << left << st.clas << endl
        << right << setw(10) << "Role : "
        << left << st.role << endl
        << right << setw(10) << "Email : "
        << left << st.email << endl
        << "______________________________\n";
}

void PrintTeacher(Teacher te)
{
    cout << "Teacher ID : " << te.id
        << endl << "______________________________\n";
    cout << right << setw(10) << "Name : "
        << left << te.name << endl
        << right << setw(10) << "Surname : "
        << left << te.surname << endl
        << right << setw(10) << "Email : "
        << left << te.email << endl
        << "______________________________\n";
}

void PrintTeam(Team t)
{
    cout << "Name of the team : " << t.name
        << endl << "______________________________\n";
    cout << right << setw(15) << "Description : "
        << left << t.description << endl
        << right << setw(15) << "Mentor : "
        << left << t.mentor << endl
        << right << setw(15) << "ScrumTrainer : "
        << left << t.scrumTrainer << endl
        << right << setw(15) << "Frontend : "
        << left << t.frontend << endl
        << right << setw(15) << "Backend : "
        << left << t.backend << endl
        << right << setw(15) << "QualityEng : "
        << left << t.qualityEng << endl
        << "______________________________\n";
}

void WritingStudent()
{
    //променлива, регистрираща дали има успешен вход на имейл
    bool successEmail = false;
    //променлива, регистрираща дали има успешен статус
    bool successRole = false;
    Student st;
    ifstream readFileCounter;
    readFileCounter.open("counter.txt");
    readFileCounter >> autoNumber;
    readFileCounter >> numberOfStudents;
    readFileCounter >> numberOfTeachers;
    readFileCounter >> numberOfTeams;
    readFileCounter.close();
    //даваме id na ученика и увеличаваме променливата
    autoNumber++;
    st.id = autoNumber;
    cout << "\nReading student's data\n"
        << "----------------------\n";
    cout << "Please, input the name of the student: ";
    cin >> st.name;
    //ToUpperCase(st.name); 
    cout << "Please, input the surname of the student: ";
    cin >> st.surname;
    cout << "Please, input the class of the student: ";
    cin >> st.clas;
    while (!successRole)
    {
        cout << "Please, input the role of the student: "
            << endl << "1 - for ScrumTrainer"
            << endl << "2 - for Frontend"
            << endl << "3 - for Backend"
            << endl << "4 - for QualityEng" << endl;
        int role;
        cin >> role;
        if (role == 1)
        {
            st.role = "ScrumTrainer";
            successRole = true;
        }
        else if (role == 2)
        {
            st.role = "Frontend";
            successRole = true;
        }
        else if (role == 3)
        {
            st.role = " Backend";
            successRole = true;
        }
        else if (role == 4)
        {
            st.role = " QualityEng";
            successRole = true;
        }
        else
        {
            cout << "Wrong role!" << endl;
            cout << "Do you want to continue y/n ?  ";
            char ans;
            cin >> ans;
            if (ans == 'n' || ans == 'N')
            {
                break;
            }
        }
    }

    while (!successEmail && successRole)
    {
        cout << "Please, input the email of the student: ";
        cin >> st.email;
        if (st.email.find("@codingburgas.bg") == -1)
        {
            cout << "Wrong email!" << endl;
            cout << "Do you want to continue y/n ?  ";
            char ans;
            cin >> ans;
            if (ans == 'n' || ans == 'N') break;
        }
        else successEmail = true;
    }
   
    if (successEmail && successRole)
    {
        cout << endl;
        PrintStudent(st);
        cout << "Save data: y/n ?  ";
        char ans;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            //запис на ученик
            numberOfStudents++;
            ofstream writeFileStudents("students.txt", ios::app);
            writeFileStudents << st.id << endl << st.name << endl
                << st.surname << endl << st.role << endl
                << st.email << endl;
            writeFileStudents.close();
            //запис на броячите
            ofstream writeFileCounter("counter.txt");
            writeFileCounter << autoNumber << endl
                << numberOfStudents << endl
                << numberOfTeachers << endl
                << numberOfTeams << endl;
            writeFileCounter.close();
            cout << "Done!\n";
        }
    }


}

void WritingTeacher()
{
    //променлива, регистрираща дали има успешен вход на имейл
    bool successEmail = false;
    Teacher te;
    ifstream readFileCounter;
    readFileCounter.open("counter.txt");
    readFileCounter >> autoNumber;
    readFileCounter >> numberOfStudents;
    readFileCounter >> numberOfTeachers;
    readFileCounter >> numberOfTeams;
    readFileCounter.close();
    //даваме id na учителя и увеличаваме променливата
    autoNumber++;
    te.id = autoNumber;
    cout << "Please, input the name of the teacher: ";
    cin >> te.name;
    cout << "Please, input the surname of the teacher: ";
    cin >> te.surname;

    numberOfTeachers++;

    while (!successEmail)
    {
        cout << "Please, input the email of the teacher: ";
        cin >> te.email;
        if (te.email.find("@codingburgas.bg") == -1)
        {
            cout << "Wrong email!" << endl;
            cout << "Do you want to continue y/n ?  ";
            char ans;
            cin >> ans;
            if (ans == 'n' || ans == 'N') break;
        }
        else successEmail = true;
    }
    if (successEmail)
    {
        cout << endl;
        PrintTeacher(te);
        cout << "Save data: y/n ?  ";
        char ans;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            numberOfTeachers++;
            ofstream writeFileTeachers("teachers.txt", ios::app);
            writeFileTeachers << te.id << endl << te.name << endl << te.surname << endl << te.email << endl;
            writeFileTeachers.close();
            ofstream writeFileCounter("counter.txt");
            writeFileCounter << autoNumber << endl
                << numberOfStudents << endl
                << numberOfTeachers << endl
                << numberOfTeams << endl;
            writeFileCounter.close();
        }
        cout << "Done" << endl;
    }
}

void WritingTeam()
{
    Team tm;
    bool successStatus = false;
    readFileCounter >> numberOfTeams;
    ofstream writeFileTeams("teams.txt", ios::app);
    cout << "Please, input the name of the team: ";
    getline(cin, tm.name);
    cout << "Please, input the description of the team: ";
    getline(cin, tm.description);
    cout << "Please, input the email of the team: ";
    //cin >> tm.email;
    while (!successStatus)
    {
        cout << "Please, choose status of the project: "
            << endl << "1 - for In use"
            << endl << "2 - for Not active"
            << endl << "3 - for Archived" << endl;
        int status;
        cin >> status;
        if (status == 1)
        {
            tm.status = "In use";
            successStatus = true;
        }
        else if (status == 2)
        {
            tm.status = "Not active";
            successStatus = true;
        }
        else if (status == 3)
        {
            tm.status = "Archived";
            successStatus = true;
        }
        else
        {
            cout << "Wrong status!" << endl;
            cout << "Do you want to continue y/n ?  ";
            char ans;
            cin >> ans;
            if (ans == 'n' || ans == 'N') break;
        }
    }
    numberOfTeams++;
    ofstream writeFileStudents("students.txt", ios::app);
    writeFileStudents << tm.name << endl
        << tm.description << endl << tm.status << endl;
    writeFileStudents.close();
    //запис на броячите
    ofstream writeFileCounter("counter.txt");
    writeFileCounter << autoNumber << endl
        << numberOfStudents << endl
        << numberOfTeachers << endl
        << numberOfTeams << endl;
    writeFileCounter.close();
    cout << "Done!\n";
}

int main()
{
    WritingStudent();
    WritingTeacher();
    WritingTeam();
}