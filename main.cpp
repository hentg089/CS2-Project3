//Mark Hentges 5814125 2/23/2023

#include <iostream>
#include <fstream>
#include <sstream>

#include "LinkedSet.cpp"

std::string cleanString(std::string clean); //removes uneccessary characters from beginning and end of string and makes lowercase
bool isBadChar(char cChar); //checks to see if our character is unnecesary
void readDictionary(LinkedSet<std::string>& dictionary); //reads in our dictionary file
void readSpellCheckFile(LinkedSet<std::string>& fileBeingSpellChecked); //reads in our files to be spell checked

int main() {
    //char for spell checking another file
    char yORn = 'y';
    LinkedSet<std::string> dictionary;
    LinkedSet<std::string> fileBeingSpellChecked;
    LinkedSet<std::string> difference;



    readDictionary(dictionary);

    do{
        fileBeingSpellChecked.clear();
        readSpellCheckFile(fileBeingSpellChecked);

        difference = fileBeingSpellChecked.difference(dictionary);
        std::cout << "the difference set: " << std::endl;
        for(std::string& i : difference.toVector()){
            std::cout << i << std::endl;
        }

        fileBeingSpellChecked.clear(); //clears the files
        difference.clear(); //clears the files

        std::cout << "Do you want to spell check another file?(y/n)" << std::endl;
        std::cin >> yORn;

    }while(yORn == 'y');
}



std::string cleanString(std::string clean){
    std::string cleanedString;
    int firstNums = 0;
    int lastNums = 0;

    //checks to see how many bad charactesr are in front of the string
    for(int i = 0; i < clean.length(); ++i){
        if(isBadChar(clean.at(i))){
            firstNums++;
        }else{
            break;
        }
    }

    //checks to see how many bad characers are in the back of the string
    for(int i = 1; i <= clean.length(); ++i){
        if(isBadChar(clean.at(clean.length() - i))){
            lastNums++;
        }else{
            break;
        }
    }

    cleanedString = clean.substr(firstNums, clean.length() - lastNums - firstNums);

    //puts our string in lowercase
    for(int i = 0; i < cleanedString.length(); ++i){
        cleanedString.at(i) = tolower(cleanedString.at(i));
    }
    return cleanedString;
}

bool isBadChar(char cChar){
    //all of the unwanted characters
    std::string badChars = "!@#$%^&*()_-+={}[]:;\"'`<>,.?/|\\";

    //loops to see if any are the bad characters
    for(int i = 0; i < badChars.length(); ++i){
        if(cChar == badChars.at(i)) return true;
    }

    return false;
}

void readDictionary(LinkedSet<std::string>& dictionary){
    std::string filename;
    std::ifstream file;

    do{
        std::cout << "give me the file location for the dictionary\n";
        std::cin >> filename;
        std::ifstream file(filename);

        if(file.is_open()){
            std::string line;
            while(!file.eof()){
                std::getline(file, line);
                dictionary.add(line);
            }
            file.close(); //closes the file to prevent corruption
            break;
        }

    }while(true);
}

void readSpellCheckFile(LinkedSet<std::string>& fileBeingSpellChecked){
    std::string filename;
    std::ifstream file;

    do{
        std::cout << "give me the file location for file to be spell checked\n";
        std::cin >> filename;
        std::ifstream file(filename);

        if(file.is_open()){
            std::string line;
            while(!file.eof()){
                std::getline(file, line);
                std::istringstream lineSS(line);
                while(!lineSS.eof()){
                    std::string item;
                    getline(lineSS, item, ' ');
                    fileBeingSpellChecked.add(cleanString(item));
                }
            }
            file.close(); //closes the file to prevent corruption
            break;
        }

    }while(true);
}


