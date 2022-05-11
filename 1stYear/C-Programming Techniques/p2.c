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
            float x4, y4;
        } rectangle;
    } gshapes;
    void (*area)(struct gshape *gs);
    void (*read_shape)(struct gshape *gs);
};

float triarea(struct gshape tria)
{
    float l12, l23, l31;
    l12 = sqrt((tria.gshapes.triangle.x2 - tria.gshapes.triangle.x1) * (tria.gshapes.triangle.x2 - tria.gshapes.triangle.x1) + (tria.gshapes.triangle.y2 - tria.gshapes.triangle.y1) * (tria.gshapes.triangle.y2 - tria.gshapes.triangle.y1));
    l23 = sqrt((tria.gshapes.triangle.x3 - tria.gshapes.triangle.x2) * (tria.gshapes.triangle.x3 - tria.gshapes.triangle.x2) + (tria.gshapes.triangle.y3 - tria.gshapes.triangle.y2) * (tria.gshapes.triangle.y3 - tria.gshapes.triangle.y2));
    l31 = sqrt((tria.gshapes.triangle.x1 - tria.gshapes.triangle.x3) * (tria.gshapes.triangle.x1 - tria.gshapes.triangle.x3) + (tria.gshapes.triangle.y1 - tria.gshapes.triangle.y3) * (tria.gshapes.triangle.y1 - tria.gshapes.triangle.y3));
}

void read_circle(struct gshape *gs)
{
    printf(" radiu s ? ");
    scanf("%f ", &(gs->gshapes.circle.radius));
    printf("X center ? ");
    scanf("%f ", &(gs->gshapes.circle.x));
    printf("Y center ? ");
    scanf("%f ", &(gs->gshapes.circle.y));
}
/*void write_circle(struct gshape *gs)
{
    printf("Printing circle ID=%d:\n ", gs->ID);
}*/
void read_triangle(struct gshape *gs)
{
    printf(" Reading triangle :\n ");
}
/*void write_triangle(struct gshape *gs)
{
    printf("Triangle (% f ,% f ) (% f ,% f ) , (% f ,% f )\n ", gs->gshape.triangle.x1, gs->gshape.triangle.y1, gs->gshape.triangle.x2,
           gs->gshape.triangle.y2, gs->gshape.triangle.x3,
           gs->gshape.triangle.y3);
}*/
void read_rectangle(struct gshape *gs)
{
    printf(" Reading rectangle :\n ");
}
/*void write_rectangle(struct gshape *gs)
{
    printf(" Printing rectangle :\n ");
}*/
int main(void)
{
    int i, type;
    struct gshape gs[N];
    printf(" I n i t i a l i z i n g the geome t ric shapes c o l l e c t i o n :\n ");
    for (i = 0; i < N; i++)
    {
        do
        {
            printf(" Shape ID %d : ", i);
            printf("What type o f shape i s i t ? (0= c i r c l e , 1= t ri a n gl e , 2= r e c t a n gl e ) ");
            scanf("%d ", &type);
            gs[i].type = type;
            gs[i].ID = i;
            switch (gs[i].type)
            {
            case 0:
                gs[i].read_shape(&gs[i]);
                gs[i].read_shape = &read_circle;
                //gs[i].write_gshape(&gs[i]);
                //gs[i].write_gshape = &write_circle;
                break;
            case 1:
                gs[i].read_shape(&gs[i]);
                gs[i].read_shape = &read_triangle;
                //gs[i].write_gshape(&gs[i]);
                //gs[i].write_gshape = &write_triangle;

                break;

            case 2:
                gs[i].read_shape(&gs[i]);
                gs[i].read_shape = &read_rectangle;
                //gs[i].write_gshape(&gs[i]);
                //gs[i].write_gshape = &write_rectangle;
                break;
            default:
                printf(" Yikes !\n ");
            }
        } while ((gs[i].type != 0) && (gs[i].type != 1) && (gs[i].type != 2));
    }

    printf(" Printing all the c i r c l e s from our c o l l e c t i o n :\n ");
    for (i = 0; i < N; i++)
        if (gs[i].type == 0)
            //gs[i].write_gshape(&gs[i]);
            return 1;
}
