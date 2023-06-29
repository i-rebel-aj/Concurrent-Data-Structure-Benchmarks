#include<ios>
#include<iostream>
#include<sys/types.h>
#include<vector>
#include<cstdlib>
#include<chrono>
#include<string>
#include<stdexcept>
#include<thread>
#include<algorithm>
#include<fstream>
#include<random>

#include "./data_structures/linked_list.h"
using namespace std;

template <class T>
void executeOperations(char &op, LinkedList::LinkedList<T> *my_list){
    switch (op) {
        case 'R':
            break;
        case 'W':
            break;    
        default:
            break;
    }
}
//Concurrent Users 1
//request time 500, response time 500

int generateRandomIndex(int start, int end){
    // Create a random number generator.
    default_random_engine generator(time(0));
    uniform_int_distribution<int> distribution(start, end - 1);
    return distribution(generator);
}

string convertTimePointToEpoch(chrono::time_point<std::chrono::high_resolution_clock> start){
    auto epochStart = std::chrono::time_point_cast<std::chrono::microseconds>(start);
    auto epochTime = epochStart.time_since_epoch().count();
    return to_string(epochTime);
}

template<class T>
class DataStructure{

};

int main(int argc, char* argv[]){
    int items_in_list = std::stoi(argv[1]);
    int total_users= std::stoi(argv[2]);
    fstream list_items("listData.txt");
    vector <string> my_list;
    
    //LinkedList::LinkedList<string> *my_list=new LinkedList::LinkedList<string>();
    
    for(int i=0;i<items_in_list; i++){
        string line;
        getline(list_items, line);
        //LinkedList::Node<string> *new_node=new LinkedList::Node<string>(line);
        //my_list->insertNode(new_node);
        my_list.push_back(line);
    }
    
    string total_users_string=argv[2];
    string out_file_name="Metrics-"+ total_users_string +".txt";
    ofstream MetricFile(out_file_name, ios::app);
    MetricFile<<"Total Users "<<total_users_string<<endl;

    for(float percent_concurrent=0;percent_concurrent<=1; percent_concurrent+=0.1){

        int concurrent_users=total_users*percent_concurrent;
        MetricFile<<"Concurrent Users "<<concurrent_users<<endl;
        MetricFile<<"User No,Request,Request Time,Response Time,Latency"<<endl;
        
        
        for(int i=0;i<total_users;i++){
            //Assume Match will Always be not found, enhance data set better
            int randomVectorIndex=generateRandomIndex(0, my_list.size());
            
            auto value_to_find=my_list[randomVectorIndex];
            
            auto operation_start_time = std::chrono::high_resolution_clock::now();
            
            auto foundItr=find(my_list.begin(), my_list.end(), value_to_find);
            
            auto operation_end_time = std::chrono::high_resolution_clock::now();
            
            auto latency = (std::chrono::duration_cast<std::chrono::microseconds>(operation_end_time - operation_start_time)).count();

            string user_log_entry= to_string(i)+ ",R "+value_to_find+","+
            convertTimePointToEpoch(operation_start_time)+","+convertTimePointToEpoch(operation_end_time)+
            +","+to_string(latency);
            
            MetricFile<<user_log_entry<<endl;
        
        }

    }

    // cout<<"My Linked List is"<<endl;
    // my_list->printList();
    // delete my_list;
}