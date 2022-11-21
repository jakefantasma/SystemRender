#include "headers.hpp"
int main(int argc, char **argv)
{
    addEntity(getBox(0.1f, 0.00f));
    // addEntity(getBox(0.2f, 0.00f));
    // addEntity(getBox(0.3f, 0.00f));
    // addEntity(getBox(0.1f, 0.00f));
    addEntity(getNavePlayer(0.2f, 0.00f));
    RunGame(argc, argv);
}
/*
void draw()
    {
        glPushMatrix();
        glTranslatef(this->getX(), this->getY(), 0);
        glPointSize(2);
        glBegin(GL_LINE_STRIP);
        glVertex2f(0.00f, 0.00f);
        glVertex2f(0.02f, 0.04f);
        glVertex2f(0.04f, 0.00f);
        glVertex2f(0.02f, 0.015F);
        glVertex2f(0.00f, 0.00F);
        glEnd();
        glPopMatrix();
    };*/