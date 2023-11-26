#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include "vector.h"
#include "list.h"
using namespace std;


pair<double, double> test_vector(const string& input_file, const string& output_file1, const string& output_file2) {

    auto start_read = high_resolution_clock::now();
    vector<StudentasV1> studentai = nuskaityti_duomenis_vector(input_file); 
    auto stop_read = high_resolution_clock::now();
  auto duration_read = duration_cast<microseconds>(stop_read - start_read);
    auto start_split = high_resolution_clock::now();
    pair<vector<StudentasV1>, vector<StudentasV1>> padalinimas = padalinti_studentus_vector(studentai); 
    auto stop_split = high_resolution_clock::now();
    auto duration_split = duration_cast<microseconds>(stop_split - start_split);
    auto start_sort = high_resolution_clock::now();
    surusiuoti_studentus_vector(padalinimas.first); 
    surusiuoti_studentus_vector(padalinimas.second);
    auto stop_sort = high_resolution_clock::now();
    auto duration_sort = duration_cast<microseconds>(stop_sort - start_sort);
    auto start_write = high_resolution_clock::now();
    isvesti_duomenis_vector(output_file1, padalinimas.first); 
    isvesti_duomenis_vector(output_file2, padalinimas.second);
    auto stop_write = high_resolution_clock::now();
    auto duration_write = duration_cast<microseconds>(stop_write - start_write);
    return make_pair(duration_read.count() / 1000000.0, duration_split.count() / 1000000.0 + duration_sort.count() / 1000000.0 + duration_write.count() / 1000000.0); 
}

pair<double, double> test_list(const string& input_file, const string& output_file1, const string& output_file2) {
    
    auto start_read = high_resolution_clock::now();
    list<StudentasL1> studentai = nuskaityti_duomenis_list(input_file); 
    auto stop_read = high_resolution_clock::now();
    auto duration_read = duration_cast<microseconds>(stop_read - start_read);
    auto start_split = high_resolution_clock::now();
    pair<list<StudentasL1>, list<StudentasL1>> padalinimas = padalinti_studentus_list(studentai); 
    auto stop_split = high_resolution_clock::now();
    auto duration_split = duration_cast<microseconds>(stop_split - start_split);
    auto start_sort = high_resolution_clock::now();
    surusiuoti_studentus_list(padalinimas.first);
    surusiuoti_studentus_list(padalinimas.second);
    auto stop_sort = high_resolution_clock::now();
    auto duration_sort = duration_cast<microseconds>(stop_sort - start_sort);
    auto start_write = high_resolution_clock::now();
    isvesti_duomenis_list(output_file1, padalinimas.first); 
    isvesti_duomenis_list(output_file2, padalinimas.second);
    auto stop_write = high_resolution_clock::now();
    auto duration_write = duration_cast<microseconds>(stop_write - start_write);
    return make_pair(duration_read.count() / 1000000.0, duration_split.count() / 1000000.0 + duration_sort.count() / 1000000.0 + duration_write.count() / 1000000.0); 
}

int main() {
  try {
      pair<double, double> vector_times = test_vector("studentai10000.txt", 
"vargs_v_1strat.txt", 
"kiet_v_1strat.txt"); 
      pair<double, double> list_times = test_list("studentai10000.txt", 
"vargs_l_1strat.txt", 
"kiet_l_1strat.txt"); 
    
      cout << "Programa baige darba.\n";
      cout << "VECTOR LAIKAS:\n";
      cout << "Vector duomenu nuskaitymas: " << vector_times.first << " sek.\n";
      cout << "Vektor kitos operacijos: " << vector_times.second << " sek.\n";
      cout << "LIST LAIKAS:\n";
      cout << "List duomenu nuskaitymas: " << list_times.first << " sek.\n";
      cout << "List kitos operacijos: " << list_times.second << " sek.\n";
      cout << "SKIRTUMAS (Vector-List):\n";
      cout << "Duomenu nuskaitymas: " << vector_times.first - list_times.first << " sek.\n";
      cout << "Kitos operacijos:"<< vector_times.second-list_times.second<<" sek.\n";


    double vector_time_total = 0.0;
    double list_time_total = 0.0;

    const int TEST_COUNT = 10;

    for (int i = 0; i < TEST_COUNT; i++) {
        pair<double, double> vector_times = test_vector("studentai10000.txt", 
"vargs_v_1strat.txt", 
"kiet_v_1strat.txt");
        pair<double, double> list_times = test_list("studentai10000.txt", 
"vargs_l_1strat.txt", 
"kiet_l_1strat.txt");
        vector_time_total += vector_times.first + vector_times.second;
        list_time_total += list_times.first + list_times.second;
    }

    double vector_time_average = vector_time_total / TEST_COUNT;
    double list_time_average = list_time_total / TEST_COUNT;

    cout << "VECTOR VIDURKIS 1 strat:\n";
    cout << "Vector bendras laikas 1 strat: " << vector_time_average << " sek.\n";
    cout << "LIST VIDURKIS 1 strat:\n";
    cout << "List bendras laikas 1 strat: " << list_time_average << " sek.\n";
    cout << "SKIRTUMAS (Vector-List) 1 strat.:\n";
    cout << "Bendras laikas 1 strat: " << vector_time_average - list_time_average << " sek.\n";

  }
    catch (const exception& e){
              cout << "Klaida: " << e.what() << "\n";
          }return 0;}
