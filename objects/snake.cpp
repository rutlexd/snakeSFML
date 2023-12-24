struct Position{
    int x = 50;
    int y = 200;
};

class Snake{

    private:
        int size = 1;
        Sprite head;

    public:

        

};


int size = 4;

Position Pos;

Position getSnakePos(int moveSide){
    if (moveSide == 0){
        Pos.x += 32;
    }
    else if (moveSide == 1){
        Pos.x -= 32;
    }
    else if (moveSide == 2){
        Pos.y -= 32;
    }
    else if (moveSide == 3){
        Pos.y += 32;
    }

    return Pos;

}