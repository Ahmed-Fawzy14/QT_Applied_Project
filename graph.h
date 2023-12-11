//
// Created by Fawzy on 11/10/2023.
//

#ifndef APPLIED_PROJECT_GRAPHHEADER_H
#define APPLIED_PROJECT_GRAPHHEADER_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <queue>
#include "Trie.h"
#include <unordered_map>
#include <map>
using namespace std;

class Graph{

public:


    struct Node{

        string name;
        Trie trie;
        int weight;


        bool operator==(const Node& other) const {
            return 1/* condition for equality */;

        }

        bool operator!=(const Node& other) const {
            return !(*this == other);
        }


        Node(){

        };

        Node(string name, Trie t, int weight){
            this->name = name;
            this->trie = t;
            this->weight = weight;

        }
    };

    unordered_map<string, int> nodeToIndexMap;
    int intNodeIndex(string nodeName) const;


    //Adj List
    int size; //number of buildings
    vector<vector<Node>> adjList;




    enum Buildings {
        BruceLLudwigFamilySquare, DrHamzaAlKohliInformationCentre, Gate1, AllamAmphitheatre, SchoolOfContinuingEducation, AUCPortal,AUCCenterForArts,Jameel, JameelFirstFloor, JameelSecondFloor, BusGate, SSE, SSEFirstFloor, SSESecondFloor, SSERoof, SSEPlaza, Hatem, HatemFirstFloor, HatemSecondFloor, HatemThird, HatemRoof, Quick, OmarMohsen, Waleed, WaleedFirstFloor, WaleedSecondFloor,ArtFF,TabaliPlaza,ArtsGate,Gate5,SocialResearchCenter,WatsonHouse,LinkPlaza,Administration,AdministrationGarden,AdministrationFirstFloor,AdministrationSecondFloor,WestGarden,BarlettPlaza,Library,LibraryGarden,LibraryFirstFloor,LibrarySecondFloor,LibraryThirdFloor,CVC,CampusCenter,EastGarden,NorthGarden,GardensGate,Gate2,AUCResid,AUCResidFF,AUCResidSS,SportsPlaza,EastEntrance,SportsComplex,PepsiGate,Gate4,ArnoldPavillion,SportGate,IndoorSports,SportsFF,ComplexPool,ComplexOutdoor,Gate3

    };

    Buildings usethis;

    string nodeName = "";
    string startNode="";
    string endNode= "";
    string room = "";


    vector<vector<Node>> test;

    void buildNodeToIndexMap();
    unordered_map<int, string> buildIndexToNodeMap();
    Graph();

    Graph(int size);

    //reads a line and tell you how many elements are in it
    // then use this for the while loop (or a for loop)
    //commas +1
    void getLoop(int commaCount[]);
    void createGraph(Buildings ind);

    vector<string>  readFile(string &theFile);
    void getPath(int startNode, int endNode, const vector<int>& pred, vector<string>& p);

    void insertInNode(string nodeName, vector<string> s, vector<string> t) const ;
    bool searchClassroomInNode(string nodeName, const std::string& classroom, string &word, string &o) const;
    void dijkstra(int startNode, vector<string>& p, string endNode, int &x);

    string createSub(int &index, string &theFile, Buildings ind);
    void dijkstra(int startNode);

    vector<vector<Node> > getAdjlist();

    int findNodeIndex(const string& nodeName);
    map<int, string> indexToNodeMap;

    void printPath(int startNode, int endNode, const vector<int>& pred);

    //need a funciton to initalize all nodes
    //give the node its name
    //give the node its respective trie
    //give the node its weight from the root node
    //(JAMEEL, t0, 0) -> (FF, t1, 1) -> (SF, t2, 2) -> (ROOF, t3, 3)
    //Name and weight can be gotten from a file
    //Trie needs to be sent from main function


    void print();

    void addNodeToIndexMapping(const std::string& nodeName, Buildings index);

    ~Graph();

    vector<std::string> classGround;
    vector<string> typeJamG;
    vector<std::string> classFirst;
    vector<string> typeJamF;
    vector<std::string> classSecond;
    vector<string> typeJamS;
    vector<string> AdminGround;
    vector<string> AdminFF;
    vector<string> AdminSF;
    vector<string> AdminG;
    vector<string> AdminGType;
    vector<string> AdminType;
    vector<string> SSEplazaType;
    vector<string> SSEType;
    vector<string> SSEFF;
    vector<string> SSESF;
    vector<string> SSEG;
    int totalDistance = 0;




};



#endif //APPLIED_PROJECT_GRAPHHEADER_H
