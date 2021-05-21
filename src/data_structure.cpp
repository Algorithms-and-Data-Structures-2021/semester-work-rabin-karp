#include "data_structure.hpp"


namespace itis {
  size_t modPowSubstring(size_t n) {
    const size_t s = 31;
    const size_t d = (size_t(1) << s) - 1;
    size_t m;

    for (m = n; n > d; n = m) {
      for (m = 0; n; n >>= s) {
        m += n & d;
      }
    }
    m = m == d ? 0 : m;
    return m;
  }

  size_t randSize(size_t min, size_t max) {
    size_t result = size_t(rand() % (max-min+1) + min);
    return result;
  }
  std::vector<int> search(std::string &sub, std::string &source) {
    std::vector<int> found_substring{};
    size_t const source_len = static_cast<int>(source.length());
    size_t const sub_len = static_cast<int>(sub.length());
    if (source_len == 0 || sub_len == 0) {
      return found_substring;
    }
    size_t constexpr prime_q = (size_t(1) << 31) - 1; // it's (2^31 - 1)
    size_t const x = randSize(2, prime_q - 1);

    size_t sub_hash = 0;
    size_t source_hash = 0; // хэш текущей части текста
    size_t x_pow = 1;

    int a;
    int b;

    for (a = 0; a < sub_len - 1; a++) {
      x_pow = modPowSubstring(x_pow * x);
    }

    // вычисление хэша подстроки и первого хэша исходного текста
    for (a = 0; a < sub_len; a++) {
      sub_hash = modPowSubstring(x * sub_hash + sub[a]);
      source_hash = modPowSubstring(x * source_hash + source[a]);
    }

    for (a = 0; a < source_len - sub_len + 1; a++) {
      if (sub_hash == source_hash) {
        // хэши равны - проверим, совпадают ли строки в точности
        for (b = 0; b < sub_len; b++) {
          if (sub[b] != source[a+b]) {
            break;
          }
        }

        if (b == sub_len) {
          found_substring.push_back(a);
        }
      }
      //сдвиг строки, пересчет хэша.
      if (size_t(a) < source_len - sub_len) {
        size_t t1 = modPowSubstring(x_pow * size_t(source[a])); // a*x_pow
        signed t2 = modPowSubstring(source_hash + prime_q - t1); // old_sub - a*x_pow
        size_t t3 = modPowSubstring(x*t2); // (old_sub - a*x_pow) * x
        source_hash = modPowSubstring(t3 + size_t(source[a + sub_len])); // (old_sub - a*x_pow) * x + new_char
      }
    }
    return found_substring;
  }
}  // namespace itis