/* 
Author: Min Kim
Program Description: This program will help you keep track of your students. You can input as many studets as you like, and you will be able to store their first name, last name, id, and gpa.
Date: 11/04/2022
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


void add(vector<Student*> & studentlist) {//adds new student information into studentlist vector
  Student* newstudent = new Student();
  char temp_firstname[80];
  char temp_lastname[80];
  int temp_id;
  float temp_gpa;

  // get the new student information
  cout << "------------------------" << endl;
  cout << "First Name: " << endl;
  cin.getline(temp_firstname, 80);
  cout << "Last Name: " << endl;
  cin.getline(temp_lastname, 80);
  cout << "ID: " << endl;
  cin >> temp_id;
  cout << "GPA: " << endl;
  cin >> temp_gpa;
  cout << "------------------------" << endl;

  // copys the temporary variables into studentlist vector
  strcpy(newstudent->firstname, temp_firstname);
  strcpy(newstudent->lastname, temp_lastname);
  newstudent->id = temp_id;
  newstudent->gpa = temp_gpa;

  studentlist.push_back(newstudent);

}

void delet(vector<Student*> & studentlist) {//deletes info of student from specified id
  int deleteID = 0;
  cout << "------------------------" << endl;
  cout << "Student ID: ";
  cin >> deleteID;
  cout << "------------------------" << endl;
  int num = 0;
  for (int i = 0; i < studentlist.size(); ++i) {
    if (deleteID == studentlist[i]->id) {
      num = i;
      break;
    }
  }
  studentlist.erase(studentlist.begin()+num);
}


void print(vector<Student*> & studentlist) {//prints everything in the studentlist vector
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
  //a vector of pointers to studentlist
  vector <Student*> studentlist;
  while (cont == true) {
    cout << "Would you like to add, print, delete, or quit? (ADD, PRINT, DELETE, QUIT): " << endl;
    cin.getline(input, 20);
    if (strcmp(input, "ADD") == 0) {//add
      add(studentlist);
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
