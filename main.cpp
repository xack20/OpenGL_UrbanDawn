#include<windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)  // 3.1415926535897932




void init(void)
{
    glClearColor(240.0/255.0, 230.0/255.0, 65.0/255.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100, 0,100);
}





void drawShapes(void)
{
    glClear(GL_COLOR_BUFFER_BIT);




    /** Sky Color Shading **/

    double R = 244,
           G = 225,
           B = 60 ;
    for(double i = 0 ; i <= 100 ; i+=.01)
    {
        if(i>50){
            R-=(244-225)/5000.0;
            G-=(225-88)/5000.0;
            B+=(95-60)/5000.0;
        }
        glColor3f( R /255.0, G /255.0, B /255.0);
        glBegin(GL_LINES);
        glVertex2d(0,i);
        glVertex2d(100,i);
        glEnd();
    }





    double x =0, y = 40;

    /**            Sun            **/

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    for(int i =0 ; i < 360 ; i ++)glVertex2d( 50 +( cos(i*(PI/180.0))*15 ), 50+( sin(i*(PI/180.0))*15 ) );
    glEnd();







    /**     Buildings       **/

    double rect[9][9][2] =
    {
        {{0,0}, {18,0}, {18,-40}, {0,-40}}
        , {{2,0}, {16,0}, {16,5}, {2,5}}
        , {{18,-40}, {18,8}, {26,8},{26,-40}}
        , {{26,-40},{26,-21}, {36,-21}, {36,-40}}
        , {{36,-40},{36,0}, {50,0}, {50,-40}}
        , {{50,-40},{50,10}, {60,10}, {60,-40}}
        , {{64,-40}, {64,0}, {76,0}, {76,-40}}
        , {{80,-40}, {80,20}, {100,20}, {100,-40}}
        , {{84,20}, {96,20}, {96,36}, {84,36}}
    } ;
    double tmb[9][2] = {{4,5}, {4.09,11.87}, {5.26,14.19}, {7,16.31}, {9.17,17.74}, {11.66,16.15}, {13.14,14.09}, {14.14,11.81}, {14.14,5}};


    for(int i = 0 ; i < 9 ; i ++)
    {




        if(i!=1 && i!=8)
        {
            glColor3f(0,2/255.0,30/255.0);
            double mxx=-1,mxy=-1,mnx=200,mny=200;
            glBegin(GL_LINE_LOOP);
            for(int j = 0 ; j < 4 ; j++)
            {
                glVertex2d(rect[i][j][0]+x,rect[i][j][1]+y);
                mxx = max(mxx,rect[i][j][0]+x);
                mnx = min(mnx,rect[i][j][0]+x);
                mxy = max(mxy,rect[i][j][1]+y);
                mny = min(mny,rect[i][j][1]+y);
            }
            glEnd() ;


            double R = 0.0, // 2
                   G = 2.0, // 30
                   B = 30.0 ; // 95
            for(double i = mxy ; i >= mny ; i-=.01)
            {
                R+=((2-0)/((mxy-mny)/.01));
                G+=((30-2)/((mxy-mny)/.01));
                B+=((95-30)/((mxy-mny)/.01));

                glColor3f( R /255.0, G /255.0, B /255.0);
                glBegin(GL_LINES);
                glVertex2d(mnx,i);
                glVertex2d(mxx,i);
                glEnd();
            }
        }
        else
        {
            glColor3f(0,2/255.0,30/255.0);
            glBegin(GL_POLYGON);
            for(int j = 0 ; j < 4 ; j++)glVertex2d(rect[i][j][0]+x,rect[i][j][1]+y);
            glEnd() ;
        }
    }
    glColor3f(0,2/255.0,30/255.0);
    glBegin(GL_POLYGON);
    for(int j = 0 ; j < 9 ; j++)glVertex2d(tmb[j][0]+x,tmb[j][1]+y);
    glEnd() ;


    glBegin(GL_LINES);
    glVertex2d(9.17+x,17.74+y);
    glVertex2d(9.17+x,17.74+y+7);

    glVertex2d(85,36+y);
    glVertex2d(85,36+y+7);

    glVertex2d(95,36+y);
    glVertex2d(95,36+y+7);
    glEnd();




    /**      Birds         **/



    double bird[2][12][2] =
    {
        {{0,0}, {3.86,0.3}, {7.99,1.56}, {12.31,0.64}, {7.1,-1.62}, {2.21,-1.97}, {-2.48,-3.6}, {-2.74,1.62}, {-4.55,5.71},{-4.32,10.88}, {-1.8,7.05}, {-1.06,3.61}},
        {{2,1.5}, {1.39,1.19}, {0.95,0.07}, {0.95,0.07},{0,0},{0,0},{0,0},{0,0}, {0.21,1.29}, {0.88,1.69}, {1.41,1.93}, {2.16,1.96}}
    };





    glColor3f(0,0,0);
    for(int i = 0 ; i < 2 ; i ++)
    {
        glBegin(GL_POLYGON);
        for(int j = 0 ; j < 12 ; j ++)glVertex2d( (bird[i][j][0]+375)*0.2, (bird[i][j][1]+375)*0.2 );
        glEnd();
    }

    glColor3f(0,0,0);
    for(int i = 0 ; i < 2 ; i ++)
    {
        glBegin(GL_POLYGON);
        for(int j = 0 ; j < 12 ; j ++)glVertex2d( (bird[i][j][0]+330)*0.2, (bird[i][j][1]+360)*0.2 );
        glEnd();
    }

    glColor3f(0,0,0);
    for(int i = 0 ; i < 2 ; i ++)
    {
        glBegin(GL_POLYGON);
        for(int j = 0 ; j < 12 ; j ++)glVertex2d( (bird[i][j][0]+310)*0.2, (bird[i][j][1]+400)*0.2 );
        glEnd();
    }



    /**        Windows        **/
    glColor3f(0,0,0);
    double win[37][2] =
    {
        {88.92,31.81}, {93.63,14.15}, {84.55,14.35}, {93.36,2.5}, {84.53,2.33}, {93.36,-9.63}, {84.53,-9.54}, {93.47,-20}, {85,-20}, {93.6,-30.06}, {85,-30}, {67.88,-29.42}, {68.01,-18.45}, {67.76,-5.88}, {55.15,-29.45}, {54.96,-18.2}, {55.19,-5.88}, {55.19,3.98}, {41.93,-6.17}, {41.93,-17.81}, {41.93,-28.27}, {29.64,-32.37}, {29.76,-23.72}, {21.27,-31.44}, {21.19,-18.94}, {21.19,-6.98}, {21.19,4.15}, {12.1,-32.84}, {2,-24.98}, {12.15,-25}, {1.93,-32.93}, {12,-10}, {2,-10}, {12,6}, {4,6}, {12,-4}, {2,-4}
    };
    for(int i = 0 ; i < 37 ; i ++)
    {
        glBegin(GL_POLYGON);
        glVertex2d(win[i][0],win[i][1]+40);
        glVertex2d(win[i][0]+2,win[i][1]+40);
        glVertex2d(win[i][0]+2,win[i][1]+42);
        glVertex2d(win[i][0],win[i][1]+42);
        glEnd();
    }


    glFlush();

}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutInitWindowPosition(400, 50);
    glutInitWindowSize(650,650);
    glutCreateWindow("171-15-9556");

    init();
    glutDisplayFunc(drawShapes);
    glutMainLoop();

    return 0;
}
