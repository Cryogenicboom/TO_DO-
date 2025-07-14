#include <iostream>
#include <string>
#include <vector>

void add(std::vector<std::string>& list ){
    // "&" is used to use the original list rather than its copy

    std::cout<<"Enter Tasks to be added or 'q' to quit:\n";

    // char user_input;
    // std::cin>>user_input;

    // while(user_input != 'q'){
    //     std::string task;
    //     std::cin.ignore(); // clears buffer which usually contain \n
    //     getline(std::cin, task); // takes whole line
    //     list.push_back(task);    
    // }

    while (true) {
        std::string task;
        std::getline(std::cin >> std::ws, task); 
        if (task == "q") 
            break;
        list.push_back(task);
    }
}

void view(const std::vector<std::string>& list) {
    std::cout << "Current tasks:\n";
    if (list.empty()) {
        std::cout << "No tasks found.\n";
    } 
    else {
        for (int i = 0; i < list.size(); i++) {
            std::cout << i + 1 << ". " << list[i] << std::endl;
        }
    }
}

void remove(std::vector<std::string>& list ){ //remove the const as we will be changing it 
    view(list);
    while (true) {
        int task;
        std::cout<<"Enter Task's number to be adderemoved or (0 to quit):\n";
        std::cin>>task;
        if (task == 0) 
            break;
        else if(task <1 || task > list.size()){
            std::cout<<"Invalid input";
        }
        list.erase(list.begin() + task-1); // important
        
    }

}

int main(){
    std::vector<std::string> list{};
    int user_input;
    
    while(user_input != 4){
        std::cout<<"MENU:\n>1 to add task\n>2 to view task\n>3 to remove tasks\n>4 to quit.\n";
        std::cin>>user_input;

        if(user_input == 1){
            add(list);
        }
        else if(user_input == 2){
            view(list);
        }
        else if(user_input == 3){
            remove(list);
        }
        else if(user_input ==4){
            std::cout<<"Exiting...";
            break;
        }
        else{
            std::cout<<"Invalid order.";
        }
    }
}
