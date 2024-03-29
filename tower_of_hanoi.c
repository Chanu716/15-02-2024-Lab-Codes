#include <stdio.h>

void move(int n, int source, int destination, int intermediate) {
    if (n == 1) {
        printf("Move disk 1 from shaft %d to shaft %d\n", source, destination);
        return;
    }

    move(n - 1, source, intermediate, destination);
    printf("Move disk %d from shaft %d to shaft %d\n", n, source, destination);
    move(n - 1, intermediate, destination, source);
}

int main() {
    int n = 4;
    int source = 1;
    int destination = 3;
    int intermediate = 2;

    printf("Tower of Hanoi solution:\n");
    move(n, source, destination, intermediate);

    return 0;
}
