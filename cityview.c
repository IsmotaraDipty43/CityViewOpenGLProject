#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cmath>

#define Forwardmegh1 1
#define Backwardmegh2 -1

#define Forwardmegh2 1
#define Backwardmegh2 -1

#define Forwardmegh3 1
#define Backwardmegh3 -1

#define Forwardboat 1
#define Backwardboat -1

#define Forwardsun 1
#define Backwardsun -1

#define Forwardduck 1
#define Backwardduck -1

#define Forwardcow 1
#define Backwardcow -1

#define Forwardbowl 1
#define Backwardbowl -1

#define Forwardbachur 1
#define Backwardbachur -1

#define Forwarddolna 1///for first line
#define Backwarddolna -1///for first line
#define Forwarddolna2 1///for 2nd line
#define Backwarddolna2 -1///for 2nd line

int windowWidth = 850;
int windowHeight = 650;

/// Dolna Animation -----------------------------------------------------------------------

float angle1 = 0;
float angle2 = 0;

///first line dolna animation----------------------------------------
int position = Forwarddolna;
void lineone(int value) {
    switch(position) {
        case Forwarddolna:
            if(angle1 < 10) angle1+=0.3;
            else position = Backwarddolna;
            break;
        case Backwarddolna:
            if(angle1 > -7) angle1-=0.3;
            else position = Forwarddolna;
            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, lineone, 0);
}

///
///2nd line dolna animation-----------------------------------------------
int pos = Forwarddolna2;
void linetwo(int value) {
    switch(pos) {
        case Forwarddolna2:
            if(angle2 < 10) angle2+=0.3;
            else pos = Backwarddolna2;
            break;
        case Backwarddolna2:
            if(angle2 > -7) angle2-=0.3;
            else pos = Forwarddolna2;
            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, linetwo, 0);
}


/// Bachur Cow animation---------------------------------------------------------------------------------------------------------

float y_inc_bachur = 0;
int state_bachur = Forwardsun;
void timer_bachur(int value) {
    switch(state_bachur) {
        case Forwardsun:
            if(y_inc_bachur < 13) y_inc_bachur+=0.1;
            else state_bachur = Backwardbachur;
            break;
//        case Backwardboat:
//            if(x_incboat >-3) x_incboat-=0.2;
//            else stateboat = Backwardboat;
//            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer_bachur, 0);
}

///Cow food bowl animation---------------------------------------------------------------------------------------------------------

float x_inc_bowl = 0;

int state_bowl = Forwardbowl;
void timer_bowl(int value) {
    switch(state_bowl) {
        case Forwardbowl:
            if(x_inc_bowl < 11) x_inc_bowl+=0.1;
            else state_bowl = Backwardbowl;
            break;
//        case BACKWARD:
//            if(x_inc = 85) x_inc-=0.2;
//            else state = FORWARD;
//            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer_bowl, 0);
}

/// Cow Animation------------------------------------------------------------------------------------

float x_inc_cow = 0;
int state_cow = Backwardduck;
void timer_cow (int value) {
    switch(state_cow) {
        case Backwardduck:
            if(x_inc_cow > -20) x_inc_cow-=0.1;
            else state_cow = Forwardcow;
            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer_cow, 0);
}
///----------------------------------------------------------------------keyboard func-----------
int tx=0, ty=0;
int tx_boat=0, ty_boat=0;
void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 27:
            exit(0);
            break;
        case 'a':
        case 'A':
            tx-=1;
            glutPostRedisplay();
            break;

        case 'd':
        case 'D':
            tx+=1;
            glutPostRedisplay();
            break;

        case 'w':
        case 'W':
            ty+=1;
            glutPostRedisplay();
            break;

        case 's':
        case 'S':
            ty-=1;
            glutPostRedisplay();
            break;
///----------------------boat keyboard event
        case 'f':
        case 'F':
            tx_boat-=1;
            glutPostRedisplay();
            break;

        case 'h':
        case 'H':
            tx_boat+=1;
            glutPostRedisplay();
            break;

        case 't':
        case 'T':
            ty_boat+=1;
            glutPostRedisplay();
            break;

        case 'g':
        case 'G':
            ty_boat-=1;
            glutPostRedisplay();
            break;
///----------------------cow keyboard event


    }
}


//void Circle(double r, float x_center, float y_center){
//    int deg =0;
//    double x,y, theta;
//
//    glBegin(GL_POLYGON);
//
//    while(deg<360){
//        theta = (deg * M_PI) /100;
//        x = x_center + r* cos(theta);
//        y = y_center + r* sin(theta);
//        deg++;
//        glVertex2d(x,y);
//    }
//    glEnd();
//}

/// Duck Animation---------------------------------------------------------------------------------------------------------

float x_inc_duck = 0;
int state_duck = Backwardduck;
void timer_duck (int value) {
    switch(state_duck) {
        case Backwardduck:
            if(x_inc_duck > -31) x_inc_duck-=0.1;
            else state_duck = Forwardduck;
            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer_duck, 0);
}


/// Sun animation---------------------------------------------------------------------------------------------------------

float y_inc_sun = 0;
int state_sun = Forwardsun;
void timer_sun(int value) {
    switch(state_sun) {
        case Forwardsun:
            if(y_inc_sun < 19) y_inc_sun+=0.2;
            else state_sun = Backwardboat;
            break;
//        case Backwardboat:
//            if(x_incboat >-3) x_incboat-=0.2;
//            else stateboat = Backwardboat;
//            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer_sun, 0);
}


///Firts cloud animation---------------------------------------------------------------------------------------------------------

float x_inc_1stcloud = 0;

int state = Forwardmegh1;
void timer(int value) {
    switch(state) {
        case Forwardmegh1:
            if(x_inc_1stcloud < 85) x_inc_1stcloud+=0.2;
            else x_inc_1stcloud = -35;
            break;
//        case BACKWARD:
//            if(x_inc = 85) x_inc-=0.2;
//            else state = FORWARD;
//            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}

///2nd cloud animation---------------------------------------------------------------------------------------------------------

float x_inc_2ndcloud = 0;

int state_2ndcloud = Forwardmegh2;

void timer_2ndcloud(int value) {
    switch(state_2ndcloud) {
        case Forwardmegh2:
            if(x_inc_2ndcloud < 65) x_inc_2ndcloud+=0.1;
            else state_2ndcloud= Backwardmegh2;
            break;
        case Backwardmegh2:
            if(x_inc_2ndcloud>-70) x_inc_2ndcloud-=0.1;
            else state_2ndcloud = Forwardmegh2;
            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer_2ndcloud, 0);

}

///3rd cloud animation---------------------------------------------------------------------------------------------------------

float x_inc_3rdcloud = 0;

int state_3rdcloud = Backwardmegh3;

void timer_3rdcloud(int value) {
    switch(state_3rdcloud) {
        case Backwardmegh3:
            if(x_inc_3rdcloud > -100) x_inc_3rdcloud-=0.2;
            else x_inc_3rdcloud = 20;
            break;
//        case BACKWARD:
//            if(x_inc = 85) x_inc_2ndcloud-=0.2;
//            else state_2ndcloud = Backwardmegh2;
//            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer_3rdcloud, 0);
}

///Boat animation---------------------------------------------------------------------------------------------------------

float x_incboat = 0;
int stateboat = Forwardboat;
void timersecond(int value) {
    switch(stateboat) {
        case Forwardboat:
            if(x_incboat < 85) x_incboat+=0.2;
            else stateboat = Backwardboat;
            break;
        case Backwardboat:
            if(x_incboat >-3) x_incboat-=0.2;
            else stateboat = Backwardboat;
            break;
        default:
            //nothing
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, timersecond, 0);
}

void Circle(double r, float x_center, float y_center){
    int deg =0;
    double x,y, theta;

    glBegin(GL_POLYGON);

    while(deg<360){
        theta = (deg * M_PI) /100;
        x = x_center + r* cos(theta);
        y = y_center + r* sin(theta);
        deg++;
        glVertex2d(x,y);
    }
    glEnd();
}

/// Primary Structure of Boats:-------------------------------------------- Functions

  void boats(float tx, float ty){
  glPushMatrix();
  glTranslatef(tx, ty, 0);
    glBegin(GL_QUADS);
    glColor3ub(195,111,50);
    glVertex2i(50,12);
    glVertex2i(60,12);
    glVertex2i(60,10);
    glVertex2i(50,10);

    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(195,111,50);
    glVertex2i(50,12);
    glVertex2i(50,10);
    glVertex2i(47,14);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(195,111,50);
    glVertex2i(60,12);
    glVertex2i(60,10);
    glVertex2i(63,14);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(50,12);
    glVertex2i(52,15);
    glVertex2i(54,12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(132,85,13);
    glVertex2i(52,15);
    glVertex2i(59,15);
    glVertex2i(60,12);
    glVertex2i(54,12);

    glEnd();
  glPopMatrix();
  }

///duck basic structure:-------------------------------------------------------  Functions

void duck(float tx, float ty){
  glPushMatrix();
  glTranslatef(tx, ty, 0);
    glBegin(GL_POLYGON);
    glColor3ub(251,229,92);
    glVertex2i(90,5);
    glVertex2i(90,3);
    glVertex2i(93,6);

    glEnd();
      glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(250,155,73);
    glVertex2i(89,7);
    glVertex2i(87,6);


    glEnd();

    glColor3ub(251,229,92);

     Circle(2,90,5);
    Circle(1,89,7);
     glColor3ub(0,0,0);
    Circle(0.3,89,7);
  glPopMatrix();
}

/// Cow basic structure:----------------------------------------------------------- Functions

void cow(float tx, float ty){

    glPushMatrix();
    float r=0, g=0, b=0;
    glColor3ub(r, g, b);
    glTranslatef(tx, ty, 0);
    glBegin(GL_POLYGON);
    glColor3ub(255,252,235);
    glVertex2i(69,69);
    glVertex2i(61,69);
    glVertex2i(63,64);
    glVertex2i(69,64);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,252,235);

    glVertex2f(70.8,64);
    glVertex2f(72,64.6);
    glVertex2f(72,62.3);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(62,71);
    glVertex2f(62,72);
    glVertex2f(62,70);
    glVertex2f(61,72);
    glEnd();




    glColor3ub(255,252,235);
    Circle(2,62,69);
    glColor3ub(230,147,131);
    Circle(1.2,61,68);
    Circle(0.7,63,71);
    Circle(0.7,61,71);

    glColor3ub(0,0,0);
    Circle(0.3,61,68);
    Circle(0.3,60,68);
    glColor3ub(0,0,0);
    Circle(0.4,61,70);
    Circle(0.4,62,70);
    glColor3ub(101,78,64);
    Circle(0.6,64,61);
    Circle(0.6,66,61);
    Circle(0.6,67,60);
    Circle(0.6,68,61);
    glColor3ub(166,94,56);
    Circle(1,67,67);
    Circle(0.4,66,66);
    Circle(0.5,68,65);
    Circle(0.6,63,65);
    Circle(0.5,65,67);




    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3ub(255,252,235);
    glVertex2f(64,64);
    glVertex2f(64,61);
    glVertex2f(66,65);
    glVertex2f(66,61);

    glVertex2f(67,64);
    glVertex2f(67,60);
    glVertex2f(68,64);
    glVertex2f(68,61);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,252,235);
    glVertex2f(69,69);
    glVertex2f(71,64);
    glEnd();

    glPopMatrix();
}

    ///hill right side face  basic structure tree1------------------------------------------------------------
void hill_rightsideface (float tx, float ty){
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(140,107,79);
        glVertex2f(18,73);
        glVertex2f(18,78);
        glEnd();

       glColor3ub(157,179,29);

     Circle(1.5,18,78);
    Circle(1,19,77);
    glPopMatrix();

}

///hillLeft side face basic structure tree1------------------------------------------------------------

void hill_leftsideface (float tx, float ty){
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(140,107,79);
        glVertex2f(63,73);
        glVertex2f(63,78);
        glEnd();

       glColor3ub(157,179,29);

     Circle(1.5,63,78);
    Circle(1,62,77);
    glPopMatrix();

}

///Human Basic Structure  ------------------------------------------------------ Functions

void human(float x, float y){

    glPushMatrix();
    glTranslatef(x, y, 0);

    glBegin(GL_QUADS);
    glColor3ub(22,154,255);
    glVertex2i(31,50);
    glVertex2i(31,51);
    glVertex2i(33,51);
    glVertex2i(33,50);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(100,15,255);
    glVertex2i(31,50);
    glVertex2i(30,48);
    glVertex2i(34,48);
    glVertex2i(33,50);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(146,226,253);
    glVertex2i(31,50);
    glVertex2i(33,50);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(248,218,207);
    glVertex2i(32,51);
    glVertex2i(32,52);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(248,218,207);
    glVertex2i(33,51);
    glVertex2i(34,49);
    glVertex2i(31,51);
    glVertex2i(30,49);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(248,218,207);
    glVertex2i(31,48);
    glVertex2i(31,47);
    glVertex2i(33,48);
    glVertex2i(33,47);
    glEnd();


    glColor3ub(248,218,207);
    Circle(0.9,32,52);

    glColor3ub(0,0,0);
    Circle(0.2,32.5,52);
    Circle(0.2,31.5,52);

    glColor3ub(128,100,76);
    Circle(0.5,32.3,53.2);

    glColor3ub(25,255,253);
    Circle(0.2,3,51);

    glPopMatrix();
}

///---------------------------------------------Void Display------------------------------------

void display(void){

glClear(GL_COLOR_BUFFER_BIT);


    glColor3ub(135, 206, 235);
    glBegin(GL_POLYGON);

    ///sky-------------------------------------------------------------------------------------------------------------
    glVertex3f(0.0f, 75.0f, 0.0f);
    glVertex3f(100.0f, 75.0f, 0.0f);
    glVertex3f(100.0f, 100.0f, 0.0f);
    glVertex3f(0.00f ,100.0f, 0.0f);
    glEnd();
    ///


    /// SUN ------------------------------------------------------------------------------------------------------

    glPushMatrix();
    glTranslatef(0, y_inc_sun, 0);
    glTranslatef(0, -15, 0);
    glColor3ub(253, 184, 19);
    Circle(3,80,89);
    glPopMatrix();

    ///hill--------------------------------------------------------------------------------------------------------
    glBegin(GL_POLYGON);
    glColor3ub(5, 73, 7);

    glVertex2i(0,75);
    glVertex2i(0,80);
    glVertex2i(2,78);
    glVertex2i(5,78);
    glVertex2i(9,80);
    glVertex2i(14,78);
    glVertex2i(19,82);
    glVertex2i(27,80);
    glVertex2i(36,81);
    glVertex2i(40,77);
    glVertex2i(44,79);
    glVertex2i(47,75);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(5, 73, 7);

    glVertex2i(43,76);
    glVertex2i(47,76);
    glVertex2i(50,78);
    glVertex2i(54,80);
    glVertex2i(58,78);
    glVertex2i(62,82);
    glVertex2i(67,80);
    glVertex2i(74,81);
    glVertex2i(78,77);
    glVertex2i(83,79);
    glVertex2i(87,75);
    glVertex2i(43,75);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(5, 73, 7);

    glVertex2i(84,76);
    glVertex2i(88,80);
    glVertex2i(92,78);
    glVertex2i(95,81);
    glVertex2i(98,78);
    glVertex2i(98,82);
    glVertex2i(100,80);
    glVertex2i(100,75);
    glVertex2i(84,75);
  glEnd();


    ///greenfield---------------------------------------------------------------------------------------


    glBegin(GL_QUADS);
    glColor3ub(111,161,40);
    //glColor3ub(107, 173, 72);
    glVertex2i(0,75);
    glVertex2i(0,0);
    glVertex2i(100,0);
    glVertex2i(100,75);
    glEnd();

  ///tree-----------------------------------------------------------------------------------------------
    glPushMatrix();
    glTranslatef(-20, -4, 0);
    glBegin(GL_QUADS);
    glColor3ub(157,107,73);
    glVertex2i(25,48);
    glVertex2i(26,48);
    glVertex2i(26,54);
    glVertex2i(25,54);
    glEnd();

    glColor3ub(227, 234, 131);
    Circle(3,26,55);
    Circle(2,24,54);
    Circle(3,24,57);
    Circle(3,27,57);
    Circle(2,26,59);
    glPopMatrix();


    /// nodir sather mati jomi
    glPushMatrix();
    glTranslatef(-120, -50, 0);
    glScalef(4, 2, 0);
    glTranslatef(15, -20, 0);
    glColor3ub(239, 179, 76);
    Circle(3,26,55);
    Circle(2,24,54);
    Circle(3,24,57);
    Circle(3,27,57);
    Circle(2,26,59);
    glPopMatrix();

    /// nodir sather mati jomi
    glPushMatrix();
    glTranslatef(-200, -140, 0);
    glScalef(6, 4, 0);
    glTranslatef(15, -20, 0);
    glColor3ub(239, 179, 76);
    Circle(3,26,55);
    Circle(2,24,54);
    Circle(3,24,57);
    Circle(3,27,57);
    Circle(2,26,59);
    glPopMatrix();

    /// Dolnar sather mati jomi
    glPushMatrix();
    glTranslatef(-49, 35, 0);
    glScalef(1.5, .7, 0);
    glTranslatef(15, -20, 0);
    glColor3ub(229, 159, 73);
    Circle(3,26,55);
    Circle(2,24,54);
    Circle(3,24,57);
    Circle(3,25,57);
    Circle(2,26,59);
    glPopMatrix();



    ///tree last part----------------------------------------------------------------------------------------------

    glPushMatrix();

    glTranslatef(-26, 12, 0);

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(69,31,17);
    glVertex2i(95,48);
    glVertex2i(95,59);

    glVertex2i(95,52);
    glVertex2i(97,56);
    glVertex2i(95,54);
    glVertex2i(93,58);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(146, 169, 91);

    glVertex2i(92,57);
    glVertex2i(98,57);
    glVertex2i(95,63);

    glEnd();

    glColor3ub(146, 169, 91);
    Circle(3.1,95,54);
    Circle(2.9,95,57);


    glPopMatrix();



    ///1st cloud---------------------------------------------------------------------------------
    glPushMatrix();
    glTranslatef(x_inc_1stcloud, 0, 0);
    glTranslatef(-3, 0, 0);
    glColor3f(1.0,1.0,1.0);
    Circle(3,21,91);
    Circle(2.5,24,92);
    Circle(2.4,19,88);
    Circle(2.2,22,87);
    Circle(2.4,25,88);
    glPopMatrix();


    ///2nd cloud----------------------------------------------------------------------------------------
    glPushMatrix();
    glTranslatef(x_inc_2ndcloud, 0, 0);
    glTranslatef(-3,-1, 0);
    glColor3f(1.0,1.0,1.0);

    Circle(3.8,55,93);
    Circle(2.6,52,92);
    Circle(2.6,59,92);
    Circle(2.5,53.5,90);
    Circle(2.5,60,91);
    Circle(2.0,57,90);

    glPopMatrix();

    ///3rd cloud---------------------------------------------------------------------------------------------
    glPushMatrix();
    glTranslatef(x_inc_3rdcloud, 0, 0);
    glTranslatef(70, 3, 0);
    glColor3f(1.0,1.0,1.0);
    Circle(3,21,91);
    Circle(2.5,24,92);
    Circle(2.4,19,88);
    Circle(2.2,22,87);
    Circle(2.4,25,88);
    glPopMatrix();

   ///waterfal-----------------------------------------------------------------

    glBegin(GL_QUADS);
    glColor3ub(156,210,217);
    glVertex2i(77,75);
    glVertex2i(77,40);
    glVertex2i(90,40);
    glVertex2i(90,75);
    glEnd();

    ///side jorna left leaf part------------------------------------------------------------

    glColor3ub(158,200,28);

    Circle(3,74,43);
    Circle(3,73,47);
    Circle(3,73,50);
    Circle(2.3,73,53);
    Circle(3.2,74,56);
    Circle(2.3,73,59);
    Circle(3.0,73,62);
    Circle(3.2,72,65);
    Circle(3.4,72,68);
    Circle(3,73,70);
    Circle(1.8,71,71);
    Circle(1.5,73,74);
    Circle(1.8,75,74);

    ///jorna left mati part----------------------------------------------------------

    glBegin(GL_POLYGON);
    glColor3ub(184,130,2);
    glVertex2i(75,40);
    glVertex2i(75,45);
    glVertex2i(73,49);
    glVertex2i(75,52);
    glVertex2i(73,56);
    glVertex2i(74,59);
    glVertex2i(72,61);
    glVertex2i(75,65);
    glVertex2i(73,67);
    glVertex2i(76,72);
    glVertex2i(77,70);
    glVertex2i(77,40);
    glEnd();

    /// jorna right side leaf part------------------------------------------------------------

    glColor3ub(158,200,28);
    Circle(3,94,43);
    Circle(3,93,47);
    Circle(3,95,50);
    Circle(2.3,96,53);
    Circle(3.4,96,56);
    Circle(2.3,96,59);
    Circle(3.3,95,62);
    Circle(3.4,96,65);
    Circle(3.4,95,69);
    Circle(3.4,94,71);
    Circle(3.2,93,73);

    ///jorna left mati part 3rd part----------------------------------------------

    glBegin(GL_POLYGON);
    glColor3ub(184,130,2);
    glVertex2i(93,40);
    glVertex2i(93,45);
    glVertex2i(96,49);
    glVertex2i(93,52);
    glVertex2i(96,56);
    glVertex2i(97,59);
    glVertex2i(95,61);
    glVertex2i(93,65);
    glVertex2i(96,67);
    glVertex2i(94,72);
    glVertex2i(90,75);
    glVertex2i(90,40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(184,130,2);
    glVertex2i(75,40);
    glVertex2i(75,45);
    glVertex2i(73,49);
    glVertex2i(75,52);
    glVertex2i(73,56);
    glVertex2i(74,59);
    glVertex2i(72,61);
    glVertex2i(75,65);
    glVertex2i(73,67);
    glVertex2i(75,73);
    glVertex2i(77,75);
    glVertex2i(77,40);
    glEnd();


    ///river down part------------------------------------------------------------------

    glColor3ub(156,210,217);

    Circle(4,80,38);
    Circle(3,76,37);
    Circle(3,83,38);
    Circle(3,85,38);
    Circle(3,88,38);
    Circle(3,91,38);
    Circle(3,94,38);
    Circle(5,93,34);
    Circle(10,97,33);
    Circle(6,88,33);
    Circle(6,80,33);
    Circle(9,83,31);
    Circle(9,83,25);
    Circle(9,75,25);
    Circle(9,73,25);
    Circle(9,75,20);
    Circle(9,73,15);
    Circle(9,70,14);
    Circle(9,65,14);
    Circle(9,60,14);
    Circle(9,55,13);
    Circle(9,50,10);
    Circle(8,48,5);
    Circle(5,46,0);
    Circle(10,50,0);
    Circle(10,55,0);
    Circle(10,60,0);
    Circle(10,70,0);
    Circle(10,80,0);
    Circle(10,95,14);
    Circle(10,97,15);

    Circle(10,90,0);
    Circle(10,90,10);
    Circle(10,100,0);
    Circle(6,38,0);

        /// Ghater mati jomi
    glPushMatrix();
    glRotatef(40, 0, 0 , 1);
    glTranslatef(22.1, -46.0, 0);
    glScalef(1.3, .7, 0);
    glTranslatef(15, -20, 0);
    glColor3ub(56, 42, 42);
    Circle(3,23,55);
    Circle(2,24,55);
    Circle(3,24,56);
    Circle(3,23,56);
    Circle(2,25,55);
    glPopMatrix();

        /// Ghater mati jomi2

    glPushMatrix();
    glRotatef(40, 0, 0 , 1);
    glTranslatef(45, -41.0, 0);
    glScalef(.7, .5, 0);
    glTranslatef(15, -20, 0);
    glColor3ub(56, 42, 42);
    Circle(3,23,55);
    Circle(2,24,55);
    Circle(3,24,56);
    Circle(3,23,56);
    Circle(2,25,55);
    glPopMatrix();





///river leaf---------------------------------------------------------------------------------------------------------

    glPushMatrix();
    glTranslatef(3,10,0);

    glColor3ub(129,194,64);
    Circle(3,94,20);
    Circle(2,80,25);

    Circle(2.3,74,15);

    glBegin(GL_TRIANGLES);
    glColor3ub(156,210,217);
    glVertex2i(95,15);
    glVertex2i(96,15);
    glVertex2i(94,21);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(156,210,217);
    glVertex2i(82,18);
    glVertex2i(89,18);
    glVertex2i(80,25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(156,210,217);
    glVertex2i(73,10);
    glVertex2i(75,10);
    glVertex2i(74,16);
    glEnd();
    glPopMatrix();

    /// boat1-------------------------------------------------------------------------------------------------
    glPushMatrix();
    glTranslatef(x_incboat, 0, 0);
    boats(-5,0);
    glPopMatrix();
    /// boat2--------------------------------------------------------------------------------------------------
    glPushMatrix();
    glTranslatef(-2, -2, 0);
    glTranslatef(tx_boat, ty_boat, 0);
    boats(5,8);
    glPopMatrix();

    ///ghat


    ///duck4 separate one-------------------------------------------------------------------------------------------------

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glTranslatef(7,10, 0);
    glScalef(.7, .8, 0);
    duck(25,-10);
    glPopMatrix();

///-----------------------------Start Animation of Duck--------------------------------------
    glPushMatrix();
    glTranslatef(30, 3.5, 0);

    ///Mother duck2-------------------------------------------------------------------------------------------------
    glPushMatrix();
        glTranslatef(x_inc_duck, 0, 0);
    glTranslatef(-16,3, 0);
    glScalef(1.1, 1.0, 0);
    duck(5,20);
    glPopMatrix();
    ///duck3 under mother --------------------------------------------------------------------------------------------------
    glPushMatrix();
        glTranslatef(x_inc_duck, 0, 0);
    glTranslatef(10,10, 0);
    glScalef(.7, .8, 0);
    duck(29,15);
    glPopMatrix();

    ///duck2 above mother --------------------------------------------------------------------------------------------------
    glPushMatrix();
        glTranslatef(x_inc_duck, 0, 0);
    glTranslatef(10,10, 0);
    glScalef(.7, .8, 0);
    duck(26,22);
    glPopMatrix();

    glPopMatrix();

///--------------------------------------------------------------End Duck Animation-----------------------------------------------

    ///Small house-----------------------------------------------------------------
    glBegin(GL_QUADS);
    glColor3ub(161,144,118);
    glVertex2i(41,63);
    glVertex2i(41,71);
    glVertex2i(50,71);
    glVertex2i(50,62);

    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(132,85,13);
    glVertex2i(40,71);
    glVertex2i(43,76);
    glVertex2i(53,76);
    glVertex2i(50,71);


     glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(161,144,118);
    glVertex2i(50,62);
    glVertex2i(50,71);
    glVertex2i(53,76);
    glVertex2i(55,71);
    glVertex2i(55,63);
     glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3ub(132,85,13);
        glVertex2f(56,70);
        glVertex2f(53,76);
        glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(52,47,38);
    glVertex2i(44,62);
    glVertex2i(44,68);
    glVertex2i(46,68);
    glVertex2i(46,62);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(52,47,38);
    glVertex2i(51,66);
    glVertex2i(51,69);
    glVertex2i(54,69);
    glVertex2i(54,66);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(96,91,69);
    glVertex2i(44,62);
    glVertex2i(44,68);
    glVertex2i(46,68);
    glVertex2i(46,62);
    glVertex2i(51,66);
    glVertex2i(51,69);
    glVertex2i(54,69);
    glVertex2i(54,66);
    glVertex2i(53,69);
    glVertex2i(53,66);
    glVertex2i(52,69);
    glVertex2i(52,66);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(118,141,167);
    glVertex2f(50,71);
    glVertex2f(50,62);
    glEnd();

///Big house------------------------------------------------------------------
    glBegin(GL_QUADS);
    glColor3ub(156,180,206);
    glVertex2i(30,62);
    glVertex2i(30,70);
    glVertex2i(40,70);
    glVertex2i(40,62);

    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(220,130,58);
    glVertex2i(30,69);
    glVertex2i(28,76);
    glVertex2i(39,76);
    glVertex2i(41,69);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(220,130,58);
    glVertex2f(25,69);
    glVertex2f(28,76);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(118,141,167);
    glVertex2f(30,69);
    glVertex2f(30,62);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(157,181,209);
    glVertex2i(30,62);
    glVertex2i(25,62);
    glVertex2i(25,69);
    glVertex2i(28,76);
    glVertex2i(30,69);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(52,47,38);
    glVertex2i(28,62);
    glVertex2i(26,62);
    glVertex2i(26,67);
    glVertex2i(28,67);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(52,47,38);
    glVertex2i(32,64);
    glVertex2i(34,64);
    glVertex2i(34,67);
    glVertex2i(32,67);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(52,47,38);
    glVertex2i(36,64);
    glVertex2i(38,64);
    glVertex2i(38,67);
    glVertex2i(36,67);

    glEnd();

     glLineWidth(2);
     glBegin(GL_LINES);
    glColor3ub(96,91,69);
    glVertex2i(36,64);
    glVertex2i(38,64);
    glVertex2i(38,67);
    glVertex2i(36,67);
    glVertex2i(36,64);
    glVertex2i(36,67);
    glVertex2i(38,64);
    glVertex2i(38,67);
    glVertex2i(37,64);
    glVertex2i(37,67);
    //
    glVertex2i(32,64);
    glVertex2i(34,64);
    glVertex2i(34,67);
    glVertex2i(32,67);
    glVertex2i(32,64);
    glVertex2i(32,67);
    glVertex2i(34,64);
    glVertex2i(34,67);
    glVertex2i(33,64);
    glVertex2i(33,67);


    glEnd();



    /// Dolnar tree----------------------------------------------------------------------------------------


    glColor3ub(129,194,64);
    Circle(3,4,76);
    Circle(3,12,75);
    Circle(4,10,77);
    Circle(3.5,8,73);
    Circle(4,4,73);
    Circle(4,5,76);
    Circle(5,6,77);
    Circle(3,9,80);
    Circle(3,6,80);
    Circle(3,5,80);
    //
    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(157,125,100);
    glVertex2i(6,59);
    glVertex2i(6,77);
    glVertex2i(6,72);
    glVertex2i(12,75);
    glVertex2i(6,73);
    glVertex2i(4,76);
    glEnd();




///1st line dolna
  glPushMatrix();
  glTranslatef(8,73,0);
    glRotatef(angle1,0,0,1);
    glTranslatef(-8,-73,0);

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3ub(157,125,100);
    glVertex2i(8,73);
    glVertex2i(8,63);
    glEnd();
    glPopMatrix();

    ///2ndline Dolana
    glPushMatrix();
    glTranslatef(11,74,0);
    glRotatef(angle2,0,0,1);
    glTranslatef(-11,-74,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(11,74);
    glVertex2i(11,63);
    glEnd();

    glLineWidth(11);
    glBegin(GL_LINES);
    glColor3ub(205,174,143);
     glVertex2i(8,63);
    glVertex2i(11,63);
    glEnd();

    ///human-------------------------------------------------------------------
    glPushMatrix();
    glTranslatef(-44.5, -32, 0);
    glScalef(.7, 1.2f, 1.0f);
    human(45, 30);
    glPopMatrix();
    glPopMatrix();


///swing--1 -------------------cow fench side

    glPushMatrix();

    glRotatef(5, 0, 0, 1);
    glTranslatef(-13, -36, 0);
    glScalef(1.2, .7, 0);

    glTranslatef(10, 40, 0);
    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(195,114,85);
    glVertex2f(23,11);
    glVertex2f(23,17);
    glEnd();

    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(195,114,85);
    glVertex2f(15,15);
    glVertex2f(30,19);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(195,114,85);
    glVertex2f(15,12);
    glVertex2f(15,18);
    glVertex2f(30,22);
    glVertex2f(30,16);
    glEnd();

    glColor3ub(139,95,60);
    Circle(1,23,17);

    glPopMatrix();


///swing--1 -------------------cow fench side

    glPushMatrix();

    glRotatef(30, 0, 0, 1);
    glTranslatef(14, -45, 0);
    glScalef(1.01, .7, 0);

    glTranslatef(10, 40, 0);
    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(195,114,85);
    glVertex2f(20,13);
    glVertex2f(23,17);
    glEnd();

    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(195,114,85);
    glVertex2f(15,15);
    glVertex2f(30,19);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(195,114,85);
    glVertex2f(15,12);
    glVertex2f(15,18);
    glVertex2f(30,22);
    glVertex2f(30,16);
    glEnd();

    glColor3ub(139,95,60);
    Circle(1,23,17);

    glPopMatrix();


    ///hill tree1------------------------------------------------------------

    hill_rightsideface(-2,0);
    hill_rightsideface(1.5,0);
    hill_leftsideface(-39,0);

    ///hill tree2
    hill_rightsideface(22.5,0);
    ///hill tree3

    hill_rightsideface(40,0);
    hill_rightsideface(45,0);
    hill_leftsideface(0,0);
    hill_leftsideface(5,0);

    ///hill tree4
    hill_leftsideface(35,0);


    ///Road to house from river--------------------------------------------------------

    glColor3ub(178,178,178);

    Circle(0.9,43,59);
    Circle(1.0,46,58);
    Circle(1.0,45,61);
    Circle(0.5,43,61);
    Circle(0.8,46,56);
    Circle(0.8,45,56);
    Circle(1.3,47,53);
    Circle(0.8,46,52);
    Circle(1.3,49,50);
    Circle(0.8,50,49);
    Circle(1.3,52,47);
    Circle(0.4,50,46);
    Circle(1.3,55,45);
    Circle(1,54,43);

    Circle(0.8,54,45);
    Circle(0.8,55,43);

    Circle(1,57,40);
    Circle(0.8,58,41);
    Circle(0.5,57,40);
    Circle(0.8,58,41);
    Circle(1,60,37);
    Circle(1.5,61,40);
    Circle(0.8,64,36);
    Circle(1.3,63,35);

    Circle(1,65,34);
    Circle(1.2,26,60);
    Circle(1.0,28,58);
    Circle(0.5,28,60);
    Circle(0.5,30,56);
    Circle(0.8,30,58);
    Circle(1,32,56);
    Circle(0.8,34,55);
    Circle(0.5,33,56);
    Circle(0.5,35,53);
    Circle(0.9,37,54);
    Circle(0.5,39,52);
    Circle(0.9,42,53);
    Circle(1.2,43,52);
    Circle(0.4,41,51);

///Cow house border-----------------------------------------------------------------------------------

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(96,91,69);
    glVertex2i(0,45);
    glVertex2i(15,45);
    glVertex2i(0,43);
    glVertex2i(15,43);


    glVertex2i(1,42);
    glVertex2i(1,46);
    glVertex2i(3,42);
    glVertex2i(3,46);
    glVertex2i(5,42);
    glVertex2i(5,46);
    glVertex2i(7,42);
    glVertex2i(7,46);
    glVertex2i(9,42);
    glVertex2i(9,46);
    glVertex2i(11,42);
    glVertex2i(11,46);
    glVertex2i(13,42);
    glVertex2i(13,46);
    glVertex2i(15,36);
    glVertex2i(15,46);
    glVertex2i(15,20);
    glVertex2i(15,3);
    glVertex2i(15,46);
    glVertex2i(16,43);
    glVertex2i(15,42);
    glVertex2i(16,39);
    glVertex2i(15,37);
    glVertex2i(16,35);
    glVertex2i(15,19);
    glVertex2i(16,16);
    glVertex2i(15,15);
    glVertex2i(16,12);
    glVertex2i(15,11);
    glVertex2i(16,9);
    glVertex2i(15,8);
    glVertex2i(16,5);

    glVertex2i(0,5);
    glVertex2i(15,5);
    glVertex2i(0,3);
    glVertex2i(15,3);
    glVertex2i(1,2);
    glVertex2i(1,6);
    glVertex2i(3,2);
    glVertex2i(3,6);
    glVertex2i(5,2);
    glVertex2i(5,6);
    glVertex2i(7,2);
    glVertex2i(7,6);
    glVertex2i(9,2);
    glVertex2i(9,6);
    glVertex2i(11,2);
    glVertex2i(11,6);
    glVertex2i(13,2);
    glVertex2i(13,6);
    glVertex2i(15,2);
    glVertex2i(15,6);

    glEnd();

    /// Cow home----------------------------------------------------------------------------------------------


    glPushMatrix();
    glScalef(0.9, 1.6, 0 );
    glTranslatef(-27, 30, 0);
    glRotatef(-90, 0, 0, 1);

    glBegin(GL_POLYGON);
    glColor3ub(168,63,42);
    glVertex2i(3,39);
    glVertex2i(6,36);
    glVertex2i(6,28);
    glVertex2i(3,30);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(168,63,42);
    glVertex2i(3,39);
    glVertex2i(6,36);
    glVertex2i(6,42);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(236,152,82);
    glVertex2i(6,40);
    glVertex2i(9,40);
    glVertex2i(9,30);
    glVertex2i(6,30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2i(7,36);
    glVertex2i(9,36);
    glVertex2i(9,33);
    glVertex2i(7,33);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(96,91,69);
    glVertex2i(7,33);
    glVertex2i(9,33);
    glVertex2i(7,36);
    glVertex2i(9,36);

    glVertex2i(7,36);
    glVertex2i(7,33);
    glEnd();

    glPopMatrix();

/// Cow Food Bowl------------------------------------------------------------------------------------------------
    glPushMatrix();
    glTranslatef(x_inc_bowl, 0, 0);
    glTranslatef(-15, 12, 0);
    glBegin(GL_POLYGON);
    glColor3ub(149,45,10);
    glVertex2i(6,15);
    glVertex2i(7,13);
    glVertex2i(11,13);
    glVertex2i(12,15);
    glEnd();

    glColor3ub(243,217,142);
     Circle(1.2,8,16);
     Circle(1,7,16);
     Circle(1,7,17);
     Circle(1.2,9,16);
     Circle(1,10,16);
     Circle(1,11,16);

    glPopMatrix();


    ///cow1 Mother--------------------------------------------------------------------
    glPushMatrix();
    glTranslatef(x_inc_cow, 0, 0);
    glTranslatef(-25, -23, 0);
    cow(-8,-15);
    glPopMatrix();

    ///cow2 Bachur---------------------------
    glColor3ub(255, 0, 0);
    glPushMatrix();
    glTranslatef(0, y_inc_bachur, 0);
    glTranslatef(-22.5, -20, 0);
    glScalef(0.5, 0.5, 1);
    cow(0, -8);
    glPopMatrix();



    glutSwapBuffers();

}
void reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    if(width != 1500 || height != 900) {
        glutPositionWindow(100, 50);
        glutReshapeWindow(1200, 650);
        glutPostRedisplay();
    }
    glMatrixMode(GL_MODELVIEW);

}


//void init(){
//    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
//    gluOrtho2D(0.0f, 100.0f, 0.0f, 100.0f);
//
//}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(850,650);
    glutInitWindowPosition(300,100);
    glutCreateWindow("My Project");// j window create hobe setar nam thik kora.
    glutTimerFunc(5000, timer, 0);
    glutTimerFunc(4000, timer_2ndcloud, 0);
    glutTimerFunc(5000, timer_3rdcloud, 0);
    glutTimerFunc(14000, timersecond, 0);//boat
    glutTimerFunc(3000, timer_sun, 0);
    glutTimerFunc(1000, timer_duck, 0);
    glutTimerFunc(18000, timer_cow, 0);
    glutTimerFunc(10000, timer_bowl, 0);
    glutTimerFunc(25000, timer_bachur, 0);
    glutTimerFunc(40000, lineone, 0);
    glutTimerFunc(40000, linetwo, 0);
    //init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();// eta diye muloto keyboard diye input er maddome shap0e change kori like rotation,moveing etc.

    return 0;


}
