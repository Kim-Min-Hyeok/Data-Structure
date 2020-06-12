/*On my honor, I pledge that I have neither received
nor provided improper assistance in the completion
of this programming assignment. Signed: Minhyeok Kim*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string name;
  // Use setvbuf() to prevent the output from buffered on console.
  setvbuf(stdout, NULL, _IONBF, 0);
if(argc<=1){
  while (EOF){
    cout << "Enter a name: ";
    getline(cin, name);
    if(name == "") break;
    cout << "Hello " << name << "!\n";
  }
}else{
  for (int i = 1; i < argc; i++)
    cout << "Hello " << argv[i] << "!\n";
  }

  cout << "Hello World!\n";
  // Use system("pause") to prevent the terminal from disappearing
  // as soon as the program terminates as in Visual Studio sometimes.
   system("pause");
   return EXIT_SUCCESS;
 }
