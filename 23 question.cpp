#include <stdio.h>
#include <stdlib.h>

#define DIRECTION_UP 0
#define DIRECTION_DOWN 1

void SCAN(int *requests, int n, int start, int direction, int size) {
    int total_head_movement = 0;
    int current_track = start;
    int visited[size];

    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }

    while (1) {
        if (direction == DIRECTION_UP) {
            for (int i = current_track; i < size; i++) {
                if (visited[i] == 0 && requests[i] != -1) {
                    printf("%d -> ", requests[i]);
                    total_head_movement += abs(current_track - i);
                    current_track = i;
                    visited[i] = 1;
                }
            }
            direction = DIRECTION_DOWN;
        } else if (direction == DIRECTION_DOWN) {
            for (int i = current_track; i >= 0; i--) {
                if (visited[i] == 0 && requests[i] != -1) {
                    printf("%d -> ", requests[i]);
                    total_head_movement += abs(current_track - i);
                    current_track = i;
                    visited[i] = 1;
                }
            }
            direction = DIRECTION_UP;
        }

        int all_visited = 1;
        for (int i = 0; i < size; i++) {
            if (visited[i] == 0) {
                all_visited = 0;
                break;
            }
        }

        if (all_visited) {
            break;
        }
    }

    printf("\nTotal head movement: %d\n", total_head_movement);
}

int main() {
    int n, start, size;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the size of the disk: ");
    scanf("%d", &size);

    int requests[size];
    for (int i = 0; i < size; i++) {
        requests[i] = -1;
    }

    printf("Enter the requests (tracks): ");
    for (int i = 0; i < n; i++) {
        int track;
        scanf("%d", &track);
        requests[track] = track;
    }

    printf("Enter the starting position of the disk arm: ");
    scanf("%d", &start);

    printf("\nSCAN algorithm output:\n");
    SCAN(requests, n, start, DIRECTION_UP, size);

    return 0;
}

