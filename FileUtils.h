#include<iostream>
#include<fstream>
#include"MyList.h"
using namespace std;
//extern MyList v;
class FileUtils{
public:
	static void write2File(MyList *v){
		ofstream ofile;
		ofile.open("E:\\graph.txt");
		char* s1;
		Graph* Gp;
		cout << "Sssssssssssssssssssss\n";
		for (int i = 0; i < v->size()-1; i++){
			Gp = v->get(i);
			s1 = Gp->getName();
			if (ofile.is_open()){
				cout << "iiiiiiiiiiiiiiiiiiiiis\n";
				ofile << s1 <<"@"<< Gp->top<<"@" << Gp->left <<"@"<< Gp->bottom<<"@" << Gp->right << "#";
				ofile << '%';
			}

		}
		Gp = v->get(v->size()-1);
		s1 = Gp->getName();
		if (ofile.is_open()){
			cout << "iiiiiiiiiiiiiiiiiiiiis\n";
			ofile << s1 << "@" << Gp->top << "@" << Gp->left << "@" << Gp->bottom << "@" << Gp->right << "#";
			ofile << '&';
		}
		
		ofile.close();
		
	}

	static MyList* readFromFile(){
		MyList *Lp = new MyList();
		ifstream ifile;
		Graph *p;
		char ch[1024];
		string ch_s="";
		string buf_name;
		string buf_left;
		string buf_top;
		string buf_right;
		string buf_bottom;
		string temp;
		int i = 0;
		int index=-1, start=0;
		ifile.open("E:\\graph.txt");

		do{
			i = 0;
			while (ifile.get(ch[i])){
				if (ch[i] == '#')
					break;
				i++;
			}

			for (int x = 0; x <= i; x++){
				ch_s += ch[x];
			}
			
			//找名字
			start = index + 1;
			index = ch_s.find('@',start);
			buf_name = ch_s.substr(start, index-start);
			//找第一个坐标
			start = index + 1;
			index = ch_s.find('@', start);
			buf_top = ch_s.substr(start, index - start);
			//找第二个坐标
			start = index + 1;
			index = ch_s.find('@', start);
			buf_left = ch_s.substr(start, index - start);
			//第三个坐标
			start = index + 1;
			index = ch_s.find('@', start);
			buf_bottom = ch_s.substr(start, index - start);
			//第四个坐标
			start = index + 1;
			index = ch_s.find('#', start);
			buf_right = ch_s.substr(start, index - start);


			if (buf_name == "rect"){
				p = new Rect(atof(buf_top.c_str()), atof(buf_left.c_str()), atof(buf_bottom.c_str()), atof(buf_right.c_str()));
				Lp->add(p);
			}
			if (buf_name == "circle"){
				p = new Circle(atof(buf_top.c_str()), atof(buf_left.c_str()), atof(buf_bottom.c_str()), atof(buf_right.c_str()));
				Lp->add(p);
			}
				

			cout << "读了这些字符：" << i << ch_s << "sss" << "\n";
			cout << "名字为：" << buf_name << "\n";
			cout << "top 为：" << buf_top << "\n";
			cout << "left 为：" << buf_left << "\n";
			cout << "bottom 为：" << buf_bottom << "\n";
			cout << "right 为：" << buf_right << "\n";


			ifile.get(ch[i + 1]);
			cout << "get::" << ch[i + 1]<<"\n";
			

			
		} while (ch[i+1] != '&');
		
		
		return Lp;
	}
};
