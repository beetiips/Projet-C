#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "shapes.h"
#include "cli.h"


int main(void) {
    FILE* myfile = fopen("test.svg", "w");

    fprintf(myfile, "<svg viewBox='0 0 1000 1000' xmlns='http://www.w3.org/2000/svg'>\n");

    printf("Welcome in your very own SVG editor!\nIn this editor, you can create any shape you'd like, modify them, delete them or directly create a Patrick.\n");
    printf("Please keep in mind your .svg canvas is 1000x1000.\n  Let's start!\n");

    int chosen_action = 0;

    int loop = 0;
        while (loop < 20) {
            printf("Chose what you'd like to do:\n Create a shape = 1\n Create a Patrick = 2\n Modify a shape = 3\n Delete a shape = 4\n Exit the editor = 0\n");
            scanf("%d", &chosen_action);

        if(chosen_action == 0) {
            printf("Exiting the editor.\n");
            break;
        }

    switch (chosen_action) {
        case 1: {

            int chosen_shape = 0;
    
            printf("Choose a shape:\n Line = 1\n Ellipse = 2\n Rectangle = 3\n Polyline = 4\n Polygon = 5\n");

            scanf("%d", &chosen_shape);

            switch (chosen_shape) {
            case 1: {

            int x1, y1, x2, y2;
            char* stroke;
            x1 = ask_for_int("Choose the X1 coordinate:");
            y1 = ask_for_int("Choose the Y1 coordinate:");
            x2 = ask_for_int("Choose the X2 coordinate:");
            y2 = ask_for_int("Choose the Y2 coordinate:");
            stroke = ask_for_char("Write the stroke color:");
            line_t *line = create_line(x1, y1, x2, y2, stroke);

            printf("You created a line with the following data: x1=%d y1=%d x2=%d y2=%d stroke=%s.\n", line->x1, line->y1, line->x2, line->y2, line->stroke);

            fprintf(myfile, "<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='%s' />\n", line->x1, line->y1, line->x2, line->y2, line->stroke);
            
            free(stroke);
            free_line(line);
                break;
            }
            case 2: {

            int cx, cy, rx, ry;
            cx = ask_for_int("Choose the CX coordinate:");
            cy = ask_for_int("Chose the CY coordinate:");
            rx = ask_for_int("Choose the X radius:");
            ry = ask_for_int("Choose the Y radius:");
            ellipse_t *ellipse = create_ellipse(cx, cy, rx, ry);

             int do_style = ask_for_int("Do you want to personalise the ellipse?\n Yes = 1\n No = 2\n");

                if (do_style == 1) {
                personalise_t* style_data = create_style_from_input();
                printf("You created an ellipse with the following data: cx=%d cy=%d rx=%d ry=%d stroke=%s fill=%s stroke width=%d.\n", ellipse->cx, ellipse->cy, ellipse->rx, ellipse->ry, style_data->stroke, style_data->fill, style_data->stroke_width);
                fprintf(myfile, "<ellipse cx='%d' cy='%d' rx='%d' ry='%d' stroke='%s' fill='%s' stroke-width='%d'/>\n", ellipse->cx, ellipse->cy, ellipse->rx, ellipse->ry, style_data->stroke, style_data->fill, style_data->stroke_width);
            if (style_data->stroke) free(style_data->stroke);
            if (style_data->fill) free(style_data->fill);
            free(style_data);
            } else {
            printf("You created an ellipse with the following data: cx=%d cy=%d rx=%d ry=%d.\n", ellipse->cx, ellipse->cy, ellipse->rx, ellipse->ry);
            fprintf(myfile, "<ellipse cx='%d' cy='%d' rx='%d' ry='%d' />\n", ellipse->cx, ellipse->cy, ellipse->rx, ellipse->ry);
            }
            free_ellipse(ellipse);
                break;
            }
            case 3: {

            int x, y, width, height;
            x = ask_for_int("Choose the X coordinate:");
            y = ask_for_int("Chose the Y coordinate:");
            width = ask_for_int("Choose the width:");
            height = ask_for_int("Choose the height:");
            rectangle_t *rect = create_rectangle(x, y, width, height);

             int do_style = ask_for_int("Do you want to personalise the rectangle?\n Yes = 1\n No = 2\n");

                if (do_style == 1) {
                personalise_t* style_data = create_style_from_input();
                printf("You created a rectangle with the following data: X=%d Y=%d W=%d H=%d stroke=%s fill=%s stroke width=%d.\n", rect->x, rect->y, rect->width, rect->height, style_data->stroke, style_data->fill, style_data->stroke_width);
                fprintf(myfile, "<rect x='%d' y='%d' width='%d' height='%d' stroke='%s' fill='%s' stroke-width='%d'/>\n", rect->x, rect->y, rect->width, rect->height, style_data->stroke, style_data->fill, style_data->stroke_width);
            if (style_data->stroke) free(style_data->stroke);
            if (style_data->fill) free(style_data->fill);
            free(style_data);
            } else {
            printf("You created a rectangle with the following data: X=%d Y=%d W=%d H=%d\n", rect->x, rect->y, rect->width, rect->height);
            fprintf(myfile, "<rect x='%d' y='%d' width='%d' height='%d' />\n", rect->x, rect->y, rect->width, rect->height);
            }
            free_rectangle(rect);
                break;
            }
            case 4: {

            int num_points = ask_for_int("Choose the number of points:");
            char points_str[1024] = "";

            for (int i = 0; i < num_points; i++) {
                int px = ask_for_int("Choose the X coordinate:");
                int py = ask_for_int("Choose the Y coordinate:");
                char buffer[50];
                sprintf(buffer, "%d,%d ", px, py);
                strcat(points_str, buffer);
            }

            int do_style = ask_for_int("Do you want to personalise the polyline?\n Yes = 1\n No = 0\n");

            if (do_style == 1) {
                personalise_t* style_data = create_style_from_input();
                printf("You created a polyline.\n");
                fprintf(myfile, "<polyline fill='%s' stroke='%s' stroke-width='%d' points='%s'/>\n", style_data->fill, style_data->stroke, style_data->stroke_width, points_str);
            if (style_data->stroke) free(style_data->stroke);
            if (style_data->fill) free(style_data->fill);
            free(style_data);
            } else {
            printf("You created a polyline.\n");
            fprintf(myfile, "<polyline fill='none' stroke='black' points='%s'/>\n", points_str);
        }
                break;
            }
            case 5: {

            int nb_points = ask_for_int("Choose the number of points:");
            char points_str2[1024] = "";

            for (int p = 0; p < nb_points; p++) {
                int px = ask_for_int("Choose the X coordinate:");
                int py = ask_for_int("Choose the Y coordinate:");
                char buff[50];
                sprintf(buff, "%d,%d ", px, py);
                strcat(points_str2, buff);
            }

            int do_style = ask_for_int("Do you want to personalise the polygon?\n Yes = 1\n No = 0\n");

            if (do_style == 1) {
                personalise_t* style_data = create_style_from_input();
                printf("You created a polygon.\n");
                fprintf(myfile, "<polygon fill='%s' stroke='%s' stroke-width='%d' points='%s'/>\n", style_data->fill, style_data->stroke, style_data->stroke_width, points_str2);
            if (style_data->stroke) free(style_data->stroke);
            if (style_data->fill) free(style_data->fill);
            free(style_data);
            } else {
            printf("You created a polygon.\n");
            fprintf(myfile, "<polygon points='%s'/>\n", points_str2);
        }
                break;
            }
            default:
            printf("https://www.youtube.com/watch?v=XfELJU1mRMg");
                break;
            }
            
            loop++;
        break;
        }
        case 2: {
        printf("You created a Patrick!\n");
        fprintf(myfile, "<polygon fill='pink' points='500,250 750,750 250,500 750,500 250,750' stroke='pink'/>\n");
        fprintf(myfile, "<polygon fill='green' points='335,575 665,575 700,650 550,650 500,625 450,650 300,650'/>\n");
        fprintf(myfile, "<ellipse cx='470' cy='400' rx='20' ry='30' fill='white'/>\n");
        fprintf(myfile, "<ellipse cx='530' cy='400' rx='20' ry='30' fill='white'/>\n");
        fprintf(myfile, "<ellipse cx='470' cy='400' rx='15' ry='18' fill='black'/>\n");
        fprintf(myfile, "<ellipse cx='530' cy='400' rx='15' ry='18' fill='black'/>\n");
        fprintf(myfile, "<path d='M 450 450 C 450 450, 500 500, 550 450 z' fill='none' stroke='black' stroke-width='3'/>\n");
         break;
        }
        case 3: {
        printf("Which shape would you like to modify?\n");
        break;
        }
        case 4: {
        printf("Which shape would you like to delete?\n");
        break;
        }
        default: {
        printf("Please chose a valid number.\n");
        }
        }

    }

    fprintf(myfile, "</svg>");
    fclose(myfile);

    printf("Your .svg has been saved in test.svg.\n");
    
    return EXIT_SUCCESS;
}

