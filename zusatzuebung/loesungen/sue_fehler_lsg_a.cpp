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

#include <string>
#include <iostream> //ERR: fehlt

void most_common_char(std::string s, char& r_chr, int& r_num){ //ERR: Ref.
    int counter[256]; //ERR: Zahl
    for(int i = 0; i < 256; ++i){ //ERR: Init
        counter[i] = 0;
    }
    r_chr = 0;
    r_num = 0;
    for(int i = 0; i < s.size(); ++i){ //ERR: int i
        if(++counter[s[i]] > r_num){
            r_num++;
            r_chr = s[i]; //ERR: falschrum
        }
    }
}

int main(){ //ERR: ret-type
    const std::string str = "das wildpferd frisst wirklich keinen gurkensalat";
    char c = 0;
    int  n = 0;
    most_common_char(str, c, n);
    std::cout << "Der Buchstabe '" << c << "' kommt " << n << " mal vor." << std::endl; //ERR: falschrum
}