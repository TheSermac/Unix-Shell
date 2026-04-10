#include <iostream>
#include <string>
#include <vector>

class Shell {
    private:
        bool exit;
        const std::string delimitier = " ";

        // Private process to separate the arguments of a cmd
        std::vector<std::string> strsep(std::string cmd){
            std::vector<std::string> args;
            std::string token;
            size_t pos;
            while((pos = cmd.find(delimitier)) != std::string::npos){
                token = cmd.substr(0, pos);
                cmd.erase(0, pos + delimitier.size());
                args.push_back(token);
            }
            args.push_back(token);
            return args;
        }

        // Redirects the command to be executed correctly
        void execute(const std::vector<std::string>& args){

        }
    
    public:

        //Constructor of the shell
        Shell(){
            exit = false;
        }

        //Interactive mode of the shell
        void run(){
            std::string cmd;
            std::vector<std::string> args;
            while(!exit){
                std::cout << "prompt> ";
                std::getline(std::cin, cmd);
                std::cout << std::endl << "wish> ";
                args = strsep(cmd);
                //execute(args);
            }
        }
};


int main(){
    Shell sh;
    sh.run();
}