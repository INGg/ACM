#include <cstdio>
#include <set>

static unsigned vec[100000];
int main()
{
    unsigned n, s, e;
    unsigned long total = 0;
    std::set<unsigned> inrange;
    
    scanf("%u", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%u", &vec[i]);
    }

    for (s = 0, e = 0; e < n; ++e) {
        // find a the earliest s that doesn't contain e
        while (inrange.find(vec[e]) != inrange.end()) {
            inrange.erase(vec[s++]);
        }

        inrange.insert(vec[e]);
        total += (e - s) + 1;
    }

    printf("%lu\n", total);
}
