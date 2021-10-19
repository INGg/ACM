#include <algorithm>
#include <cstdio>
#include <cmath>

const int MAX_TASKS = 1000;
const int MAX_PILOTS = 100;

struct Task
{
    int start;
    int end;
    int points;
    int task;
};

static Task tasks[MAX_TASKS+1];
static int ntasks;
static int npilots;
static double expected[MAX_PILOTS][MAX_TASKS+1];
static int prev[MAX_TASKS+1];
static double memo[MAX_TASKS+1];
static double predscores[MAX_PILOTS];
static int rank[MAX_PILOTS];

int main()
{
    scanf("%d %d", &ntasks, &npilots);

    // it's convenient for the DP to start numbering tasks at 1 
    // rather than 0
    //
    for (int i = 1; i <= ntasks; i++) {
        scanf("%d %d %d", &tasks[i].start, &tasks[i].end, &tasks[i].points);
        tasks[i].task = i;
    }

    for (int i = 0; i < npilots; i++) {
        for (int j = 1; j <= ntasks; j++) {
            scanf("%lf", &expected[i][j]);
            // expected score is prob * total points
            expected[i][j] *= tasks[j].points;
        }
    } 

    std::sort(&tasks[1], &tasks[ntasks+1], [](const Task &l, const Task &r) {
        return l.end < r.end;
    });

    // prev[i] is the maximum index of any task before i that does not
    // overlap i
    //
    for (int i = 1; i <= ntasks; i++) {
        prev[i] = 0;
        for (int j = i-1; j > 0; j--) {
            if (tasks[j].end <= tasks[i].start) {
                prev[i] = j;
                break;
            }
        }
    }    

    for (int i = 0; i < npilots; i++) {
        memo[0] = 0.0;
        for (int j = 1; j <= ntasks; j++) {
            double with = expected[i][tasks[j].task] + memo[prev[j]];
            double without = memo[j-1];

            memo[j] = std::max(with, without);
        }

        predscores[i] = memo[ntasks];
        rank[i] = i;
    }
    
    std::sort(&rank[0], &rank[npilots], [&](int left, int right) {
        return predscores[left] > predscores[right];
    });

    for (int i = 0; i < std::min(npilots, 3); i++) {
        printf("%d %.2f\n", rank[i] + 1, predscores[rank[i]]);
    }
}
