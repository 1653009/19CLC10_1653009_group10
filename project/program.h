#pragma once 
#include<Windows.h>
#include<conio.h>



#include<iostream>
#include<string>
#include<fstream>
#include<sstream>


using namespace std;
struct Score {
	string Mid, Final, Lab, Bonus;
};
struct Attendance {
	string w1, w2, w3, w4, w5, w6, w7, w8, w9, w10;
};
struct Schedules {
	string No, CourseID;
	string Year;
	string CourseName;
	string LecturerName;
	string StartDate;
	string EndDate;
	string StartTime;
	string EndTime;
	string DayofWeek;
	string Semester;
};

struct Student {
	string ID, No;
	string LName, FName;
	string Sex;
	string date;
	string pass;
	Schedules* Courses;
	Score * score;
	Attendance* checkin;
	int count;
};


struct Course {
	string No, CourseID;
	string Year;
	string CourseName;
	string LecturerName;
	string StartDate;
	string EndDate;
	string StartTime;
	string EndTime;
	string DayofWeek;
	string Semester;

};

struct Lecture {
	string ID;
	string Name;
	string pass;
};
struct Staff {
	string ID, Name, pass;
};


void login(Student* sL, int n, string in);
int CountLine(string in);
void inputStudent(string in, Student *sL);
string getDoB(string date);
void Logged(Student &stu, int n, Student *sL, string in);
void changepass(Student &stu);
void outputStuTxt(string in, Student *sL, int n);
void remove(Student *sL, string in);
int PrintCourseList(string in, string name, string semester);
void ListofCourse(string name);
void ListStudentofCourse(string name);
void InputSchedules(Student *sL, int i, string in2);
void LoggedLecturer(string name, Student*sL1, Student*sL2, Student*sL3, Student*sL4, Student*sL5);
void AddCourse(Student& stu);
//void insertStudent(StudentList &sL, Student stu);
void CopyCourse(Schedules sch, Schedules &result);
Student* AddStudent(Student*sL, int &n, string in);
void CopyStudent(Student stu, Student &result);
void CopyScore(Score sco, Score &result);
void InputScore(Student*sL, int n, string in);
void OutputScore(Student*sL, string in, int dem);
void OutputShedules(Student*sL, string in);


void InputLecture(Lecture* l, string in);
void loginLecture(Lecture* l, int n, Student*sL1, Student*sL2, Student*sL3, Student*sL4, Student*sL5);
void InputStaff(Staff* sT, string in);

void loginStaff(Staff*sT, int n, Student*sL1, Student*sL2, Student*sL3, Student*sL4, Student*sL5, Lecture*l);
void LoggedStaff(string name, Student*sL1, Student*sL2, Student*sL3, Student*sL4, Student*sL5, Lecture*l);
void InputAtten(Student*sL, int n, string in);
void OutputCheckin(Student*sL, string in, int dem);

void EditCourse(Student* sL, int n);
void RemoveCourse(Student* sL, int n);
void EditStudent(Student* sL, int n);
void RemoveStudent(Student* sL, int &n);
void ViewScoreboard(string cla, Student*sL);
void EditGrade(string cla, Student*sL);

void viewCheckin(string cla, Student*sL);
void editCheckin(string cla, Student*sL);

void checkinStu(Student &stu);