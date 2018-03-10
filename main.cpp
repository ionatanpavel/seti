#include <iostream>
#include <fstream>
#include <string>
#define MXN 200005
using namespace std;
string t, s, a[MXN], aux,  aux1, aux2;
int nr = 0;
int main()
{
    ifstream fin ("seti.in");
    ofstream fout ("seti.out");
    fin >> t;
    while(fin >> s)  {
        nr ++;
        a[nr] = s;
    }
    for (int i = 1; i < nr; i ++)
        for (int j = i + 1; j <= nr; j ++)  {
            aux1 = a[i];
            aux2 = a[j];
            int ok = 0;
            for (int i = 0; i < 4; i ++)
                if (t.find(aux1[i]) > t.find(aux2[i]))  {
                    ok = 1;
                    break;
                }
            if (ok == 1)    {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    for (int i = 1; i <= nr; i ++)
        fout << a[i] << endl;
    return 0;
}
