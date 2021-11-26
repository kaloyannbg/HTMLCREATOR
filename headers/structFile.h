typedef char *string;

struct HTML_STRUCT
{
    char HTML_OPEN[30];
    char HEAD_OPEN[30];
    char STYLE_OPEN[30];
    char BACKGROUND_COLOR[30];
    char TEXT_COLOR[30];
    char STYLE_CLOSE[30];
    char TITLE_OPEN[30];
    string TITLE_CONT;
    char TITLE_CLOSE[30];
    char HEAD_CLOSE[30];
    char BODY_OPEN[30];
    char BODY_H1_OPEN[30];
    string BODY_H1_CONT;
    char BODY_H1_CLOSE[30];
    char BODY_P_OPEN[30];
    string BODY_P_CONT;
    char BODY_P_CLOSE[30];
    char BODY_CLOSE[30];
    char HTML_CLOSE[30];
};

typedef struct HTML_STRUCT html_t;