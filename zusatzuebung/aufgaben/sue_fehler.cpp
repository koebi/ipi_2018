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
 *     Wie lässt sich dies durch Änderung des return-Typs beheben?  (Theorie, nicht impl.!)
 *     
 */

#include <string>

void most_common_char(std::string s, char r_chr, int r_num){
    int counter[];
    r_chr = 0;
    r_num = 0;
    for(i = 0; i < s.size(); ++i){
        if(++counter[s[i]] > r_num){
            r_num++;
            s[i] = r_chr;
        }
    }
}

main(){
    const std::string str = "das wildpferd frisst wirklich keinen gurkensalat";
    char c = 0;
    int  n = 0;
    most_common_char(str, c, n);
    std::cout << "Der Buchstabe '" << n << "' kommt " << c << " mal vor." << std::endl;
}