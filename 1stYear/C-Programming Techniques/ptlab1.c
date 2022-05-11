#include <stdio.h>
#define N 5
#include <math.h>
struct gshape
{
    int type;
    int ID;
    union
    {
        struct
        {
            float radius;
            float x, y;
        } circle;
        struct
        {
            float x1, y1, x2, y2, x3, y3;
        } triangle;
        struct
        {
            float x1, y1;
            float x2, y2;
            float x3, y3;
            float x4, y4;
        } rectangle;
    } gshapes;
    float (*area)(struct gshape *gs);
    void (*read_shape)(struct gshape *gs);
};

void read_circle(struct gshape *gs)
{
    printf(" radius ");
    scanf("%f", &(gs->gshapes.circle.radius));
    printf("X center ");
    scanf("%f", &(gs->gshapes.circle.x));
    printf("Y center ");
    scanf("%f", &(gs->gshapes.circle.y));
}

float circarea(struct gshape *circ)
{
    return (3.14 * circ->gshapes.circle.radius * circ->gshapes.circle.radius);
}

void read_triangle(struct gshape *gs)
{
    printf(" Reading triangle :\n");
    printf(" 1st vertice x coord ");
    scanf("%f", &(gs->gshapes.triangle.x1));
    printf(" 1st vertice y coord ");
    scanf("%f", &(gs->gshapes.triangle.y1));
    printf(" 2nd vertice x coord ");
    scanf("%f", &(gs->gshapes.triangle.x2));
    printf(" 2nd vertice y coord ");
    scanf("%f", &(gs->gshapes.triangle.y2));
    printf(" 3rd vertice x coord ");
    scanf("%f", &(gs->gshapes.triangle.x3));
    printf(" 3rd vertice y coord ");
    scanf("%f", &(gs->gshapes.triangle.y3));
}

float triarea(struct gshape tria)
{
    float l12, l23, l31;
    l12 = sqrt((tria.gshapes.triangle.x2 - tria.gshapes.triangle.x1) * (tria.gshapes.triangle.x2 - tria.gshapes.triangle.x1) + (tria.gshapes.triangle.y2 - tria.gshapes.triangle.y1) * (tria.gshapes.triangle.y2 - tria.gshapes.triangle.y1));
    l23 = sqrt((tria.gshapes.triangle.x3 - tria.gshapes.triangle.x2) * (tria.gshapes.triangle.x3 - tria.gshapes.triangle.x2) + (tria.gshapes.triangle.y3 - tria.gshapes.triangle.y2) * (tria.gshapes.triangle.y3 - tria.gshapes.triangle.y2));
    l31 = sqrt((tria.gshapes.triangle.x1 - tria.gshapes.triangle.x3) * (tria.gshapes.triangle.x1 - tria.gshapes.triangle.x3) + (tria.gshapes.triangle.y1 - tria.gshapes.triangle.y3) * (tria.gshapes.triangle.y1 - tria.gshapes.triangle.y3));
    float sur = (l12 + l23 + l31) / 2;
    float res = sqrtf(sur * (sur - l12) * (sur - l23) * (sur - l31));
    return res;
}

void read_rectangle(struct gshape *gs)
{
    printf(" Reading rectangle :\n");
    printf(" 1st vertice x coord ");
    scanf("%f", &(gs->gshapes.rectangle.x1));
    printf(" 1st vertice y coord ");
    scanf("%f", &(gs->gshapes.rectangle.y1));
    printf(" 2nd vertice x coord ");
    scanf("%f", &(gs->gshapes.rectangle.x2));
    printf(" 2nd vertice y coord ");
    scanf("%f", &(gs->gshapes.rectangle.y2));
    printf(" 3rd vertice x coord ");
    scanf("%f", &(gs->gshapes.rectangle.x3));
    printf(" 3rd vertice y coord ");
    scanf("%f", &(gs->gshapes.rectangle.y3));
    printf(" 4th vertice x coord ");
    scanf("%f", &(gs->gshapes.rectangle.x4));
    printf(" 4th vertice y coord ");
    scanf("%f", &(gs->gshapes.rectangle.y4));
}

float recarea(struct gshape *rec)
{
    float l = sqrtf((rec->gshapes.rectangle.y2 - rec->gshapes.rectangle.y1) * (rec->gshapes.rectangle.y2 - rec->gshapes.rectangle.y1) + (rec->gshapes.rectangle.x2 - rec->gshapes.rectangle.x1) * (rec->gshapes.rectangle.x2 - rec->gshapes.rectangle.x1));
    float w = sqrtf((rec->gshapes.rectangle.y4 - rec->gshapes.rectangle.y1) * (rec->gshapes.rectangle.y4 - rec->gshapes.rectangle.y1) + (rec->gshapes.rectangle.x4 - rec->gshapes.rectangle.x1) * (rec->gshapes.rectangle.x4 - rec->gshapes.rectangle.x1));

    return l * w;
}

int main(void)
{
    int i;
    struct gshape gs[N];
    printf(" Initializing the geometric shapes collection :\n ");
    for (i = 0; i < N; i++)
    {
        do
        {
            printf(" Shape ID %d : ", i);
            printf("What type of shape is it ? (0 = circle , 1 = triangle , 2 = rectangle ) ");
            scanf("%d", &(gs[i].type));
            gs[i].ID = i;
            switch (gs[i].type)
            {
            case 0:
                gs[i].read_shape = &read_circle;
                gs[i].read_shape(&gs[i]);
                printf("%f %f %f\n", gs[i].gshapes.circle.radius, gs[i].gshapes.circle.x, gs[i].gshapes.circle.y);
                break;
            case 1:
                gs[i].read_shape = &read_triangle;
                gs[i].read_shape(&gs[i]);
                printf("%f %f %f %f %f %f\n", gs[i].gshapes.triangle.x1, gs[i].gshapes.triangle.y1, gs[i].gshapes.triangle.x2, gs[i].gshapes.triangle.y2, gs[i].gshapes.triangle.x3, gs[i].gshapes.triangle.y3);
                break;

            case 2:
                gs[i].read_shape = &read_rectangle;
                gs[i].read_shape(&gs[i]);
                printf("%f %f %f %f %f %f %f %f\n", gs[i].gshapes.rectangle.x1, gs[i].gshapes.rectangle.y1, gs[i].gshapes.rectangle.x2, gs[i].gshapes.rectangle.y2, gs[i].gshapes.rectangle.x3, gs[i].gshapes.rectangle.y3, gs[i].gshapes.rectangle.x4, gs[i].gshapes.rectangle.y4);
                break;
            default:
                printf(" Yikes !\n ");
            }
        } while ((gs[i].type != 0) && (gs[i].type != 1) && (gs[i].type != 2));
    }

    printf(" Printing all the circles from our collection :\n ");
    for (i = 0; i < N; i++)
        if (gs[i].type == 2)
        {
            gs[i].area = &recarea;
            printf("Area of the %d rectangle is %f \n", i, gs[i].area(&gs[i]));
        }
    return 0;
}