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
		glutCreateWindow("��ͼ����1��.Բ����2��.������0��.�ƶ�����-��.�������ƣ���[�����棬��]����");
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