#include <stdio.h>
#include <string.h>

#define NE 0
#define NW 1
#define SE 2
#define SW 3

#define SIZE 10

int get_dx(int dir) {
    if (dir == NE || dir == SE)
        return 1;
    else
        return -1;
}

int get_dy(int dir) {
    if (dir == NE || dir == NW)
        return -1;
    else
        return 1;
}

int is_hole(int num_holes, int *holes_x, int *holes_y, int x, int y) {
    for (int i = 0; i < num_holes; i++) { // linear search
        if (holes_x[i] == x && holes_y[i] == y) {
            return 1; // found
        }
    }
    return 0; // not found
}

void start_moving(int x, int y, int dir, int rows, int cols, int num_holes, int *holes_x, int *holes_y) {
    int dx, dy; // step/delta

    dx = get_dx(dir);
    dy = get_dy(dir);

    // for (int i = 0; i < 20; i++) {
    int count = 0;
    while(1) {
        count ++;
        if (count > 4*rows*cols) {
            printf("Bounces forever");
            break;
        }
        if (is_hole(num_holes, holes_x, holes_y, x, y) == 1) {
            printf("Falls through hole at (%d,%d)", y, x);
            break;
        }
        // printf("%d %d\n", x, y);
        x = x + dx;
        y = y + dy;

        if (x < 0) { // left boundary
            x = 0; // x++
            if (dir == NW) {
                dir = NE;
            } else { // SW
                dir = SE;
            }
            dx = get_dx(dir);
        }
        if (y < 0) { // upper boundary
            y = 0; // y++
            if (dir == NW) {
                dir = SW;
            } else { // NE
                dir = SE;
            }
            dy = get_dy(dir);
        }
        if (x == cols) { // right boundary
            x = cols - 1; // x--
            if (dir == NE) {
                dir = NW;
            } else { // SE
                dir = SW;
            }
            dx = get_dx(dir);
        }
        if (y == rows) { // lower boundary
            y = rows - 1; // y--
            if (dir == SE) {
                dir = NE;
            } else { // SW
                dir = NW;
            }
            dy = get_dy(dir);
        }
    }
    
}



int main(int argc, char const *argv[])
{
    FILE *fp = fopen("input4.txt", "r");
    int rows, cols, start_x, start_y, num_holes;
    char direction[3];
    int current_direction;
    int holes_x[SIZE], holes_y[SIZE];
    fscanf(fp, "%d %d", &rows, &cols);
    fscanf(fp, "%d", &num_holes);
    for(int i=0; i<num_holes; i++) {
        fscanf(fp, "%d %d", &holes_y[i], &holes_x[i]);
    }
    fscanf(fp, "%d %d", &start_y, &start_x);
    fscanf(fp, "%s", direction);

    if (strcmp(direction, "NE") == 0) {
        current_direction = NE;
    } else if (strcmp(direction, "NW") == 0) {
        current_direction = NW;
    } else if (strcmp(direction, "SE") == 0) {
        current_direction = SE;
    } else { // if (strcmp(direction, "SW") == 0) {
        current_direction = SW;
    } 

    start_moving(start_x, start_y, current_direction, rows, cols, num_holes, holes_x, holes_y);

    return 0;
}
