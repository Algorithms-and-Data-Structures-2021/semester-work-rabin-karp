#include "data_structure.hpp"
#include <bits/stdc++.h>
using namespace std;
#define d 256
namespace itis
{
  void algorithm(char *pattern, char *text, int q)
  {
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int patternHash = 0; // значение хеша для шаблона
    int textHash = 0; // значение хеша для текста
    int h = 1;

    for (int i = 0; i < patternLength - 1; i++)
      h = (h * d) % q;

    for (int i = 0; i < patternLength; i++)
    {
      patternHash = (d * patternHash + pattern[i]) % q;
      textHash = (d * textHash + text[i]) % q;
    }

    // Сдвиг шаблона по тексту один за одним
    for (int i = 0; i <= textLength - patternLength; i++)
    {
      if (patternHash == textHash)
      {
        int j;
        // Проверка всех символов один за одним
        for (j = 0; j < patternLength; j++)
        {
          if (text[i+j] != pattern[j])
            break;
        }

        if (j == patternLength)
          cout<<"Pattern found at index "<< i<<endl;
      }

      if (i < textLength - patternLength)
      {
        textHash = (d * (textHash - text[i] * h) + text[i + patternLength]) % q;

        if (textHash < 0)
          textHash = (textHash + q);
      }
    }
  }
}  // namespace itis