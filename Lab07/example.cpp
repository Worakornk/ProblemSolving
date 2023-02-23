#include "probelib.h"
#include <cstdio>

int n;

main()
{
    int n = probe_init();
    // binary search
    int l = 0, r = n-1;
    while(l < r) {
        int m = (l+r)/2;
        if(probe_check(l,m)) {
            r = m;
        } else {
            l = m+1;
        }
    }
    probe_answer(l);
}
