#pragma once
#include "..\headers.hpp"
#include "Entity.hpp"
template <typename Type>
void DrawEntity(Type *e)
{
    int x = e->getX();
    int y = e->getY();
    glPushMatrix();
    glTranslatef(e->getX(), e->getY(), 0);
    glPointSize(2);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < e->getListLines().size(); i++)
    {
        Lines lin = e->getLine(i);
        glVertex2f(lin._x, lin._y);
    };
    glEnd();
    glPopMatrix();
}
// dividir codigo
bool update = false;
void dev()
{
    std::string mensaje = "aplicando render";
    Console->gotoxy(10, 20);
    if (update)
    {
        Console->warning(mensaje);
    }
    else
    {
        Console->error(mensaje);
    }
    update = !update;
}
void renderScene()
{
    // glVertex2f
    if (false)
    {
        dev();
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 0.0f);
    DrawEntities();
    UpdatesEntities();
    glFlush();
    Sleep(1);
}
void changeSize(int w, int h)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void customkey(unsigned char key, int x, int y); // reserva de memoria de la funcion
void RunGame(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(850, 250);
    glutCreateWindow("By jake");
    glutReshapeFunc(changeSize);
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(customkey);
    glutMainLoop();
}
