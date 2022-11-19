#pragma once
#include "../../headers.hpp"
namespace ContextoDisparo
{

    class Disparo : public Entity
    {
    private:
        float live = 100;
        bool isUp = true;
        float step = 0.004f;

    public:
        Disparo(float x_, float y_) : Entity(x_, y_){};
        void def()
        {
            AddLine(0.02f, 0.04f);
            AddLine(0.02f, 0.01f);
        }
        void update()
        {
            if (isUp)
            {
                moveY(step);
                if (getY() >= 1.0f)
                {
                    RemoveEntity(this);
                }
                if (getY() == 1.3f)
                {
                    step = -step;
                }
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