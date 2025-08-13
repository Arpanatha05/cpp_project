#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Teacher
{
private:
    int salary;

protected:
    int roll_no;

public:
    string name;
    int age;
    string gender;
    void Teacher_setdata()
    {   cout<<"=====INPUT TEACHER DETAILS====="<<endl;
        int a1, a2;
        long long int a3;
        string p;
        cout << "Enter the Teacher Name:";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the Teacher Age:";
        cin >> a1;
        age = a1;
        cout << "Enter the Teacher Salary:";
        cin >> a2;
        salary = a2;
        cout << "Enter the Teacher Roll NO:";
        cin >> a3;
        roll_no = a3;
        cout << "Enter the Teacher Gender:";
        cin >> p;
        gender = p;
        cout<<endl;
    }
    void Teacher_getdata()
    {
        cout << "=====TEACHERS DETAILS=====" << endl;
        cout << "Name:" << name << endl
             << "Age:" << age << endl
             << "Gender:" << gender << endl
             << "Rollno:" << roll_no << "tec" << endl;
    }
};

class Student : public Teacher
{
public:
    void Student_setdata()
    {   cout<<"=====INPUT STUDENT DETAILS====="<<endl;
        int a1, a2;
        long long int a3;
        string p;
        string n;
        cout << "Enter the Student name:";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the Student age:";
        cin >> a1;
        age = a1;
        cout << "Enter the Student roll:";
        cin >> a3;
        roll_no = a3;
        cout << "Enter the Student gender:";
        cin >> p;
        gender = p;
    }
    void Student_getdata()
    {
        cout << "=====STUDENT DETAILS=====" << endl;
        cout << "Name:" << name << endl
             << "Age:" << age << endl
             << "Gender:" << gender << endl
             << "Rollno:" << roll_no << "stu" << endl;
    }
};
class Student_number : public Student
{
public:
    int Physics, Biology, Math, Bengali, English, Chemistry;
    void setnumber()
    {
        int a1, a2, a3, a4, a5, a6, n1;
        cout << "Enter the Student name:";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Student roll no:";
        cin >> n1;
        roll_no = n1;
        cout << "Enter Physics Number:";
        cin >> a1;
        Physics = a1;
        cout << "Enter Biology Number:";
        cin >> a2;
        Biology = a2;
        cout << "Enter Chemistry Number:";
        cin >> a3;
        Chemistry = a3;
        cout << "Enter Math Number:";
        cin >> a4;
        Math = a4;
        cout << "Enter Bengali Number:";
        cin >> a5;
        Bengali = a5;
        cout << "Enter English Number:";
        cin >> a6;
        English = a6;
    }

    void getNumber()
    {
        cout << "=====RESULT=====" << endl;
        cout << "Student Name:" << name << endl
             << "Roll No:" << roll_no << endl;
        cout << "Physics:" << Physics << endl;
        cout << "Biology:" << Biology << endl;
        cout << "Math:" << Math << endl;
        cout << "Chemistry:" << Chemistry << endl;
        cout << "Bengali:" << Bengali << endl;
        cout << "English:" << English << endl;
        cout << "You got Total " << Physics + Bengali + Biology + Math + English + Chemistry << " Marks Out of 600" << endl;
    }
};

int main()
{
    int n;
    char ch = 'y';
    vector<Teacher> teachers;
    vector<Student> students;
    vector<Student_number> numbers;
    while (ch == 'y' || ch == 'Y')
    {
        system("cls");
        cout << "=====MAIN MENU FOR ABC SCHOOL=====" << endl
             << "1)New Teacher Detail" << endl
             << "2)New Student Detail" << endl
             << "3)Enter student number" << endl;
        cout << "4)Display Teacher Detail" << endl
             << "5)Display Student Detail" << endl
             << "6)Display Student Marks" << endl;
        cout << "Enter your choice(1-6):";
        cin >> n;
        cout<<endl;
        switch (n)
        {
        case 1:
        {
            Teacher t1;
            t1.Teacher_setdata();
            teachers.push_back(t1);
        }
        break;
        case 2:
        {

            Student s1;
            s1.Student_setdata();
            students.push_back(s1);
        }
        break;
        case 3:
        {
            Student_number n1;
            n1.setnumber();
            numbers.push_back(n1);
        }
        break;
        case 4:
        {
            if (teachers.size() == 0)
            {
                cout << "There are no input data" << endl;
            }
            else
            {
                for (int i = 0; i < teachers.size(); i++)
                {
                    cout << i + 1 << " No Teacher Detail:" << endl;
                    teachers[i].Teacher_getdata();
                }
            }
        }

        break;
        case 5:
        {
            if (students.size() == 0)
            {
                cout << "There are no input data" << endl;
            }
            else
            {
                for (int i = 0; i < students.size(); i++)
                {
                    cout << i + 1 << " No Student Detail:" << endl;
                    students[i].Student_getdata();
                }
            }

            break;
        case 6:
        {
            if (numbers.size() == 0)
            {
                cout << "There are no input data" << endl;
            }
            else
            {
                for (int i = 0; i < numbers.size(); i++)
                {
                    cout << i + 1 << " No Student rsult detail:" << endl;
                    numbers[i].getNumber();
                }
            }
        }
        break;

        default:
            cout << "Wrong input" << endl;

            exit(0);
        }
        }
        cout << "Do you want to continue(y/n):";
        cin >> ch;
    }
    return 0;
}