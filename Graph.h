
#include"stdafx.h"
#include<GL\glut.h>
#include<math.h>
#pragma once

class Graph{
public:
	float top;
	float left;
	float bottom;
	float right;


	Graph(float top, float left, float bottom, float right){
		this->top = top;
		this->bottom = bottom;
		this->left = left;
		this->right = right;

	}
	Graph(){}
	
	~Graph(){}
	virtual void draw(){
		printf("ffffffffffffffffff\n");
	}
	virtual char* getName(){
		return "graph";
	}
	void move(float distance_x, float distance_y){
		this->left += distance_y;
		this->right += distance_y;
		this->top += distance_x;
		this->bottom += distance_x;
	}
	Graph* selected(float x, float y){
		float mid_x = (this->top + this->bottom)/2;
		float len_x = abs(this->top - this->bottom);

		float mid_y = (this->left + this->right) / 2;
		float len_y = abs(this->left - this->right);

		if (mid_x - len_x/2 < x && x < mid_x + len_x/2 && y < mid_y + len_y/2 && mid_y - len_y/2 < y){
			printf("ÕÒµ½\n");
			return this;
		}
		else
		{
			printf( "Ã»ÕÒµ½\n");
			return NULL;
		}
	}


};

