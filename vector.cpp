#include "vector1.h"


double skaiciuoti_galutini(const vector<int>& nd, int egz) {
    double suma = 0;
    for (int pazymys : nd) {
        suma += pazymys;
    }
    double vidurkis = suma / nd.size();
    return 0.4 * vidurkis + 0.6 * egz;
}

vector<StudentasV1> nuskaityti_duomenis_vector(const string& failo_vardas) {
    vector<StudentasV1> studentai; 
    ifstream failas(failo_vardas); 
    if (failas.fail()) { 
        throw runtime_error("Nepavyko atidaryti failo " + failo_vardas); 
    }
    string eilute; 
    getline(failas, eilute); 
    while (getline(failas, eilute)) { 
        StudentasV1 s; 
        stringstream ss(eilute); 
        ss >> s.vardas >> s.pavarde; 
        int pazymys; 
        while (ss >> pazymys) { 
            s.nd.push_back(pazymys); 
        }
        s.egz = s.nd.back(); 
        s.nd.pop_back(); 
        s.galutinis = skaiciuoti_galutini(s.nd, s.egz); 
        studentai.push_back(s);
    }
    failas.close(); 
    return studentai; 
}

void isvesti_duomenis_vector(const string& failo_vardas, const vector<StudentasV1>& studentai) {
    ofstream failas(failo_vardas); 
    if (failas.fail()) { 
        throw runtime_error("Nepavyko atidaryti failo " + failo_vardas); 
    }
    failas << "Vardas\tPavarde\tGalutinis\n";
    for (const StudentasV1& s : studentai) { 
        failas << s.vardas << "\t" << s.pavarde << "\t" << s.galutinis << "\n"; 
    }
    failas.close();
}

pair<vector<StudentasV1>, vector<StudentasV1>> padalinti_studentus_vector(const vector<StudentasV1>& studentai) {
    vector<StudentasV1> vargsiukai_vector; // 
    vector<StudentasV1> kietiakiai_vector; //
    for (const StudentasV1& s : studentai) { 
        if (s.galutinis < 5.0) { 
            vargsiukai_vector.push_back(s);
        } else {
            kietiakiai_vector.push_back(s);
        }
    }
    return make_pair(vargsiukai_vector, kietiakiai_vector); 
}
void surusiuoti_studentus_vector(vector<StudentasV1>& studentai) {
    sort(studentai.begin(), studentai.end(),[] (const StudentasV1& a, const StudentasV1& b) {
        if (a.vardas < b.vardas) return true;
        if (a.vardas > b.vardas) return false;
        if (a.pavarde < b.pavarde) return true;
        if (a.pavarde > b.pavarde) return false;
        return a.galutinis > b.galutinis;
    });
}
