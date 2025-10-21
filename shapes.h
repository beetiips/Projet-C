#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef SHAPES
#define SHAPES


typedef struct background_s {
    char *background;
} background_t;


typedef struct personalise_s {
    char* fill;
    char* stroke;
    int stroke_width;
} personalise_t;


typedef struct rectangle_s {
    int x;
    int y;
    int width;
    int height;
    personalise_t *style;
} rectangle_t;


typedef struct ellipse_s {
    int cx;
    int cy;
    int rx;
    int ry;
    personalise_t *style;
} ellipse_t;


typedef struct line_s {
    int x1;
    int y1;
    int x2;
    int y2;
    char* stroke;
} line_t;


typedef struct poly_points {
    int value;
    struct poly_points *next;
}poly_points, *List;


typedef struct shapes_you_made {
    char shapes;
    struct shapes_you_made *next;
}shapes_you_made, *DList;

typedef enum shapes {
    LINE,
    ELLIPSE,
    RECTANGLE,
    POLYLINE,
    POLYGONE,
} shapes_enum;

typedef union shapes_un {
    line_t LINE;
    ellipse_t ELLIPSE;
    rectangle_t RECTANGLE;
    poly_points POLYLINE;
    poly_points POLYGONE;
} shapes_union;


List new_list(void);
bool is_empty_list(List li);
int list_length(List li);
void print_list(List li);
// List push_back_list(List li, int x);
// List push_front_list(List li, int x);
// List pop_back_list(List li);



personalise_t *create_style(char* fill, char* stroke, int stroke_width);

personalise_t* create_style_from_input();

void free_style(personalise_t *style);


rectangle_t *create_rectangle(int x, int y, int width, int height);

void free_rectangle(rectangle_t *rectangle);


ellipse_t *create_ellipse(int cx, int cy, int rx, int ry);

void free_ellipse(ellipse_t *ellipse);


line_t *create_line(int x1, int y1, int x2, int y2, char* stroke);

void free_line(line_t *line);

#endif