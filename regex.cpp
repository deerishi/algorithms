#include <string>
#include <iostream>
#include <regex>
using namespace std;
int main() {
    string s = "qwthifdfsthis";
    regex r("thi.*s");
    smatch m;
    if(regex_search(s,m,r)) 
    {
        
        cout<<"pattern found at "<<m.position()<<"\n";
    }
    for(sregex_iterator i = sregex_iterator(s.begin(), s.end(), r);
                            i != sregex_iterator();
                            ++i )
    {
        //cout<<"pattern is "<< *i<<"\n";
        smatch m = *i;
        cout << m.str() << " at position " << m.position() << '\n';
    }
}
