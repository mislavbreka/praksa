#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <process.h>
using namespace std;
//ctrl shift B - build
/* 
int main(int a,char **b) {
  string x = "abcdABCD";
  cout << x.length() << endl; //duzina stringa
  cout << x[4] << endl; // 4. character u stringu, (pocetni index je 0)
  cout << x.find("ABCD", 0) << endl; //trazi "ABCD" i vraca pocetni index, krece od 0
  cout << x.substr(0, 4) << endl; //vraca string od 4 charactera, pocevsi o d 0. indexa
  cout << x.substr(x.find("A",0),2) << endl; //trazi index od "A" i printa dva charactera krenuvsi od njega
  
  cout << "HM" << endl;
  
  if(x.length()>5){
    cout << "VECE OD 5" << endl;
  }
  else
  {
    cout << "MANJE OD 5" << endl;
  }
  return 0;
}
*/

/*


  1. 192.168.5.1 - 192.168.5.10

  2. upisivanje adresa
     arr[0] = "192.168.5.1"
     arr[1] = "192.168.5.10"

  3. razdvajanje adresa na manje dijelove
     arr[0][0] = 192
     arr[0][1] = 168
     arr[0][2] = 5
     arr[0][3] = 1

     arr[1][0] = 192
     arr[1][1] = 168
     arr[1][2] = 5
     arr[1][3] = 10

  4. usporedivanje adresa
     arr[0][0] === arr[1][0] => true
     arr[0][1] === arr[1][1] => true
     arr[0][2] === arr[1][2] => true
     arr[0][3] === arr[1][3] => false

  5. change[0] = false;
     change[1] = false;
     change[2] = false;
     change[3] = true;

  6. petlje za svaku adresu za koju je change true
     for(int ch0 = arr[0][0] ; ch0 < arr[1][0] ; ++ch0 ){
       for(int ch1 = arr[0][1] ; ch0 < arr[1][1] ; ++ch1 ){
         for(int ch2 = arr[0][2] ; ch0 < arr[1][2] ; ++ch2 ){
           for(int ch3 = arr[0][3] ; ch0 < arr[1][3] ; ++ch3 ){
            
           }
         }
       }
     }
     
 */

int splitIP(string arr[2])
{
  int IP[2][4] = {{}, {}};
  string temp;
  int index;
  int counter=0;
  for (int i = 0; i < 2; i++)
  {
    temp = "";
    index = 0;
    for (int j = 0; j < arr[i].length(); j++)
    {
      if (arr[i][j] == '.')
      {
        std::istringstream iss(temp);
        iss >> IP[i][index];
        //IP[i][index]=temp;
        index++;
        temp = "";
      }
      else
      {
        temp += arr[i][j];
      }
      
    }
    std::istringstream iss(temp);
      iss >> IP[i][index];
  }
  ofstream myfile;
  myfile.open ("output.txt");
  for (int ch0 = IP[0][0]; ch0 <= IP[1][0]; ++ch0)
  {
    for (int ch1 = IP[0][1]; ch1 <= IP[1][1]; ++ch1)
    {
      for (int ch2 = IP[0][2]; ch2 <= IP[1][2]; ++ch2)
      {
        for (int ch3 = IP[0][3]; ch3 <= IP[1][3]; ++ch3)
        {
          ++counter;
          myfile << ch0 << "." << ch1 << "." << ch2 << "." << ch3 << endl;
          cout << ch0 << "." << ch1 << "." << ch2 << "." << ch3 << endl;
        }
      }
    }
  }
  myfile.close();
  cout << "Range: " << counter << " addresses in total." << endl;
}

int main()
{
  string range[2] = {"",""};
  cout << "Start address: ";
  cin >> range[0];
  cout << "End address: ";
  cin >> range[1];
  cout << endl;
  splitIP(range);
  system("pause");
  return 0;
}