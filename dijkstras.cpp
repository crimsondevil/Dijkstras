#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MXSZ 200
#define MAX 40000

int size, mat[MXSZ][MXSZ], start=0;
int path[MXSZ], flag, pathArr[MXSZ][MXSZ], flag1;

void fileread();
void dijkstra(int[MXSZ][MXSZ]);
int minDist(int[], bool[]);
void display(int[], int[]);
void mpt(int[], int);

int main(){
    fileread();
    cout<<"Routing Table of node "<<start<<endl;
    dijkstra(mat);
    return 0;
}

void fileread(){
    string myText, myTextArr[MAX], sz, s, de, di, data;
    int i=0,a=0,b=0,c=0,m=0,n=0,p=0, flag=0, src[MAX], dest[MAX], dist[MAX];

    ifstream MyReadFile("Adj.txt");
    while (getline (MyReadFile, myText)) {
        myTextArr[i++]=myText;
        flag++;
    }
    MyReadFile.close();

    sz=myTextArr[0];
    stringstream s1(sz);
    s1 >> size;

    for(i=1;i<flag;i++){
        int pos=myTextArr[i].find(" ");
        s=myTextArr[i].substr(0,(pos));
        data=myTextArr[i].substr(pos+1);

        int pos1=data.find(" ");
        de=data.substr(0,(pos1));
        di=data.substr(pos1+1);

        stringstream s2(s);
        s2 >> src[a++];

        stringstream d1(de);
        d1 >> dest[b++];

        stringstream d2(di);
        d2 >> dist[c++];
    }

    for(m=0;m<size;m++){
        for(n=0;n<size;n++){
            if(m==n){
                mat[m][n]=0;
                continue;
            }
            else{
                while(p<flag-1){
                    if((src[p]==m)&&(dest[p]==n)){
                        mat[m][n]=dist[p];
                        p++;
                        break;
                    }
                    else{
                        mat[m][n]=0;
                        break;
                    }
                }
            }
        }
    }
}

void dijkstra(int adj[MXSZ][MXSZ]){
    int cost[size];
    bool counter[size];
    int parent[size];

    for (int i=0;i<size;i++){
		parent[0]=-1;
		cost[i]=MAX;
		counter[i]=false;
	}

    cost[start]=0;

    for (int count=0;count<size-1;count++){
        int u=minDist(cost, counter);
        counter[u]=true;

        for (int v=0;v<size;v++){
            if ((!counter[v])&&adj[u][v]&&(cost[u] + adj[u][v] < cost[v])){
                parent[v]=u;
				cost[v]=cost[u]+adj[u][v];
			}
        }
    }

    display(cost, parent);
}

int minDist(int dst[], bool ctr[]){
    int min=MAX;
    int min_index;

	for (int v=0;v<size;v++){
        if ((ctr[v]==false)&&(dst[v]<=min)){
            min=dst[v];
            min_index=v;
        }
    }

	return min_index;
}

void display(int cost[], int parent[]){
    cout<<"Destination\tCost\tNext Hop";
	for (int i = 1; i < size; i++)
	{
		cout<<endl<<"\t"<<i<<"\t"<<cost[i];
        flag=1;
		mpt(parent, i);
        cout<<"\t"<<path[1];
        for (int y=0;y<flag;y++){
            pathArr[flag1][y]=path[y];
        }
        flag1++;
	}
    cout<<endl<<endl<<"Minimum Path Tree: (from 0 to each node, sequenced numerically)"<<endl;
    for(int p=0;p<flag1;p++){
        cout<<pathArr[p][0];
        for(int q=1;q<size;q++){
            if(pathArr[p][q]==0)
                continue;
            cout<<" "<<pathArr[p][q];
        }
        cout<<endl;
    }
}

void mpt(int parent[], int j){
    if (parent[j] == - 1)
		return;

	mpt(parent, parent[j]);
    path[0]=0;
    path[flag++]=j;
}
