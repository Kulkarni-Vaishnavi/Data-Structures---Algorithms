#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;

class Edge{

    public :
    int destinationID;
    int weight;

    Edge();
    Edge(int num1,int num2);
    int getdestinationID();
    int getWeight();
    void setWeight(int num);
};

void Edge :: setWeight(int num){
    this->weight = num;
}

Edge :: Edge(){

}

Edge :: Edge(int num1,int num2){
    this->destinationID = num1;
    this->weight = num2;
}

int Edge :: getdestinationID(){
    return this->destinationID;
}

int Edge :: getWeight(){
    return this->weight;
}

class Vertex{

    public :
    int sourceID;
    int flag;
    string placeName;
    list <Edge> edgeList;

    Vertex();
    Vertex(int num1,string str1);
    int getSourceID();
    void setSourceID(int num);
    string getPlaceName();
    void setPlaceName(string str);
    list <Edge> getEdgeList();
    void printEdgeList(vector <Vertex> :: iterator iter);
};

Vertex ::Vertex(){
    this->flag = -1;
}

Vertex :: Vertex(int num1,string str1){
    this->sourceID = num1;
    this->placeName = str1;
    this->flag = -1;
    // 0 for present in Queue and 1 for visisted and popped out and -1 for 
    // not visisted in queue
}

int Vertex :: getSourceID(){
    return this->sourceID;
}

string Vertex :: getPlaceName(){
    return this->placeName;
}

list <Edge> Vertex :: getEdgeList(){
    return this->edgeList;
}

void Vertex :: setSourceID(int num){
    this->sourceID = num;
}

void Vertex :: setPlaceName(string str){
    this->placeName = str;
}

class Graph{

    public :

    vector <Vertex> vertices;
    void addVertex(int num,string str);
    int checkNoSameVertex(int num);
    void addEdge(int num1,int num2,int num3);
    int checkIfEdgeExist(int num1,int num2);
    int checkIfVertexExist(int num);
    void printGraph();
    void updateVertex(int num,string str);
    void checkIfNeighbour(int num1,int num2);
    void deleteEdge(int num1,int num2);
    void updateEdge(int num1,int num2,int num3);
    void printNeighbours(int num);
    void deleteVertex(int num);
    void BFSTraversal(int num);
    void DFSTraversal(int num);
    void detectCycleInUndirected();
    void detectCycleInDirected();
    
};

void Graph :: detectCycleInUndirected(){

    int visited[50];
    int num;
    num = vertices.at(0).sourceID;

    for(int i = 0;i <50;i++){
        visited[i+1] = -1;
    }

    queue <int> bfsList;
    bfsList.push(num);
    visited[num] = 0;

    while(!bfsList.empty()){
        int node = bfsList.front();
        bfsList.pop();
        visited[node] = 1;
        for(int i = 0;i<vertices.size();i++){
            if(node == vertices.at(i).sourceID){
                auto it = vertices.at(i).edgeList.begin();
                for(it;it!=vertices.at(i).edgeList.end();it++){
                    if(visited[it->destinationID] == -1){
                        visited[it->destinationID] = 0;
                        bfsList.push(it->destinationID);
                    }

                    else if(visited[it->destinationID] == 0){
                        cout<<"The graph has a cycle in it"<<endl;
                        return;
                    }
                }
            }
        }
    }

    cout<<"The graph dont have a cycle in it"<<endl;
}

void Graph :: BFSTraversal(int num){
    int noOfVertices = vertices.size();
    int visited[50];

    for(int i = 0;i <50;i++){
        visited[i+1] = 0;
    }

    queue <int> bfsList;
    cout<<num<<" ";
    visited[num] = 1;
    bfsList.push(num);

    while(!bfsList.empty()){
        int node = bfsList.front();
        bfsList.pop();
        for(int i = 0;i<vertices.size();i++){
            if(node == vertices.at(i).sourceID){
                auto it = vertices.at(i).edgeList.begin();
                for(it;it!=vertices.at(i).edgeList.end();it++){
                    if(visited[it->destinationID] == 0){
                        cout<<it->destinationID<<" ";
                        visited[it->destinationID] = 1;
                        
                        bfsList.push(it->destinationID);
                    }
                }
            }
        }
    }
}

void Graph :: DFSTraversal(int num){

    int noOfVertices = vertices.size();
    int visited[50];

    for(int i = 0;i <50;i++){
        visited[i+1] = 0;
    }

    stack <int> dfsList;
    cout<<num<<" ";
    visited[num] = 1;
    dfsList.push(num);

    while(!dfsList.empty()){
        int node = dfsList.top();
        dfsList.pop();
        for(int i = 0;i<vertices.size();i++){
            if(node == vertices.at(i).sourceID){
                auto it = vertices.at(i).edgeList.begin();
                for(it;it!=vertices.at(i).edgeList.end();it++){
                    if(visited[it->destinationID] == 0){
                        cout<<it->destinationID<<" ";
                        visited[it->destinationID] = 1;
                        dfsList.push(it->destinationID);
                    }
                }
            }
        }
    }
}

//important
void Graph :: deleteVertex(int num){

    int flag = -1;
    if(checkIfVertexExist(num)){
      for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).sourceID == num) {
          flag = i;
        }
        }
      for (int i = 0; i < vertices.size(); i++) {
        auto it = vertices.at(i).edgeList.begin();
        for (it; it != vertices.at(i).edgeList.end(); it++) {
          if (it ->destinationID ==num) {
            vertices.at(i).edgeList.erase(it);
            break;
          }
        }

      }
      vertices.erase(vertices.begin() + flag);
      cout << "Vertex Deleted Successfully" << endl;

    }
    else{
        cout<<"Vertex dont exist so cannot delete the vertex"<<endl;
    }
}

void Graph :: printNeighbours(int num){
    if(checkIfVertexExist(num)){
        vector < Vertex > :: iterator iter;
        iter = vertices.begin();

        for(iter;iter!=vertices.end();iter++){
            if( iter->sourceID == num){
                auto it = iter->edgeList.begin();
                cout<<"The neighbours list of ID "<<num<<" is "<<"[";
                for(it;it!=iter->edgeList.end();it++){
                    cout<<it->destinationID;
                    cout<<"("<<it->weight<<") ";
                }
                cout<<"]"<<endl;

            }
        }
    }

    else{
        cout<<"The given vertex dont exist"<<endl;
    }
}

void Graph :: deleteEdge(int num1,int num2){
    if(checkIfVertexExist(num1) && checkIfVertexExist(num2)){
        if(checkIfEdgeExist(num1,num2)){
            for(int i = 0;i<vertices.size();i++){
                if(vertices.at(i).sourceID == num1){
                    auto it = vertices.at(i).edgeList.begin();
                    for(it; it != vertices.at(i).edgeList.end(); it++){
                        if(it->destinationID == num2){
                            vertices.at(i).edgeList.erase(it);
                            break;
                        }
                    }
                }

                else if(vertices.at(i).sourceID == num2){
                    auto it = vertices.at(i).edgeList.begin();
                    for(it; it != vertices.at(i).edgeList.end(); it++){
                        if(it->destinationID == num1){
                            vertices.at(i).edgeList.erase(it);
                            break;
                        }
                    }
                }
            }
            cout<<"The edge is Successfuly deleted "<<endl;
        }
    }

    else{
        cout<<"The edge cannot be deleted becasue there is no edge present"<<endl;
    }
}

void Graph :: updateEdge(int num1,int num2,int num3){
    if(checkIfVertexExist(num1) && checkIfVertexExist(num2)){
        if(checkIfEdgeExist(num1,num2)){
            for(int i = 0;i<this->vertices.size();i++){
                if(vertices[i].sourceID == num1){
                    auto it = vertices.at(i).edgeList.begin();
                    for(it;it!=vertices.at(i).edgeList.end();it++){
                        if(it->destinationID == num2){
                            it->weight = num3;
                        }
                    }
                }

                else if(vertices[i].sourceID == num2){
                    auto it = vertices.at(i).edgeList.begin();
                    for(it;it!=vertices.at(i).edgeList.end();it++){
                        if(it->destinationID == num1){
                            it->weight = num3;
                        }
                    }
                }
            }
        }
    }

    else{
        cout<<"The edge is not present in between the ID's"<<endl;
        return;
    }
}

void Graph :: checkIfNeighbour(int num1,int num2){

    int flag = 0;
    if(checkIfVertexExist(num1) && checkIfVertexExist(num2)){
        if(checkIfEdgeExist(num1,num2)){
            flag = 1;
        }
    }

    if(flag){
        cout<<"Yes they both are neighbours "<<endl;
    }

    else{
        cout<<"No they both are not neighbours "<<endl;       
    }
}

int Graph :: checkIfVertexExist(int num){

    vector <Vertex> :: iterator iter;
    iter = this->vertices.begin();   

    for(iter;iter!=this->vertices.end();iter++){
        if(num == iter->getSourceID()){
            return 1;
        }
    }
    return 0;
}

int Graph :: checkNoSameVertex(int num){

    vector <Vertex> :: iterator iter;
    iter = this->vertices.begin();

    for(iter;iter!=this->vertices.end();iter++){
        if(num == iter->getSourceID()){
            cout<<"Aldready a node exist with the given ID or Place Name "<<endl;
            return 1;
        }
    }

    return 0;
}

void Graph :: addVertex(int num,string str){

    int temp = checkNoSameVertex(num);

    if(!temp){

        Vertex new_vertex;
        new_vertex.setSourceID(num);
        new_vertex.setPlaceName(str);
        this->vertices.push_back(new_vertex);
        cout<<"The node is succesfully added in the Graph"<<endl;
    }

    else{
        return;
    }

}

int Graph :: checkIfEdgeExist(int num1,int num2){

    vector <Vertex> :: iterator iter;
    iter = vertices.begin();
    int i = 0;
    Vertex temp;
    for(iter;iter!=vertices.end();iter++){
        if(num1==iter->getSourceID()){
            temp = vertices[i];//imp
        }
        i++;
    }

    list <Edge> :: iterator it;
    it = temp.edgeList.begin();

    for(it;it!=temp.edgeList.end();it++){
        if(num2 == it->getdestinationID()){
            return 1;
        }
    }

    return 0;

}

void Graph :: addEdge(int num1,int num2,int num3){

    int temp1 = checkIfVertexExist(num1);
    int temp2 = checkIfVertexExist(num2);
    int temp3 = 1;
    if(temp1 && temp2){
        temp3 = checkIfEdgeExist(num1,num2);
    }

    if(!temp3){
        vector <Vertex> :: iterator iter;
        iter = vertices.begin();

        for(iter;iter!=vertices.end();iter++){
            if(num1 == iter->getSourceID()){
                Edge new_edge(num2,num3);
                iter->edgeList.push_back(new_edge);
            }

            if(num2 == iter->getSourceID()){
                Edge new_edge(num1,num3);
                iter->edgeList.push_back(new_edge);
            }
        }
    }

    else{
        cout<<"There is aldready edge present between given nodes"<<endl;
        return;
    }

}

void Vertex :: printEdgeList(vector <Vertex> :: iterator iter){

    list <Edge> listTemp;
    listTemp = iter->getEdgeList();
    list <Edge> :: iterator it;
    it = listTemp.begin();

    cout<<"["<<"";
    for(it;it!=listTemp.end();it++){
        cout<<it->getdestinationID();
        cout<<"(";
        cout<<it->getWeight();
        cout<<")";
        cout<<"->";
    }

    cout<<"]"<<endl;
}

void Graph :: printGraph(){

    vector <Vertex> :: iterator iter;
    iter = this->vertices.begin();

    for(iter;iter!=vertices.end();iter++){
        cout<<iter->getSourceID()<<"-";
        cout<<iter->getPlaceName()<<" ";
        iter->printEdgeList(iter);

    }

}

void Graph :: updateVertex(int num,string str){

    if(checkIfVertexExist(num)){

        vector <Vertex> :: iterator iter;
        iter = this->vertices.begin();

        for(iter;iter!=vertices.end();iter++){
            if(iter->sourceID == num){
                iter->placeName = str;
                cout<<"The vertex is succesfully Updated"<<endl;
                break;
            }
        }
    }

    else{
        return;
    }

}

int main(){

    Graph g;
    g.addVertex(1,"TS");
    g.addVertex(2,"AP");
    g.addVertex(3,"KL");
    g.addVertex(4,"JK");
    g.addVertex(5,"MH");
    g.addVertex(6,"OR");
    g.addVertex(7,"CH");
    g.addEdge(1,2,1000);
    g.addEdge(1,3,2000);
    g.addEdge(2,3,3000);
    g.addEdge(1,4,7000);
    g.addEdge(4,3,5000);
    g.addEdge(5,6,4500);
    g.addEdge(6,7,5500);
    g.addEdge(7,1,7500);
    g.updateVertex(2,"KA");
    g.checkIfNeighbour(1,3);
    g.checkIfNeighbour(2,4);
    g.printGraph();
    g.printNeighbours(3);
    g.deleteEdge(1,3);
    // g.deleteEdge(2,3);
    g.updateEdge(1,4,10000);
    g.printNeighbours(1);
    // g.deleteVertex(2);
    // g.deleteVertex(3);
    // g.deleteVertex(1);
    g.printGraph();
    cout<<"BFS: "<<endl;
    //  cout<<"BFS: "<<endl;
    g.BFSTraversal(7);
    cout<<endl;
     cout<<"DFS: "<<endl;
    g.DFSTraversal(7);
    cout<<endl;
    g.detectCycleInUndirected();
    
    return 0;
}