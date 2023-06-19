//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_SIM_OBJECT_H
#define PROJECT_3_SIM_OBJECT_H


class Sim_object {
    std::string name;
    std::pair<float,float> location;
    std::string state;

protected:
    std::string getName() const noexcept;
    std::string getLocation() const noexcept;
    void update();
    std::string broad_current_state() const noexcept;

};


#endif //PROJECT_3_SIM_OBJECT_H
