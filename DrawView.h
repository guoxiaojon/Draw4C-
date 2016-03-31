#include "stdafx.h"
#include <GL/glut.h>
#include"Rect.h"
#include<iostream>



int FULL_LINE = GL_LINE;
class DrawView
{
public:
	DrawView(){

	}
	~DrawView(){}
	void drawCircle(float x1, float y1, float x2, float y2){
		float r = abs(x1 - x2);
		float x = (x1 + x2) / 2;
		float y = (y1 + y2) / 2;
		int i;
		int n = 1000;
		float Pi = 3.14159265f;
		
		glBegin(GL_LINE_LOOP);
		for (i = 0; i < n; ++i)
			glVertex2f(x + r*cos(2 * Pi / n*i), y + r*sin(2 * Pi / n*i));
		glEnd();


	}
	

private:
	void baseDraw(){
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glPolygonMode(GL_FRONT, FULL_LINE);
		glPolygonMode(GL_BACK, FULL_LINE);
		glLineWidth(5.0f);
		glColor3f(0.0f, 1.0f, 1.0f);
		glRectf(-0.9f, 0.9f, -0.8f, 0.8f);


	}
};