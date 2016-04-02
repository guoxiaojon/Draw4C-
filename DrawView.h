#include "stdafx.h"
#include <GL/glut.h>
#include"Rect.h"
#include<iostream>



int FULL_LINE = GL_LINE;
class DrawView
{
public:
	
	
	DrawView(int argc, _TCHAR* argv[],void(*callback)(int, int, int, int), void(*moveCB)(int, int),void(*display)(void),void(*keyboard)(unsigned char,int,int)){
		glutInit(&argc, (char**)argv);
		glutInitWindowPosition(200, 100);
		glutInitWindowSize(700, 500);
		glutCreateWindow("画图：‘1’.圆，‘2’.方，‘0’.移动，‘-’.继续绘制，‘[’保存，‘]’打开");
		glutDisplayFunc(display);
		//glutMouseFunc(mouseCallBack);
		glutMouseFunc(callback);
		//glutMotionFunc(mouseMoveCB);
		glutMotionFunc(moveCB);
		
		glutKeyboardFunc(keyboard);
		glutMainLoop();
	}
	~DrawView(){}



	
};