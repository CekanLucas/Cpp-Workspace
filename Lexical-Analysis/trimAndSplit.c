#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char *part1;
    char *part2;
} SplitResult;

SplitResult split(const char *originalString, char splitChar);
char *trim(const char *original);

int main() {
    const char *str = "\nsum1 = var1 + var2";
    SplitResult result = split(str, '=');

    if (result.part1) {
        printf("Part 1: %s\n", result.part1);
    }

    if (result.part2) {
        printf("Part 2: %s\n", result.part2);
    } else {
        printf("Splitting failed.\n");
    }

    // Free dynamically allocated memory
    free(result.part1);
    free(result.part2);

    return 0;
}

SplitResult split(const char *originalString, char splitChar) {
    char *str = trim(originalString);
    char *str2 = trim(strstr(str, &splitChar));

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == splitChar) {
            str[i] = '\0'; // Replacing splitChar with null terminator
            str2 = &str[i + 1]; // move pointer for str2
        }
    }

    SplitResult result;
    result.part1 = strdup(trim(str));
    result.part2 = strdup(trim(str2));

    free(str); // Free dynamically allocated memory
    return result;
}

/* Trims whitespace characters from beginning and end then returns string */
char *trim(const char *original)
{
  int start = 0;
  int end = strlen(original) - 1;

  // Find the first non-whitespace character
  while (isspace(original[start]))
  {
    start++;
  }

  // Find the last non-whitespace character
  while (end > start && isspace(original[end]))
  {
    end--;
  }

  // Calculate the length of the trimmed string
  int length = end - start + 1;

  // Allocate memory for the trimmed string and copy the content
  char *trimmedStr = (char *)malloc(length + 1); // +1 for null terminator
  strncpy(trimmedStr, original + start, length);
  trimmedStr[length] = '\0'; // Null-terminate the string

  return trimmedStr;
}