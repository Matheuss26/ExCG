#include <stdio.h>

void desenha(int x, int y);

int main (void){

    int raio, x1, y1;
    float p = 0.0;

    printf("entre com o raio:");
    scanf("%d", &raio);

    x1 = 0, y1 = raio;
    p = (5.0 / 4) - raio;

    desenha(x1,y1);

    while (x1 < y1) {
        if(p<0){
            x1 = x1 + 1;
            p = p + 2*x1 + 1;
        }
        else{
            x1 = x1 + 1;
            y1 = y1 - 1;
            p = p + 2*x1 + 1 - 2*y1;
        }
        desenha(x1,y1);
    }
    return 0;
}

void desenha(int x, int y){
    printf("(%d),(%d)\n", x, y);
}