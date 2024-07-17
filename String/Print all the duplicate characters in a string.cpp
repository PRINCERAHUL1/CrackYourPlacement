#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int printDuplicates(string str)
{
  sort(str.begin(),  str.end());
  for(int i=0;i<str.length();i++)
  {
    int c=1;
    
    if (i > 0 && str[i] == str[i - 1])
    {
      continue;
    }
    
    for(int j=i+1;j<str.length();j++)
    {
      if(str[i] == str[j])
      {
        c++;
      }
    }
    if(c>1)
    {
      cout << str[i] << ", count = " << c << endl;
    }
  }
  
}

int main()
{
    string str = "test string";
    printDuplicates(str);
    return 0;
}
