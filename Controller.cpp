//
// Created by igor on 25/06/2023.
//

#include "Controller.h"

void Controller::GetInput(string &input) {


    //lines 11-17 : separate input to words using a vector
    std::istringstream iss(input);
    std::vector<std::string> words;

    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }

    try {
        //lines 22-54  inputs related to view

        if (words.front() == "default" && words.size() == 1) {
            view.ddefault();

        }
        else if(words.front() == "size"  && words.size() == 2){
            int s = std::stoi(words.back());
            if (s>6 && s<=30 ){
                view.setSize(s);
            }
            else{
                throw std::invalid_argument("invalid input");
            }
        }
        else if(words.front() == "zoom" && words.size()==2){
            int num = std::stoi(words.back());
            if (num>0){
                view.zoom(num);
            }

            else{ throw std::invalid_argument("invalid input");}

        }

        else if(words.front() == "pan" && words.size() == 3){
            words.erase(words.begin());
            double x = stoi(words.front());
            double y = stoi(words.back());
            view.pan(x,y);

        }
        else if(words.front() == "show"  && words.size() == 1){
            view.show();
        }


        //line 59- related to model
        else if(words.front() == "status " && words.size() == 1){
            model.status();
        }
        else if(words.front() == "go"  && words.size() == 1){
            model.go();
        }
        else if(words.front() == "create" && words.size() >4 ){
            words.erase(words.begin());
            std::string name = words.front();
            words.erase(words.begin());
            std::string type = words.front(); //knight , thug or peasant
            if(!(type == "peasant" || type == "thug" || type == "knight"    && isStringOnlyLetters(name))) {
                throw std::invalid_argument("invalid input");
            }

            if (words.size() == 2 && words.front().size()==3  && words.back().size() == 2) //coordination in the form of (x, y)-thug or peasant or knight.
            {
                std::string word1 = words.front();   //should be in the form of (x,
                word1.substr(1);
                word1.pop_back();
                double x = std::stoi(word1);
                std::string word2 = words.back();
                word2.pop_back();
                double y = std::stoi(word2);
                Point p(x,y);

                model.addAgent(name,type,p);

            }
            else if(words.size() == 1 && type == "knight"){
                model.addAgent(name,type,words.front());
            }




        }
        //this commands will be given after the name.
        std::string name = words.front();
        words.erase(words.begin());
        if( words.front() == "course" && (words.size() ==2 || words.size() == 3))
        {
            words.erase(words.begin());
            std::string  word1 = words.front();
            int theta = std::stoi(word1);
            int speed = -1;
            if (words.size()>1){
                std::string  word2 = words.back();
                speed = std::stoi(word2);
                if (speed<=0)  {throw std::invalid_argument("invalid input");}
            }
            model.course(name,theta,speed);

        }
        if (words.front() == "position" && (words.size()==3 || words.size() == 4)){
            words.erase(words.begin());
            std::string word1 = words.front();   //should be in the form of (x,
            word1.substr(1);
            word1.pop_back();
            double x = std::stoi(word1);
            words.erase(words.begin());
            std::string word2 = words.front();
            word2.pop_back();
            double y = std::stoi(word2);
            Point p(x,y);
            int speed;
            if (words.size()>1){  //its a thug
                std::string word3 = words.back();
                speed = stoi(word3);
            }
            model.position(name,p,speed);
        }











    }


    catch (const std::exception&e){}
}

bool Controller::isStringOnlyLetters(const string &str) const noexcept {

        for (char ch : str) {
            if (!std::isalpha(ch)) {
                return false;
            }
        }
        return true;

}
