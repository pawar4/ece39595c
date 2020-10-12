#ifndef DISPLAYABLE_H_
#define DISPLAYABLE_H_
#include <iostream>
#include <string>

class Displayable {
public:
    Displayable(int maxHit, int hpMoves, int Hp, char type, 
                int v, int PosX, int PosY, int Width, int Height);
    Displayable();
   virtual void setInvisible();
   virtual void setVisible();
   virtual void setMaxHit(int maxHit);
   virtual void setHpMove(int hpMoves);
   virtual void setHp(int Hp);
   virtual void setType(char t);
   virtual void setIntValue(int v);
   virtual void setPosX(int x);
   virtual void setPosY(int y);
   virtual void setWidth(int x);
   virtual void setHeight(int y);
private:
    int maxHit;
    int hpMoves;
    int Hp;
    char type;
    int v;
    int PosX, PosY;
    int Width, Height;
};

#endif /* DISPLAYABLE_H_*/
