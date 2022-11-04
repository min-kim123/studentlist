/* 
Author: Min Kim
Program Description: This program will help you keep track of your students. You can input as many studets as you like, and you will be able to store their first name, last name, id, and gpa.
Date: 11/04/22
  */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;

struct Student {
  char firstname[80];
  char lastname[80];
  int id;
  float gpa;
};


void add(vector<Student*> & studentlist) {
/*  struct Student newstruct;
    cout << "First name: ";
    cin.getline(newstruct.firstname, 80);
    cout << "Last name: ";
    cin.getline(newstruct.lastname, 80);
    cout << "ID: ";
    cin >> newstruct.id;
    cout << "GPA: ";
    cin >> newstruct.gpa;
    studentlist.push_back(newstruct);
  }*/

  Student* addStudent = new Student();
  char firstNameTemp[30];
  char lastNameTemp[30];
  int studentIDTemp;
  float gpaTemp;

  // inputting everything
  cout << "First Name: " << endl;
  cin >> firstNameTemp;
  cout << "Last Name: " << endl;
  cin >> lastNameTemp;
  cout << "ID: " << endl;
  cin >> studentIDTemp;
  cout << "GPA: " << endl;
  cin >> gpaTemp;

  // copys from temp variables into the vector
  strcpy(addStudent->firstname, firstNameTemp);
  strcpy(addStudent->lastname, lastNameTemp);
  addStudent->id = studentIDTemp;
  addStudent->gpa = gpaTemp;

  studentlist.push_back(addStudent);

}

void delet(vector<Student*> & studentlist) {
  int deleteID = 0;
  cout << "Student ID: ";
  cin >> deleteID;
  int num = 0;
  for (int i = 0; i < studentlist.size(); ++i) {
    if (deleteID == studentlist[i]->id) {
      num = i;
      break;
    }
  }
  studentlist.erase(studentlist.begin()+num);
}


void print(vector<Student*> & studentlist) {
  cout<<fixed<<setprecision(2);
  for (int i = 0; i < studentlist.size(); ++i) {
  cout << "------------------------" << endl;
  cout << studentlist[i]->firstname << endl;
  cout << studentlist[i]->lastname << endl;
  cout << studentlist[i]->id << endl;
  cout << studentlist[i]->gpa << endl;
  }
  cout << "------------------------" << endl;
}



int main() {
  char input[20];
  bool cont = true;
  vector <Student*> studentlist;
  while (cont == true) {
    cout << "Would you like to add, print, delete, or quit? (ADD, PRINT, DELETE, QUIT): ";
    cin.getline(input, 20);
    if (strcmp(input, "ADD") == 0) {//add
      add(studentlist);
      cout << "d";
    }
    else if (strcmp(input, "PRINT") == 0) {//print
      print(studentlist);
    }
    else if (strcmp(input, "DELETE") == 0) {//delete
      delet(studentlist);
    }
    else if (strcmp(input, "QUIT") == 0) {//quit
      cout <<"Bye";
      cont = false;
    }
  }
  return 0;
}
