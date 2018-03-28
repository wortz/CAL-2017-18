#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
	//1.a)
	GraphViewer *gv = new GraphViewer(600, 600, true);
	//gv->setBackground("background.jpg"); //from 1.b)
	gv->createWindow(600, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	//1.b)
	gv->addNode(0);
	gv->addNode(1);
	gv->addEdge(0,0,1,EdgeType::UNDIRECTED);
	gv->removeNode(1);
	gv->addNode(2);
	gv->addEdge(1,0,2,EdgeType::UNDIRECTED);
	gv->setVertexLabel(2,"Cona");
	gv->setEdgeLabel(1,"Pénis");
	gv->setVertexLabel(0,"Testículos");
	gv->setVertexColor(2,"green");
	gv->setEdgeColor(1,"yellow");


}

void exercicio2()
{
	//2.a)
	GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);
	gv->addNode(0,300,50);
	gv->addNode(1,318,58);
	gv->addNode(2,325,75);
	gv->addNode(3,318,93);
	gv->addNode(4,300,100);
	gv->addNode(5,282,93);
	gv->addNode(6,275,75);
	gv->addNode(7,282,58);
	gv->addNode(8,150,200);
	gv->addNode(9,300,200);
	gv->addNode(10,450,200);
	gv->addNode(11,300,400);
	gv->addNode(12,200,550);
	gv->addNode(13,400,550);
	//2.b)
	gv->addEdge(0,0,1,EdgeType::UNDIRECTED);
	gv->addEdge(1,1,2,EdgeType::UNDIRECTED);
	gv->addEdge(2,2,3,EdgeType::UNDIRECTED);
	gv->addEdge(3,3,4,EdgeType::UNDIRECTED);
	gv->addEdge(4,4,5,EdgeType::UNDIRECTED);
	gv->addEdge(5,5,6,EdgeType::UNDIRECTED);
	gv->addEdge(6,6,7,EdgeType::UNDIRECTED);
	gv->addEdge(7,7,0,EdgeType::UNDIRECTED);
	gv->addEdge(8,4,9,EdgeType::UNDIRECTED);
	gv->addEdge(9,9,8,EdgeType::UNDIRECTED);
	gv->addEdge(10,9,10,EdgeType::UNDIRECTED);
	gv->addEdge(11,9,11,EdgeType::UNDIRECTED);
	gv->addEdge(12,11,12,EdgeType::UNDIRECTED);
	gv->addEdge(13,11,13,EdgeType::UNDIRECTED);
	//2.c)
	while(true){
	Sleep(500);
	gv->removeNode(12);
	gv->removeNode(13);
	gv->addNode(14,250,550);
	gv->addNode(15,350,550);
	gv->addEdge(14,11,14,EdgeType::UNDIRECTED);
	gv->addEdge(15,11,15,EdgeType::UNDIRECTED);
	Sleep(500);
	gv->removeNode(14);
	gv->removeNode(15);
	gv->addNode(16,300,550);
	gv->addNode(17,300,550);
	gv->addEdge(16,11,16,EdgeType::UNDIRECTED);
	gv->addEdge(17,11,17,EdgeType::UNDIRECTED);
	Sleep(500);
	gv->removeNode(16);
	gv->removeNode(17);
	gv->addNode(12,200,550);
	gv->addNode(13,400,550);
	gv->addEdge(12,11,12,EdgeType::UNDIRECTED);
	gv->addEdge(13,11,13,EdgeType::UNDIRECTED);
	}
}

void exercicio3()
{
	GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(600, 600);
	ifstream file;
	stringstream ss;
	string line;
	char crab;
	int n;//id
	int x;//x coord in nodes , in edges id of first node
	int y;//y coord in nodes , in edges id of second node
	file.open("nos.txt");
	if (file.is_open())
	  {
	    while ( getline (file,line) )
	    {
	    	stringstream ss(line);
	    	ss >> n >> crab >> x >> crab >> y;
	    	gv->addNode(n,x,y);
	    }
	    file.close();
	  }

	  else cout << "Unable to open nos.txt file";

	file.open("arestas.txt");
	if (file.is_open())
		  {
		    while ( getline (file,line) )
		    {
		    	stringstream ss(line);
		    	ss >> n >> crab >> x >> crab >> y;
		    	gv->addEdge(n,x,y,EdgeType::UNDIRECTED);		    }
		    file.close();
		  }

		  else cout << "Unable to open arestas.txt file";
}

int main() {
	//exercicio1();
	//exercicio2();
	exercicio3();
	getchar();
	return 0;
}
