#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    struct word w;
    struct sentence* sen;
    struct paragraph* para;
    struct document* doc;

    int wordIdx = 0;
    int wordLength = 1;

    w.data = (char*)malloc(sizeof(char) * wordLength);
    sen = (struct sentence*)malloc(sizeof(struct sentence*));
    sen->data = (struct word*)malloc(sizeof(struct word));
    para = (struct paragraph*)malloc(sizeof(struct paragraph*));
    para->data = (struct sentence*)malloc(sizeof(struct sentence*));
    doc = (struct document*)malloc(sizeof(struct document*));
    doc->data = (struct paragraph*)malloc(sizeof(struct paragraph*));

    sen->word_count = 0;
    para->sentence_count = 0;
    doc->paragraph_count = 0;

    for (int i = 0; i <= strlen(text); i++) {
        if( *(text + i) == ' ' || *(text + i) == '.' ) {
            w.data = (char*)realloc(w.data, sizeof(char) * wordLength);
            w.data[wordIdx] = '\0';

            sen->word_count++;
            sen->data = (struct word*)realloc(sen->data, sizeof(struct word) * sen->word_count);
            sen->data[sen->word_count - 1].data = (char*)malloc(sizeof(char) * wordLength);
            memcpy(sen->data[sen->word_count - 1].data, w.data, wordLength);

            wordIdx = 0;
            wordLength = 1;
            free(w.data);
            w.data = (char*)malloc(sizeof(char) * wordLength);
        }

        if( *(text + i) == '.' ) {
            para->sentence_count++;
            para->data = (struct sentence*)realloc(para->data, sizeof(struct sentence*) * para->sentence_count);
            memcpy(para->data + (para->sentence_count - 1), sen, sizeof(struct sentence));

            free(sen);
            free(sen->data);
            sen = (struct sentence*)malloc(sizeof(struct sentence*));
            sen->data = (struct word*)malloc(sizeof(struct word));
            sen->word_count = 0;
        }

        if ( *(text + i) == '\n' || *(text + i) == '\0' ) {
            doc->paragraph_count++;
            doc->data = (struct paragraph*)realloc(doc->data, sizeof(struct paragraph*) * doc->paragraph_count);
            memcpy(doc->data + (doc->paragraph_count - 1), para, sizeof(struct paragraph));

            free(para);
            free(para->data);
            para = (struct paragraph*)malloc(sizeof(struct paragraph*));
            para->data = (struct sentence*)malloc(sizeof(struct sentence*));
            para->sentence_count = 0;
        }

        if( *(text + i) != ' ' && *(text + i) != '.' && *(text + i ) != '\n' ) {
            w.data = (char*)realloc(w.data, sizeof(char) * wordLength);
            w.data[wordIdx] = *(text + i);
            wordIdx++;
            wordLength++;
        }
    }

    return *doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[k - 1].data[m - 1].data[n - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[k - 1].data[m - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main()
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }
}
