#include <cstdio>
#include <cmath>
using namespace std;

#define PI 3.14159265358;

struct star {
    double x;
    double y;
    double rank;
};

star A;
star B;

int T;
int n;
double a, b, r;


int main()
{
    scanf("%d", &T);
    while(T--)
    {
        A.rank = 4;
        A.rank = 4;
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            scanf("%lf%lf%lf", &a, &b, &r);
            if(A.rank > r)
            {
                B.x = A.x;
                B.y = A.y;
                B.rank = A.rank;
                A.x = a;
                A.y = b;
                A.rank = r;
            }
            else if(B.rank > r)
            {
                B.x = a;
                B.y = b;
                B.rank = r;
            }
        }
        double m, n, p, q;
        scanf("%lf%lf%lf%lf", &m, &n, &p, &q);
        double mut = (A.x - B.x)*(m - p) + (A.y - B.y)*(n - q);
        double ab = sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
        double mp = sqrt((m-p)*(m-p) + (n-q)*(n-q));
        double ans = acos(mut/(ab*mp));
        ans /= PI;
        ans *= 180.00;
        printf("%.3lf\n", ans);
    }
    return 0;
}