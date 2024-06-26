#include <stdio.h>
#include <time.h>

int main() 
{


    struct timespec start, end;
    long long diff_ns;

    clock_gettime(3, &start);
    // Perform some task or delay to observe the time difference
    // For example, a small delay to observe nanosecond difference
    for (int i = 0; i < 1000; i++) {
        // Some minimal computation or delay
    }
    clock_gettime(3, &end);

    // Calculate the time difference in nanoseconds
    diff_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);

    printf("Time Difference: %lld nanoseconds\n", diff_ns);

    return 0;
}
