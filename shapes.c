#include <stdlib.h>
#include "shapes.h"
#include "cli.h"


personalise_t *create_style(char* fill, char* stroke, int stroke_width) {
    personalise_t *style = malloc(sizeof(personalise_t));
    style->fill = fill;
    style->stroke = stroke;
    style->stroke_width = stroke_width;
    return style;
}

personalise_t* create_style_from_input() {
    personalise_t* style = malloc(sizeof(personalise_t));
    style->stroke = ask_for_char("Choose the stroke color:");
    style->fill = ask_for_char("Choose the fill color:");
    style->stroke_width = ask_for_int("Choose the width of the stroke:");
    return style;
}

//-----------------------------------------------------------------

rectangle_t *create_rectangle(int x, int y, int width, int height) {
    rectangle_t *rectangle = malloc(sizeof(rectangle));
    rectangle->x = x;
    rectangle->y = y;
    rectangle->width = width;
    rectangle->height = height;
    return rectangle;
}

void free_rectangle(rectangle_t *rectangle) {
    free(rectangle);
}

// ----------------------------------------------------------------

ellipse_t *create_ellipse(int cx, int cy, int rx, int ry) {
    ellipse_t *ellipse = malloc(sizeof(ellipse));
    ellipse->cx = cx;
    ellipse->cy = cy;
    ellipse->rx = rx;
    ellipse->ry = ry;
    return ellipse;
}

void free_ellipse(ellipse_t *ellipse) {
    free(ellipse);
}

// -----------------------------------------------------------------

line_t *create_line(int x1, int y1, int x2, int y2, char* stroke) {
    line_t *line = malloc(sizeof(line));
    line->x1 = x1;
    line->y1 = y1;
    line->x2 = x2;
    line->y2 = y2;
    line->stroke = stroke;
    return line;
}

void free_line(line_t *line) {
    free(line);
}



// ----------------------------------------------------------------

List new_list(void) {
    return NULL;
}

bool is_empty_list(List li) {
    if (li == NULL)
        return true;
    
    return false;
}

int list_length(List li) {
    int size = 0;

    if(!is_empty_list(li))
        while(li != NULL) {
        ++size;
        li = li->next;
    }


    return size;
}

void print_list(List li) {
    if(is_empty_list(li)) {
        printf("You didn't chose any points - the list is empty.\n");
        return;
    }

    while(li != NULL) {
        printf("%d", li->value);
        li = li->next;
    }

}


// ---------------------------------------------------

// List push_back_list(List li, int x) {
//     ListElement *element;
    
//     element = malloc(sizeof(*element));

//     if(element == NULL) {
//         printf(stderr, "Allocation error, please try again.\n");
//         exit(EXIT_FAILURE);
//         }

//     element->value = x;
//     element->next = NULL;

//     if(is_empty_list(li))
//         return element;

//     ListElement *temp;
//     temp = li;

//     while(temp->next != NULL)
//         temp = temp->next;
    
//     temp->next = element;

//     return li;
// }

// List push_front_list(List li, int x) {
//     ListElement *element;
    
//     element = malloc(sizeof(*element));

//     if(element == NULL) {
//         printf(stderr, "Allocation error, please try again.\n");
//         exit(EXIT_FAILURE);
//         }
//     element->value = x;
//     if(is_empty_list(li))
//         element->next = NULL;
//     else
//         element->next = li;
    
//     return element;
// }



// List pop_back_list(List li) {
//     if(is_empty_list(li))
//         return new_list();
    
//     if(li->next == NULL) {
//         free(li);
//         li == NULL;

//         return new_list();
//     }

//     ListElement *temp = li;
//     ListElement *before = li;

//     while(temp->next != NULL) {
//         before = temp;
//         temp = temp->next;
//     }

//     before->next = NULL;
//     free(temp);
//     temp = NULL;

//     return li;
// }