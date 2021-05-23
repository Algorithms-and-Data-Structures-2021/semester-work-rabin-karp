#pragma once
#include <vector>
#include <string>
#include <iostream>
// Заголовочный файл с объявлением структуры данных

namespace itis {

  size_t modPowSubstring(size_t n);
  size_t randSize(size_t min, size_t max);
  std::vector<int> search(std::string &sub, std::string &source);

}  // namespace itis