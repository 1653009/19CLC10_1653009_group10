#include "program.h"

void login(Student* sL, int n, string in) {
	Student stu;
	bool check = false;
	int ch, count = 0;
	bool co = true;
	system("cls");
	cout << "Welcome to Student Management System" << endl;
	while (co) {
		cout << "\t\tLOGIN" << endl;
		cout << "\tUsername: ";
		if (count == 0)
			cin.ignore();
		getline(std::cin, stu.ID);
		cout << "\tPassword: ";
		stu.pass = "";
		while (ch = _getch()) {
			if (ch == 13) {
				for (int i = 0; i < n; i++) {
					if (stu.ID == sL[i].ID && stu.pass == sL[i].pass)
					{
						system("cls");
						cout << "\nLogin Success !" << endl;
						stu = sL[i];
						Logged(stu, n, sL, in);
						check = true;
						co = false;
						break;
					}

				}
				if (check == true)
					break;
				else {
					cout << "\nWrong user or password. Input again !" << endl;
					cout << "You have entered wrong 3 times system will disconnect !" << endl;
					stu.pass = "";
					count++;
					if (count == 3) {
						cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
						getchar();
						system ("cls");
						co = false;
						break;
					}
					break;
				}
			}
			else if (ch == 8) {
				if (stu.pass.length() > 0) {
					cout << "\b \b";
					stu.pass.erase(stu.pass.length() - 1);
				}
			}
			else {
				cout << "*";
				stu.pass += ch;
			}
		}

	}
}
void Logged(Student &stu, int n, Student *sL, string in) {
	int choose;
	cout << "Hello " << stu.FName << " " << stu.LName << "!" << endl;
	cout << "\t1. Profile" << endl;
	cout << "\t2. Change passsword" << endl;
	cout << "\t3. Check-in" << endl;
	cout << "\t4. View score of a course" << endl;
	cout << "\t5. View list of students in class" << endl;
	cout << "\t6. View Schedules" << endl;
	cout << "\tPress any key to log out." << endl;
	cout << "Input choose : ";
	cin >> choose;
	if (choose == 1) {
		system("cls");
		cout << "\tYOUR PROFILE" << endl;
		cout << "\tMSSV :" << stu.ID << endl;
		cout << "\tFull name :" << stu.FName << " " << stu.LName << endl;
		cout << "\tGender : " << stu.Sex << endl;
		cout << "\tDoB: " << stu.date << endl;
		cout << "Press Enter to go back." << endl;
		cin.ignore();
		getchar();
		system("cls");
		return Logged(stu, n, sL, in);
	}
	else if (choose == 2) {
		changepass(stu);
		cout << "\nPress Enter to go back." << endl;
		getchar();
		system("cls");
		return Logged(stu, n, sL, in);
	}
	else if (choose == 3) {
		system("cls");
		checkinStu(stu);
		OutputCheckin(sL, "CheckIn_" + in + "_NMLT.csv", 0);
		OutputCheckin(sL, "CheckIn_" + in + "_KTLT.csv", 1);
		cout << "Press Enter to go back." << endl;
		cin.ignore();
		getchar();
		system("cls");
		return Logged(stu, n, sL, in);
	}
	else if (choose == 4) {
		ViewScoreboard(in, sL);
		cout << "Press Enter to go back." << endl;
		cin.ignore();
		getchar();
		system("cls");
		return Logged(stu, n, sL, in);
	}
	else if (choose == 5) {
		system("cls");
		cout << "\t\t LIST CLASS :" << endl;
		cout << "\tID \t \t  FullName" << endl;
		for (int i = 0; i < n; i++) {
			cout << "\t" << sL[i].ID << " \t " << sL[i].FName << " " << sL[i].LName << endl;
		}
		cout << "Press enter to back!";
		cin.ignore();
		getchar();
		system("cls");
		return Logged(stu, n, sL, in);
	}
	else if (choose == 6) {
		system("cls");
		cout << "\t SCHEDULES" << endl;
		cout << endl;
		for (int i = 0; i < stu.count; i++)
		{
			cout << "Hoc ki " << stu.Courses[i].Semester;
			cout << ", " << stu.Courses[i].CourseID;
			cout << ", " << stu.Courses[i].CourseName;
			cout << ", [" << stu.Courses[i].StartDate;
			cout << " ~ " << stu.Courses[i].EndDate << "] ";
			cout << ", " << stu.Courses[i].DayofWeek;
			cout << "(" << stu.Courses[i].StartTime;
			cout << " - " << stu.Courses[i].EndTime << ")" << endl;
		}
		cout << "\nPress Enter to go back." << endl;
		cin.ignore();
		getchar();
		system("cls");
		return Logged(stu, n, sL, in);
	}
	else {
		cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
		system("cls");
	}
}

void changepass(Student &stu) {
	int ch, rech;
	string pass = "", repass = "";
	system("cls");
	cout << "\tCHANGE PASS" << endl;
	cin.ignore();
	cout << "Input new pass : ";
	while (ch = _getch()) {
		if (ch == 13) {
			break;
		}
		else if (ch == 8) {
			if (pass.length() > 0) {
				cout << "\b \b";
				pass.erase(pass.length() - 1);
			}
		}
		else {
			cout << "*";
			pass += ch;
		}
	}
	cout << "\nInput again : ";
	while (ch = _getch()) {
		if (ch == 13) {
			break;
		}
		else if (ch == 8) {
			if (repass.length() > 0) {
				cout << "\b \b";
				repass.erase(repass.length() - 1);
			}
		}
		else {
			cout << "*";
			repass += ch;
		}
	}
	if (pass == repass) {
		cout << "\nChange Success !" << endl;
		stu.pass = pass;
	}
	else
	{
		cout << "\nChange unsuccess !" << endl;
	}
}
int CountLine(string in) {
	fstream fin;
	fin.open(in, ios::in);
	int n = 0;
	if (fin.is_open()) {
		string temp;
		while (!fin.eof()) {
			getline(fin, temp, '\n');
			n++;
		}
	}
	if (!fin.is_open()) {
		fstream fin2;
		in.erase((in.length() - 4), 4);
		in += ".txt";
		fin2.open(in, ios::in);
		if (fin2.is_open()) {
			string temp;
			while (!fin2.eof()) {
				getline(fin2, temp, '\n');
				n++;
			}
		}
	}
	if (in.back() == 'v') return n;
	else return n - 1;
}

string getDoB(string date) {

	for (int i = 0; i < date.length(); i++) {
		if (date[i] == '/' || date[i] == '-') {
			date.erase(i, 1);
		}
	}
	return date;
}
void inputStudent(string in, Student *sL) {
	fstream fin;
	fin.open(in, ios::in);
	int dem = 0;
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, sL[dem].No, ',');
			getline(fin, sL[dem].ID, ',');
			getline(fin, sL[dem].FName, ',');
			getline(fin, sL[dem].LName, ',');
			getline(fin, sL[dem].Sex, ',');
			getline(fin, sL[dem].date, '\n');
			sL[dem].pass = sL[dem].ID + getDoB(sL[dem].date);
			dem++;
		}
		fin.close();
		outputStuTxt(in, sL, CountLine(in));
	}
	else if (!fin.is_open()) {
		string in2 = in;
		in2.erase(6, 4);
		in2 += ".txt";
		fstream fin2;
		fin2.open(in2, ios::in);
		while (dem < CountLine(in2)) {
			getline(fin2, sL[dem].No, ',');
			getline(fin2, sL[dem].ID, ',');
			getline(fin2, sL[dem].FName, ',');
			getline(fin2, sL[dem].LName, ',');
			getline(fin2, sL[dem].Sex, ',');
			getline(fin2, sL[dem].date, '\n');
			sL[dem].pass = sL[dem].ID + getDoB(sL[dem].date);
			dem++;
		}
		fin2.close();
	}
	else cout << "Unable to open " << in << endl;
}

void InputScore(Student*sL, int n, string in)
{

	for (int i = 0; i < n; i++)
		sL[i].score = new Score[2];
	in.erase((in.length() - 4), 4);
	string in2 = "Score_" + in + "_NMLT.csv";
	string in3 = "Score_" + in + "_KTLT.csv";
	fstream fin;
	fin.open(in2, ios::in);
	string next;
	int dem = 0;
	int i = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			while (i < n) {
				getline(fin, next, ',');
				getline(fin, sL[i].score[dem].Mid, ',');
				getline(fin, sL[i].score[dem].Final, ',');
				getline(fin, sL[i].score[dem].Lab, ',');
				getline(fin, sL[i].score[dem].Bonus, '\n');
				i++;
			}
			break;
		}
	}
	else if (!fin.is_open())
	{
		fstream fin2;
		in2.erase((in2.length() - 4), 4);
		in2 += ".txt";
		fin2.open(in2, ios::in);
		string next;
		int i = 0;
		if (fin2.is_open())
		{
			while (i < n) {
				getline(fin2, next, ',');
				getline(fin2, sL[i].score[dem].Mid, ',');
				getline(fin2, sL[i].score[dem].Final, ',');
				getline(fin2, sL[i].score[dem].Lab, ',');
				getline(fin2, sL[i].score[dem].Bonus, '\n');
				i++;
			}
		}
	}
	OutputScore(sL, in2, dem);
	dem++;
	fstream fin3;
	fin3.open(in3, ios::in);
	i = 0;
	if (fin3.is_open())
	{
		while (i < n) {
			getline(fin3, next, ',');
			getline(fin3, sL[i].score[dem].Mid, ',');
			getline(fin3, sL[i].score[dem].Final, ',');
			getline(fin3, sL[i].score[dem].Lab, ',');
			getline(fin3, sL[i].score[dem].Bonus, '\n');
			i++;
		}

	}
	else if (!fin3.is_open())
	{
		fstream fin4;
		in3.erase((in3.length() - 4), 4);
		in3 += ".txt";
		fin4.open(in3, ios::in);
		string next;
		int i = 0;
		if (fin4.is_open())
		{
			while (i < n) {
				getline(fin4, next, ',');
				getline(fin4, sL[i].score[dem].Mid, ',');
				getline(fin4, sL[i].score[dem].Final, ',');
				getline(fin4, sL[i].score[dem].Lab, ',');
				getline(fin4, sL[i].score[dem].Bonus, '\n');
				i++;
			}
		}
	}
	OutputScore(sL, in3, dem);
}

void OutputShedules(Student*sL, string in) //string in la ten file thoi khoa bieu CLC1.csv
{
	int n = CountLine(in);
	in.erase((in.length() - 4), 4);
	in += ".txt";
	ofstream fout;
	fout.open(in, ios::out);
	for (int i = 0; i < n; i++)
	{
		fout << i + 1 << "," << sL[0].Courses[i].CourseID << "," << sL[0].Courses[i].Year << "," << sL[0].Courses[i].CourseName << "," << sL[0].Courses[i].LecturerName;
		fout << "," << sL[0].Courses[i].StartDate << "," << sL[0].Courses[i].EndDate << "," << sL[0].Courses[i].StartTime << "," << sL[0].Courses[i].EndTime;
		fout << "," << sL[0].Courses[i].DayofWeek << "," << sL[0].Courses[i].Semester << endl;
	}
}

void OutputScore(Student*sL, string in, int dem)
{
	int n = CountLine(in);
	in.erase((in.length() - 4), 4);
	in += ".txt";
	ofstream fout;
	fout.open(in, ios::out);
	for (int i = 0; i < n; i++)
	{
		fout << sL[i].ID << "," << sL[i].score[dem].Mid << "," << sL[i].score[dem].Final << "," << sL[i].score[dem].Lab << "," << sL[i].score[dem].Bonus << endl;
	}
}


void outputStuTxt(string in, Student *sL, int n)
{
	ofstream fout;
	int i = 0;
	in.erase(6, 4);
	in += ".txt";
	fout.open(in, ios::out);
	if (fout.is_open()) {
		do {
			fout << sL[i].No;
			fout << "," << sL[i].ID;
			fout << "," << sL[i].FName;
			fout << "," << sL[i].LName;
			fout << "," << sL[i].Sex;
			fout << "," << sL[i].date << "\n";
			i++;
		} while (i < n);
		fout.close();
	}
	else cout << "Unable to open " << in << endl;
}

void InputSchedules(Student *sL, int i, string in2)
{
	sL[i].count = CountLine(in2);
	sL[i].Courses = new Schedules[CountLine(in2)];
	fstream fin2;
	fin2.open(in2, ios::in);
	string next;
	int dem = 0;
	if (fin2.is_open())
	{
		while (dem < CountLine(in2))
		{
			getline(fin2, sL[i].Courses[dem].No, ',');
			getline(fin2, sL[i].Courses[dem].CourseID, ',');
			getline(fin2, sL[i].Courses[dem].Year, ',');
			getline(fin2, sL[i].Courses[dem].CourseName, ',');
			getline(fin2, sL[i].Courses[dem].LecturerName, ',');
			getline(fin2, sL[i].Courses[dem].StartDate, ',');
			getline(fin2, sL[i].Courses[dem].EndDate, ',');
			getline(fin2, sL[i].Courses[dem].StartTime, ',');
			getline(fin2, sL[i].Courses[dem].EndTime, ',');
			getline(fin2, sL[i].Courses[dem].DayofWeek, ',');
			getline(fin2, sL[i].Courses[dem].Semester, '\n');

			dem++;
		}
	}
	else if (!fin2.is_open())
	{
		in2.erase((in2.length() - 4), 4);
		in2 += ".txt";
		fstream fin3;
		fin3.open(in2, ios::in);
		if (fin3.is_open())
		{
			while (dem < CountLine(in2))
			{
				getline(fin3, sL[i].Courses[dem].No, ',');
				getline(fin3, sL[i].Courses[dem].CourseID, ',');
				getline(fin3, sL[i].Courses[dem].Year, ',');
				getline(fin3, sL[i].Courses[dem].CourseName, ',');
				getline(fin3, sL[i].Courses[dem].LecturerName, ',');
				getline(fin3, sL[i].Courses[dem].StartDate, ',');
				getline(fin3, sL[i].Courses[dem].EndDate, ',');
				getline(fin3, sL[i].Courses[dem].StartTime, ',');
				getline(fin3, sL[i].Courses[dem].EndTime, ',');
				getline(fin3, sL[i].Courses[dem].DayofWeek, ',');
				getline(fin3, sL[i].Courses[dem].Semester, '\n');
				dem++;
			}
		}
	}
	else cout << "Unable to open " << in2 << endl;
}


int PrintCourseList(string in, string name, string semester)
{
	fstream fin;
	Course *tC;
	int check = 0;
	int n = CountLine(in);
	tC = new Course[n];
	fin.open(in, ios::in);
	string next;
	int dem = 0;
	if (fin.is_open()) {
		in = "18" + in;
		in.erase((in.length() - 4), 4);
		while (dem<CountLine(in)) {
			getline(fin, tC[dem].No, ',');
			getline(fin, tC[dem].CourseID, ',');
			getline(fin, tC[dem].Year, ',');
			getline(fin, tC[dem].CourseName, ',');
			getline(fin, tC[dem].LecturerName, ',');
			getline(fin, tC[dem].StartDate, ',');
			getline(fin, tC[dem].EndDate, ',');
			getline(fin, tC[dem].StartTime, ',');
			getline(fin, tC[dem].EndTime, ',');
			getline(fin, tC[dem].DayofWeek, ',');
			getline(fin, tC[dem].Semester, '\n');
			if (tC[dem].LecturerName == name && tC[dem].Semester == semester)
			{
				cout << in << ":  ";
				cout << tC[dem].CourseID;
				cout << ", " << tC[dem].CourseName;
				cout << ", hoc ki " << tC[dem].Semester;
				cout << ", [" << tC[dem].StartDate;
				cout << " ~ " << tC[dem].EndDate << "] ";
				cout << ", " << tC[dem].DayofWeek;
				cout << "(" << tC[dem].StartTime;
				cout << " - " << tC[dem].EndTime << ")" << endl;
				check++;
			}
			//else if (tC[dem].LecturerName == name && tC[dem].Semester != semester)
			//{
			//	check++;
			//}
			dem++;
		}
		fin.close();
		return check;
	}
	else if (!fin.is_open()) {
		string in2 = in;
		in2.erase((in2.length() - 4), 4);
		in2 += ".txt";
		fstream fin2;
		fin2.open(in2, ios::in);
		if (fin2.is_open()) {
			int temp1 = CountLine(in2);
			in2 = "18" + in2;
			while (dem < temp1) {
				getline(fin2, tC[dem].No, ',');
				getline(fin2, tC[dem].CourseID, ',');
				getline(fin2, tC[dem].Year, ',');
				getline(fin2, tC[dem].CourseName, ',');
				getline(fin2, tC[dem].LecturerName, ',');
				getline(fin2, tC[dem].StartDate, ',');
				getline(fin2, tC[dem].EndDate, ',');
				getline(fin2, tC[dem].StartTime, ',');
				getline(fin2, tC[dem].EndTime, ',');
				getline(fin2, tC[dem].DayofWeek, ',');
				getline(fin2, tC[dem].Semester, '\n');
				if (tC[dem].LecturerName == name && tC[dem].Semester == semester)
				{
					in2.erase((in2.length() - 4), 4);
					cout << in2 << ":  ";
					cout << tC[dem].CourseID;
					cout << ", " << tC[dem].CourseName;
					cout << ", hoc ki " << tC[dem].Semester;
					cout << ", [" << tC[dem].StartDate;
					cout << " ~ " << tC[dem].EndDate << "] ";
					cout << ", " << tC[dem].DayofWeek;
					cout << "(" << tC[dem].StartTime;
					cout << " - " << tC[dem].EndTime << ")" << endl;
					check++;
				}
				dem++;
			}
			fin2.close();
			return check;
		}

	}
}

void ListofCourse(string name) //name la ten giao vien
{
	string choose;
	int check = 0;
	cout << "Choose a Semester:" << endl;
	cout << "\t1. Semester 1" << endl;
	cout << "\t2. Semester 2" << endl;
	cout << "\t0. EXIT" << endl;
	cout << "Input your choice: ";
	cin >> choose;
	if (choose == "0") return;
	if (choose != "0") {
		while (choose != "1" && choose != "2")
		{
			if (choose == "0") return;
			cout << "ERROR. Input your choice: ";
			cin >> choose;
		}
		cout << endl << "This is your course in Semester " << choose << endl;
		check += PrintCourseList("CLC1.csv", name, choose);
		check += PrintCourseList("CLC2.csv", name, choose);
		check += PrintCourseList("CLC3.csv", name, choose);
		check += PrintCourseList("CLC4.csv", name, choose);
		check += PrintCourseList("CLC5.csv", name, choose);
		if (check == 0)
			cout << "\n\tNo course available." << endl;
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		ListofCourse(name);
	}
}


void ListStudentofCourse(string name) // name la ten giao vien
{
	Student *sL;
	string cla;
	string choose;
	int check = 0;
	cout << "Choose a Semester:" << endl;
	cout << "\t1. Semester 1" << endl;
	cout << "\t2. Semester 2" << endl;
	cout << "\t0. EXIT" << endl;
	cout << "Input your choice: ";
	cin >> choose;
	if (choose == "0") return;
	if (choose != "0") {
		while (choose != "1" && choose != "2")
		{
			if (choose == "0") return;
			cout << "ERROR. Input your choice: ";
			cin >> choose;
		}
		cout << endl;
		check += PrintCourseList("CLC1.csv", name, choose);
		check += PrintCourseList("CLC2.csv", name, choose);
		check += PrintCourseList("CLC3.csv", name, choose);
		check += PrintCourseList("CLC4.csv", name, choose);
		check += PrintCourseList("CLC5.csv", name, choose);
		if (check != 0) {
			cout << "This is your course in this semester.\nChoose a class to view list of student in your course (Ex 18CLC1, 18CLC2): ";
			cin >> cla;
			while (cla != "18CLC1" && cla != "18CLC2" && cla != "18CLC3" && cla != "18CLC4" && cla != "18CLC5")
			{
				cout << "Error. Please make sure that you input the right name of class(Ex 18CLC1, 18CLC2)\nInput again: ";
				cin >> cla;
			}
			cla += ".csv";
			int n6 = CountLine(cla);
			if (n6 == 0) {
				cla.erase(6, 4);
				cla += ".txt";
				n6 = CountLine(cla);
			}
			sL = new Student[n6];
			inputStudent(cla, sL);
			cout << "List of Student:" << endl;
			for (int dem = 0; dem < n6; dem++)
			{
				cout << "\t" << sL[dem].No << " ";
				cout << sL[dem].FName << " " << sL[dem].LName << endl;
			}
			cout << "\nPress Enter to go back...";
			cin.ignore();
			getchar();
			system("cls");
			ListStudentofCourse(name);
		}
		else {
			cout << "\n\tNo course available." << endl;
			cout << "\nPress Enter to go back...";
			cin.ignore();
			getchar();
			system("cls");
			ListStudentofCourse(name);
		}
	}
}



void EditGrade(string cla, Student*sL) //cla="18CLC1"
{
	int stu, subj, score;
	system("cls");
	cout << "List of Courses of Class " << cla << ": " << endl;
	cla.erase(0, 2);
	cla += ".csv"; // ->  cla="CLC1.csv"
	for (int i = 0; i < CountLine(cla); i++)
	{
		cout << i + 1 << ". " << sL[0].Courses[i].CourseName << endl;
	}
	cout << "0. EXIT" << endl;
	cout << "Choose a course to Edit Grade: ";
	cin >> subj;
	if (subj == 0) return;
	if (subj != 0) {
		while (subj < 0 || subj > CountLine(cla))
		{
			cout << "ERROR. Choose again: ";
			cin >> subj;
			if (subj == 0) return;
		}

		system("cls");
		cout << "Choose student:" << endl;
		cla = "18" + cla; // -> cla="18CLC1.csv"
		for (int i = 0; i < CountLine(cla); i++)
		{
			cout << i + 1 << ". " << sL[i].FName << " " << sL[i].LName << endl;
		}
		cout << "Choose a student: ";
		cin >> stu;
		while (stu < 1 || stu > CountLine(cla))
		{
			cout << "ERROR. Choose again: ";
			cin >> stu;
		}
		system("cls");
		cout << "1. Midterm\n2. Final\n3. Lab\n4. Bonus" << endl;
		cout << "Choose one to edit: ";
		cin >> score;
		while (score < 1 || score > 4)
		{
			cout << "ERROR. Choose again: ";
			cin >> score;
		}
		system("cls");
		if (score == 1) {
			cout << "Student " << sL[stu - 1].FName << " " << sL[stu - 1].LName << ":  Old Midterm score: " << sL[stu - 1].score[subj - 1].Mid << endl;
			cout << "Input new score: ";
			int temp;
			cin >> temp;
			while (temp < 0 || temp>10)
			{
				cout << "Are you kidding me? Input again: ";
				cin >> temp;
			}
			sL[stu - 1].score[subj - 1].Mid = to_string(temp);
		}
		else if (score == 2) {
			cout << "Student " << sL[stu - 1].FName << " " << sL[stu - 1].LName << ":  Old Final score: " << sL[stu - 1].score[subj - 1].Final << endl;
			cout << "Input new score: ";
			int temp;
			cin >> temp;
			while (temp < 0 || temp>10)
			{
				cout << "Are you kidding me? Input again: ";
				cin >> temp;
			}
			sL[stu - 1].score[subj - 1].Final = to_string(temp);
		}
		else if (score == 3) {
			cout << "Student " << sL[stu - 1].FName << " " << sL[stu - 1].LName << ":  Old Lab score: " << sL[stu - 1].score[subj - 1].Lab << endl;
			cout << "Input new score: ";
			int temp;
			cin >> temp;
			while (temp < 0 || temp>10)
			{
				cout << "Are you kidding me? Input again: ";
				cin >> temp;
			}
			sL[stu - 1].score[subj - 1].Lab = to_string(temp);
		}
		else if (score == 4) {
			cout << "Student " << sL[stu - 1].FName << " " << sL[stu - 1].LName << ":  Old Bonus score: " << sL[stu - 1].score[subj - 1].Bonus << endl;
			cout << "Input new score: ";
			int temp;
			cin >> temp;
			while (temp < 0 || temp>10)
			{
				cout << "Are you kidding me? Input again: ";
				cin >> temp;
			}
			sL[stu - 1].score[subj - 1].Bonus = to_string(temp);
		}
		cout << "Edit score successfully";
		cout << "\nPress Enter to go back...";
		cla.erase(6, 4);
		cin.ignore();
		getchar();
		system("cls");
		return EditGrade(cla, sL);
	}
}
void ViewScoreboard(string cla, Student*sL)
{
	int choose;
	system("cls");
	cout << "List of Courses of Class " << cla << ": " << endl;
	cla.erase(0, 2);
	cla += ".csv";
	for (int i = 0; i < CountLine(cla); i++)
	{
		cout << i + 1 << ". " << sL[0].Courses[i].CourseName << endl;
	}
	cout << "0. EXIT" << endl;
	cout << "Choose a course to View Score Board: ";
	cin >> choose;
	if (choose == 0) return;
	if (choose != 0) {
		while (choose < 0 || choose > CountLine(cla))
		{
			cout << "ERROR. Choose again: ";
			cin >> choose;
			if (choose == 0) return;
		}
		system("cls");
		for (int i = 0; i < CountLine(cla); i++)
		{
			if (i == choose - 1) {
				cla = "18" + cla;
				cout << "Score Board of " << sL[0].Courses[i].CourseName << endl;
				for (int j = 0; j < CountLine(cla); j++)
				{
					cout << sL[j].No << ". " << sL[j].FName << " " << sL[j].LName << ":\t";
					cout << "Mid: " << sL[j].score[i].Mid;
					cout << "  Final: " << sL[j].score[i].Final;
					cout << "  Lab: " << sL[j].score[i].Lab;
					cout << "  Bonus: " << sL[j].score[i].Bonus << endl;
				}
			}
		}
		cla.erase(6, 4);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return ViewScoreboard(cla, sL);
	}
}

void LoggedLecturer(string name, Student*sL1, Student*sL2, Student*sL3, Student*sL4, Student*sL5)
{
	int choose;
	cout << "\t1. View list of course" << endl;
	cout << "\t2. View list of student of a course" << endl;
	cout << "\t3. View attendance list of a course" << endl;
	cout << "\t4. Edit an attendance" << endl;
	cout << "\t5. Edit grade of a student" << endl;
	cout << "\t6. View scoreboard" << endl;
	cout << "\t0. EXIT" << endl;
	cout << "Input your choice: ";
	cin >> choose;
	while (choose < 0 || choose>6)
	{
		cout << "ERROR. Input your choice: ";
		cin >> choose;
	}
	if (choose == 1) {
		system("cls");
		ListofCourse(name);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedLecturer(name, sL1, sL2, sL3, sL4, sL5);
	}
	if (choose == 2) {
		system("cls");
		ListStudentofCourse(name);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedLecturer(name, sL1, sL2, sL3, sL4, sL5);
	}
	if (choose == 3) {
		system("cls");
		Student* Cla = new Student;
		string cla;
		int n;
		cout << "View Attendance: " << endl;
		cout << "\t1. 18CLC1\n\t2. 18CLC2\n\t3. 18CLC3\n\t4. 18CLC4\n\t5. 18CLC5\n\t0. EXIT" << endl;
		cout << "Choose a class: ";
		cin >> n;
		while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
		{
			cout << "ERROR. Input again: ";
			cin >> n;
		}
		if (n == 1) {
			cla = "18CLC1";
			Cla = sL1;
		}
		else if (n == 2) {
			cla = "18CLC2";
			Cla = sL2;
		}
		else if (n == 3) {
			cla = "18CLC3";
			Cla = sL3;
		}
		else if (n == 4) {
			cla = "18CLC4";
			Cla = sL4;
		}
		else if (n == 5) {
			cla = "18CLC5";
			Cla = sL5;
		}
		else if (n == 0) {
			system("cls");
			return LoggedLecturer(name, sL1, sL2, sL3, sL4, sL5);
		}
		viewCheckin(cla, Cla);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedLecturer(name, sL1, sL2, sL3, sL4, sL5);
	}
	if (choose == 4) {
		system("cls");
		Student* Cla = new Student;
		string cla;
		int n;
		cout << "Edit Attendance of a class:" << endl;
		cout << "\t1. 18CLC1\n\t2. 18CLC2\n\t3. 18CLC3\n\t4. 18CLC4\n\t5. 18CLC5\n\t0. EXIT" << endl;
		cout << "Choose a Class to Edit Attendance: ";
		cin >> n;
		while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
		{
			cout << "ERROR. Input again: ";
			cin >> n;
		}
		if (n == 1) {
			cla = "18CLC1";
			Cla = sL1;
		}
		else if (n == 2) {
			cla = "18CLC2";
			Cla = sL2;
		}
		else if (n == 3) {
			cla = "18CLC3";
			Cla = sL3;
		}
		else if (n == 4) {
			cla = "18CLC4";
			Cla = sL4;
		}
		else if (n == 5) {
			cla = "18CLC5";
			Cla = sL5;
		}
		else if (n == 0) {
			system("cls");
			return LoggedLecturer(name, sL1, sL2, sL3, sL4, sL5);
		}
		editCheckin(cla, Cla);
		OutputCheckin(Cla, "CheckIn_" + cla + "_NMLT.csv", 0);
		OutputCheckin(Cla, "CheckIn_" + cla + "_KTLT.csv", 1);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedLecturer(name, sL1, sL2, sL3, sL4, sL5);
	}
	if (choose == 5) {
		system("cls");
		Student* Cla = new Student;
		string cla;
		int n;
		cout << "Edit grade of a student:" << endl;
		cout << "\t1. 18CLC1\n\t2. 18CLC2\n\t3. 18CLC3\n\t4. 18CLC4\n\t5. 18CLC5\n\t0. EXIT" << endl;
		cout << "Choose a Class to Edit Grade: ";
		cin >> n;
		while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
		{
			cout << "ERROR. Input again: ";
			cin >> n;
		}
		if (n == 1) {
			cla = "18CLC1";
			Cla = sL1;
		}
		else if (n == 2) {
			cla = "18CLC2";
			Cla = sL2;
		}
		else if (n == 3) {
			cla = "18CLC3";
			Cla = sL3;
		}
		else if (n == 4) {
			cla = "18CLC4";
			Cla = sL4;
		}
		else if (n == 5) {
			cla = "18CLC5";
			Cla = sL5;
		}
		else if (n == 0) {
			system("cls");
			return LoggedLecturer(name, sL1, sL2, sL3, sL4, sL5);
		}
		EditGrade(cla, Cla);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedLecturer(name, sL1, sL2, sL3, sL4, sL5);
	}
	if (choose == 6) {
		system("cls");
		Student* Cla = new Student;
		string cla;
		int n;
		cout << "View Score Board: " << endl;
		cout << "\t1. 18CLC1\n\t2. 18CLC2\n\t3. 18CLC3\n\t4. 18CLC4\n\t5. 18CLC5\n\t0. EXIT" << endl;
		cout << "Choose a class: ";
		cin >> n;
		while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
		{
			cout << "ERROR. Input again: ";
			cin >> n;
		}
		if (n == 1) {
			cla = "18CLC1";
			Cla = sL1;
		}
		else if (n == 2) {
			cla = "18CLC2";
			Cla = sL2;
		}
		else if (n == 3) {
			cla = "18CLC3";
			Cla = sL3;
		}
		else if (n == 4) {
			cla = "18CLC4";
			Cla = sL4;
		}
		else if (n == 5) {
			cla = "18CLC5";
			Cla = sL5;
		}
		else if (n == 0) {
			system("cls");
			return LoggedLecturer(name, sL1, sL2, sL3, sL4, sL5);
		}
		ViewScoreboard(cla, Cla);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedLecturer(name, sL1, sL2, sL3, sL4, sL5);
	}
	if (choose == 0) {
		cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
		return;
	}
}
void AddCourse(Student& stu) {
	system("cls");
	int count = stu.count;
	Schedules *temp = new Schedules[count + 1];
	for (int i = 0; i < stu.count; i++) {
		CopyCourse(stu.Courses[i], temp[i]);
	}
	stu.count++;
	cout << "\tADD NEW COURSE " << endl;
	temp[count].No = stu.count;
	cout << "Input Course ID : ";
	cin.ignore();
	getline(std::cin, temp[count].CourseID);
	cout << "Input Year ( Ex: 2019-2020) : ";

	getline(std::cin, temp[count].Year);
	cout << "Input Name Course : ";
	getline(std::cin, temp[count].CourseName);
	cout << "Input Account Lecture : ";

	getline(std::cin, temp[count].LecturerName);
	cout << "Input Start Day : ";

	getline(std::cin, temp[count].StartDate);
	cout << "Input End Day : ";

	getline(std::cin, temp[count].EndDate);
	cout << "Input Start Time : ";

	getline(std::cin, temp[count].StartTime);
	cout << "Input End Time : ";

	getline(std::cin, temp[count].EndTime);
	cout << "Input Day of Week : ";

	getline(std::cin, temp[count].DayofWeek);
	cout << "Input Semester : ";

	getline(std::cin, temp[count].Semester);

	stu.Courses = new Schedules[count + 1];
	for (int i = 0; i < stu.count; i++) {
		CopyCourse(temp[i], stu.Courses[i]);
	}
	delete[]temp;
}
void CopyCourse(Schedules sch, Schedules &result) {
	result.No = sch.No;
	result.CourseID = sch.CourseID;
	result.Year = sch.Year;
	result.CourseName = sch.CourseName;
	result.LecturerName = sch.LecturerName;
	result.StartDate = sch.StartDate;
	result.EndDate = sch.EndDate;
	result.StartTime = sch.StartTime;
	result.EndTime = sch.EndTime;
	result.DayofWeek = sch.DayofWeek;
	result.Semester = sch.Semester;
}

Student* AddStudent(Student*sL, int &n, string in) {
	Student *temp = new Student[n + 1];
	for (int i = 0; i < n; i++) {
		CopyStudent(sL[i], temp[i]);
	}
	system("cls");
	cout << "\tADD STUDENT" << endl;
	temp[n].No = to_string(n + 1);
	cout << "Input ID : ";
	cin.ignore();
	getline(std::cin, temp[n].ID);
	cout << "Input First Name : ";
	getline(std::cin, temp[n].FName);
	cout << "Input Last Name : ";
	getline(std::cin, temp[n].LName);
	cout << "Input gender : ";
	getline(std::cin, temp[n].Sex);
	cout << "Input Date of Birth (Ex : 10/10/2010) : ";
	getline(std::cin, temp[n].date);
	temp[n].pass = temp[n].ID + getDoB(temp[n].date);
	n++;
	delete[] sL;
	sL = new Student[n];
	sL = temp;
	return sL;
}

void CopyStudent(Student stu, Student &result) {
	result.No = stu.No;
	result.ID = stu.ID;
	result.FName = stu.FName;
	result.LName = stu.LName;
	result.Sex = stu.Sex;
	result.date = stu.date;
	result.count = stu.count;
	result.pass = stu.pass;

}
void CopyScore(Score sco, Score &result) {
	result.Bonus = sco.Bonus;
	result.Final = sco.Final;
	result.Lab = sco.Lab;
	result.Mid = sco.Mid;
}


void InputLecture(Lecture* l, string in) {
	fstream fin;
	int n = CountLine(in);
	fin.open(in, ios::in);
	if (fin.is_open()) {
		for (int i = 0; i < n; i++) {
			getline(fin, l[i].ID, ',');
			getline(fin, l[i].Name, '\n');
			l[i].pass = l[i].ID + "123";
		}
		fin.close();
	}
	else if (!fin.is_open()) {
		fstream fin2;
		in.erase(in.length() - 4, 4);
		in += ".txt";
		fin2.open(in, ios::in);
		for (int i = 0; i < n; i++) {
			getline(fin2, l[i].ID, ',');
			getline(fin2, l[i].Name, '\n');
			l[i].pass = l[i].ID + "123";
		}
		fin2.close();
	}
	else cout << "Unable to open file !" << endl;
}


void loginLecture(Lecture* l, int n, Student*sL1, Student*sL2, Student*sL3, Student*sL4, Student*sL5) {
	Lecture lec;
	bool check = false;
	int ch, count = 0;
	bool co = true;
	system("cls");
	cout << "Welcome to Student Management System" << endl;
	while (co) {
		cout << "\t\tLOGIN" << endl;
		cout << "\tUsername: ";
		if (count == 0)
			cin.ignore();
		getline(std::cin, lec.ID);
		cout << "\tPassword: ";
		lec.pass = "";
		while (ch = _getch()) {
			if (ch == 13) {
				for (int i = 0; i < n; i++) {
					if (lec.ID == l[i].ID && lec.pass == l[i].pass)
					{
						system("cls");
						cout << "\nLogin Success !" << endl;
						lec = l[i];
						cout << "Hello " << l[i].Name << endl;
						LoggedLecturer(lec.ID, sL1, sL2, sL3, sL4, sL5);
						check = true;
						co = false;
						break;
					}

				}
				if (check == true)
					break;
				else {
					cout << "\nWrong user or password. Input again !" << endl;
					cout << "You have entered wrong 3 times system will disconnect !" << endl;
					lec.pass = "";
					count++;
					if (count == 3) {
						cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
						co = false;
						break;
					}
					break;
				}
			}
			else if (ch == 8) {
				if (lec.pass.length() > 0) {
					cout << "\b \b";
					lec.pass.erase(lec.pass.length() - 1);
				}
			}
			else {
				cout << "*";
				lec.pass += ch;
			}
		}
	}
}
void InputStaff(Staff* sT, string in) {
	fstream fin;
	int n = CountLine(in);
	fin.open(in, ios::in);
	if (fin.is_open()) {
		for (int i = 0; i < n; i++) {
			getline(fin, sT[i].ID, ',');
			getline(fin, sT[i].Name, '\n');
			sT[i].pass = sT[i].ID + "giaovu";
		}
		fin.close();
	}
	else if (!fin.is_open()) {
		fstream fin2;
		in.erase(in.length() - 4, 4);
		in += ".txt";
		fin2.open(in, ios::in);
		for (int i = 0; i < n; i++) {
			getline(fin2, sT[i].ID, ',');
			getline(fin2, sT[i].Name, '\n');
			sT[i].pass = sT[i].ID + "giaovu";
		}
		fin2.close();
	}
	else cout << "Unable to open file !" << endl;
}
void loginStaff(Staff*sT, int n, Student*sL1, Student*sL2, Student*sL3, Student*sL4, Student*sL5, Lecture*l) {
	Staff staff;
	bool check = false;
	int ch, count = 0;
	bool co = true;
	system("cls");
	cout << "Welcome to Student Management System" << endl;
	while (co) {
		cout << "\t\tLOGIN" << endl;
		cout << "\tUsername: ";
		if (count == 0)
			cin.ignore();
		getline(std::cin, staff.ID);
		cout << "\tPassword: ";
		staff.pass = "";
		while (ch = _getch()) {
			if (ch == 13) {
				for (int i = 0; i < n; i++) {
					if (staff.ID == sT[i].ID && staff.pass == sT[i].pass)
					{
						system("cls");
						cout << "\nLogin Success !" << endl;
						staff = sT[i];
						cout << "Hello " << sT[i].Name << endl;
						LoggedStaff(staff.ID, sL1, sL2, sL3, sL4, sL5, l);
						check = true;
						co = false;
						break;
					}

				}
				if (check == true)
					break;
				else {
					cout << "\nWrong user or password. Input again !" << endl;
					cout << "You have entered wrong 3 times system will disconnect !" << endl;
					staff.pass = "";
					count++;
					if (count == 3) {
						cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
						co = false;
						break;
					}
					break;
				}
			}
			else if (ch == 8) {
				if (staff.pass.length() > 0) {
					cout << "\b \b";
					staff.pass.erase(staff.pass.length() - 1);
				}
			}
			else {
				cout << "*";
				staff.pass += ch;
			}
		}
	}
}
void LoggedStaff(string name, Student*sL1, Student*sL2, Student*sL3, Student*sL4, Student*sL5, Lecture*l) {
	int choose;
	int count;
	cout << "\t1. Add a new student to a class." << endl;
	cout << "\t2. View list of course" << endl;
	cout << "\t3. View list of student of a course" << endl;
	cout << "\t4. View attendance list of a course" << endl;
	cout << "\t5. Edit an attendance" << endl;
	cout << "\t6. Import scoreboard of a course (midterm, final, lab, bonus) from a csv file" << endl;
	cout << "\t7. Edit grade of a student" << endl;
	cout << "\t8. View scoreboard" << endl;
	cout << "\t9. Edit course" << endl;
	cout << "\t10. Remove student" << endl;
	cout << "\t0. EXIT" << endl;
	cout << "Input your choice: ";
	cin >> choose;
	while (choose < 0 || choose>10)
	{
		cout << "ERROR. Input your choice: ";
		cin >> choose;
	}
	if (choose == 1) {
		int n;
		string cla;
		Student* Cla = new Student;
		system("cls");
		cout << "\tADD A NEW STUDENT." << endl << endl;
		cout << "\t1. 18CLC1\n\t2. 18CLC2\n\t3. 18CLC3\n\t4. 18CLC4\n\t5. 18CLC5\n\t0. EXIT" << endl;
		cout << "Choose a Class to Add a Student: ";
		cin >> n;
		while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
		{
			cout << "ERROR. Input again: ";
			cin >> n;
		}
		if (n == 1) {
			cla = "18CLC1";
			Cla = sL1;
		}
		else if (n == 2) {
			cla = "18CLC2";
			Cla = sL2;
		}
		else if (n == 3) {
			cla = "18CLC3";
			Cla = sL3;
		}
		else if (n == 4) {
			cla = "18CLC4";
			Cla = sL4;
		}
		else if (n == 5) {
			cla = "18CLC5";
			Cla = sL5;
		}
		else if (n == 0) {
			system("cls");
			return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
		}
		cla = cla + ".csv";
		int count = CountLine(cla);
		cla.erase(0, 2);
		Cla = AddStudent(Cla, count, cla);
		for (int i = 0; i < count; i++)
		{
			InputSchedules(Cla, i, cla);
		}
		cla = "18" + cla;
		InputScore(Cla, count, cla);
		outputStuTxt(cla, Cla, count);
		cout << "Add success !" << endl;
		cout << "Press Enter to back !";
		getchar();
		system("cls");
		if (cla == "18CLC1.csv")
		{
			sL1 = Cla;
		}
		if (cla == "18CLC2.csv")
		{
			sL2 = Cla;
		}
		if (cla == "18CLC3.csv")
		{
			sL3 = Cla;
		}
		if (cla == "18CLC4.csv")
		{
			sL4 = Cla;
		}
		if (cla == "18CLC5.csv")
		{
			sL5 = Cla;
		}
		return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
	}
	if (choose == 2) {
		system("cls");
		cout << "1. Le Hoang Thai (lhthai)" << endl; 
		cout << "2. Nguyen Minh Huy (nmhuy)" << endl;
		string temp;
		int choice;
		cin >> choice;
		if (choice == 1)
			temp = "lhthai";
		else temp = "nmhuy";
		for (int i = 0; i < sL1[0].count; i++) {
			if (sL1[0].Courses[i].LecturerName == temp)
			{
				cout << "Class 18CLC1 , ";
				cout << sL1[0].Courses[i].CourseID;
				cout << ", " << sL1[0].Courses[i].CourseName;
				cout << ", hoc ki " << sL1[0].Courses[i].Semester;
				cout << ", [" << sL1[0].Courses[i].StartDate;
				cout << " ~ " << sL1[0].Courses[i].EndDate << "] ";
				cout << ", " << sL1[0].Courses[i].DayofWeek;
				cout << "(" << sL1[0].Courses[i].StartTime;
				cout << " - " << sL1[0].Courses[i].EndTime << ")" << endl;
			}
				
		}
		for (int i = 0; i < sL2[0].count; i++) {
			if (sL2[0].Courses[i].LecturerName == temp)
			{
				cout << "Class 18CLC2 , ";
				cout << sL2[0].Courses[i].CourseID;
				cout << ", " << sL2[0].Courses[i].CourseName;
				cout << ", hoc ki " << sL2[0].Courses[i].Semester;
				cout << ", [" << sL2[0].Courses[i].StartDate;
				cout << " ~ " << sL2[0].Courses[i].EndDate << "] ";
				cout << ", " << sL2[0].Courses[i].DayofWeek;
				cout << "(" << sL2[0].Courses[i].StartTime;
				cout << " - " << sL2[0].Courses[i].EndTime << ")" << endl;
			}

		}
		for (int i = 0; i < sL3[0].count; i++) {
			if (sL3[0].Courses[i].LecturerName == temp)
			{
				cout << "Class 18CLC3 , ";
				cout << sL3[0].Courses[i].CourseID;
				cout << ", " << sL3[0].Courses[i].CourseName;
				cout << ", hoc ki " << sL3[0].Courses[i].Semester;
				cout << ", [" << sL3[0].Courses[i].StartDate;
				cout << " ~ " << sL3[0].Courses[i].EndDate << "] ";
				cout << ", " << sL3[0].Courses[i].DayofWeek;
				cout << "(" << sL3[0].Courses[i].StartTime;
				cout << " - " << sL3[0].Courses[i].EndTime << ")" << endl;
			}

		}
		for (int i = 0; i < sL4[0].count; i++) {
			if (sL4[0].Courses[i].LecturerName == temp)
			{
				cout << "Class 18CLC4 , ";
				cout << sL4[0].Courses[i].CourseID;
				cout << ", " << sL4[0].Courses[i].CourseName;
				cout << ", hoc ki " << sL4[0].Courses[i].Semester;
				cout << ", [" << sL4[0].Courses[i].StartDate;
				cout << " ~ " << sL4[0].Courses[i].EndDate << "] ";
				cout << ", " << sL4[0].Courses[i].DayofWeek;
				cout << "(" << sL4[0].Courses[i].StartTime;
				cout << " - " << sL4[0].Courses[i].EndTime << ")" << endl;
			}

		}
		for (int i = 0; i < sL5[0].count; i++) {
			if (sL5[0].Courses[i].LecturerName == temp)
			{
				cout << "Class 18CLC5 , ";
				cout << sL5[0].Courses[i].CourseID;
				cout << ", " << sL5[0].Courses[i].CourseName;
				cout << ", hoc ki " << sL5[0].Courses[i].Semester;
				cout << ", [" << sL5[0].Courses[i].StartDate;
				cout << " ~ " << sL5[0].Courses[i].EndDate << "] ";
				cout << ", " << sL5[0].Courses[i].DayofWeek;
				cout << "(" << sL5[0].Courses[i].StartTime;
				cout << " - " << sL5[0].Courses[i].EndTime << ")" << endl;
			}

		}

		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
	}
	if (choose == 3) {
		system("cls");
		cout << "1. Le Hoang Thai (lhthai)" << endl;
		cout << "2. Nguyen Minh Huy (nmhuy)" << endl;
		string temp;
		int choice;
		cin >> choice;
		if (choice == 1)
			temp = "lhthai";
		else temp = "nmhuy";
		ListStudentofCourse(temp);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
	}
	if (choose == 4) {
		system("cls");
		Student* Cla = new Student;
		string cla;
		int n;
		cout << "View Attendance: " << endl;
		cout << "\t1. 18CLC1\n\t2. 18CLC2\n\t3. 18CLC3\n\t4. 18CLC4\n\t5. 18CLC5\n\t0. EXIT" << endl;
		cout << "Choose a class: ";
		cin >> n;
		while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
		{
			cout << "ERROR. Input again: ";
			cin >> n;
		}
		if (n == 1) {
			cla = "18CLC1";
			Cla = sL1;
		}
		else if (n == 2) {
			cla = "18CLC2";
			Cla = sL2;
		}
		else if (n == 3) {
			cla = "18CLC3";
			Cla = sL3;
		}
		else if (n == 4) {
			cla = "18CLC4";
			Cla = sL4;
		}
		else if (n == 5) {
			cla = "18CLC5";
			Cla = sL5;
		}
		else if (n == 0) {
			system("cls");
			return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5,l);
		}
		viewCheckin(cla, Cla);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5,l);
	}
	if (choose == 5) {
		system("cls");
		Student* Cla = new Student;
		string cla;
		int n;
		cout << "Edit Attendance of a class:" << endl;
		cout << "\t1. 18CLC1\n\t2. 18CLC2\n\t3. 18CLC3\n\t4. 18CLC4\n\t5. 18CLC5\n\t0. EXIT" << endl;
		cout << "Choose a Class to Edit Attendance: ";
		cin >> n;
		while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
		{
			cout << "ERROR. Input again: ";
			cin >> n;
		}
		if (n == 1) {
			cla = "18CLC1";
			Cla = sL1;
		}
		else if (n == 2) {
			cla = "18CLC2";
			Cla = sL2;
		}
		else if (n == 3) {
			cla = "18CLC3";
			Cla = sL3;
		}
		else if (n == 4) {
			cla = "18CLC4";
			Cla = sL4;
		}
		else if (n == 5) {
			cla = "18CLC5";
			Cla = sL5;
		}
		else if (n == 0) {
			system("cls");
			return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5,l);
		}
		editCheckin(cla, Cla);
		OutputCheckin(Cla, "CheckIn_" + cla + "_NMLT.csv", 0);
		OutputCheckin(Cla, "CheckIn_" + cla + "_KTLT.csv", 1);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
	}
	if (choose == 6) {
		system("cls");
		string cla;
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
	}
	if (choose == 7) {
		system("cls");
		Student* Cla = new Student;
		string cla;
		int n;
		cout << "Edit grade of a student:" << endl;
		cout << "\t1. 18CLC1\n\t2. 18CLC2\n\t3. 18CLC3\n\t4. 18CLC4\n\t5. 18CLC5\n\t0. EXIT" << endl;
		cout << "Choose a Class to Edit Grade: ";
		cin >> n;
		while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
		{
			cout << "ERROR. Input again: ";
			cin >> n;
		}
		if (n == 1) {
			cla = "18CLC1";
			Cla = sL1;
		}
		else if (n == 2) {
			cla = "18CLC2";
			Cla = sL2;
		}
		else if (n == 3) {
			cla = "18CLC3";
			Cla = sL3;
		}
		else if (n == 4) {
			cla = "18CLC4";
			Cla = sL4;
		}
		else if (n == 5) {
			cla = "18CLC5";
			Cla = sL5;
		}
		else if (n == 0) {
			system("cls");
			return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
		}
		EditGrade(cla, Cla);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
	}
	if (choose == 8) {
		system("cls");
		Student* Cla = new Student;
		string cla;
		int n;
		cout << "View Score Board: " << endl;
		cout << "\t1. 18CLC1\n\t2. 18CLC2\n\t3. 18CLC3\n\t4. 18CLC4\n\t5. 18CLC5\n\t0. EXIT" << endl;
		cout << "Choose a class: ";
		cin >> n;
		while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
		{
			cout << "ERROR. Input again: ";
			cin >> n;
		}
		if (n == 1) {
			cla = "18CLC1";
			Cla = sL1;
		}
		else if (n == 2) {
			cla = "18CLC2";
			Cla = sL2;
		}
		else if (n == 3) {
			cla = "18CLC3";
			Cla = sL3;
		}
		else if (n == 4) {
			cla = "18CLC4";
			Cla = sL4;
		}
		else if (n == 5) {
			cla = "18CLC5";
			Cla = sL5;
		}
		else if (n == 0) {
			system("cls");
			return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
		}
		ViewScoreboard(cla, Cla);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
	}
	if (choose == 9) {
		system("cls");
		Student* Cla = new Student;
		string cla;
		int n;
		cout << "Edit Courses : " << endl;
		cout << "\t1. 18CLC1\n\t2. 18CLC2\n\t3. 18CLC3\n\t4. 18CLC4\n\t5. 18CLC5\n\t0. EXIT" << endl;
		cout << "Choose a class: ";
		cin >> n;
		while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
		{
			cout << "ERROR. Input again: ";
			cin >> n;
		}
		if (n == 1) {
			cla = "18CLC1";
			Cla = sL1;
		}
		else if (n == 2) {
			cla = "18CLC2";
			Cla = sL2;
		}
		else if (n == 3) {
			cla = "18CLC3";
			Cla = sL3;
		}
		else if (n == 4) {
			cla = "18CLC4";
			Cla = sL4;
		}
		else if (n == 5) {
			cla = "18CLC5";
			Cla = sL5;
		}
		else if (n == 0) {
			system("cls");
			return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
		}
		cla += ".csv";
		count = CountLine(cla);
		EditCourse(Cla, CountLine(cla));
		cla.erase(0, 2);
		OutputShedules(Cla, cla);
		for (int i = 0; i < count; i++)
		{

			InputSchedules(Cla, i, cla);
		}
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return LoggedStaff(name, sL1, sL2, sL3, sL4, sL5, l);
	}
	if (choose == 10)
	{
		system("cls");
		Student* Cla = new Student;
		string cla;
		int n;
		cout << "Edit Courses : " << endl;
		cout << "\t1. 18CLC1\n\t2. 18CLC2\n\t3. 18CLC3\n\t4. 18CLC4\n\t5. 18CLC5\n\t0. EXIT" << endl;
		cout << "Choose a class: ";
		cin >> n;
		while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5)
		{
			cout << "ERROR. Input again: ";
			cin >> n;
		}
		if (n == 1) {
			cla = "18CLC1";
			Cla = sL1;
		}
		else if (n == 2) {
			cla = "18CLC2";
			Cla = sL2;
		}
		else if (n == 3) {
			cla = "18CLC3";
			Cla = sL3;
		}
		else if (n == 4) {
			cla = "18CLC4";
			Cla = sL4;
		}
		else if (n == 5) {
			cla = "18CLC5";
			Cla = sL5;
		}
		cla = cla + ".csv";
		int count = CountLine(cla);
		RemoveStudent(Cla, count);
		outputStuTxt(cla, Cla, count);
	}
	if (choose == 0) {
		cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
		return;
	}
}
void InputAtten(Student*sL, int n, string in)
{

	for (int i = 0; i < n; i++)
		sL[i].checkin = new Attendance[2];
	in.erase((in.length() - 4), 4);
	string in2 = "CheckIn_" + in + "_NMLT.csv";
	string in3 = "CheckIn_" + in + "_KTLT.csv";
	fstream fin;
	fin.open(in2, ios::in);
	string next;
	int dem = 0;
	int i = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			while (i < n) {
				getline(fin, next, ',');
				getline(fin, sL[i].checkin[dem].w1, ',');
				getline(fin, sL[i].checkin[dem].w2, ',');
				getline(fin, sL[i].checkin[dem].w3, ',');
				getline(fin, sL[i].checkin[dem].w4, ',');
				getline(fin, sL[i].checkin[dem].w5, ',');
				getline(fin, sL[i].checkin[dem].w6, ',');
				getline(fin, sL[i].checkin[dem].w7, ',');
				getline(fin, sL[i].checkin[dem].w8, ',');
				getline(fin, sL[i].checkin[dem].w9, ',');
				getline(fin, sL[i].checkin[dem].w10, '\n');
				i++;
			}
			break;
		}
	}
	else if (!fin.is_open())
	{
		fstream fin2;
		in2.erase((in2.length() - 4), 4);
		in2 += ".txt";
		fin2.open(in2, ios::in);
		string next;
		int i = 0;
		if (fin2.is_open())
		{
			while (i < n) {
				getline(fin2, next, ',');
				getline(fin2, sL[i].checkin[dem].w1, ',');
				getline(fin2, sL[i].checkin[dem].w2, ',');
				getline(fin2, sL[i].checkin[dem].w3, ',');
				getline(fin2, sL[i].checkin[dem].w4, ',');
				getline(fin2, sL[i].checkin[dem].w5, ',');
				getline(fin2, sL[i].checkin[dem].w6, ',');
				getline(fin2, sL[i].checkin[dem].w7, ',');
				getline(fin2, sL[i].checkin[dem].w8, ',');
				getline(fin2, sL[i].checkin[dem].w9, ',');
				getline(fin2, sL[i].checkin[dem].w10, '\n');
				i++;
			}
		}
	}
	OutputCheckin(sL, in2, dem);
	dem++;
	fstream fin3;
	fin3.open(in3, ios::in);
	i = 0;
	if (fin3.is_open())
	{
		while (i < n) {
			getline(fin3, next, ',');
			getline(fin3, sL[i].checkin[dem].w1, ',');
			getline(fin3, sL[i].checkin[dem].w2, ',');
			getline(fin3, sL[i].checkin[dem].w3, ',');
			getline(fin3, sL[i].checkin[dem].w4, ',');
			getline(fin3, sL[i].checkin[dem].w5, ',');
			getline(fin3, sL[i].checkin[dem].w6, ',');
			getline(fin3, sL[i].checkin[dem].w7, ',');
			getline(fin3, sL[i].checkin[dem].w8, ',');
			getline(fin3, sL[i].checkin[dem].w9, ',');
			getline(fin3, sL[i].checkin[dem].w10, '\n');
			i++;
		}

	}
	else if (!fin3.is_open())
	{
		fstream fin4;
		in3.erase((in3.length() - 4), 4);
		in3 += ".txt";
		fin4.open(in3, ios::in);
		string next;
		int i = 0;
		if (fin4.is_open())
		{
			while (i < n) {
				getline(fin4, next, ',');
				getline(fin4, sL[i].checkin[dem].w1, ',');
				getline(fin4, sL[i].checkin[dem].w2, ',');
				getline(fin4, sL[i].checkin[dem].w3, ',');
				getline(fin4, sL[i].checkin[dem].w4, ',');
				getline(fin4, sL[i].checkin[dem].w5, ',');
				getline(fin4, sL[i].checkin[dem].w6, ',');
				getline(fin4, sL[i].checkin[dem].w7, ',');
				getline(fin4, sL[i].checkin[dem].w8, ',');
				getline(fin4, sL[i].checkin[dem].w9, ',');
				getline(fin4, sL[i].checkin[dem].w10, '\n');
				i++;
			}
		}
	}
	OutputCheckin(sL, in3, dem);
}

void OutputCheckin(Student*sL, string in, int dem)
{
	int n = CountLine(in);
	in.erase((in.length() - 4), 4);
	in += ".txt";
	fstream fout;
	fout.open(in, ios::out);
	for (int i = 0; i < n; i++)
	{
		fout << sL[i].ID << "," << sL[i].checkin[dem].w1 << "," << sL[i].checkin[dem].w2 << "," << sL[i].checkin[dem].w3 << "," << sL[i].checkin[dem].w4 << "," << sL[i].checkin[dem].w5 << "," << sL[i].checkin[dem].w6 << "," << sL[i].checkin[dem].w7 << "," << sL[i].checkin[dem].w8 << "," << sL[i].checkin[dem].w9 << "," << sL[i].checkin[dem].w10 << endl;
	}
}
void EditCourse(Student* sL, int n)
{
	system("cls");
	string temp;
	int i;
	bool flag = true;
	cout << "\tEDIT COURSE" << endl << endl;
	for (i = 0; i < sL[0].count; i++)
	{
		cout << sL[0].Courses[i].No << ", " << sL[0].Courses[i].CourseID << ", " << sL[0].Courses[i].Year << ", " << sL[0].Courses[i].CourseName << ", " << sL[0].Courses[i].LecturerName << ", " << sL[0].Courses[i].StartDate << ", " << sL[0].Courses[i].EndDate << ", " << sL[0].Courses[i].StartTime << ", " << sL[0].Courses[i].EndTime << ", " << sL[0].Courses[i].DayofWeek << ", " << sL[0].Courses[i].Semester << "." << endl;
	}
	while (flag)
	{
		cout << "\nEnter Course ID you want to edit : ";
		cin >> temp;
		for (i = 0; i < sL[0].count; i++)
		{
			if (sL[0].Courses[i].CourseID == temp)
			{
				flag = false;
				break;
			}
		}
		if (i == sL[0].count)
		{
			cout << "Can't find course" << endl;
		}
	}
	cout << "\n\tSelected: " << sL[0].Courses[i].CourseID << ". Input new time :" << endl << endl;
	cout << "Input Start Time : ";
	cin.ignore();
	getline(std::cin, sL[0].Courses[i].StartTime);
	cout << "Input End Time : ";
	getline(std::cin, sL[0].Courses[i].EndTime);
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < sL[0].count; j++)
		{
			CopyCourse(sL[0].Courses[j], sL[i].Courses[j]);
		}
	}
	cout << "\nEdit success !" << endl << endl;
	//OutputShedules()
}

void RemoveCourse(Student* sL, int n)
{
	system("cls");
	string temp;
	int i;
	bool flag = true;
	cout << "\tREMOVE COURSE" << endl << endl;
	for (i = 0; i < sL[0].count; i++)
	{
		cout << sL[0].Courses[i].No << ", " << sL[0].Courses[i].CourseID << ", " << sL[0].Courses[i].Year << ", " << sL[0].Courses[i].CourseName << ", " << sL[0].Courses[i].LecturerName << ", " << sL[0].Courses[i].StartDate << ", " << sL[0].Courses[i].EndDate << ", " << sL[0].Courses[i].StartTime << ", " << sL[0].Courses[i].EndTime << ", " << sL[0].Courses[i].DayofWeek << ", " << sL[0].Courses[i].Semester << "." << endl;
	}
	while (flag)
	{
		cout << "\nEnter Course ID you want to remove : ";
		cin >> temp;
		for (i = 0; i < sL[0].count; i++)
		{
			if (sL[0].Courses[i].CourseID == temp)
			{
				flag = false;
				break;
			}
		}
		if (i == sL[0].count)
		{
			cout << "Can't find course" << endl;
		}
	}
	system("cls");
	cout << "\n\tSelected: " << sL[0].Courses[i].CourseID << ".";
	flag = true;
	while (flag)
	{
		cout << "\nAre you sure that you want to remove this course ? (Yes/No) : ";
		cin >> temp;
		if (temp == "Yes" || temp == "yes")
		{
			for (int j = i; j + 1 < sL[0].count; j++)
			{
				sL[0].Courses[j] = sL[0].Courses[j + 1];
				sL[0].Courses[j].No = to_string(stoi(sL[0].Courses[j].No) - 1);
			}
			for (i = 0; i < n; i++)
			{
				sL[i].count--;
			}
			for (i = 0; i < n; i++)
			{
				for (int j = 0; j < sL[0].count; j++)
				{
					CopyCourse(sL[0].Courses[j], sL[i].Courses[j]);
				}
			}
			flag = false;
			cout << "Remove success !" << endl;
		}
		else if (temp == "No" || temp == "no")
		{
			flag = false;
		}
		else
		{
			cout << "\nError! Input again." << endl;
		}
	}
	/*OutputShedules()*/
}

void EditStudent(Student* sL, int n)
{
	system("cls");
	string temp;
	int i;
	bool flag = true;
	cout << "\tEDIT STUDENT" << endl << endl;
	while (flag)
	{
		cout << "Input ID of student you want to edit : ";
		cin >> temp;
		for (i = 0; i < n; i++)
		{
			if (sL[i].ID == temp)
			{
				flag = false;
				break;
			}
		}
		if (i == n)
		{
			cout << "Error! Input again." << endl << endl;
		}
	}
	cout << "\n Selected: " << sL[i].ID << ". Press Enter to edit all information of this student.";
	getchar();
	cout << "\n\tINPUT NEW" << endl << endl;
	cout << "Input ID : ";
	cin.ignore();
	getline(std::cin, sL[i].ID);
	cout << "Input First Name : ";
	getline(std::cin, sL[i].FName);
	cout << "Input Last Name : ";
	getline(std::cin, sL[i].LName);
	cout << "Input sex : ";
	getline(std::cin, sL[i].Sex);
	cout << "Input date (eg: 26/12/2000) : ";
	getline(std::cin, sL[i].date);
	sL[i].pass = sL[i].ID + getDoB(sL[i].date);
	cout << "\nEdit success !" << endl;
	/*outputStuTxt()*/
}

void RemoveStudent(Student* sL, int &n)
{
	system("cls");
	string temp;
	int i;
	bool flag = true;
	cout << "\tREMOVE STUDENT" << endl << endl;
	while (flag)
	{
		cout << "Input ID of student you want to remove : ";
		cin >> temp;
		for (i = 0; i < n; i++)
		{
			if (sL[i].ID == temp)
			{
				flag = false;
				break;
			}
		}
		if (i == n)
		{
			cout << "Error! Input again." << endl << endl;
		}
	}
	system("cls");
	flag = true;
	cout << "\n Selected: " << sL[i].ID << ".";
	while (flag)
	{
		cout << "\nAre you sure that you want to remove this student ? (Yes/No) : ";
		cin >> temp;
		if (temp == "Yes" || temp == "yes")
		{
			for (i; i + 1 < n; i++)
			{
				sL[i] = sL[i + 1];
			}
			flag = false;
			n--;
			cout << "Remove success !" << endl;
		}
		else if (temp == "No" || temp == "no")
		{
			flag = false;
		}
		else
		{
			cout << "\nError! Input again." << endl;
		}
	}
	//outputStuTxt();
	//outputScore();
}
void viewCheckin(string cla, Student*sL) {
	int choose;
	system("cls");
	cout << "List of Check-in of Class " << cla << ": " << endl;
	cla.erase(0, 2);
	cla += ".csv";
	for (int i = 0; i < CountLine(cla); i++)
	{
		cout << i + 1 << ". " << sL[0].Courses[i].CourseName << endl;
	}
	cout << "0. EXIT" << endl;
	cout << "Choose a course to View Check in: ";
	cin >> choose;
	if (choose == 0) return;
	if (choose != 0) {
		while (choose < 0 || choose > CountLine(cla))
		{
			cout << "ERROR. Choose again: ";
			cin >> choose;
			if (choose == 0) return;
		}
		system("cls");
		for (int i = 0; i < CountLine(cla); i++)
		{
			if (i == choose - 1) {
				cla = "18" + cla;
				cout << "Check in of " << sL[0].Courses[i].CourseName << endl;
				cout << "No \t Full Name \t    Week01  Week02  Week03  Week04  Week05  Week06  Week07  Week08  Week09  Week10" << endl;
				for (int j = 0; j < CountLine(cla); j++)
				{
					cout << sL[j].No << ".\t " << sL[j].FName << " " << sL[j].LName << ":";
					cout << "\t" << sL[j].checkin[i].w1;
					cout << "\t" << sL[j].checkin[i].w2;
					cout << "\t" << sL[j].checkin[i].w3;
					cout << "\t" << sL[j].checkin[i].w4;
					cout << "\t" << sL[j].checkin[i].w5;
					cout << "\t" << sL[j].checkin[i].w6;
					cout << "\t" << sL[j].checkin[i].w7;
					cout << "\t" << sL[j].checkin[i].w8;
					cout << "\t" << sL[j].checkin[i].w9;
					cout << "\t" << sL[j].checkin[i].w10 << endl;
				}
			}
		}
		cla.erase(6, 4);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return viewCheckin(cla, sL);
	}
}
void editCheckin(string cla, Student*sL) {
	int choose;
	system("cls");
	cout << "List of Check-in of Class " << cla << ": " << endl;
	cla.erase(0, 2);
	cla += ".csv";
	for (int i = 0; i < CountLine(cla); i++)
	{
		cout << i + 1 << ". " << sL[0].Courses[i].CourseName << endl;
	}
	cout << "0. EXIT" << endl;
	cout << "Choose a course to Edit Check in: ";
	cin >> choose;
	if (choose == 0) return;
	if (choose != 0) {
		while (choose < 0 || choose > CountLine(cla))
		{
			cout << "ERROR. Choose again: ";
			cin >> choose;
			if (choose == 0) return;
		}
		system("cls");
		for (int i = 0; i < CountLine(cla); i++)
		{
			if (i == choose - 1) {
				cla = "18" + cla;
				cout << "Check in of " << sL[0].Courses[i].CourseName << endl;
				for (int i = 0; i < CountLine(cla); i++)
				{
					cout << i + 1 << ". " << sL[i].FName << " " << sL[i].LName << endl;
				}
				cout << "Choose a student to Edit Checkin: ";
				int choose1;
				cin >> choose1;
				if (choose1 == 0) return;
				if (choose1 != 0) {
					while (choose < 0 || choose1 > CountLine(cla))
					{
						cout << "ERROR. Choose again: ";
						cin >> choose1;
						if (choose1 == 0) return;
					}
					for (int j = 0; j < CountLine(cla); j++)
					{
						if (j == choose1 - 1) {
							cout << "No \t Full Name \t    Week01  Week02  Week03  Week04  Week05  Week06  Week07  Week08  Week09  Week10" << endl;
							cout << sL[j].No << ".\t " << sL[j].FName << " " << sL[j].LName << ":";
							cout << "\t" << sL[j].checkin[i].w1;
							cout << "\t" << sL[j].checkin[i].w2;
							cout << "\t" << sL[j].checkin[i].w3;
							cout << "\t" << sL[j].checkin[i].w4;
							cout << "\t" << sL[j].checkin[i].w5;
							cout << "\t" << sL[j].checkin[i].w6;
							cout << "\t" << sL[j].checkin[i].w7;
							cout << "\t" << sL[j].checkin[i].w8;
							cout << "\t" << sL[j].checkin[i].w9;
							cout << "\t" << sL[j].checkin[i].w10 << endl << endl;
							cout << "\T EDIT CHECK-IN" << endl;
							cout << "Week 01 : "; cin >> sL[j].checkin[i].w1;
							cout << "\nWeek 02 : "; cin >> sL[j].checkin[i].w2;
							cout << "\nWeek 03 : "; cin >> sL[j].checkin[i].w3;
							cout << "\nWeek 04 : "; cin >> sL[j].checkin[i].w4;
							cout << "\nWeek 05 : "; cin >> sL[j].checkin[i].w5;
							cout << "\nWeek 06 : "; cin >> sL[j].checkin[i].w6;
							cout << "\nWeek 07 : "; cin >> sL[j].checkin[i].w7;
							cout << "\nWeek 08 : "; cin >> sL[j].checkin[i].w8;
							cout << "\nWeek 09 : "; cin >> sL[j].checkin[i].w9;
							cout << "\nWeek 10 : "; cin >> sL[j].checkin[i].w10;
							cout << "\n Edit Success!";
						}
					}
				}
			}
		}
		cla.erase(6, 4);
		cout << "\nPress Enter to go back...";
		cin.ignore();
		getchar();
		system("cls");
		return viewCheckin(cla, sL);
	}
}
void checkinStu(Student &stu) {

	cout << "\tCHECK-IN " << endl;
	for (int i = 0; i < stu.count; i++)
	{
		cout << i + 1 << ". " << stu.Courses[i].CourseName << endl;
	}
	cout << "0. EXIT" << endl;
	int choose;
	cout << "Choose a course to Check in: ";
	cin >> choose;
	if (choose == 0) return;
	if (choose != 0) {
		while (choose < 0 || choose >stu.count)
		{
			cout << "ERROR. Choose again: ";
			cin >> choose;
			if (choose == 0) return;
		}
		system("cls");
		cout << "No \t Full Name \t    Week01  Week02  Week03  Week04  Week05  Week06  Week07  Week08  Week09  Week10" << endl;
		cout << stu.No << ".\t " << stu.FName << " " << stu.LName << ":";
		cout << "\t" << stu.checkin[choose - 1].w1;
		cout << "\t" << stu.checkin[choose - 1].w2;
		cout << "\t" << stu.checkin[choose - 1].w3;
		cout << "\t" << stu.checkin[choose - 1].w4;
		cout << "\t" << stu.checkin[choose - 1].w5;
		cout << "\t" << stu.checkin[choose - 1].w6;
		cout << "\t" << stu.checkin[choose - 1].w7;
		cout << "\t" << stu.checkin[choose - 1].w8;
		cout << "\t" << stu.checkin[choose - 1].w9;
		cout << "\t" << stu.checkin[choose - 1].w10 << endl << endl;
		cout << "Now is week 10. Please check-in (0 : absent - 1 : present ) : ";
		cin >> stu.checkin[choose - 1].w10;
		cout << "Check in success ! ";
	}
}