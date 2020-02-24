#include  <iostream>

using namespace std;

//macro definitions for max variable length
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_ABOUT_LENGTH 200

using namespace std;

int main () {
  char name[MAX_NAME_LENGTH], address[MAX_ADDRESS_LENGTH],
    about[MAX_ABOUT_LENGTH];

  cout << "Enter name: ";
  cin.getline (name, MAX_NAME_LENGTH);

  cout << "Enter address: ";
  cin.getline (address, MAX_ADDRESS_LENGTH);

  cout << "Enter about yourself (press # to complete): ";
  cin.getline (about, MAX_ABOUT_LENGTH, '#');	//# is a delimiter 

  cout << "\nEntered details are:\n";
  cout << "Name: " << name << endl;
  cout << "Address: " << address << endl;
  cout << "About: " << about << endl;
}
