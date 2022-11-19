#pragma once
#include "../../headers.hpp"
namespace ContextoMisil
{

    class Misil : public Entity
    {
    private:
        float live = 100;
        bool isUp = true;

    public:
        Misil(float x_, float y_) : Entity(x_, y_){};
        void def()
        {
            AddLine(0.02f, 0.01f);
            AddLine(0.02f, 0.04f);
            AddLine(0.014f, 0.036f);
            AddLine(0.022f, 0.028f);
            AddLine(0.016f, 0.028f);
            AddLine(0.026f, 0.036f);
            AddLine(0.02f, 0.04f);
        }
        void update()
        {
            if (isUp)
            {
                float step = 0.004f;
                moveY(step);
                if (getY() >= 1.0f)
                {
                    RemoveEntity(this);
                }
            }
        }
        ~Misil();
    };
    Misil *getMisil(float x, float y)
    {
        Misil *bx = new Misil(x, y);
        bx->def();
        return bx;
    }

} // namespace ContextoNave