#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<math.h>
#define int GLint
#define PI 3.1416
using namespace std;
bool f=1;
float pos1=0,pos2=400,speed1=2.9f, speed2=2.5f, spin=0.0f,sp1=2.0f;
//House Structure(Neshat,Afrin Saidatun,ID-21-44384-1)
void house(){
    //House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);
	glEnd();
    //House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);
	glEnd();
    //House_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);
	glEnd();
    //House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);
	glEnd();
    //House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);
	glEnd();
    //House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);
	glEnd();
    //House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    //House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);
	glEnd();
    //House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    //House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    //House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();

}
//House 2 structure
void house2(){
    //body
    glTranslatef(50,100,0);
    glColor3ub(64, 73, 237);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(100,0);
    glVertex2i(100,49);
    glVertex2i(0,49);
    glEnd();
    //roof
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2i(0,50);
    glVertex2i(105,50);
    glVertex2i(105,60);
    glVertex2i(0,67);
    glEnd();
    //window1
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(15,7);
    glVertex2i(35,7);
    glVertex2i(35,25);
    glVertex2i(15,25);
    glEnd();
    //window2
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(78,7);
    glVertex2i(95,7);
    glVertex2i(95,25);
    glVertex2i(78,25);
    glEnd();
    //door
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(42,0);
    glVertex2i(68,0);
    glVertex2i(68,33);
    glVertex2i(42,33);
    glEnd();
    //extra design
    glBegin(GL_POLYGON);
    glColor3ub(224, 169, 121);
    glVertex2i(-20,0);
    glVertex2i(0,0);
    glVertex2i(0,70);
    glVertex2i(-20,70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(47, 38, 224);
    glVertex2i(-20,70);
    glVertex2i(0,70);
    glVertex2i(-5,80);
    glVertex2i(-25,80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(224, 169, 121);
    glVertex2i(-25,10);
    glVertex2i(-20,0);
    glVertex2i(-20,70);
    glVertex2i(-25,80);
    glEnd();
}
   //road Model
void road(){
    //road
	glBegin(GL_POLYGON);
    if(f)glColor3f(0.38, 0.41, 0.36);
    else glColor3ub(0.38, 0.41, 0.36);
	glVertex2i(0, 180);
	glVertex2i(0, 220);
	glVertex2i(1000, 220);
	glVertex2i(1000, 180);
	glEnd();

    // road strip1
     glBegin(GL_POLYGON);
    if(f)glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    else glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	glVertex2i(20, 200);
	glVertex2i(20, 197);
	glVertex2i(110, 197);
	glVertex2i(110, 200);

	glEnd();

	//road strip2
	glBegin(GL_POLYGON);
    if(f)glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    else glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	glVertex2i(250, 200);
	glVertex2i(250, 197);
	glVertex2i(320, 197);
	glVertex2i(320, 200);
	glEnd();

	//road strip3
	glBegin(GL_POLYGON);
    if(f)glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    else glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	glVertex2i(460, 200);
	glVertex2i(460, 197);
	glVertex2i(530, 197);
	glVertex2i(530, 200);
	glEnd();

	//road strip4
	glBegin(GL_POLYGON);
    if(f)glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    else glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	glVertex2i(670, 200);
	glVertex2i(670, 197);
	glVertex2i(740, 197);
	glVertex2i(740, 200);
	glEnd();

	//road strip5
	glBegin(GL_POLYGON);
    if(f)glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    else glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	glVertex2i(880, 200);
	glVertex2i(880, 197);
	glVertex2i(950, 197);
	glVertex2i(950, 200);
	glEnd();

}
//Boat Structure
void boat1(){
    glTranslatef(50,100,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(60,0);
    glVertex2i(150,0);
    glVertex2i(200,40);
    glVertex2i(0,40);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(30,40);
    glVertex2i(65,40);
    glVertex2i(65,80);

    glVertex2i(67,40);
    glVertex2i(102,40);
    glVertex2i(67,75);
    glEnd();

}
//Right Side-House
void rightHouse(){
    glPushMatrix();
    glTranslatef(400,150,0);
    house();
    glPopMatrix();
}
//Left Side house
void leftHouse(){
    glPushMatrix();
    glTranslatef(420,120,0);
    house2();
    glPopMatrix();
}
//Boat1
void boatA(){
    glPushMatrix();
    glTranslatef(pos1,-15,0);
    boat1();
    glPopMatrix();
}

//Boat2
void boatB(){
    glPushMatrix();
    glTranslatef(pos2,-70,0);
    boat1();
    glPopMatrix();
}
//Water
void water(){
    if(f)glColor3ub(107, 117, 255);
    else glColor3ub(0, 10, 143);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(1000,0);
    glVertex2i(1000,220);
    glVertex2i(0,220);
    glEnd();
    glPopMatrix();

}
//Main function called
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255.0,0.0,1.0);

	water();
    rightHouse();
    leftHouse();

    road();
    boatA();
    boatB();
	glFlush();
}
void init(void){
	glClearColor(0.65, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

void update(int value){
    ///spin+=0.1;
    ///Boat Control
    if(pos1>980)pos1=-100;
    if(pos2>980)pos2=-100;
    pos1+=speed1;
    pos2-=speed2;
    glutTimerFunc(100, update, 0);
    glutPostRedisplay();
}
void handleKeypress(unsigned char key, int x, int y){
	switch (key){
        case 'd':
            f=1;
            break;
        case 'n':
            f=0;
            break;
        glutPostRedisplay();
	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1900, 1900);
	glutCreateWindow("CG Project- Marine Drive");
	init();
	glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(1000, update, 0);
    glutMainLoop();
	//
}

