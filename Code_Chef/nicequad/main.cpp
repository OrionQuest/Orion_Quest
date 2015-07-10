#include <cmath>
#include <iostream>
#include <vector>

class Point
{
  public:
    int x,y;

    Point(int x_input,int y_input)
        :x(x_input),y(y_input)
    {}
};

bool Integer_Area(const Point& p1,const Point& p2,const Point& p3)
{
    int twice_area=std::abs((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y));
    if(twice_area%2!=0) return false;
    return true;
}

bool Nice_Quad(const std::vector<Point>& points)
{
    bool is_integer_area1=Integer_Area(points[0],points[1],points[2]);
    bool is_integer_area2=Integer_Area(points[2],points[3],points[0]);

    if(!(is_integer_area1^is_integer_area2)) return true;
    return false;
}

int main()
{
    int tests;
    std::cin>>tests;
    for(int t=0;t<tests;++t){
        int num_points;
        std::cin>>num_points;
        std::vector<Point> group1,group2,group3,group4;
        for(int p=0;p<num_points;++p){
            int x,y;
            std::cin>>x>>y;
            if(x>0 && y>0) group1.push_back(Point(x,y));
            else if(x>0 && y<0) group2.push_back(Point(x,y));
            else if(x<0 && y<0) group3.push_back(Point(x,y));
            else if(x<0 && y>0) group4.push_back(Point(x,y));
        }

        if(group1.size()==0 || group2.size()==0 || group3.size()==0 || group4.size()==0){
            std::cout<<0<<std::endl;
            break;
        }

        //std::cout<<"Points:";
        //for(int p=0;p<points.size();++p) std::cout<<" ("<<points[p].first<<","<<points[p].second<<")";
        //std::cout<<std::endl;
    
        int value=0;
        for(int g1=0;g1<group1.size();++g1) for(int g2=0;g2<group2.size();++g2) for(int g3=0;g3<group3.size();++g3) for(int g4=0;g4<group4.size();++g4){
            std::vector<Point> points;
            points.push_back(group1[g1]);
            points.push_back(group2[g2]);
            points.push_back(group3[g3]);
            points.push_back(group4[g4]);

            if(Nice_Quad(points)) ++value;
        }

        std::cout<<value<<std::endl;
    }
    return 0;
}
