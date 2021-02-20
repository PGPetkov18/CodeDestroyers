#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

//променливата, ко€то ще дава стойности на id-тата
int autoNumber;
//брой на записните ученици и учители
int numberOfStudents;
int numberOfTeachers;

struct Student
{
    int id;
    string name;
    string surname;
    string clas;
    string role;
    string email;
    string status;
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
    int DateOfSetUp;
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
        << right << setw(10) << "Status : "
        << left << st.status << endl
        << "______________________________\n";
}
void WritingStudent()
{
    //променлива, регистрираща дали има успешен вход на имейл
    bool successEmail = false;
    //променлива, регистрираща дали има успешен статус
    bool successStatus = false;
    bool successRole = false;
    Student st;
    ifstream readFileCounter;
    readFileCounter.open("counter.txt");
    readFileCounter >> autoNumber;
    readFileCounter >> numberOfStudents;
    readFileCounter >> numberOfTeachers;
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
        cout << "Please, choose the number of the student's role: "
            << endl << "1 - for scrum Trainer"
            << endl << "2 - for ....."
            << endl << "3 - for ....." << endl;
        int role;
        cin >> role;
        if (role == 1)
        {
            st.role = " ..... ";
            successRole = true;
        }
        else if (role == 2)
        {
            st.role = " ......";
            successRole = true;
        }
        else if (role == 3)
        {
            st.role = " .....";
            successRole = true;
        }
        else
        {
            cout << "Wrong role!" << endl;
            cout << "Do you want to continue y/n ?  ";
            char ans;
            cin >> ans;
            if (ans == 'n' || ans == 'N') break;
        }
    }

    while (!successEmail)
    {
        cout << "Please, input the email of the student: ";
        cin >> st.email;
        if (st.email.find("@codingburgas.bg") == -2)
        {
            cout << "Wrong email!" << endl;
            cout << "Do you want to continue y/n ?  ";
            char ans;
            cin >> ans;
            if (ans == 'n' || ans == 'N') break;
        }
        else successEmail = true;
    }
    while (!successStatus)
    {
        cout << "Please, choose status of the student: "
            << endl << "1 - for ....."
            << endl << "2 - for ....."
            << endl << "3 - for ....." << endl;
        int status;
        cin >> status;
        if (status == 1)
        {
            st.status = " ..... ";
            successStatus = true;
        }
        else if (status == 2)
        {
            st.status = " ......";
            successStatus = true;
        }
        else if (status == 3)
        {
            st.status = " .....";
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
    if (successEmail && successStatus && successRole)
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
                << st.email << endl << st.status << endl;
            writeFileStudents.close();
            //запис на бро€чите
            ofstream writeFileCounter("counter.txt");
            writeFileCounter << autoNumber << endl
                << numberOfStudents << endl
                << numberOfTeachers << endl;
            writeFileCounter.close();
            cout << "Done!\n";
        }
    }


}

void WritingTeacher()
{
    Teacher te;

    ifstream readFileCounter;
    readFileCounter.open("counter.txt");
    readFileCounter >> autoNumber;
    readFileCounter >> numberOfStudents;
    readFileCounter >> numberOfTeachers;
    readFileCounter.close();
    //даваме id na учител€ и увеличаваме променливата
    autoNumber++;
    te.id = autoNumber;
    cout << "Please, input the name of the teacher: ";
    cin >> te.name;
    cout << "Please, input the surname of the teacher: ";
    cin >> te.surname;
    cout << "Please, input the email of the teacher: ";
    cin >> te.email;
    numberOfTeachers++;
    ofstream writeFileTeachers("teachers.txt", ios::app);
    writeFileTeachers << te.id << endl << te.name << endl << te.surname << endl << te.email << endl;
    writeFileTeachers.close();
    ofstream writeFileCounter("counter.txt");
    writeFileCounter << autoNumber << endl
        << numberOfStudents << endl
        << numberOfTeachers << endl;
    writeFileCounter.close();
}

void WritingTeam()
{
    Team tm;
    ofstream writeFileTeams("teams.txt", ios::app);
    cout << "Please, input the name of the team: ";
    getline(cin, tm.name);
    cout << "Please, input the description of the team: ";
    getline(cin, tm.description);
    cout << "Please, input the email of the team: ";
    //cin >> tm.email;
}

int main()
{
    //WritingTeacher();
    int t = time(0);
    cout << t;
    WritingStudent();
}