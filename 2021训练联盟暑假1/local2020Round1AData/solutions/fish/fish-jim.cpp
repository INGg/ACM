#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using std::vector;

#define MAXFISH 100

struct point {
    int x, y;
};

struct sweepevent {
    double angle;
    bool enter;
};

static point fish[MAXFISH];

int main()
{
    int radius;
    int nfish;
    scanf("%d %d", &radius, &nfish);

    for (int i = 0; i < nfish; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        fish[i].x = x;
        fish[i].y = y;
    }

    int best = 1;

    for (int swpcen = 0; swpcen < nfish; swpcen++) {
        vector<sweepevent> events; 
        for (int i = 0; i < nfish; i++) {
            if (i == swpcen) {
                continue;
            }

            int dx = fish[i].x - fish[swpcen].x;
            int dy = fish[i].y - fish[swpcen].y;
            int dsquared = dx*dx + dy*dy;
            
            if (dsquared > 4 * radius * radius) {
                // to far away to be in this sweep
                continue;
            }

            double cosa = sqrt(dsquared) / (2.0 * radius);
            double tria = acos(cosa);
            double cena = atan2(dy, dx);

            events.push_back(sweepevent{cena - tria, true});
            events.push_back(sweepevent{cena + tria, false});
        }        
       
        std::sort(events.begin(), events.end(), [](const sweepevent &left, const sweepevent &right) {
            if (fabs(left.angle - right.angle) < 1e-6) {
                return left.enter > right.enter;
            }

            if (left.angle < right.angle) {
                return true;
            }
            return false;
        });

        int incir = 1;
        for (const sweepevent &ev : events) {
            if (ev.enter) {
                incir++;
                best = std::max(best, incir);
            } else {
                incir--;
            }
        }
    }
    
    printf("%d\n", best);
}

