#include "Hungarian.h"

int main()
{
    Matrix src{
        { 50, INF, INF, 10, INF, 20, INF },
        { INF, 30, 45, INF, 30, INF, 25 },
        { INF, 5, INF, INF, 10, 15, INF },
        { 15, INF, INF, 20, INF, INF, INF },
        { INF, INF, 20, INF, INF, 5, INF },
        { INF, INF, INF, INF, 40, INF, 5 },
        { INF, INF, INF, 15, INF, INF, INF },
    };
    
    Hungarian hungarian = Hungarian(src);
    hungarian.Algorithm();

    return 0;
}
