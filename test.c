#include <stdio.h>
#include <stdlib.h>

typedef struct Rectangle {
    int width;
    int height;
    int (*area)(struct Rectangle);
    int (*perimeter)(struct Rectangle);
} Rectangle;

int rectArea(Rectangle data) {
    return data.width * data.height;
}

int rectPerimeter(Rectangle data) {
    return 2 * data.width + 2 * data.height;
}

void scale(Rectangle *data, int factor) {
    data->width *= factor;
    data->height *= factor;
}

Rectangle biggest(Rectangle arr[], int count) {
    Rectangle winner = arr[0];
    for(int i = 0; i < count; i++) {
        if(arr[i].area(arr[i]) > winner.area(winner)) {
            winner = arr[i];
        }
    }

    return winner;
}

int main() {
    int n = 4;

    Rectangle *shapes = malloc(n * sizeof(Rectangle));

    if (shapes == NULL) {
        printf("Allocation failed!\n");
        return 1;
    }

    shapes[0] = (Rectangle){100, 50, rectArea, rectPerimeter};
    shapes[1] = (Rectangle){200, 100, rectArea, rectPerimeter};
    shapes[2] = (Rectangle){300, 150, rectArea, rectPerimeter};
    shapes[3] = (Rectangle){400, 200, rectArea, rectPerimeter};

    for(int i = 0; i < n; i++) {
        printf("Width: %d\n", shapes[i].width);
        printf("Height: %d\n", shapes[i].height);
        printf("Area: %d\n", shapes[i].area(shapes[i]));
        printf("Perimeter: %d\n", shapes[i].perimeter(shapes[i]));
    }

    Rectangle winner = biggest(shapes, n);

    printf("Width: %d\n", winner.width);
    printf("Height: %d\n", winner.height);
    printf("Area: %d\n", winner.area(winner));
    printf("Perimeter: %d\n", winner.perimeter(winner));

    free(shapes);
}