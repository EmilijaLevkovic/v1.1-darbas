#include <algorithm>
#include <chrono> // Įtraukiame biblioteką, kuri leidžia matuoti laiką
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using std::vector;
using std::string;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::seconds;
using namespace std;

struct StudentasV1 {
  string vardas;
  string pavarde;
  vector<int> nd;   // Namų darbų pažymiai
  int egz;          // Egzamino pažymys
  double galutinis; // Galutinis balas
};


vector<StudentasV1> nuskaityti_duomenis_vector(const string& failo_vardas);

pair<vector<StudentasV1>, vector<StudentasV1>> padalinti_studentus_vector(const vector<StudentasV1>& studentai);

void surusiuoti_studentus_vector(vector<StudentasV1>& studentai);

void isvesti_duomenis_vector(const string& failo_vardas, const vector<StudentasV1>& studentai);
