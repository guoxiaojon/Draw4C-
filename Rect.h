#include"stdafx.h"
#include"Graph.h"
#pragma once
class Rect :public Graph
{
public:
	void draw(){
		glRectf(this->top, this->left, this->bottom, this->right);
		
	}
	 char* getName(){
		return "rect";
	}
	
	Rect(float top, float left, float bottom, float right) :Graph(top,left,bottom,right)
	{}
	~Rect(){}
	

};

