#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

//the following 5 rows initialize:
int autoNumber; //student ids
int numberOfStudents; //total number of students
int numberOfTeachers; //total number of teachers
int numberOfTeams; //total number of teams
int numberOfSchools; //total number of schools
int mainMenuFlag = false;
int inputingMenuFlag = false;

struct Student
	//creates a structure for every student's data
{
	int id;
	string name;
	string surname;
	string clas;
	string role;
	string email;
};

struct Teacher
	//creates a structure for every teacher's data
{
	int id;
	string name;
	string surname;
	string email;
};

struct School
	//creates a structure for every school and its address
{
	string city;
	string name;
	string list1;
	string list2;
};

struct Team
	//creates a structure for every team and member roles
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
//function which displays user's input, written in the file "students.txt"
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
//function which displays user's input, written in the file "teachers.txt"
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

void PrintSchool(School sc)
//function which displays user's input, written in the file "schools.txt"
{
	cout << "______________________________\n";
	cout << "Name of the school: " << sc.name << endl;
	cout << "Name of the city: " << sc.city << endl
		<< "______________________________\n";
}

void PrintTeam(Team tm)
//function which displays user's input, written in the file "teams.txt"
{
	cout << "______________________________\n";
	cout << left << "Name of the team : " << tm.name << endl
		<< right << setw(19) << "Description : "
		<< left << tm.description << endl
		<< right << setw(19) << "Status : "
		<< left << tm.status << endl
		<< right << setw(19) << "Mentor : "
		<< left << tm.mentor << endl
		<< right << setw(19) << "ScrumTrainer : "
		<< left << tm.scrumTrainer << endl
		<< right << setw(19) << "Frontend : "
		<< left << tm.frontend << endl
		<< right << setw(19) << "Backend : "
		<< left << tm.backend << endl
		<< right << setw(19) << "QualityEng : "
		<< left << tm.qualityEng << endl
		<< "______________________________\n";
}

void WritingStudent()
{
	//email verification
	bool successEmail = false;
	//role verification
	bool successRole = false;
	Student st;
	ifstream readFileCounter;
	readFileCounter.open("counter.txt");
	readFileCounter >> autoNumber;
	readFileCounter >> numberOfStudents;
	readFileCounter >> numberOfTeachers;
	readFileCounter >> numberOfTeams;
	readFileCounter >> numberOfSchools;
	readFileCounter.close();
	autoNumber++;
	st.id = autoNumber;
	cout << "\nReading student's data\n"
		<< "----------------------\n";
	cout << "Please, input the name of the student: ";
	cin >> st.name;
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
			//registers student data in the specified file
			numberOfStudents++;
			ofstream writeFileStudents("students.txt", ios::app);
			writeFileStudents << st.id << endl << st.name << endl
				<< st.surname << endl << st.role << endl
				<< st.email << endl;
			writeFileStudents.close();
			//registers counter data in the specified file
			ofstream writeFileCounter("counter.txt");
			writeFileCounter << autoNumber << endl
				<< numberOfStudents << endl
				<< numberOfTeachers << endl
				<< numberOfSchools << endl
				<< numberOfTeams << endl;
			writeFileCounter.close();
			cout << "Done!\n";
		}
	}
}

void WritingTeacher()
{
	bool successEmail = false; // checks email format
	Teacher te; //declaring a variable of type "Teacher"
	ifstream readFileCounter;
	readFileCounter.open("counter.txt");
	readFileCounter >> autoNumber;
	readFileCounter >> numberOfStudents;
	readFileCounter >> numberOfTeachers;
	readFileCounter >> numberOfSchools;
	readFileCounter >> numberOfTeams;
	readFileCounter.close();
	autoNumber++; //increases the consecutive student number
	te.id = autoNumber;
	cout << "Please, input the name of the teacher: ";
	cin >> te.name;
	cout << "Please, input the surname of the teacher: ";
	cin >> te.surname;

	numberOfTeachers++;

	while (!successEmail) // makes sure the email ends with @codingburgas.bg
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
	if (successEmail) //moves on as long as data is correct
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
				<< numberOfSchools << endl
				<< numberOfTeams << endl;
			writeFileCounter.close();
		}
		cout << "Done" << endl;
	}
}

void WritingSchool()
{
	School sc;
	ifstream readFileCounter;
	readFileCounter >> autoNumber;
	readFileCounter >> numberOfStudents;
	readFileCounter >> numberOfTeachers;
	readFileCounter >> numberOfSchools;
	readFileCounter >> numberOfTeams;
	ofstream writeFileTeams("teams.txt", ios::app);
	cout << "Please, input the name of the school: ";
	cin.ignore();
	getline(cin, sc.name);
	cout << "Please, input the city: ";
	getline(cin, sc.city);

	PrintSchool(sc);
	cout << "Save data: y/n ?  ";
	char ans;
	cin >> ans;
	if (ans == 'y' || ans == 'Y')
	{
		numberOfSchools++;
		ofstream writeFileSchools("schools.txt", ios::app);
		writeFileSchools << sc.name << endl << sc.city << endl;
		writeFileSchools.close();
		ofstream writeFileCounter("counter.txt");
		writeFileCounter << autoNumber << endl
			<< numberOfStudents << endl
			<< numberOfTeachers << endl
			<< numberOfSchools << endl
			<< numberOfTeams << endl;
		writeFileCounter.close();
	}
	cout << "Done" << endl;
}

void WritingTeam()
//function which inputs the status of each team
{
	Team tm;
	bool successStatus = false;
	ifstream readFileCounter;
	readFileCounter >> autoNumber;
	readFileCounter >> numberOfStudents;
	readFileCounter >> numberOfTeachers;
	readFileCounter >> numberOfSchools;
	readFileCounter >> numberOfTeams;
	ofstream writeFileTeams("teams.txt", ios::app);
	cout << "Please, input the name of the team: ";
	cin.ignore();
	getline(cin, tm.name);
	cout << "Please, input the description of the team: ";
	getline(cin, tm.description);
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
	vector <Student> students;
	ifstream readFileStudents("students.txt");
	Student st;
	while (readFileStudents) {
		readFileStudents >> st.id >> st.name >> st.surname
			>> st.clas >> st.role >> st.email;
		students.push_back(st);
	}
	readFileStudents.close();

	vector <Teacher> teachers;
	ifstream readFileTeachers("teachers.txt");
	Teacher te;
	while (readFileTeachers) {
		readFileTeachers >> te.id >> te.name >> te.surname >> te.email;
		if (readFileTeachers)
		{
			teachers.push_back(te);
		}
	}
	readFileTeachers.close();

	cout << "List of mentor's id: " << endl;
	int n = teachers.size();
	for (int i = 0; i < n; i++)
	{
		PrintTeacher(teachers[i]);
	}
	cout << "please choose the id of the mentor you want:";
	cin >> tm.mentor;

	cout << "List of scrum trainers by id: " << endl;
	n = students.size();
	for (int i = 0; i < n; i++)
	{
		if (students[i].role == "ScrumTrainer")
		{
			PrintStudent(students[i]);
		}
	}
	cout << "please choose the id of the scrum trainer you want:";
	cin >> tm.scrumTrainer;

	cout << "List of backend developers by id: " << endl;
	n = students.size();
	for (int i = 0; i < n; i++)
	{
		if (students[i].role == "Backend")
		{
			PrintStudent(students[i]);
		}
	}
	cout << "please choose the id of the backend developer you want:";
	cin >> tm.backend;

	cout << "List of frontend developer by id: " << endl;
	n = students.size();
	for (int i = 0; i < n; i++)
	{
		if (students[i].role == "frontend")
		{
			PrintStudent(students[i]);
		}
	}
	cout << "please choose the id of the frontend developer you want:";
	cin >> tm.frontend;

	cout << "List of quality engineers by id: " << endl;
	n = students.size();
	for (int i = 0; i < n; i++)
	{
		if (students[i].role == "qualityEng")
		{
			PrintStudent(students[i]);
		}
	}
	cout << "please choose the id of the quality engineer you want:";
	cin >> tm.qualityEng;

	PrintTeam(tm);
	numberOfTeams++;
	ofstream writeFileStudents("teams.txt", ios::app);
	writeFileStudents << tm.name << endl
		<< tm.description << endl << tm.status << endl;
	writeFileStudents.close();
	ofstream writeFileCounter("counter.txt");
	writeFileCounter << autoNumber << endl
		<< numberOfStudents << endl
		<< numberOfTeachers << endl
		<< numberOfSchools << endl
		<< numberOfTeams << endl;
	writeFileCounter.close();
	cout << "Done!\n";
}

void InputingMenu()
{
	int InputMenuChoice;
	cout << "1. Input student information." << endl;
	cout << "2. Input teacher information." << endl;
	cout << "3. Input school information." << endl;
	cout << "4. Input team information." << endl;
	cout << "5. Go to the main menu." << endl;
	cin >> InputMenuChoice;
	switch (InputMenuChoice)
	{
	case 1:
	{
		WritingStudent();
		break;
	}
	case 2:
	{
		WritingTeacher();
		break;
	}
	case 3:
	{
		WritingSchool();
		break;
	}
	case 4:
	{
		WritingTeam();
		break;
	}
	case 5:
	{
		inputingMenuFlag = true;
		break;
	}
	default:
	{
		cout << "Please, type a valid number:" << endl;
		cin >> InputMenuChoice;
	}
	}
}

void MainMenu() //program's main menu
{
	Student st;
	Team tm;
	School sc;
	Teacher te;
	int MainMenuChoice;
	cout << "Please, choose the menu you want to go to:" << endl;
	cout << "1. Inputing new information." << endl;
	cout << "2. Show information." << endl;
	cout << "3. Exit the program." << endl;
	cin >> MainMenuChoice;
	switch (MainMenuChoice)
	{
	case 1:
	{
		do
		{
			InputingMenu();
		} while (inputingMenuFlag != true);
		break;
	}
	case 2:
	{
		PrintStudent(st);
		PrintTeacher(te);
		PrintSchool(sc);
		PrintTeam(tm);
		break;
	}
	case 3:
	{
		mainMenuFlag = true;
		break;
	}
	default:
	{
		cout << "Please, input a valid number:" << endl;
		break;
	}
	}
}

int main()
{
	do
	{
		MainMenu();
	} while (mainMenuFlag != true);
	cout << "Thank you for using the program!" << endl;
}