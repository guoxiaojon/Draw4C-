#include"Graph.h"
#include<math.h>
#include<GL\glut.h>
class Circle :public Graph{

public:
	void draw(){
		float r = abs(this->top - this->bottom);
		float x = (this->top + this->bottom) / 2;
		float y = (this->left + this->right) / 2;
		int n = 1000;
		float Pi = 3.14159265f;
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT);Çå¿Õ»­±Ê
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_LINE);
		glLineWidth(5.0f);
		glColor3f(0.0f, 1.0f, 1.0f);
		
		glBegin(GL_POLYGON);
		for (int i = 0; i < n; i++)
			glVertex2f(x + r*cos(2 * Pi / n*i), y + r*sin(2 * Pi / n*i));
		glEnd();
		x = 0;
		y = 0;

	}
	char* getName(){
		return "circle";
	}

	Circle(float top, float left, float bottom, float right) :Graph(top, left, bottom, right)
	{}
	~Circle(){}

};