#include <iostream>
using namespace std;

class Department{
private:
    string dept_name;
    string hod_name;

    class Student{
    public:
        int roll_no;
        float dgpa;
        int pass_out_year;

        Student(){}

        Student(int r, float d, int y){
            roll_no = r;
            dgpa = d;
            pass_out_year = y;
        }

        void display(){
            cout << "Roll No: " << roll_no << endl;
            cout << "DGPA: " << dgpa << endl;
            cout << "Pass Out Year: " << pass_out_year << endl;
        }
    };

    Student *students;
    int total_students;
    int capacity;

public:

    Department(){}

    Department(string d, string h){
        dept_name = d;
        hod_name = h;

        capacity = 3;
        total_students = 0;

        students = new Student[capacity];
    }

    void freeStudents(){
        delete[] students;
    }

    void addStudent(int r, float d, int y){
        if(total_students < capacity){
            students[total_students] = Student(r,d,y);
            total_students++;
        }
    }

    string getDeptName(){
        return dept_name;
    }

    void searchByRoll(int roll){
        for(int i=0;i<total_students;i++){
            if(students[i].roll_no == roll){
                cout << "\nDepartment: " << dept_name << endl;
                cout << "HOD: " << hod_name << endl;
                students[i].display();
            }
        }
    }

    void searchByYear(int year){
        for(int i=0;i<total_students;i++){
            if(students[i].pass_out_year == year){
                cout << "\nDepartment: " << dept_name << endl;
                students[i].display();
            }
        }
    }

    void searchByDGPA(float threshold){
        for(int i=0;i<total_students;i++){
            if(students[i].dgpa > threshold){
                cout << "\nDepartment: " << dept_name << endl;
                students[i].display();
            }
        }
    }
};

int main(){

    int deptCount = 2;

    Department *deptList = new Department[deptCount];   // DMA for departments

    deptList[0] = Department("CSE","Dr. Roy");
    deptList[0].addStudent(1,8.5,2024);
    deptList[0].addStudent(2,7.9,2023);
    deptList[0].addStudent(3,9.1,2025);

    deptList[1] = Department("IT","Dr. Sen");
    deptList[1].addStudent(4,8.0,2024);
    deptList[1].addStudent(5,6.9,2023);
    deptList[1].addStudent(6,9.3,2025);

    int choice;

    do{
        cout << "\n1.Search by Roll Number\n";
        cout << "2.Search by Dept & Passout Year\n";
        cout << "3.Search by DGPA Threshold\n";
        cout << "4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1){
            int roll;
            cout << "Enter Roll: ";
            cin >> roll;

            for(int i=0;i<deptCount;i++)
                deptList[i].searchByRoll(roll);
        }

        else if(choice == 2){
            string dept;
            int year;

            cout << "Enter Dept Name: ";
            cin >> dept;
            cout << "Enter Pass Out Year: ";
            cin >> year;

            for(int i=0;i<deptCount;i++)
                if(deptList[i].getDeptName() == dept)
                    deptList[i].searchByYear(year);
        }

        else if(choice == 3){
            float th;
            cout << "Enter DGPA Threshold: ";
            cin >> th;

            for(int i=0;i<deptCount;i++)
                deptList[i].searchByDGPA(th);
        }

        else continue;

    }while(choice != 4);
    for(int i = 0; i < deptCount; i++)
        deptList[i].freeStudents();
    delete[] deptList;   // free department memory

    return 0;
}