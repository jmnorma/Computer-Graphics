#include<GL/glut.h>
#include<GL/gl.h> 
#include<math.h>
#define PI 3.14159265
#include<iostream>
using namespace std;
int x,y,z;
double sine(double x)
{
	x=x*3.14;
	x=x/180;
	return sin(x);
}
//Function for cosine
double cosine(double x)
{
	x=x*3.14;
	x=x/180;
	return cos(x);
}
double arctan(double slope)
{
	double theta;
	//Arc tan code for converting slope to angle of slope to rotate parallel to axis
	theta=atan(slope);
	theta=theta*180;
	theta=theta/PI;
	return theta;
}
void init()
{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(1.0, 0.0, 0.0, 1.0);
    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, 		Max Height)
    gluOrtho2D(0.0, 700, 0.0, 700);
}
void display()
{
	glClear( GL_COLOR_BUFFER_BIT );
	glColor3f(1, 1, 1);
	////////////////////////
	double flag,tx,ty,tz,S,theta,sxy,sxz,syx,syz,szx,szy,x1,y1,z1,m,c,A,B,C;
	int ch;
	flag=0;
	glBegin(GL_POINTS);
	glVertex3f(x,y,z);
	glEnd();
	glFlush();
///////////////////////////////////////
	cout<<"1) Translation"<<endl;
	cout<<"2) Rotation about X Axis"<<endl;
	cout<<"3) Rotation about Y Axis"<<endl;
	cout<<"4) Rotation about Z Axis"<<endl;
	cout<<"5) Scaling"<<endl;
	cout<<"6) Reflection about XY axis"<<endl;
	cout<<"7) Reflection about YZ axis"<<endl;
	cout<<"8) Reflection about ZX axis"<<endl;
	//9 and 10th can only be done on 2D transformation and not on 3D and it is thus only done on X,Y co-ordinates
	cout<<"9) Reflection about Line y=mx+c"<<endl;
	cout<<"10) Reflection about Line ax + by + c = 0"<<endl;
	cout<<"11) Shear about edge"<<endl;
	cout<<"12) Shear about vertex"<<endl;
	cout<<"13) Exit"<<endl;
	cout<<"\n"<<endl;
	cout<<"Enter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Translation of point"<<endl;
			cout<<"Enter the translation factors"<<endl;
			cin>>tx>>ty>>tz;
			x=x+tx;
			y=y+ty;
			z=z+tz;
			break;
		case 2:
			cout<<"Rotation About X axis"<<endl;
			cout<<"Enter Rotation Angle: ";
			cin>>theta;
			y = y*cosine(theta) - z*sine(theta);
			z = z*cosine(theta) + y*sine(theta);
			break;
		case 3:
			cout<<"Rotation About Y axis"<<endl;
			cout<<"Enter Rotation Angle: ";
			cin>>theta;
			z = z*cosine(theta) - x*sine(theta);
			x = x*cosine(theta) + z*sine(theta);
			break;
		case 4:
			cout<<"Rotation About Z axis"<<endl;
			cout<<"Enter Rotation Angle: ";
			cin>>theta;
			x = x*cosine(theta) - y*sine(theta);
			y = y*cosine(theta) + x*sine(theta);
			break;
		case 5:
			cout<<"Scaling of point"<<endl;
			cout<<"Enter the scaling factor: ";
			cin>>S;
			x=x*S;
			y=y*S;
			z=z*S;
			break;
		case 6:
			cout<<"Reflection about XY Plane"<<endl;
			z=z*(-1);
			break;
		case 7:
			cout<<"Reflection about YZ Plane"<<endl;
			x=x*(-1);
			break;
		case 8:
			cout<<"Reflection about ZX Plane"<<endl;
			y=y*(-1);
			break;
		case 9:
			cout<<"Reflection about line y=mx+c"<<endl;
			cout<<"Define line in terms of Y=mX+c form"<<endl;
			cout<<"Enter slope: ";
			cin>>m;
			cout<<"Enter Intercept: ";
			cin>>c;
			//Doing reflection about X axis
			//Pass through origin
			y=y-c;
			theta=arctan(m);
			//Clockwise rotation wrt X axis -> sin --- (-sin)
			x=x*cosine(theta)+y*sine(theta);
			y=y*cosine(theta)-x*sine(theta);
			//Reflection---> y=-y
			y=y*(-1);
			//Anti clockwise rotation
			x=x*cosine(theta)-y*sine(theta);
			y=x*sine(theta)+y*cosine(theta);
			//Inverse Translate
			y=y+c;
			break;
		case 10:
			cout<<"Reflection about line ax+by+c"<<endl;
			//converting to form y=-a/b*x -c/b
			cout<<"Enter a: ";
			cin>>A;
			cout<<"Enter b: ";
			cin>>B;
			cout<<"Enter c: ";
			cin>>C;
			m=A/B;
			m=m*(-1);
			c=C/B;
			c=c*(-1);  
			////
			y=y-c;
			x=x*cosine(theta)+y*sine(theta);
			y=y*cosine(theta)-x*sine(theta);
			//Reflection---> y=-y
			y=y*(-1);
			//Anti clockwise rotation
			x=x*cosine(theta)-y*sine(theta);
			y=x*sine(theta)+y*cosine(theta);
			//Inverse Translate
			y=y+c;
			////
			break;
		case 11:
			cout<<"Shear about Edge\n";
			cout<<"X shear wrt Y [0,1]: ";
			cin>>sxy;
			cout<<"Shear about Edge\n";
			cout<<"X shear wrt Z [0,1]: ";
			cin>>sxz;
			cout<<"Shear about Edge\n";
			cout<<"Y shear wrt X [0,1]: ";
			cin>>syx;
			cout<<"Shear about Edge\n";
			cout<<"Y shear wrt Z [0,1]: ";
			cin>>syz;
			cout<<"Shear about Edge\n";
			cout<<"Z shear wrt X [0,1]: ";
			cin>>szx;
			cout<<"Shear about Edge\n";
			cout<<"Z shear wrt Y [0,1]: ";
			cin>>szy;
			x=x+(y*sxy)+(z*sxz);
			y=y+(x*syx)+(z*syz);
			z=z+(x*szx)+(y*szy);
			break;	
		case 12:
			cout<<"Shear about Vertex\n";
			cout<<"Enter the pivot point (x,y,z): ";
			cin>>x1>>y1>>z1;
			x=x-x1;
			y=y-y1;
			z=z-z1;
			cout<<"X shear wrt Y [0,1]: ";
			cin>>sxy;
			cout<<"Shear about Edge\n";
			cout<<"X shear wrt Z [0,1]: ";
			cin>>sxz;
			cout<<"Shear about Edge\n";
			cout<<"Y shear wrt X [0,1]: ";
			cin>>syx;
			cout<<"Shear about Edge\n";
			cout<<"Y shear wrt Z [0,1]: ";
			cin>>syz;
			cout<<"Shear about Edge\n";
			cout<<"Z shear wrt X [0,1]: ";
			cin>>szx;
			cout<<"Shear about Edge\n";
			cout<<"Z shear wrt Y [0,1]: ";
			x=x+(y*sxy)+(z*sxz);
			y=y+(x*syx)+(z*syz);
			z=z+(x*szx)+(y*szy);
			x=x+x1;
			y=y+y1;
			z=z+z1;
			break;
		case 13: cout<<"Exiting the code";
			flag=1;
			break;							
		default: cout<<"Wrong choice entered"<<endl;			
	}
	glColor3f(0,0,0);
	glBegin(GL_POINTS);
	glVertex3f(x,y,z);
	glEnd();
	glFlush();
///////////////////////////////////////
}
int main(int argc, char**argv) 
{
cout<<"3D Transformation"<<endl;
	cout<<"Enter Point (x,y,z): ";
	cin>>x>>y>>z;
    glutInit(&argc, argv); 
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); 
    glutInitWindowSize( 700,700 ); 
    glutCreateWindow("3D Transformation"); 
    init(); //Important to initialize 
    glutDisplayFunc(display); 
    glutMainLoop();  //See screen for long time similar to getch
}

