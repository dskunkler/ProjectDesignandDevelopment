#ifndef EX01_ROBOT_CLASSES_H_
#define EX01_ROBOT_CLASSES_H_



class Robot {
  public:
    Robot(int x=0, int y=0, float theta=0);
    void MoveForward( int distance );
    void Display();
    void set_position(int x, int y);
    int* get_position();
    void set_direction_angle_rad(float d);
    float get_direction_angle_rad();
    //struct Position;
    struct Position{
      int x_;
      int y_;
      Position(int x = 0, int y = 0): x_(x), y_(y){}
    }pos;
  private:
    float direction_angle_;
    int position_[2];
    

  };

#endif /* EX01_ROBOT_CLASSES_H_ */
