#ifndef ROOM_H
#define ROOM_H


class Room
{
private:
    bool left;
    bool middle;
    bool right;

public:
    Room();
    bool getLeft() const;
    void setLeft(bool value);
    bool getMiddle() const;
    void setMiddle(bool value);
    bool getRight() const;
    void setRight(bool value);

    int advanceEventTrigger();
    int stayEventTrigger();

    void treasureEvent();
    void deadEndEvent();
};

#endif // ROOM_H
