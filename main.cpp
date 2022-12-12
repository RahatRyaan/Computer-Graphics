#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
#define int GLint
#define PI 3.1416
using namespace std;
bool f=1;
float pos1=0,pos2=400,speed1=2.9f, speed2=2.5f, speed3=1.95f, spin=0.0f,cpos1=200,cpos2=400,cpos3=-250,cpos4=50,cpos5=490,sp1=2.0f;
float sun_x=620 ,sun_y=310,sp_x=0.5f,sp_y=1.0f,plane_x=0.0f, plane_speed=4.5f;
///Circle (Abir, Faisal Amin, id - 20-43206-1)
void circle(GLfloat x, GLfloat y, GLfloat rad){
    GLint triangle_amt=60,i;
    GLfloat t_pi=2*PI;
    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(43,78,88);
    glVertex2i(x,y);
    for(i=0;i<=triangle_amt;i++){
        GLfloat dx=rad*cos(i*t_pi/triangle_amt), dy=rad*sin(i*t_pi/triangle_amt);
        ///cout<<"---"<<x<<" "<<y<<" "<<dx<<" "<<dy<<"---"<<endl;
        glVertex2i(x+dx,y+dy);
    }
    glEnd();
}
///Big hill- Structure
void hill_big(){
    glBegin(GL_POLYGON);
    //glColor3ub(96, 118, 130);
    glVertex2i(70,70);
    glVertex2i(200,225);
    glVertex2i(330,70);
    glEnd();
    ///snow
    glBegin(GL_POLYGON);
    if(f)glColor3f(255,255,255);
    else glColor3ub(172, 174, 176);
    glVertex2i(200,225);
    glVertex2i(230,190);
    glVertex2i(220,180);
    glVertex2i(200,190);
    glVertex2i(190,180);
    glVertex2i(170,190);
    glEnd();

}
///Small_hill- Structure
void hill_small(){
    ///Hill_Small
	glBegin(GL_POLYGON);
    ///glColor3f(0.11, 0.23, 0.36);
	glVertex2i(250, 100);
	glVertex2i(310, 175);
	glVertex2i(370, 100);
	glEnd();

    ///Hill_Small_Snow
	glBegin(GL_POLYGON);
    if(f)glColor3f(255,255,255);
    else glColor3ub(172, 174, 176);
    glVertex2i(290, 150);
	glVertex2i(310, 175);
	glVertex2i(330, 150);
	glVertex2i(325, 140);
	glVertex2i(310, 150);
	glVertex2i(300, 140);
	glEnd();
}
///Tilla Structure
void tillaModel1(){

	glBegin(GL_POLYGON);
	if(f)glColor3f(0.1, 1.293, 0.0);
	else glColor3ub(15, 59, 11);
	glVertex2i(125, 70);
	glVertex2i(150, 80);
	glVertex2i(160, 90);
	glVertex2i(170, 90);
	glVertex2i(180, 100);
	glVertex2i(190, 105);
	glVertex2i(200, 108);
	glVertex2i(300, 110);
	glVertex2i(300, 70);
	glEnd();
}
///Tilla Model 2- Structure
void tillaModel2(){
    if(f)glColor3f(0.1, 1.293, 0.0);
	else glColor3ub(15, 59, 11);
    glPushMatrix();
    circle(430,90,30);
    circle(420,87,30);
    circle(410,80,30);
    circle(400,80,30);
    circle(390,70,30);
    circle(445,80,30);
    circle(455,75,30);
    circle(465,70,30);
    circle(470,65,30);
    circle(480,60,30);
    circle(485,55,20);
    glPopMatrix();
}

void ground(){
	glBegin(GL_POLYGON);
    if(f)glColor3ub(34,139,34);
    else glColor3ub(0,100,0);
	glVertex2i(0, 220);
	glVertex2i(0, 270);
	glVertex2i(1000, 270);
	glVertex2i(1000, 220);

	glEnd();
}


///Windmill stand structure
void Windmill_Stand_Model(){
    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}
///Windmill blade  Structure
void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}



/// Windmill Structure
void Windmill(){
    ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    if(f)glColor3f(0.11, 0.23, 0.36);
    else glColor3ub(107, 130, 199);
    circle(380,250,10);

    ///Windmill_Rotary_Blades
    if(f)glColor3f(0.11, 0.23, 0.36);
    else glColor3ub(107, 130, 199);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();

}
///Object Creation

///`Right Side_ Big Hill 1
void rightBigHill1(){
    glPushMatrix();
    glTranslatef(600,150,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(0,0,0);
    hill_big();
    glPopMatrix();
}
///Right Side- Big Hill 2
void rightBigHill2(){
    glPushMatrix();
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(31, 40, 66);
    glTranslatef(550,130,0);
    hill_big();
    glPopMatrix();
}
///Left Side- Small Hill
void leftSmallHill(){
    glPushMatrix();
    glTranslatef(0,120,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(31, 40, 66);
    hill_small();
    glPopMatrix();
}


///Right Side- Tilla
void rightTillaL(){
    glPushMatrix();
    glTranslatef(400,150,0);
    tillaModel1();
    glPopMatrix();
}
///Left Side- Tilla
void leftTillaL(){
    glPushMatrix();
    glTranslatef(0,150,0);
    tillaModel1();
    glPopMatrix();
}
///Right Side- Tilla
void rightTillaR(){
    glPushMatrix();
    glTranslatef(500,150,0);
    tillaModel2();
    glPopMatrix();
}
///Right Side- Wind Mill
void rightWindmMill(){
    glPushMatrix();
    glTranslatef(530,150,0);
    Windmill();
    glPopMatrix();
}
///Left Side- Wind Mill
void leftWindMill(){
    glPushMatrix();
    glTranslatef(0,150,0);
    Windmill();
    glPopMatrix();
}
///Left Side- Big Hill
void leftHillBig(){
    glPushMatrix();
    glTranslatef(0,130,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(0,0,0);
    hill_big();
    glPopMatrix();
}
///Left Side Tilla
void leftTillaL1(){
    glPushMatrix();
    glTranslatef(-140,150,0);
    tillaModel1();
    glPopMatrix();
}
///Left Side Tilla
void leftTillaR(){
    glPushMatrix();
    glTranslatef(0,150,0);
    tillaModel2();
    glPopMatrix();
}

void windMill_start(){
    spin+=0.1;
    glutPostRedisplay();
}


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

///Star
void star(){
    if(!f){
        glPushMatrix();
        glColor3ub(255,255,255);
        glPointSize(4);
        glBegin(GL_POINTS);

        glVertex2i(100,400);
        glVertex2i(120,420);
        glVertex2i(150,450);
        glVertex2i(170,470);
        glVertex2i(200,430);
        glVertex2i(230,470);
        glVertex2i(350,460);
        glVertex2i(900,400);
        glVertex2i(580,470);
        glVertex2i(840,460);
        glVertex2i(750,400);
        glVertex2i(950,400);
        glVertex2i(760,420);
        glVertex2i(690,450);
        glVertex2i(550,470);
        glVertex2i(790,430);
        glVertex2i(830,470);
        glVertex2i(690,460);
        glVertex2i(590,400);
        glVertex2i(490,430);
        glVertex2i(330,470);
        glVertex2i(390,460);
        glVertex2i(460,400);
        glVertex2i(490,330);
        glVertex2i(330,370);
        glVertex2i(390,360);
        glVertex2i(460,300);
        glVertex2i(990,230);
        glVertex2i(930,370);
        glVertex2i(990,360);
        glVertex2i(960,300);
        glVertex2i(160,300);
        glVertex2i(190,230);
        glVertex2i(30,370);
        glVertex2i(290,360);
        glVertex2i(260,300);
        glVertex2i(0,300);
        glVertex2i(90,230);
        glVertex2i(130,370);
        glVertex2i(60,360);
        glVertex2i(80,300);
        glVertex2i(570,200);
        glVertex2i(600,230);
        glVertex2i(630,270);
        glVertex2i(590,260);
        glVertex2i(680,200);
        glEnd();

        glPopMatrix();
    }
}
///Cloud Model-1 Structure
void cloudModel1(){
    if(f)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    circle(320,210,15);///Left
    circle(340,225,16);///Top
    circle(360,210,16);///Right
    ///Bottom
    circle(330, 210, 16);
    circle(340, 210, 16);
    circle(350, 210, 16);

    glPopMatrix();

}
///Cloud Model-2 Structure
void cloudModel2(){
    if(f)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    circle(305,205,10);///Left
    circle(320,210,15);///Top
    circle(334,207,10);///Right
    circle(320, 207, 10);///Bottom
    glPopMatrix();
}
///Cloud Model-3 Structure
void cloudModel3(){

    glColor3f(1.25,0.924,0.930);

    glPushMatrix();
    circle(300,200,15);///Left
    circle(320,210,15);///Top_Left
    circle(340,220,16);///Top
    circle(360, 210, 15);///Top_Right
    circle(380,200,15);///Right
    circle(360,190,20);///Bottom_Right
    circle(320,190,20);///Bottom_Left
    circle(340,190,20);///Bottom
    glPopMatrix();
}

///cloud1
void cloud1(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos1,170,0);
        cloudModel1();
        glPopMatrix();
    }
}
///cloud2
void cloud2(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos2,270,0);
        cloudModel2();
        glPopMatrix();
    }
}
///cloud3
void cloud3(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos3,200,0);
        cloudModel3();
        glPopMatrix();
    }
}
///cloud4
void cloud4(){
    glPushMatrix();
    glTranslatef(cpos4,250,0);
    cloudModel2();
    glPopMatrix();
}

///cloud5
void cloud5(){
    glPushMatrix();
    glTranslatef(cpos5,220,0);
    cloudModel1();
    glPopMatrix();
}

///Airplane Design
void airPlane(){
    glPushMatrix();
    glTranslatef(plane_x,370,0);

    ///body
    if(f)glColor3ub(196, 190, 0);
    else glColor3ub(0, 51, 2);
    glBegin(GL_POLYGON);
    glVertex2i(100,100);
    glVertex2i(135,100);
    glVertex2i(135,112);
    glVertex2i(100,112);
    glEnd();
    ///Windows
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2i(107,104);
    glVertex2i(115,104);
    glVertex2i(115,110);
    glVertex2i(107,110);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(122,104);
    glVertex2i(130,104);
    glVertex2i(130,110);
    glVertex2i(122,110);
    glEnd();
    ///Head
    if(f)glColor3ub(255,0,0);
    else glColor3ub(82, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(135,100);
    glVertex2i(155,102);
    glVertex2i(135,112);
    glEnd();
    ///Pakha
    glBegin(GL_POLYGON);
    if(f)glColor3ub(255,0,0);
    glVertex2i(100,112);
    glVertex2i(110,112);
    glVertex2i(103,120);
    glVertex2i(100,120);
    glEnd();

    glPopMatrix();


}
float boatXX = 0, boatSpeed = 0;

struct Color
{
    int r;
    int g;
    int b;
};
void triangle(vector<pair<float, float>> coord, Color color = {255, 255, 255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(color.r, color.g, color.b);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < coord.size(); i++)
        glVertex2d(Tx + s * coord[i].first, Ty + s * coord[i].second);
    glEnd();
}
void polygon(vector<pair<float, float>> coord, Color color = {255, 255, 255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < coord.size(); i++)
        glVertex2d(Tx + s * coord[i].first, Ty + s * coord[i].second);
    glEnd();
}
void circle(float x, float y, float radius, float height, Color color)
{
    int triangleAmount = 360;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(color.r, color.g, color.b);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= 360; i++)
        glVertex2f(x + (radius * cos(i * 2 * 3.1416 / triangleAmount)), y + (height * sin(i * 2 * 3.1416 / triangleAmount)));
    glEnd();
}

void Car(float Tx = 0, float Ty = 0, float m = 1, Color boatSails = {58, 59, 95}, Color boatMast = {10, 24, 32}, Color boatBody = {98, 41, 61})
{

    polygon({{Tx + m * 0.34, Ty + 14.87}, {Tx + m * 128.31, Ty + 14.87}, {Tx + m * 138.12, Ty + 20.12}, {Tx + m * 138.12, Ty + 8.16}, {Tx + m * 137.79, Ty + 6.26}, {Tx + m * 136.91, Ty + 3.95}, {Tx + m * 135.59, Ty + 2.48}, {Tx + m * 134.24, Ty + 1.43}, {Tx + m * 132.48, Ty + 0.87}, {Tx + m * 129.5, Ty + 0.38}, {Tx + m * 126.76, Ty + 0.11}, {Tx + m * 4.1, Ty + 0.11}, {Tx + m * 0.34, Ty + 14.87}}, boatBody);
   circle(Tx + 40, Ty, 15, 15, {0, 0, 0});
   circle(Tx + 100, Ty, 15, 15, {0, 0, 0});
}



//Main function called
void display(){
   glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255.0,0.0,1.0);

	 rightTillaL();
    rightWindmMill();
    rightBigHill1();
    rightBigHill2();
    rightTillaR();

    leftTillaL1();
    leftHillBig();
    leftSmallHill();
    leftWindMill();
    leftTillaR();
	water();
    rightHouse();
    leftHouse();
    road();
    boatA();
    boatB();
    Car(boatXX, 200, 1);
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
	boatXX+=50;
    if(boatXX > 980) boatXX = 0;
    if(cpos1>750)cpos1=-320;
    if(cpos2<-350)cpos2=650;
    if(cpos3>750)cpos3=-320;
    if(cpos4>750)cpos4=-320;
    if(cpos5<-350)cpos5=650;
    cpos1+=sp1;
    cpos2-=sp1;
    cpos3+=sp1;
    cpos4+=sp1;
    cpos5-=sp1;
    glutTimerFunc(100, update, 0);
    glutPostRedisplay();
}


void keyboard(int key, int x, int y){

	switch (key)
    {
    case GLUT_KEY_RIGHT:
        if(f == 0) {
            f = 1;
        }else {
            f = 0;
        }
        glutPostRedisplay();
        break;
    default:
        break;
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
	glutIdleFunc(windMill_start);

    glutSpecialFunc(keyboard);
    glutTimerFunc(1000, update, 0);
    glutMainLoop();
}
