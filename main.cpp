#include <iostream>
#include <vector>
#include <fstream>
#include "Shape.h"

using namespace std;

int check_name(vector<Shape*>& v, string name){
    vector<Shape*>::iterator t;
    for (t = v.begin(); t != v.end(); ++t){
        if((*t)->get_name() == name){
            return 1;
        }
    }
    return 0;
}

int main(){
    string command,tmp;
    string table_command[6];
    int i,length = 0;
    int flag = 0;
    vector<Shape*> all_shape;
    vector<Shape*>::iterator it;
    ofstream myfile;

    for(int i = 0; i < 500; i++){
        for(int j = 0; j < 500; j++){
            panel[i][j] = ' ';
        }
    }
    while(true){
        for(i = 0; i < 6; i++ ){
            table_command[i] = "";
        }
        length = 0;
        cout << "$>";
        getline (cin,command);

        for(i = 0; i < command.length();i++){
            if(command[i]==' '){
                table_command[length++] = tmp;
                tmp = "";
            }
            else{
                tmp = tmp + command[i];
            }
        }
        table_command[length++] = tmp;
        tmp = "";
        if(table_command[0] == "newrect"){
            if(check_name(all_shape,table_command[1])==1){
                cout<<"this name is already exist!!!"<<endl;
                continue;
            }
            if(length == 6){
                all_shape.push_back(new Rectangle(table_command[1],atoi(table_command[4].c_str()),atoi(table_command[5].c_str()),atoi(table_command[2].c_str()),atoi(table_command[3].c_str())));
            }
            else{
                cout<<"this command is wrong"<<endl;
            }
        }
        else if(table_command[0] == "newrhomb"){
            if(check_name(all_shape,table_command[1])==1){
                cout<<"this name is already exist!!!"<<endl;
                continue;
            }
            if(length == 5){
                all_shape.push_back(new Rhombus(table_command[1],atoi(table_command[4].c_str()),atoi(table_command[2].c_str()),atoi(table_command[3].c_str())));
            }
            else{
                cout<<"this command is wrong"<<endl;
            }
        }
        else if(table_command[0] == "newcircle"){
            if(check_name(all_shape,table_command[1])==1){
                cout<<"this name is already exist!!!"<<endl;
                continue;
            }
            if(length == 5){
                all_shape.push_back(new Circle(table_command[1],atoi(table_command[2].c_str()),atoi(table_command[3].c_str()),atoi(table_command[4].c_str())));
            }
            else{
                cout<<"this command is wrong"<<endl;
            }
        }
        else if(table_command[0] == "delete"){
            if(length == 2){
                for (it = all_shape.begin(); it != all_shape.end(); ++it){
                    if((*it)->get_name() == table_command[1]){
                        all_shape.erase(it);
                        break;
                    }

                }
            }
            else{
                cout<<"this command is wrong"<<endl;
            }
        }
        else if(table_command[0] == "translate"){
            if(length == 4){
                for (it = all_shape.begin(); it != all_shape.end(); ++it){
                    if((*it)->get_name() == table_command[1]){
                        (*it)->translate(atoi(table_command[2].c_str()),atoi(table_command[3].c_str()));
                    }
                }
            }
            else{
                cout<<"this command is wrong"<<endl;
            }
        }
        else if(table_command[0] == "scaleup"){
            if(length == 3){
                for (it = all_shape.begin(); it != all_shape.end(); ++it){
                    if((*it)->get_name() == table_command[1]){
                        (*it)->scaleup(atoi(table_command[2].c_str()));
                    }
                }
            }
            else{
                cout<<"this command is wrong"<<endl;
            }
        }
        else if(table_command[0] == "draw"){
            if(length == 1){
                myfile.open ("test1.txt",ios::out);
                for (it = all_shape.begin(); it != all_shape.end(); ++it){
                    (*it)->draw();
                }
                for(int i = 0; i < 1500; i++){
                    for(int j = 0; j < 1500; j++){
                        myfile << panel[i][j];
                    }
                    myfile << endl;
                }
                cout<<endl;
                myfile.close();
            }
            else{
                cout<<"this command is wrong"<<endl;
            }
        }
        else if(table_command[0] == "areas"){
            if(length == 1){
                for (it = all_shape.begin(); it != all_shape.end(); ++it){
                    cout<<(*it)->get_name()<<": "<<(*it)->area()<<endl;;
                }
            }
            else{
                cout<<"this command is wrong"<<endl;
            }
        }
        else if(table_command[0] == "exit"){
            break;
        }
        else{
        }
        for (it = all_shape.begin(); it != all_shape.end(); ++it){
            cout<<(*it)->get_name()<<"-->";
            (*it)->print();
        }
    }
}