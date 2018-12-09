#include <stdio.h>
int main (void){

    int x0, x1, y0, y1, p, dx, dy, deltaX, deltaY;

    printf("x0 e y0: ");
    scanf("%d %d", &x0, &y0);
    printf("x1 e y1: ");
    scanf("%d %d", &x1, &y1);

    dx = x1-x0;
    dy = y1-y0;

    deltaY = 2*dy;
    deltaX = 2*dx;

    desenhaPixel(x0,y0);

    p = (deltaY)-dx;

    while(x0<x1){
        if(p<0){
            p = p + deltaY;
            x0 = x0 + 1;
        }
        else{
            p = p + deltaY - deltaX;
            x0 = x0 + 1;
            y0 = y0 + 1;
        }
        desenhaPixel(x0,y0);
    }
    return 0;
}

desenhaPixel(int x, int y){
    printf("(%d),(%d)\n", x, y);
}
