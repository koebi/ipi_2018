/*
 *  Die folgende Funktion ermittelt, welcher Char in einem String am häufigsten vorkommt und wie oft.
 *  
 *  a) Der Code enthält 8 Fehler syntaktischer und semantischer Natur. Finde, erkläre und behebe diese.
 * 
 *  b) Schreibe den Code so um, dass er statt eines C-Arrays einen std::vector und String-Iteratoren nutzt.
 * 
 *  c) Mit welchem STL-Datentyp lässt sich die komplette Ausgabe auch über ein return-Statement realisieren? (Theorie, nicht impl.!)
 * 
 *  d) In wie fern kann bei bestimmten Eingaben ein uneindeutiges Ergebnis auftreten? (Wir gehen nur von ASCII-Eingaben aus!)
 *     Wie lässt sich dies durch Änderung des return-Typs beheben? (Theorie, nicht impl.!)
 *     
 */

// c) ein STD-Pair, das den Char und den Int enthält (std::pair<char,int>)
// d) wenn mehrere Zeichen am häufigsten vorkommen, wird nur das ersten ausgegeben. Man könnte einen Vector von pairs zurückgeben.

#include <string>
#include <iostream>
#include <vector>

void most_common_char(std::string s, char& r_chr, int& r_num){
    std::vector<int> counter(256,0); //(b)
    r_chr = 0;
    r_num = 0;
    for(auto i = s.begin(); i != s.end(); ++i){ //(b)
        if(++counter[*i] > r_num){ //(b)
            r_num++;
            r_chr = *i; //(b)
        }
    }
}

int main(){
    const std::string str = "das wildpferd frisst wirklich keinen gurkensalat";
    char c = 0;
    int  n = 0;
    most_common_char(str, c, n);
    std::cout << "Der Buchstabe '" << c << "' kommt " << n << " mal vor." << std::endl;
}

