#include <algorithm>
#include <chrono>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
using std::list;
using std::string;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::seconds;
using namespace std;

class StudentasL1 {
  public: // nurodome, kad šie nariai yra vieši ir galimi iš išorės
    string vardas;
    string pavarde;
    list<int> nd;   // Namų darbų pažymiai
    int egz;          // Egzamino pažymys
    double galutinis; // Galutinis balas
};

list<StudentasL1> nuskaityti_duomenis_list(const string& failo_vardas);

pair<list<StudentasL1>, list<StudentasL1>> padalinti_studentus_list(const list<StudentasL1>& studentai);

void surusiuoti_studentus_list(list<StudentasL1>& studentai);

void isvesti_duomenis_list(const string& failo_vardas, const list<StudentasL1>& studentai);
