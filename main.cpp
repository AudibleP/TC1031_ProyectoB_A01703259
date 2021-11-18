#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main() {
    Graph sus;
    int option;
    string start;
    string destination;
    float seconds;
    ifstream text("amogus.txt");
    cout<<"Hi"<<endl;
    cout<<"This program is a pseudo gps for the Among Us map Skeld"<<endl;
    cout<<"It works with graphos and hashes (hashes with unorder_maps)"<<endl;
    cout<<"You need to charge the file first"<<endl;
    loop:
    cout<<"Select an option:"<<endl;
    cout<<"1. Charge the file"<<endl;
    cout<<"2. Print every destination"<<endl;
    cout<<"3. Fastest way to another place"<<endl;
  cin>>option;
      if(option == 1){

      while(!text.eof()){
        text>>start>>destination>>seconds;
        sus.addEdge(start , destination , seconds);
      }
        goto loop;
    }
        else if(option == 2){
        sus.printMap();
        goto loop;
    }
        else if(option == 3){
        cout<<"Enter starting place's name"<<endl;
        cin>>start;
        cout<<"Enter destination's name:"<<endl;
        cin>>destination;
        sus.shortestPath(start , destination);
        goto loop;
    }
    else if(option == 0){
        return 0;
    }
    else{
        goto loop;
    }
}
