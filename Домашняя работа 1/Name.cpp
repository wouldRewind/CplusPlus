#include <stdafx.h>
#include <iostream>
#include <fstream>
using namespace std;
 
int main(int argc, char* argv[])
{
    ofstream fout("cppstudio.txt"); 
    fout << "Работа с файлами в C++";
    fout.close(); 
    system("pause");
    return 0;
}
