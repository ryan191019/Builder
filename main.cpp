#include <iostream>
#include <string>

using namespace std;


class House
{
public:
    void setWall(string wall)
    {
        this->wall = wall;
    }
    void setDoor(string door)
    {
        this->door = door;
    }
    void setWindow(string window)
    {
        this->window = window;
    }

    string getWall(void)
    {
        cout<<wall<<endl;
        return wall;
    }

    string getWindow(void)
    {
        cout<<window<<endl;
        return window;
    }

    string getDoor(void)
    {
        cout<<door<<endl;
        return door;
    }


private:
    string wall;
    string door;
    string window;
};


class Builder
{
public:
    virtual void makeWall() = 0;
    virtual void makeDoor() = 0;
    virtual void makeWindow() = 0;
    virtual House *getHouse() = 0;
};

class FlatBuilder : public Builder
{
public:

    FlatBuilder()
    {
        house = new House;
    }
    virtual void makeWall()
    {
        house->setWall("flat wall");
    }
    virtual void makeDoor()
    {
         house->setDoor("flat door");
    }
    virtual void makeWindow()
    {
        house->setWindow("flat window");
    }
    virtual House *getHouse()
    {
        return house;
    }

    ~FlatBuilder()
    {
        if(house)
            delete house;
    }

private:
    House *house;

};

class VillaBuilder : public Builder
{
public:

    VillaBuilder()
    {
        house = new House;
    }
    virtual void makeWall()
    {
        house->setWall("villa wall");
    }
    virtual void makeDoor()
    {
         house->setDoor("villa door");
    }
    virtual void makeWindow()
    {
        house->setWindow("villa window");
    }
    virtual House *getHouse()
    {
        return house;
    }

private:
    House *house;

};


class Direct
{
public:
    Direct(Builder *builder)
    {
        this->builder = builder;
    }

    void construct()
    {
        builder->makeWall();
        builder->makeDoor();
        builder->makeWindow();
    }

private:
    Builder *builder;
};

int main()
{

    House *house;
    Builder *builder;
    Direct *direct;

    //创建一个FlatBuilder
    builder = new FlatBuilder;
    direct = new Direct(builder);
    direct->construct();
    house = builder->getHouse();
    house->getDoor();
    house->getWall();
    house->getWindow();

    delete builder;
    delete direct;



    //创建一个VillaBuilder
    builder = new VillaBuilder;
    direct = new Direct(builder);
    direct->construct();
    house = builder->getHouse();
    house->getDoor();
    house->getWall();
    house->getWindow();

    delete builder;
    delete direct;


    //cout << "Hello world!" << endl;
    return 0;
}
