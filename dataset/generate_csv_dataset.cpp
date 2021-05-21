#include <fstream>      // ifstream, ofstream
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <string>       // string, getline
#include <string_view>  // string_view
#include <random>       // mt19937_64, random_device
#include <chrono>       // system_clock

using namespace std;

// абсолютный путь до набора данных
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};


int main() {
  const auto pathToDataSet = string(kDatasetPath);

  cout << "Dataset path To Data Set: " << pathToDataSet << endl;


  vector<string> output_streams;
  output_streams.emplace_back("/100.csv");
  output_streams.emplace_back("/500.csv");
  output_streams.emplace_back("/1000.csv");
  output_streams.emplace_back("/5000.csv");
  output_streams.emplace_back("/10000.csv");
  output_streams.emplace_back("/50000.csv");
  output_streams.emplace_back("/100000.csv");
  output_streams.emplace_back("/500000.csv");
  output_streams.emplace_back("/1000000.csv");


  vector<int> integers = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};

  while (!integers.empty()) {
    auto outputStreamDataSet01 = ofstream(pathToDataSet + "/01" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamDataSet02 = ofstream(pathToDataSet + "/02" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamDataSet03 = ofstream(pathToDataSet + "/03" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamDataSet04 = ofstream(pathToDataSet + "/04" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamDataSet05 = ofstream(pathToDataSet + "/05" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamDataSet06 = ofstream(pathToDataSet + "/06" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamDataSet07 = ofstream(pathToDataSet + "/07" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamDataSet08 = ofstream(pathToDataSet + "/08" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamDataSet09 = ofstream(pathToDataSet + "/09" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamDataSet10 = ofstream(pathToDataSet + "/10" + output_streams.front(), ios::ios_base::trunc);

    const auto seed = chrono::system_clock::now().time_since_epoch().count();
    auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения
    auto dist = uniform_int_distribution(0, 10000000);  // равновероятное распределение генерируемых чисел

    if (outputStreamDataSet01) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamDataSet01 << dist(engine) << ',';
      }
      outputStreamDataSet01 << dist(engine) << '\n';
    }

    if (outputStreamDataSet02) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamDataSet02 << dist(engine) << ',';
      }
      outputStreamDataSet02 << dist(engine) << '\n';
    }

    if (outputStreamDataSet03) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamDataSet03 << dist(engine) << ',';
      }
      outputStreamDataSet03 << dist(engine) << '\n';
    }

    if (outputStreamDataSet04) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamDataSet04 << dist(engine) << ',';
      }
      outputStreamDataSet04 << dist(engine) << '\n';
    }

    if (outputStreamDataSet05) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamDataSet05 << dist(engine) << ',';
      }
      outputStreamDataSet05 << dist(engine) << '\n';
    }

    if (outputStreamDataSet06) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamDataSet06 << dist(engine) << ',';
      }
      outputStreamDataSet06 << dist(engine) << '\n';
    }

    if (outputStreamDataSet07) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamDataSet08 << dist(engine) << ',';
      }
      outputStreamDataSet07 << dist(engine) << '\n';
    }

    if (outputStreamDataSet08) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamDataSet08 << dist(engine) << ',';
      }
      outputStreamDataSet08 << dist(engine) << '\n';
    }

    if (outputStreamDataSet09) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamDataSet09 << dist(engine) << ',';
      }
      outputStreamDataSet09 << dist(engine) << '\n';
    }

    if (outputStreamDataSet10) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamDataSet10 << dist(engine) << ',';
      }
      outputStreamDataSet10 << dist(engine) << '\n';
    }
    integers.erase(integers.begin());
    output_streams.erase(output_streams.begin());
  }

  return 0;
}