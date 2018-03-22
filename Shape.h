#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;

char panel[500][500];

class Shape{
protected:
    string name;
public:
    string get_name(){
        return name;
    }
    virtual void translate(int x, int y) = 0;
    virtual void scaleup(int s) = 0;
    virtual float area() = 0;
    virtual void draw() = 0;
    virtual void print() = 0;
};

class Rectangle : public Shape {
protected:
    int width, height,x,y;
public:
    Rectangle(const string &_name,int w,int h,int _x,int _y){
        width = w;
        height = h;
        x = _x;
        y = _y;
        name = _name;
    }
    float area(){
        return width*height;
    }
    void translate(int s1, int s2){
        x = x + s1;
        y = y + s2;
    }
    void scaleup(int _s){
        width = width * _s;
        height = height * _s;
    }

    void draw(){
        int tmp_x = 0,tmp_y = 0;
        int count2 = 0, count1 = 0;
        while(1){

            if(tmp_x == x && tmp_y == y){
                for(int i = tmp_x;count1 != height+1; i++){
                    for(int j = tmp_y; count2 != width+1; j++){
                        if(i == tmp_x || j == tmp_y || i == tmp_x+height || j == tmp_y + width){
                            panel[i][j] = '.';
                        }
                        count2++;
                    }
                    count2 = 0;
                    count1++;
                }
                break;
            }
            if(tmp_x != x)	tmp_x++;
            if(tmp_y != y)	tmp_y++;
        }
    }
    void print(){
        cout<<"width: "<<width<<" height: "<<height<<" x: "<<x<<" y: "<<y<<endl;
    }

};
class Rhombus: public Shape {
protected:
    int s,x,y;
public:
    Rhombus(const string &_name,int _s,int _x,int _y){
        s = _s;
        x = _x;
        y = _y;
        name = _name;
    }
    float area(){
        return 2*s;
    }
    void translate(int s1, int s2){
        x = x + s1;
        y = y + s2;
    }
    void scaleup(int _s){
        s = s * _s;
    }
    void draw(){
        int tmp_x = 0,tmp_y = 0;
        int count2 = 0, count1 = 0,count = 0;
        tmp_x = x - s;
        tmp_y = y - s;
        for(int i = tmp_x; i < tmp_x+s;i++){
            panel[i][tmp_y + s -1 + count] = '.';
            panel[i][tmp_y + s -1 - count] = '.';
            count++;
        }
        count = 1;
        for(int i = tmp_x+s; i < tmp_x+(2*s)-1;i++){
            panel[i][tmp_y+count] = '.';
            panel[i][tmp_y+ (s*2) - 2 -count] = '.';
            count++;
        }
    }

    void print(){
        cout<<"s: "<<s<<" x: "<<x<<" y: "<<y<<endl;
    }
};
class Circle : public Shape {
protected:
    int center_x, center_y, radius;
public:
    Circle(const string &_name,int x,int y,int r){
        center_x = x;
        center_y = y;
        radius = r;
        name = _name;
    }

    float area(){
        return 3.14*pow (radius, 2.0);
    }
    void translate(int s1, int s2){
        center_x = center_x + s1;
        center_y = center_y + s2;
    }
    void scaleup(int _s){
        radius = radius * _s;
    }
    void draw(){
        int x,y;
        for (double i = 0.0; i < 6.3 ; i+=0.1) {
            x = 0.5 * radius * sin(i) + radius + 1;
            y = radius * cos(i) + radius + 1;
            cout<< x << ":" << y <<endl;
            panel[y][x] = '.';
        }
    }
    void print(){
        cout<<"radius: "<<radius<<" x: "<<center_x<<" y: "<<center_y<<endl;
    }
};