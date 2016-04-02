// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <GL/glut.h>
#include"Rect.h"
#include<iostream>
#include<string>
#include"DrawView.h"
#include<vector>
#include<string>
#include"MyList.h"
#include"Circle.h"
#include"FileUtils.h"

using namespace std;
float start_x;
float start_y;
float current_x;
float current_y;
bool left_down;
static char command = '2';
string a;
//int flag = -1;
Graph *p;
static MyList v;
bool flag = false;
void display()
{
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT, GL_LINE);
	glPolygonMode(GL_BACK, GL_LINE);
	glLineWidth(5.0f);
	glColor3f(0.0f, 1.0f, 1.0f);

	//cout << "command" << command;
	if (command == '1'){
		
		p = new Circle(start_x, start_y, current_x, current_y);
		p->draw();
	}
		
	if (command == '2'){
		
		p = new Rect(start_x, start_y, current_x, current_y);
		p->draw();
	}
	//移动
	if (command == '0' && p != NULL ){		
		p->move(current_x - start_x, current_y - start_y);		
	}
	
	//继续绘制
	if (command == '-' && p !=NULL){
		p->top = start_x;
		p->left = start_y;
		p->bottom = current_x;
		p->right = current_y;
	}
	
	if (v.size() > 0){
		for (int i = 0; i < v.size(); i++){
			Graph* tp = v.get(i);
			tp->draw();
		}
	}

	
	

	glFlush();

	
}

float screen2worldX(float a){
	float x = (350.f - a) / 350.0f * (-1.0f);
	return x;
}

float screen2worldY(float a){
	float y = (250.0f - a) / 250.0f * (1.0f);
	return y;
}

void mouseCallBack(int button, int state, int x, int y){
	
	if (button == GLUT_LEFT_BUTTON){
		left_down = true;
		if (state == GLUT_DOWN){
			start_x = screen2worldX(x);
			start_y = screen2worldY(y);
			//‘0’移动 ‘-’继续绘制
			if (command == '0'){
				for (int i = 0; i < v.size(); i++){
					p = v.get(i);
					//寻找选中的图形
					if (p->selected(start_x, start_y)){
						//v.swapwith_0(i);
						flag = true;		
						break;
					}
				}
				if (!flag){
					p = NULL;
					cout << "没图形\n";
					return;
				}
			}

			if (command == '-'){
				for (int i = 0; i < v.size(); i++){
					p = v.get(i);
					//寻找选中的图形
					if (p->selected(start_x, start_y)){
						
						flag = true;

						break;
					}
				}
				if (!flag){
					p = NULL;
					return;
				}
				if (start_x < (p->top + p->bottom)/2){
					start_x = p->bottom;
					if (start_y > (p->left + p->right) / 2){
						start_y = p->right;
					}
					else
					{
						start_y = p->left;
					}
				}
				else
				{
					start_x = p->top;
					if (start_y > (p->left + p->right) / 2){
						start_y = p->right;
					}
					else
					{
						start_y = p->left;
					}
				}
			
			}
		}
		if (state == GLUT_UP){
			
			if (command == '0' || command == '-'){
				p = NULL;
				flag = false;
				
			}
			else{
				v.add(p);
			}
				
		}
		
	}

}


void mouseMoveCB(int x, int y){
	
	if (left_down){
		current_x = screen2worldX(x);
		current_y = screen2worldY(y);
		display();

		if (command == '0'){
			start_x = current_x;
			start_y = current_y;
		}
		
	}
}

void keyboard(unsigned char key, int x, int y){
	command = key;
	//save
	if (command == '['){
		cout << "ketkeykey";
		FileUtils::write2File(&v);
		
	}
	//open
	if (command == ']'){
		v = *FileUtils::readFromFile();
		display();
	}
}


int _tmain(int argc, _TCHAR* argv[])
{

	new DrawView(argc, argv,mouseCallBack,mouseMoveCB,display,keyboard);

	return 0;
}

