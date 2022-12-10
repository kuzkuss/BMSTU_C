#include "lab_04_02_01.h"

int main(void)
{
    setbuf(stdout, NULL);
    char str[STR_LEN];
    if (!fgets(str, STR_LEN, stdin))
    {
        printf("String error.\n");
        return STR_ERROR;
    }
    if (strchr(str, 0) == str + STR_LEN - 1 && str[STR_LEN - 2] != '\n')
    {
        printf("Overflow string.\n");
        return OVERFLOW_STR;
    }
    int str_len = strlen(str);
    if (str[str_len - 1] == '\n')
        str[str_len - 1] = '\0';
    if (str[0] == '\0')
    {
        printf("Empty string.\n");
        return EMPTY_LINE;
    }
    int n_words = 0;
    char words[STR_LEN / 2 + 1][LEN_WORD + 1];
    int rc = split(str, words, &n_words);
    if (rc == WORDS_ERR)
    {
        printf("No words.\n");
        return WORDS_ERR;
    }
    if (rc == OVERFLOW_WORD)
    {
        printf("Overflow word.\n");
        return OVERFLOW_WORD;
    }
    sorting(words, &n_words);
    printf("Result: ");
    print_words(words, &n_words);
    return 0;
}

