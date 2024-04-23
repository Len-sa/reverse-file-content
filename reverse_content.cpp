#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream file("example.txt");
    if(!file){
        cout<<"unable to open example.txt please make sure the file exists."<<endl;
        return 1;
    }
    // Calculating number of characters in the file
    file.seekg( 0 , ios::beg);
    int start = file.tellg();
    file.seekg(-1 , ios::end);
    int last = file.tellg();
    int size = last - start;

    char a, b;
    int right = 0;
    int left = -1;
    int counter = 0;

    while (counter < (size / 2) + 1) {
        // read the right character to swap
        file.seekg(right, ios::beg);
        file.get(a);

        // read the left character to swap
        file.seekg(left, ios::end);
        file.get(b);

        cout<<"swapping "<<a<<"("<<right<<"),"<<b<<"("<<left<<")"<<endl;

        // Skip newline characters to not disrupt the text structure.
        if (a == '\n' || b == '\n') {
            if (a == '\n') {
                right++;
            }
            if (b == '\n') {
                left--;
            }
            continue;
        }

        // swap characters
        file.seekg(right, ios::beg);
        file.put(b);
        file.seekg(left, ios::end);
        file.put(a);
        
        counter++;
        right++;
        left--;
    }
    file.close();
}