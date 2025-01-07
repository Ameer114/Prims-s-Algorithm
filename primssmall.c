#include<stdio.h>
int graph[10][10],visited[10],n,cost;

void prim(int c){
	int i,j;
	int min=999, adj_vertex=999, src;
	visited[c]=1;
	
	for(i=0;i<n;i++){
		if(visited[i]){
			for(j=0;j<n;j++){
				if(graph[i][j]&&!visited[j]){
					if(graph[i][j]<min){
						src=i;
						min=graph[i][j];
						adj_vertex=j;
					}
				}
			}
		}
	}

	if(adj_vertex!=999){
			printf("\n %d - %d cost: %d",src+1,adj_vertex+1,graph[src][adj_vertex]);
			cost=cost+graph[src][adj_vertex];
			prim(adj_vertex);
	}	
	return;
}


void main(){
	int i,j;
	printf("enter size of graph: ");
	scanf("%d",&n);
	printf("enter graph matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	prim(0);
	printf("\n total cost : %d",cost);
}
