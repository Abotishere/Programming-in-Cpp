#include <iostream>
#include <vector>
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

    Student students[3];
    int total_students;

public:

    Department(string d, string h){
        dept_name = d;
        hod_name = h;
        total_students = 0;
    }

    void addStudent(int r, float d, int y){
        if(total_students < 3){
            students[total_students] = Student(r,d,y);
            total_students++;
        }
    }

    string getDeptName(){
        return dept_name;
    }

    void searchByRoll(int roll){
        for(int i = 0; i < total_students; i++){
            if(students[i].roll_no == roll){
                cout << "\nDepartment: " << dept_name << endl;
                cout << "HOD: " << hod_name << endl;
                students[i].display();
            }
        }
    }

    void searchByYear(int year){
        for(int i = 0; i < total_students; i++){
            if(students[i].pass_out_year == year){
                cout << "\nDepartment: " << dept_name << endl;
                students[i].display();
            }
        }
    }

    void searchByDGPA(float threshold){
        for(int i = 0; i < total_students; i++){
            if(students[i].dgpa > threshold){
                cout << "\nDepartment: " << dept_name << endl;
                students[i].display();
            }
        }
    }
};

int main(){

    vector<Department> deptList;

    Department cse("CSE","Dr. Roy");
    cse.addStudent(1, 8.5, 2024);
    cse.addStudent(2, 7.9, 2023);
    cse.addStudent(3, 9.1, 2025);

    Department it("IT","Dr. Sen");
    it.addStudent(4, 8.0, 2024);
    it.addStudent(5, 6.9, 2023);
    it.addStudent(6, 9.3, 2025);

    deptList.push_back(cse);
    deptList.push_back(it);

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

            for(auto &d:deptList)
                d.searchByRoll(roll);
        }

        else if(choice == 2){
            string dept;
            int year;

            cout << "Enter Dept Name: ";
            cin >> dept;
            cout << "Enter Pass Out Year: ";
            cin >> year;

            for(auto &d:deptList)
                if(d.getDeptName() == dept)
                    d.searchByYear(year);
        }

        else if(choice == 3){
            float th;
            cout << "Enter DGPA Threshold: ";
            cin >> th;

            for(auto &d:deptList)
                d.searchByDGPA(th);
        }

        else continue;

    }while(choice != 4);

    return 0;
}