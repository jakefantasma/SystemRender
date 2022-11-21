#pragma once
#include "../../headers.hpp"
namespace ContextoNave
{
    class Nave : public Entity
    {
    private:
        float live = 100;
        float paso = 0.1f;

    public:
        Nave(float x_, float y_) : Entity(x_, y_){};
        void def()
        {
            AddLine(0.00f, 0.00f);
            AddLine(0.02f, 0.04f);
            AddLine(0.04f, 0.00f);
            AddLine(0.02f, 0.015F);
            AddLine(0.00f, 0.00F);
            // setType("nave");
        }
        void key(unsigned char key, int x, int y)
        {
            if (key == 119)
            {
                moveY(paso);
            }
            else if (key == 115)
            {
                moveY(-paso);
            }
            else if (key == 97)
            {
                moveX(-paso);
            }
            else if (key == 100)
            {
                moveX(paso);
            }
            else if (key == 112) // disparo
            {
                addEntity(ContextoDisparo::getDisparo(getX(), getY()));
                // moveX(paso);
            }
            else if (key == 111) // disparo
            {
                // addEntity(ContextoMisil::getMisil(getX(), getY()));
                //  moveX(paso);
            }
        }
        void update()
        {
            // live -= 0.05f;
            //      destructor();
            //
        }
        ~Nave();
    };

    Nave *getNavePlayer(float x, float y)
    {
        Nave *p1 = new Nave(x, y);
        p1->def();
        return p1;
    };

} // namespace ContextoNave
