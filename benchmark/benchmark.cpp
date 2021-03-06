#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds


// подключаем вашу структуру данных
#include "RabinKarp.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

// Возможно стоит подумать о том что данные в таблицу будут заноситься  другом порядке и изменить порядок обработки
// папок (сначала прогнать все папки для 100, 500 и тд)
string folders[10] = {"/01/", "/02/", "/03/",
                      "/04/", "/05/", "/06/",
                      "/07/", "/08/", "/09/",
                      "/10/"};
string files[9] = {"100.csv", "500.csv", "1000.csv", "5000.csv", "10000.csv", "50000.csv", "100000csv", "500000.csv", "1000000.csv"};

int main() {
  // работа с набором данных
  const auto path = string(kDatasetPath);
  string line;
  for (auto file : files) {
    for (auto folder : folders) {
      for (int i = 0; i < 5; ++i) { //прогоняем один и тот же csv файл(5 раз)
        auto input_file = ifstream(path + folder + file);

        string string_file;
        while (getline(input_file, line)) {
          for (auto j : line) {
            string_file.push_back(j);
          }
        }

        string pattern = string_file.substr(string_file.length() / 2, 50);

        // сам бенчмарк, в данном случае поиск
        auto time_point_before = chrono::high_resolution_clock::now();

        vector<int> insertions = itis::search(pattern, string_file);

        auto time_point_after = chrono::high_resolution_clock::now();
        auto time_diff = time_point_after - time_point_before;
        long time_elapsed_ns_search = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

        cout << time_elapsed_ns_search << "\n";
        string_file = "";
      }
    }
    cout << "\n";
  }
}