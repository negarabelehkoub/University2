#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
void addPlusPLus (ifstream& inStream, ofstream& outStream);
int main()
{
    ifstream fin;
    ofstream fout;
    cout << "edditing begins \n";
    fin.open("cad.dat");
    if (fin.fail())
    {
        cout << "error, wrong input\n";
        exit(1);
    }
    
    fout.open("cplus.dat");
    if (fout.fail())
    {
        cout << "error, output opening failed\n";
        exit(1);
    }
    addPlusPLus(fin, fout);
    fin.close();
    fout.close();
    cout << "end of program\n";
    return 0;
}
 void addPLusPlus(ifstream& inStream, ofstream& outStream)
 {
    char next;
    inStream.get(next);
    while (!inStream.eof());
    {
        if (next == 'C')
        {
            outStream << "C++";
        }
        else
        {
            outStream << next;
        }
        inStream.get(next);
    }
    
 }