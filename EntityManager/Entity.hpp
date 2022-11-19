#include "..\headers.hpp"
class Potition
{
private:
    float _x, _y;

public:
    Potition(float x_ = 0.0f, float y_ = 0.0f)
    {
        _x = x_;
        _y = y_;
    };
    void moveX(float step)
    {
        _x = _x + step;
    };
    void moveY(float step)
    {
        _y = _y + step;
    };
    float getX() { return _x; }
    float getY() { return _y; }
    ~Potition();
};
struct Lines
{
    float _x;
    float _y;
};

// estructura principal para los elementos dentro de la view
class Entity : public Potition
{
private:
    std::vector<Lines> LinesList;

public:
    int getId()
    {
        return reinterpret_cast<std::uintptr_t>(this);
    }
    Entity(float x_ = 0.0f, float y_ = 0.0f) : Potition(x_, y_){};
    ~Entity();
    std::vector<Lines> getListLines()
    {
        return LinesList;
    }
    Lines getLine(int potition)
    {
        return LinesList[potition];
    }
    void update()
    {
    }
    void key(unsigned char key, int x, int y)
    {
    }

    void AddLine(float x, float y)
    {
        Lines l;
        l._x = x;
        l._y = y;
        LinesList.push_back(l);
    }
};
