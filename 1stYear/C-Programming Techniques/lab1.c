#include <stdio.h>
struct points
{
    int x;
    int y;
};
typedef struct points poin_T;

struct triang
{
    poin_T A;
    poin_T B;
    poin_T C;
};
typedef struct triang triang_T;

struct circl
{
    poin_T A;
    float radius;
};
typedef struct circl circ_T;

struct sque
{
    poin_T A;
    poin_T B;
    poin_T C;
    poin_T D;
};
typedef struct sque sq_T;

union types
{
    triang_T triangle;
    circ_T circle;
    poin_T point;
    sq_T squere;
};
typedef union types types_T;

struct shape
{
    int kind;
    types_T type;
};
typedef struct shape shape_T;

int main()
{
    shape_T things[100];

    things[0].kind = 1;
    things[1].kind = 2;
    things[2].kind = 3;
    things[3].kind = 4;

    things[0].type.triangle.A.x = 3;
    things[0].type.triangle.A.y = 1;
    things[0].type.triangle.B.x = 2;
    things[0].type.triangle.B.y = 3;
    things[0].type.triangle.C.x = 5;
    things[0].type.triangle.C.y = 6;

    things[1].type.circle.A.x = 3;
    things[1].type.circle.A.y = 1;
    things[1].type.circle.radius = 5;

    things[2].type.point.x = 3;
    things[2].type.point.y = 1;

    things[3].type.squere.A.x = 3;
    things[3].type.squere.A.y = 1;
    things[3].type.squere.B.x = 2;
    things[3].type.squere.B.y = 3;
    things[3].type.squere.C.x = 5;
    things[3].type.squere.C.y = 6;
    things[3].type.squere.D.x = 5;
    things[3].type.squere.D.y = 6;

    printf("%lu %lu %lu %lu %lu %lu", sizeof(things[0]), sizeof(things[1]), sizeof(things[2]), sizeof(things[3].type.squere), sizeof(things[0].type.triangle), sizeof(things[1].type.circle));

    return 0;
}