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
    struct document doc;
    struct paragraph* para = NULL;
    struct sentence* sen = NULL;
    char* word = NULL;

    doc.data = NULL;
    doc.paragraph_count = 0;

    while(*text) {
        if (*text == ' ' || *text == '.') {
            if (para == NULL) {
                doc.paragraph_count++;
                doc.data = (struct paragraph*)realloc(doc.data, sizeof(struct paragraph) * doc.paragraph_count);

                para = doc.data + doc.paragraph_count - 1;
                para->data = NULL;
                para->sentence_count = 0;

                sen = NULL;
            }

            if (sen == NULL) {
                para->sentence_count++;
                para->data = (struct sentence*)realloc(para->data, sizeof(struct sentence) * para->sentence_count);

                sen = para->data + para->sentence_count - 1;
                sen->data = NULL;
                sen->word_count = 0;
            }

            sen->word_count++;
            sen->data = (struct word*)realloc(sen->data, sizeof(struct word) * sen->word_count);
            sen->data[sen->word_count - 1].data = word;
            word = NULL;

            if (*text == '.') {
                sen = NULL;
            }
            *text = '\0';
        } else if (*text == '\n') {
            sen = NULL;
            para = NULL;
        } else {
            if (word == NULL) {
                word = text;
            }
        }
        text++;
    }
    return doc;
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
