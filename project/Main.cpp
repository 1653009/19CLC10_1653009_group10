#include "program.h"

void  main()
{
	Student* sL1; Student* sL2; Student* sL3; Student* sL4; Student* sL5;
	Lecture* l;
	Staff * sT;
	Attendance *Atten;


	int choose;
	bool flag = true;

	int n1 = CountLine("18CLC1.csv");
	sL1 = new Student[n1];
	inputStudent("18CLC1.csv", sL1);
	for (int i = 0; i < n1; i++)
	{
		InputSchedules(sL1, i, "CLC1.csv");
	}
	InputScore(sL1, n1, "18CLC1.csv");
	InputAtten(sL1, n1, "18CLC1.csv");

	int n2 = CountLine("18CLC2.csv");
	sL2 = new Student[n2];
	inputStudent("18CLC2.csv", sL2);
	for (int i = 0; i < n1; i++)
	{
		InputSchedules(sL2, i, "CLC2.csv");
	}
	InputScore(sL2, n2, "18CLC2.csv");
	InputAtten(sL2, n2, "18CLC2.csv");


	int n3 = CountLine("18CLC3.csv");
	sL3 = new Student[n3];
	inputStudent("18CLC3.csv", sL3);
	for (int i = 0; i < n1; i++)
	{
		InputSchedules(sL3, i, "CLC3.csv");
	}
	InputScore(sL3, n3, "18CLC3.csv");
	InputAtten(sL3, n3, "18CLC3.csv");


	int n4 = CountLine("18CLC4.csv");
	sL4 = new Student[n4];
	inputStudent("18CLC4.csv", sL4);
	for (int i = 0; i < n1; i++)
	{
		InputSchedules(sL4, i, "CLC4.csv");
	}
	InputScore(sL4, n4, "18CLC4.csv");
	InputAtten(sL4, n4, "18CLC4.csv");

	int n5 = CountLine("18CLC5.csv");
	sL5 = new Student[n5];
	inputStudent("18CLC5.csv", sL5);
	for (int i = 0; i < n1; i++)
	{
		InputSchedules(sL5, i, "CLC5.csv");
	}
	InputScore(sL5, n5, "18CLC5.csv");
	InputAtten(sL5, n5, "18CLC5.csv");

	int nL = CountLine("TeacherName.csv");
	l = new Lecture[nL];
	InputLecture(l, "TeacherName.csv");

	int nS = CountLine("Staff.csv");
	sT = new Staff[nS];
	InputStaff(sT, "Staff.csv");

	cout << "Welcome to Student Management System" << endl;
	cout << "Are you ?" << endl;
	cout << "\t1.Student" << endl;
	cout << "\t2.Lecture" << endl;
	cout << "\t3.Staff" << endl;
	cout << "Press any key to Exit !";
	int type;
	cout << "\nType your choose : "; cin >> type;
	if (type == 1) {
		system("cls");
		for (int i = 0; i < 5; i++) {
			cout << "\t" << i + 1 << ". 18CLC" << i + 1 << endl;
		}
		cout << "Choose your class : ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			while (flag) {
				cout << "\t1. LOGIN" << endl;
				cout << "\t0. Exit" << endl;
				cout << "You choose: ";
				cin >> choose;
				if (choose == 1) {
					login(sL1, n1, "18CLC1");
				}

				else {
					cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
					flag = false;
				}
				break;
			}
			break;
		}
		case 2:
		{
			while (flag) {
				cout << "\t1. LOGIN" << endl;
				cout << "\t0. Exit" << endl;
				cout << "You choose: ";
				cin >> choose;
				if (choose == 1) {
					login(sL2, n2, "18CLC1");
				}

				else {
					cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
					flag = false;
				}
				break;
			}
			break;
		}
		case 3:
		{
			while (flag) {
				cout << "\t1. LOGIN" << endl;
				cout << "\t0. Exit" << endl;
				cout << "You choose: ";
				cin >> choose;
				if (choose == 1) {
					login(sL3, n3, "18CLC3");
				}

				else {
					cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
					flag = false;
				}
				break;
			}
			break;
		}
		case 4:
		{
			while (flag) {
				cout << "\t1. LOGIN" << endl;
				cout << "\t0. Exit" << endl;
				cout << "You choose: ";
				cin >> choose;
				if (choose == 1) {
					login(sL4, n4, "18CLC4");
				}

				else {
					cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
					flag = false;
				}
				break;
			}
			break;
		}
		case 5:
		{
			while (flag) {
				cout << "\t1. LOGIN" << endl;
				cout << "\t0. Exit" << endl;
				cout << "You choose: ";
				cin >> choose;
				if (choose == 1) {
					login(sL5, n5, "18CLC5");
				}

				else {
					cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
					flag = false;
				}
				break;
			}
			break;
		}
		default:
			break;
		}
	}
	if (type == 2) {
		system("cls");
		cout << "\t1. LOGIN" << endl;
		cout << "\t2. Exit" << endl;
		cout << "You choose: ";
		cin >> choose;
		if (choose == 1) {
			loginLecture(l, nL, sL1, sL2, sL3, sL4, sL5);

		}
		else {
			cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
		}

	}
	if (type == 3) {
		system("cls");
		cout << "\t1. LOGIN" << endl;
		cout << "\t2. Exit" << endl;
		cout << "You choose: ";
		cin >> choose;
		if (choose == 1) {
			loginStaff(sT, nS, sL1, sL2, sL3, sL4, sL5, l);
		}
		else {
			cout << "\n\n\tTHANK FOR USING OUR PROGRAM ^^" << endl;
		}
	}

	OutputShedules(sL1, "CLC1.csv");
	OutputShedules(sL2, "CLC2.csv");
	OutputShedules(sL3, "CLC3.csv");
	OutputShedules(sL4, "CLC4.csv");
	OutputShedules(sL5, "CLC5.csv");

	delete[] sL1, sL2, sL3, sL4, sL5, l, sT;
}