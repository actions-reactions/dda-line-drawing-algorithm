#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

int x1, y1, x2, y2, dx, dy, x, y;
float m;

void display(void) {
    /* clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 0, 0);

    /* draw white polygon (rectangle) with corners at
     * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
     */

    int i = 1;


    glColor3ub(255, 0, 0);


    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();

    if (m <= 1) {


        while (i <= dx) {

            x = x + 1;
            y = y + m;


            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
            i++;


        }
    } else {

        while (i <= dy) {


            x = x + 1 / m;
            y = y + 1;

            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();

            i++;




        }
    }


    /* don't wait!
     * start processing buffered OpenGL routines
     */
    glFlush();
}

void init(void) {
    /* select clearing (background) color */
    glClearColor(0, 0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
}

/*
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA). Open window with "hello"
 * in its title bar. Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int main(int argc, char** argv) {

    printf("x1: ");
    scanf("%d", &x1);
    printf("y1: ");
    scanf("%d", &y1);
    printf("x2: ");
    scanf("%d", &x2);
    printf("y2: ");
    scanf("%d", &y2);

    x = x1;
    y = y1;

    dx = x2 - x1;
    dy = y2 - y1;

    m = (float) dy / (float) dx;
    printf("%d %d\n", x1, y1);
    printf("%d %d\n", x2, y2);
    printf("%d %d %f\n", dx, dy, m);


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
