#include <GL/glut.h>
#include <iostream>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
float wid = 400;  
float height = wid; 
int numbers = 20; 
float t = wid/numbers; 

int x1 = -300,y1=-400,x2 =400,y2 = 100;
void draw_point(float x, float y,int k_kind,int d_kind);
float translater(int x);
void swap(int &a, int &b)
{ int tmp = 0;
 tmp = b;
 b = a;
 a = tmp; }
void bresenham(int x1, int y1,int x2, int y2){

 int k_kind = 0; 
 int d_kind =0;
 if (x1 > x2) {
 swap(x1,x2);
 swap(y1,y2);
 }
 int dx = abs(x2-x1), dy = abs(y2-y1);
 if (y1 > y2) {
 y1 = -y1;
 y2 = -y2;
 d_kind = 1;
 }
 if (dy > dx) {  
 swap(x1, y1);
 swap(x2,y2);
 swap(dx,dy);
 k_kind = 1;
 }
 float d = (dy +dy -dx)*t; 
 float x = x1+0.0,y = y1+0.0;
 draw_point(translater(x),translater(y),k_kind,d_kind); 
 while( x < x2){   
 if (d < 0){
  d += 2*dy*t;
 }
 else{
  d += 2*(dy-dx)*t;
  y += t; 
 }
 x= x + t;
 draw_point(translater(x),translater(y),k_kind,d_kind);  
 }
}
float translater(int x){
 
 return x/wid;
}
void draw_point(float x , float y, int k_kind,int d_kind){
 
 glPointSize(7);
 glColor3f(0.0,0.0,1.0);
 glBegin(GL_POINTS);
 cout <<"k:"<<k_kind<<"d:" << d_kind << endl;
 if(k_kind==0&&d_kind==1){
 y = -y;
 }else if (k_kind ==1 &&d_kind==1){
 x= -x;
 swap(x,y);
 }else if (k_kind==1&&d_kind ==0){
 swap(x,y);
 }
 glVertex3f(x,y,0.0);
 glEnd();
 glFlush();
}
void grid(){

 glClearColor(0, 0, 0, 0);
 glClear(GL_COLOR_BUFFER_BIT);
 
 int wid_number = numbers;
 int hei_number = numbers;
 float delta_wid = wid / wid_number;
 float delta_hei = height / hei_number;
 glColor3f(1.0,1.0,0);
 for (int i = 1; i < 40 ; i ++ ) {
 glBegin(GL_LINES);
 glVertex2f(-1+i*delta_hei/height, -1);
 glVertex2f(-1+i*delta_hei/height, 1);
 glVertex2f(-1,-1+i*delta_hei/height);
 glVertex2f(1,-1+i*delta_hei/height);
 glEnd();
 glFlush();
 }
 glColor3f(1.0,0,0);
 glBegin(GL_LINES); 
 glVertex2f(-1,0);
 glVertex2f(1,0);
 glVertex2f(0,-1);
 glVertex2f(0,1);
 glEnd();
 glFlush();
 glBegin(GL_LINES);
 glColor3f(1.0,0.0,0.0);
 glVertex2f(translater(x1),translater(y1));  
 glVertex2f(translater(x2),translater(y2));
 glEnd();
 glFlush();
 
 bresenham(x1, y1,x2,y2);
}
int main(int argc, char *argv[]) 
{
 
 glutInit(&argc, argv);
  
 glutInitWindowSize(700,700);
 glutInitWindowPosition(300,200);
 glutInitDisplayMode(GLUT_RGBA);
 glutCreateWindow("Mid Point Line");
 glutDisplayFunc(&grid);
 glutMainLoop();
 return 0;
}
