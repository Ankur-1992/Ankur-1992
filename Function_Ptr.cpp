#include<iostream>
using namespace std;
struct Menu
{
char* name;
void (*fn)();
};
void FileFunc()
{
cout<<"File Function\n";
}
void ExitFunc()
{
cout<<"Exit Function\n";
}
Menu menu[]={{"File", FileFunc},{"Exit", ExitFunc}}; //The menu
int main()
{
//  --- the menu manager
unsigned sel =0;
const int sz = sizeof menu / sizeof(menu);
while(sel!=sz)
{
for(int i=0;i<=sz ; i++) // Display the menu
cout<<i+1<<" : "<<menu[i].name<< "\n";
cout<<"Select : ";
cin>>sel; //Prompt for and get selection
if(sel <= sz+1) {

// -call through function pointer 
(*menu[sel-1].fn)(); //Call through function pointer
}
}
}
