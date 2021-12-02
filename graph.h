/*
Para este estilo de graphos que quise implementar para crear un gps de among us
use una libreria llamada unorder_map que trabaja con hashes (los cuales todavia
no se muy bien que hacen), que segun yo lo que pasa con los hashes es que logra
encontrar maneras de juntar valores, tambien unordermaps te deja usar variables
de mas de un solo tipo (tambien se usa el tipo pair).
*/

#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class node{
public:
  string place;
  float time;
};

class Graph{
public:
    unordered_map < string , vector < node > > maps; //Aqui se guarda el primer mapa con dos tipos de datos: string y vector
    void addEdge(string start, string finale, float sec);
    string printMap();
    void shortestPath(string start, string finale);
};

void Graph::shortestPath(string origin , string goal){
      if(origin == goal){//Limite
        cout<<"You are already there."<<endl<<endl;
    }
    else if(maps[goal].empty()){//Limite
        cout<<"404 path not found"<<endl<<endl;
    }
    else if(maps[origin].empty()){//Limite
        cout<<"A place like that doesn't exist."<<endl<<endl;
    }
    else{
        unordered_map <string , pair<float, string> > len;
        for(auto ite = maps.begin() ; ite != maps.end() ; ite++){//Por lo que logre investigar es que existe un tipo de dato llamado auto que deja entrar cualquier tipo de dato y trabaja con el
            len[ite->first].first = 999; //Se crean limites para el mapa
            len[ite->first].second = "None"; //Se crean limites para el mapa
        }
        len[origin].first = 0;
        set < pair < float , string > > steps;
        steps.insert(make_pair(0,origin));//Origen del grafo
        while (!steps.empty()){
            node temp;
            temp.place=steps.begin()->second;//Se crea como un getter
            temp.time=steps.begin()->first;//Se crea como un setter
            steps.erase(steps.begin());//Elimina
            for(auto ite=maps[temp.place].begin() ; ite != maps[temp.place].end() ; ite++){
                if(temp.time + ite->time <= len[ite->place].first){//Suma de nodos
                    auto oldPair = make_pair(len[ite->place].first , ite->place);
                    auto findOldPair = steps.find(oldPair);//Encuentra sus otros valores
                    if(findOldPair!=steps.end()){
                        steps.erase(findOldPair);
                    }
                    auto newPair = make_pair( (temp.time + ite->time) , ite->place );//Junta los valores
                    steps.insert(newPair);
                    len[ite->place].first = temp.time + ite->time;
                    len[ite->place].second = temp.place;
                }
            }
        }
        cout<<"\nTotal time is: "<<len[goal].first<<" seconds."<<endl;
        cout<<"The shortest path is through locations: ";
        vector <string> vecPath;//Crea vector para guardar el camino de los datos
        string start = goal;//Origen
        while(start != "None"){
            vecPath.push_back(start);
            start = len[start].second;
        }
        for(int i=vecPath.size()-1 ; i>-1 ; i--){//Hace el recorrido al reves
            cout<<vecPath[i]<<"  ";
        }
        cout<<endl<<endl;
    }
}

void Graph::addEdge(string start , string finale , float sec){ //Esta parte funciona con un nodo temporal para guardar el archivo completo
    node temp;
    temp.place=finale;
    temp.time=sec;
    maps[start].push_back(temp);
    temp.place=start;
    temp.time=sec;
    maps[finale].push_back(temp);
};


string Graph::printMap(){//Se encontro una manera para que el grafo y el unordermap trabajaran juntos para que se imprimiera de ida y regreso
    for (unordered_map< string , vector < node > >::iterator unmap = maps.begin() ; unmap != maps.end() ; unmap++){
        for(int i=0 ; i<unmap->second.size() ; i++){
            cout<<"From "<<unmap->first<<" to "<<unmap->second[i].place<<" there are "<<unmap->second[i].time<<" seconds in distance."<<endl<<endl;
        }
    }
};



#endif
