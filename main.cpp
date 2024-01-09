#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
int windowWidth = 1200;
int windowHeight = 1000 ;
double eyeX=7.0, eyeY=2.0, eyeZ=15.0, refX = 0, refY=0,refZ=0;
double theta = 180.0, y = 1.36, z = 7.97888, a=2;
bool flagScale = false;
void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'w': // move eye point upwards along Y axis
        eyeY+=1.0;
        break;
    case 's': // move eye point downwards along Y axis
        eyeY-=1.0;
        break;
    case 'a': // move eye point left along X axis
        eyeX-=1.0;
        break;
    case 'd': // move eye point right along X axis
        eyeX+=1.0;
        break;
    case 'o':  //zoom out
        eyeZ+=1;
        break;
    case 'i': //zoom in
        eyeZ-=1;
        break;
    case 'q': //back to default eye point and ref point
            eyeX=7.0; eyeY=2.0; eyeZ=15.0;
            refX=0.0; refY=0.0; refZ=0.0;
        break;
    case 'j': // move ref point upwards along Y axis
        refY+=1.0;
        break;
    case 'n': // move ref point downwards along Y axis
        refY-=1.0;
        break;
    case 'b': // move ref point left along X axis
        refX-=1.0;
        break;
    case 'm': // move eye point right along X axis
        refX+=1.0;
        break;
    case 'k':  //move ref point away from screen/ along z axis
        refZ+=1;
        break;
    case 'l': //move ref point towards screen/ along z axis
        refZ-=1;
        break;
    case 27:    // Escape key
        exit(1);
    }

    glutPostRedisplay();
}
static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0}, //0
    {0.0, 0.0, 3.0}, //1
    {3.0, 0.0, 3.0}, //2
    {3.0, 0.0, 0.0}, //3
    {0.0, 3.0, 0.0}, //4
    {0.0, 3.0, 3.0}, //5
    {3.0, 3.0, 3.0}, //6
    {3.0, 3.0, 0.0}  //7
};

static GLubyte quadIndices[6][4] =
{
    {0, 1, 2, 3}, //bottom
    {4, 5, 6, 7}, //top
    {5, 1, 2, 6}, //front
    {0, 4, 7, 3}, // back is clockwise
    {2, 3, 7, 6}, //right
    {1, 5, 4, 0}  //left is clockwise
};




void drawCube()
{
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
    }
    glEnd();
}
void Wall()
{
    // left wall
    glColor3f(1, 0.8, 0.7);
    glPushMatrix();
    glTranslatef(-4.5,-1,0);
    glScalef(1, 2, 5);
    drawCube();
    glPopMatrix();
    // right wall
    glColor3f(1, 0.8, 0.5);
    glPushMatrix();
    glTranslatef(-1.5,-1,.5);
    glScalef(5, 2, 0.1);
    drawCube();
    glPopMatrix();
   //ceiling
    glColor3f(1.0, 0.9, 0.8);
    glPushMatrix();
    glTranslatef(-2,5.1,0);
    glScalef(5, 0.1, 7);
    drawCube();
    glPopMatrix();
    // carpet
    glColor3f(0.4, 0.1, 0.0);
    glPushMatrix();
    glTranslatef(0,-1,0);
    glScalef(3, 0.01, 4);
    drawCube();
    glPopMatrix();

    // floor
    glColor3f(1.0, 0.9, 0.8);
    glPushMatrix();
    glTranslatef(-2,-1.4,0);
    glScalef(5, 0.1, 7);
    drawCube();
    glPopMatrix();
}
void Calender()
{
    //Calender

        //calender body
        glColor3f(0.545, 0.271, 0.075);
        glPushMatrix();
        glTranslatef(-0.9,1.8,7.87);
        glScalef(0.08, 0.25, 0.1);
        drawCube();
        glPopMatrix();

        //calender body white
        glColor3f(1.000, 0.894, 0.710);
        glPushMatrix();
        glTranslatef(-0.83,1.9,7.9);
        glScalef(0.06, 0.2, 0.08);
        drawCube();
        glPopMatrix();

        // calender date 1 er nicher part
        glColor3f(0,0,0);
        glPushMatrix();
        glTranslatef(-0.65,2.18,8.01);
        glRotatef(45, 1,0,0);
        glScalef(0.0001, 0.01, 0.04);
        drawCube();
        glPopMatrix();

        glColor3f(0,0,0);
        glPushMatrix();
        glTranslatef(-0.65,2.18,8.01);
        glRotatef(90, 1,0,0);
        glScalef(0.0001, 0.012, 0.08);
        drawCube();
        glPopMatrix();

        //calender body bottom strip
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(-0.66,1.8,7.89);
        //glRotatef(22, 0,0,1);
        glScalef(0.001, 0.01, 0.1);
        drawCube();
        glPopMatrix();

        //calender body right strip
        glColor3f(0.0,0.0,0.0);
        glPushMatrix();
        glTranslatef(-0.66,1.8,7.89);
        glScalef(0.005, 0.25, 0.01);
        drawCube();
        glPopMatrix();

        //calender body left strip
        glColor3f(0.2,0.1,0.1);
        glPushMatrix();
        glTranslatef(-0.65,1.8,8.2);
        glScalef(0.0001, 0.25, 0.01);
        drawCube();
        glPopMatrix();

}
void TV(){
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-1,1.4,4.6);
    glScalef(0.0001, .65, .8);
    drawCube();
    glPopMatrix();

}
void Table(){

    glColor3f(0.7, 0.4, 0.1);
    glPushMatrix();
    glTranslatef(-1,-0.8,1.9);
    glScalef(0.5, 0.5,2.5);
    drawCube();
    glPopMatrix();

    glColor3f(0.87, 0.56, 0.37);
    glPushMatrix();
    glTranslatef(.025,-.5,7.7);
    glScalef(0.20, 0.25,.5);
    drawCube();
    glPopMatrix();

    glColor3f(0.87, 0.56, 0.37);
    glPushMatrix();
    glTranslatef(.025,-.5,4.7);
    glScalef(0.20, 0.25,.5);
    drawCube();
    glPopMatrix();

}
void Picture(){
    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(2.2,1.6,1.1);
    glScalef(.25, .7, -0.02);
    drawCube();
    glPopMatrix();
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(2.1,1.5,1);
    glScalef(.3, .8, -0.01);
    drawCube();
    glPopMatrix();
}
void drawSofa() {
    // front sofa with coshion

    glColor3f(0.87, 0.56, 0.37);
    glPushMatrix();
    glTranslatef(8,-0.3,10);
    glRotatef(180, 0, 1, 0);     // sofa base
    glScalef(0.4, 0.25, 1.5);
    drawCube();
    glPopMatrix();

    glColor3f(0.7, 0.4, 0.1);
    glPushMatrix();
    glTranslatef(8,0.4,10);    // backrest
    glRotatef(180, 0, 1, 0);
    glScalef(0.1, 0.25, 1.5);
    drawCube();
    glPopMatrix();

    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
    glTranslatef(6.9, 0.25, 6);
    glScalef(0.25, 0.1, 0.6);          //cushion 1
    drawCube();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(6.9, 0.25, 8);
    glScalef(0.25, 0.1, 0.6);     //cushion 2
    drawCube();
    glPopMatrix();

  // front sofa with coshion end

  // side sofa with coshion start
    glColor3f(0.87, 0.56, 0.37);
    glPushMatrix();
    glTranslatef(6,-0.2,3);     // main
    glRotatef(270, 0, 1, 0);
    glScalef(0.4, 0.25, 1.5);
    drawCube();
    glPopMatrix();
    glColor3f(0.7, 0.4, 0.1);
    glPushMatrix();
    glTranslatef(6,0.4,3);
    glRotatef(270, 0, 1, 0);  // backrest
    glScalef(0.1, 0.25, 1.5);
    drawCube();
    glPopMatrix();

    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
    glTranslatef(3.7,0.35,3.25);   // cushion 1
    glRotatef(270, 0, 1, 0);
    glScalef(0.25, 0.1, 0.6);
    drawCube();
    glPopMatrix();

    glColor3f(0.9, 0.9, 0.9);  // cushion 2
    glPushMatrix();
    glTranslatef(5.7,0.35,3.25);
    glRotatef(270, 0, 1, 0);
    glScalef(0.25, 0.1, 0.6);
    drawCube();
    glPopMatrix();

    // side sofa with cushion end

}


void sofasidetable(){

    glColor3f(0.6, 0.27, 0.27);
    glPushMatrix();
    glTranslatef(-1,-0.8,1.9);
    glScalef(0.20, 0.15,.5);
    drawCube();
    glPopMatrix();




}
void Tea_table() {
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(5, 0.1, 10);
    glRotatef(180, 0, 1, 0);
    glScalef(0.25, 0.05, 0.5);
    drawCube();
    glPopMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glPushMatrix();
    glTranslatef(4.5, -0.8, 9);
    glRotatef(180, 0, 1, 0);
    glScalef(0.1, 0.25, 0.05);
    drawCube();
    glPopMatrix();
}
void fan()
{
    glPushMatrix();
    glTranslatef(3,4,8);
    //stand
    glColor3f(0.2,0.1,0.1);
    glPushMatrix();
    glTranslatef(0.1,0,0.09);
    glScalef(0.01,0.4,0.01);
    drawCube();
    glPopMatrix();

    //fan cube
    glColor3f(0.5,0.2,0.2);
    glPushMatrix();
    glScalef(0.1,0.05,0.1);
    glTranslatef(-1.5,-1.5,-1.5);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glRotatef(a, 0,1,0);
    glColor3f(0.8,0.6,0.4);
    glPushMatrix();
    glScalef(0.5,0.01,0.1);
    glTranslatef(-1.5,-1.5,-1.5);
    drawCube();
    glPopMatrix();

    glColor3f(0.8,0.6,0.4);
    glPushMatrix();
    glScalef(0.1,0.01,0.5);
    glTranslatef(-1.5,-1.5,-1.5);
    drawCube();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(60,1,1,100);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ,  refX,refY,refZ,  0,1,0);
    glViewport(0, 0, 1200, 1000);

     Wall();
     TV();
     Table();
     Picture();
     drawSofa();
     fan();
     Tea_table();
     Calender();
  //sofasidetable();
     glFlush();
     glutSwapBuffers();
}


int main (int argc, char **argv)
{

 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100,100);
 glutInitWindowSize(windowWidth, windowHeight);
 glutCreateWindow("C201095");
 glShadeModel( GL_SMOOTH );
 glEnable( GL_DEPTH_TEST );
 glutKeyboardFunc(myKeyboardFunc);
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
