#include <string.h>
#include <stdlib.h>
#define max 500
extern "C"
{
  int containsSubstring(const char *str, const char *substr)
  {
    int len = strlen(str);
    int sublen = strlen(substr);

    for (int i = 0; i <= len - sublen; i++)
    {
      int j;
      for (j = 0; j < sublen; j++)
      {
        if (str[i + j] != substr[j])
        {
          break;
        }
      }
      if (j == sublen)
      {
        return 1; // Tìm thấy xâu con
      }
    }

    return 0; // Không tìm thấy xâu con
  }
  // Hàm để hiển thị các xâu con có độ dài lớn hơn 1 đơn vị so với độ dài xâu con và chứa xâu con đó
  void displaySubstringsContaining(char strings[][max], int numStrings, char commonSubstrings[][max], int commonSubstringsCount, int length1)
  {
    for (int i = 0; i < commonSubstringsCount; i++)
    {
      int length = strlen(commonSubstrings[i]) + length1;

      // Tạo một mảng đếm cho các xâu con
      char substringCount[max][max];

      // Duyệt qua từng chuỗi trong danh sách và tìm các xâu con
      for (int j = 0; j < numStrings; j++)
      {
        int n = strlen(strings[j]);
        if (n >= length)
        {
          for (int k = 0; k <= n - length; k++)
          {
            char substring[max];
            strncpy(substring, strings[j] + k, length);
            substring[length] = '\0';

            if (containsSubstring(substring, commonSubstrings[i]))
            {
              strcpy(substringCount[k], substring);
            }
          }
        }
      }
    }
  }
    // Hàm để hiển thị các xâu con tồn tại ở tất cả các chuỗi
  void displayCommonSubstrings(char strings[][max], int numStrings, int length, int number2, char commonSubstrings[max][max], int commonSubstringsCount = 0)
  {
    // Tạo một mảng đếm cho các xâu con
    length = length - 1;

    // Duyệt qua từng chuỗi trong danh sách và tìm các xâu con
    for (int j = 0; j < numStrings; j++)
    {
      int n = strlen(strings[j]);
      if (n >= length)
      {
        for (int i = 0; i <= n - length; i++)
        {
          char substring[max];
          strncpy(substring, strings[j] + i, length);
          substring[length] = '\0';

          int found = 0;
          for (int k = 0; k < commonSubstringsCount; k++)
          {
            if (strcmp(substring, commonSubstrings[k]) == 0)
            {
              found = 1;
              break;
            }
          }

          if (!found)
          {
            int count = 1;
            for (int k = j + 1; k < numStrings; k++)
            {
              if (containsSubstring(strings[k], substring))
              {
                count++;
              }
            }
            if (count == numStrings)
            {
              strcpy(commonSubstrings[commonSubstringsCount], substring);
              commonSubstringsCount++;
            }
          }
        }
      }
    }
    displaySubstringsContaining(strings, numStrings, commonSubstrings, commonSubstringsCount, number2);
  }
}
