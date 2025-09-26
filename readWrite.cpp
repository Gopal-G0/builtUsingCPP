#include<iostream>
#include<fstream>

int main() {

    //open a file
    std::ofstream fileOut;
    fileOut.open("name.txt"); // it opens the file if exists, if it doesn't exist then it will create one then open it.

    fileOut << "name = Rekha"; // it will write 'name = Rekha' to the name.txt file

    fileOut.close(); // it will release all the resources it is holding
}