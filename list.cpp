#include "list.h"

double skaiciuoti_galutini(const list<int>& nd, int egz) {
    double suma = 0;
    for (int pazymys : nd) {
        suma += pazymys;
    }
    double vidurkis = suma / nd.size();
    return 0.4 * vidurkis + 0.6 * egz;
}
list<StudentasL1> nuskaityti_duomenis_list(const string& failo_vardas) {
    list<StudentasL1> studentai; 
    ifstream failas(failo_vardas); 
    if (failas.fail()) { 
        throw runtime_error("Nepavyko atidaryti failo " + failo_vardas); 
    }
    string eilute;
    getline(failas, eilute); 
    while (getline(failas, eilute)) { 
        StudentasL1 s; 
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
void isvesti_duomenis_list(const string& failo_vardas, const list<StudentasL1>& studentai) {
    ofstream failas(failo_vardas); 
    if (failas.fail()) { 
        throw runtime_error("Nepavyko atidaryti failo " + failo_vardas);
    }
    failas << "Vardas\tPavarde\tGalutinis\n";
    for (const StudentasL1& s : studentai) { 
        failas << s.vardas << "\t" << s.pavarde << "\t" << s.galutinis << "\n"; 
    }
    failas.close();
}
pair<list<StudentasL1>, list<StudentasL1>> padalinti_studentus_list(const list<StudentasL1>& studentai) {
    list<StudentasL1> vargsiukai_list; 
    list<StudentasL1> kietiakiai_list; 
    for (const StudentasL1& s : studentai) { 
        if (s.galutinis < 5.0) { 
            vargsiukai_list.push_back(s); 
        } else { 
            kietiakiai_list.push_back(s); 
        }
    }
    return make_pair(vargsiukai_list, kietiakiai_list); 
}
void surusiuoti_studentus_list(list<StudentasL1>& studentai) {
    studentai.sort([] (const StudentasL1& a, const StudentasL1& b) {
        if (a.vardas < b.vardas) return true;
        if (a.vardas > b.vardas) return false;
        if (a.pavarde < b.pavarde) return true;
        if (a.pavarde > b.pavarde) return false;
        return a.galutinis < b.galutinis;
    });
}
