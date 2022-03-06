#include<iostream>
// #include<vector>
using namespace std;

class Graph{
     public:
    int **adj;
    int vertices;
    int d;
   
   Graph(){
     vertices=0;
     d=0;
   }
   Graph(int v,int d){
       vertices = v;
       this->d =d;
    for (int i = 0; i < v; i++) {
      adj[i] = new int[v];
      for (int j = 0; j < v; j++)      
        adj[i][j] = 0;
    }
   }
 
    // void create();
    void insertEdge(int,int);
    void deletionEdge(int,int);
    void display();


};
// void Graph::create(){
//       int type,ver,edges,origin,destin;
//    cout<<"Enter 0 for undirected graph or 1 for directed graph"<<endl;
//    cin>>type;
//    this->d = type;

//    cout<<"enter no. of vertices"<<endl;
//    cin>>ver;
//    if(type == 0)
//    edges = ver * (ver-1)/2;
//    else
//      edges = ver * (ver-1);
    
//     for(int i=1 ;i<=edges ; i++)
//     {
//         cout<<"Enter edge "<<i<<"(-1 -1 to quit): ";
//         cin>>origin>>destin;
       
//         if(origin == -1 && destin == -1){
//              break;
//         }
       
//         if(origin <0 ||origin >= edges || destin <0 ||destin >= edges){
//             cout<<"invalid vertix"<<endl;
//             i--;
//         }
//         else{
//         // cout<<"hi";
//         adj[origin][destin] = 1;
//          cout<<"hi";
//         if(this->d == 0)
//           adj[destin][origin] = 1;
//            cout<<"hi";
//         }
        
//     }
    
// }
void  Graph::insertEdge(int origin,int destin){
    if(origin<0 || origin > this->vertices){
        cout<<"Origin vertex doesn't exist"<<endl;
        return;
    }
     if(destin <0 || destin > this->vertices){
        cout<<"Destination vertex doesn't exist"<<endl;
        return;
    }
    adj[origin][destin] = 1;
    if(this->d ==0){     //  if undirected graph
        adj[destin][origin] = 1;
    }
 }
 void Graph::deletionEdge(int origin,int destin){
     if(origin<0 || origin > this->vertices|| destin <0 || destin > this->vertices || adj[origin][destin] == 0){
         cout<<"edge doesn't exist"<<endl;
         return;
     }
     adj[origin][destin] = 0;
       if(this->d ==0){    //  if undirected graph
        adj[destin][origin] = 0;
    }
 }
 void Graph::display(){
     for(int i=0;i<this->vertices;i++){
         for(int j =0; j< this->vertices; j++){
             cout<<adj[i][j]<<" ";
         }
        cout<<endl;   
     }
     cout<<endl;
 }
 int main(){
   Graph g(4,0);


//   g.insertEdge(0, 1);
//   g.insertEdge(0, 2);
//   g.insertEdge(1, 2);
//   g.insertEdge(2, 3);
//   g.display();
   int ch,origin,destin;
//    g.create();
   while(1){

       cout<<"1.insert edge"<<endl;
       cout<<"2.delete edge"<<endl;
       cout<<"3. Display"<<endl;
       cout<<"4.Exit"<<endl;
       
       cout<<"Enter your choice: ";
	   cin>>ch;
       switch(ch){
           case 1: cout<<"enter an edge to insert: ";
                   cin>>origin>>destin;
                   g.insertEdge(origin,destin);
                   break;

            case 2: cout<<"enter an edge to delete: ";
                   cin>>origin>>destin;
                   g.deletionEdge(origin,destin);
                   break;
            case 3: g.display();
                    break;
            case 4: exit(0);

            default: cout<<"invalid choice"<<endl;

       }

//    }
    

 }
 }
