#include <iostream>
#include <string>
using namespace std;

class Department;

class Student{
    int roll;
    int marks;
    string d_name;
    string loc;
    public:

    Student(){}

    Student(int r, int m, string d, string l){
        roll = r;
        marks = m;
        d_name = d;
        loc = l;
    }

    void show(){
        cout << "Roll no.: " << roll << endl;
        cout << "Marks: " << marks << endl;
        cout << "Department name: " << d_name << endl;
        cout << "Location: " << loc << endl;
    }

    int getRoll(){ return roll; }
    int getMarks(){ return marks; }
    string getDept(){ return d_name; }
    string getLoc(){ return loc; }

    friend void searchByRoll(Student s[], Department d[], int size, int r);
    friend void searchByLocation(Student s[], int size, string l);
    friend void searchAboveMarks(Student s[], int size, int thres);
};

class Department{
    string d_name;
    string hod_name;
    public:
    Department(){}
    Department(string d, string h){
        d_name = d;
        hod_name = h;
    }

    string getDeptName(){ return d_name; }

    void show(){
        cout << "Department name: " << d_name << endl;
        cout << "HOD name: " << hod_name << endl;
    }

    friend void searchByRoll(Student s[], Department d[], int size, int r);
    friend void searchByLocation(Student s[], int size, string l);
    friend void searchAboveMarks(Student s[], int size, int thres);

};

void searchByRoll(Student s[], Department d[], int size, int r){
    for (int i = 0; i < size; i++){
        if (r == s[i].getRoll()){
            cout << "Student details--\n";
            s[i].show(); // shows student details

            for (int j = 0; j < size; j++){
                if (d[j].getDeptName() == s[i].getDept()){
                    cout << "Department details--\n";
                    d[j].show(); // shows respective department details
                    break;
                }
            }
            return;
        }
    }
    cout << "Student not found!\n";
}

void searchByLocation(Student s[], int size, string l){
    bool found = false;
    for (int i = 0; i < size; i++){
        if (l == s[i].getLoc()){
            cout << "Student details--\n";
            s[i].show(); // shows student details
            found = true;
        }
    }
    if (!found){
        cout << "Student not found!\n";
    }
}

void searchAboveMarks(Student s[], int size, int thres){
    bool found = false;
    cout << "Student details with marks above " << thres << endl;
    for (int i = 0; i < size; i++){
        if (s[i].getMarks() >= thres){
            cout << i + 1 << ".\n";
            s[i].show();
            found = true;
        }
    }
    if (!found){
        cout << "No student found!\n";
    }
}

int main(){
    int n = 3;

    // Dynamic memory allocation
    Student* stud = new Student[n];
    Department* dept = new Department[n];

    stud[0] = Student(1, 95, "CSE", "Kolkata");
    stud[1] = Student(2, 93, "IT", "Barddhaman");
    stud[2] = Student(3, 87, "CSE", "Bongaon");

    dept[0] = Department("CSE", "Dr. Saha");
    dept[1] = Department("IT", "Dr. Maitra");

    int choice;

    do {
        cout << "\n1. Search by Roll\n";
        cout << "2. Search by Location\n";
        cout << "3. Search by Marks Threshold\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1){
            int roll;
            cout << "Enter roll: ";
            cin >> roll;
            cout << endl;
            searchByRoll(stud, dept, n, roll);
        }
        else if (choice == 2){
            string loc;
            cout << "Enter location: ";
            cin >> loc;
            cout << endl;
            searchByLocation(stud, n, loc);
        }
        else if (choice == 3){
            int t;
            cout << "Enter threshold: ";
            cin >> t;
            cout << endl;
            searchAboveMarks(stud, n, t);
        }

    } while (choice != 4);

    // Free memory
    delete[] stud;
    delete[] dept;

    return 0;
}
