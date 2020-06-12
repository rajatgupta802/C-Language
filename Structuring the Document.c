struct word get_word(char* text, int beg, int end) {
    struct word answer;
    answer.data = calloc(end - beg + 2, sizeof(char));
    int index = 0;
    int i;
    for (i = beg; i <= end; i++)
        answer.data[index++] = text[i];
    answer.data[index] = 0;
    return answer;
}

struct sentence get_sentence(char* text, int beg, int end) {
    struct sentence answer;
    answer.word_count = 1;
    int i;
    for (i = beg; i <= end; i++)
        if (text[i] == ' ')
            ++answer.word_count;
    answer.data = calloc(answer.word_count, sizeof(struct word));
    int start = beg;
    int index = 0;
    for (i = beg; i <= end; i++)
        if (text[i] == ' ')
        {
            answer.data[index++] = get_word(text, start, i - 1);
            start = i + 1;
        }
    answer.data[index] = get_word(text, start, i - 1);
    return answer;
}

struct paragraph get_paragraph(char* text, int beg, int end) {
    struct paragraph answer;
    answer.sentence_count = 0;
    int i;
    for (i = beg; i <= end; i++)
        if (text[i] == '.')
            ++answer.sentence_count;
    answer.data = calloc(answer.sentence_count, sizeof(struct sentence));
    int start = beg;
    int index = 0;
    for (i = beg; i <= end; i++)
        if (text[i] == '.')
        {
            answer.data[index++] = get_sentence(text, start, i - 1);
            start = i + 1;
        }
    return answer;
}

struct document get_document(char* text) {
    struct document answer;
    answer.paragraph_count = 1;
    int i;
    for (i = 0; text[i]; i++)
        if (text[i] == '\n')
            ++answer.paragraph_count;
    answer.data = calloc(answer.paragraph_count, sizeof(struct paragraph));
    int start = 0;
    int index = 0;
    for (i = 0; text[i]; i++)
        if (text[i] == '\n')
        {
            answer.data[index++] = get_paragraph(text, start, i - 1);
            start = i + 1;
        }
    answer.data[index] = get_paragraph(text, start, i - 1);
    return answer;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}
