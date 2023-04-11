#include<iostream>
#include<curses.h>

std::string getstring(/*a coordinate*/){ // get the string input from users
    
    std::string line = "";
    std::cout<<"You should input at most 10 characters."<<std::endl;
    while (line.size() <= 10){
        /*noecho();
        cbreak();
        nodelay(stdscr, TRUE); */
        int i = getch();
        if (i == KEY_ENTER){
            break;
        }
        else if (i == KEY_BACKSPACE){
            line.push_back(line.back());
        }
        else if (i != ERR){
            line.push_back(i);
        }

        if (line.size() > 10) {
            std::cout<<"Your input exceeds the limit. Please input again."<<std::endl;
            line = "";
        }
    }
    std::cout<<"You have entered "<<line<<std::endl;
    return line;

}

int main(){
    std::string a;
    a = getstring();
    std::cout<<a<<std::endl;
    return 0;
}
