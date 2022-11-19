#pragma once
#include "../../headers.hpp"
namespace ContextoBox
{

    class Box : public Entity
    {
    private:
        float live = 100;

    public:
        Box(float x_, float y_) : Entity(x_, y_){};
        void def()
        {
            // Nave *p1 = new Nave(0.00f, 0.00f);
            AddLine(0.00f, 0.00f);
            AddLine(0.04f, 0.00f);
            AddLine(0.04f, 0.04f);
            AddLine(0.00f, 0.04f);
            AddLine(0.00f, 0.00f);
        }
        ~Box();
    };
    Box *getBox(float x, float y)
    {
        Box *bx = new Box(x, y);
        bx->def();
        return bx;
    }

} // namespace ContextoNave
