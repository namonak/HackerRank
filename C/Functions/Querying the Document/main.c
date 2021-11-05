#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    char* word = document[n-1][m-1][k-1];
    return word;
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    char** sentence = document[m-1][k-1];
    return sentence;
}

char*** kth_paragraph(char**** document, int k) {
    char*** paragraph = document[k-1];
    return paragraph;
}

char**** get_document(char* text) {
    char**** document = (char****)malloc(MAX_PARAGRAPHS * sizeof(char***));
    char* paragraph = strtok(text, "\n");
    int i = 0;
    while (paragraph != NULL) {
        document[i] = (char***)malloc(MAX_PARAGRAPHS * sizeof(char**));
        char* sentence = strtok(paragraph, ".");
        int j = 0;
        while (sentence != NULL) {
            document[i][j] = (char**)malloc(MAX_CHARACTERS * sizeof(char*));
            char* word = strtok(sentence, " ");
            int k = 0;
            while (word != NULL) {
                document[i][j][k] = (char*)malloc(MAX_CHARACTERS * sizeof(char));
                strcpy(document[i][j][k], word);
                word = strtok(NULL, " ");
                k++;
            }
            sentence = strtok(NULL, ".");
            j++;
        }
        paragraph = strtok(NULL, "\n");
        i++;
    }
    return document;
}


char* get_input_text() {
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
}

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main()
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }
}