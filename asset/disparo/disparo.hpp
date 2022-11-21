#pragma once
#include "../../headers.hpp"
namespace ContextoDisparo
{

    class Disparo : public Entity
    {
    private:
        bool isUp = true;
        float step = 0.004f;
        float limit = 0.50f;

    public:
        Disparo(float x_, float y_) : Entity(x_, y_){};
        void def()
        {
            setNameClass("ContextoDisparo::Disparo*");
            AddLine(0.02f, 0.04f);
            AddLine(0.02f, 0.01f);
        }
        void update()
        {
            if (getY() >= limit)
            {
                Console->gotoxy(20, 20);
                Console->log(getY());
                destructor();
            }
            else
            {
                moveY(step);
            }
        }
        ~Disparo();
    };
    Disparo *getDisparo(float x, float y)
    {
        Disparo *bx = new Disparo(x, y);
        bx->def();
        return bx;
    }
} // namespace ContextoNave