#include "lab_04_03_01.h"

int main(void)
{
    setbuf(stdout, NULL);
    char str[STR_LEN + 1];
    if (fgets(str, sizeof(str) + 1, stdin) == NULL)
    {
        printf("String error.\n");
        return STR_ERROR;
    }
    int str_len = strlen(str);
    if (str[str_len - 1] == '\n')
        str[str_len - 1] = '\0';
    if (strlen(str) > STR_LEN)
    {
        printf("Overflow string.\n");
        return OVERFLOW_STR;
    }
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

    char new_str[STR_LEN + 1] = "";
    form_newstr(words, &n_words, new_str);
    if (strlen(new_str) == 0)
    {
        printf("Empty new string.");
        return EMPTY_NEW_STR;
    }
    printf("Result: %s\n", new_str);
    return 0;
}

