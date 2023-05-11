#include <iostream>
#include <string>

#include "strutils.h"

using namespace std;

bool isAlpha(string sent){
    
    for (int i=0; i<sent.length();i++){
        
        if ((sent[i] < 'A' || sent[i] > 'Z') && (sent[i] < 'a' || sent[i] > 'z') && sent[i] != ' '&& (sent[i]<'0'||sent[i]>'9')){
            
            return false;
        }
        
    }
    return true;
}

string input(){
    
    string inp;
    string perm;
    
    cout<<"Enter source string: ";
    perm = "";
    while (true){
        
        cin>>inp;
        
            perm += inp + " ";
            
            if (LowerString(inp) == "end"){
                
                break;
            }
        
    }
   
    return perm.substr(0,perm.find("end"));
}

int opSelect(string arg){
    
    if (arg.at(arg.length()- 1) == '+'){
        //arg = arg.substr(0,arg.find("+"));
        //cout<<arg<<endl;
        return 1;
        
    }else if (arg.at(arg.length()- 1) == '.'){
        //arg = arg.substr(0,arg.find("."));
        //cout<<"2"<<endl;
        return 2;
    }else if (arg.at(arg.length()- 1) == '*'){
        if (arg.at(arg.length()- 2) == '*'){
            //arg = arg.substr(0,arg.find("**"));
            //cout<<"4"<<endl;
            
            return 4;
            
        }else{
            //arg = arg.substr(0,arg.find("*"));
            //cout<<"3"<<endl;
            return 3;
        }
    }else if (LowerString(arg)=="quit"){
        return 5;
    }
    else{
        return 10;
    }
}

void allSplitCheck(string source, string src){
    
    int ind, ind2, ind3;
    string word;
    ind = source.find(src);
    while(ind!=-1){
        ind2=source.rfind(" ",ind);
        ind3=source.find(" ",ind);
        word=source.substr(ind2+1,(ind3-(ind2+1)));
        cout<<"index: "<<ind<<" word: "<<word<<endl;
        ind = source.find(src,ind+1);
    }
}

void lastSplitCheck(string source, string src){
    int ind, ind2, ind3;
    string word;
    ind = source.find(src);
    while(ind!=-1){
        ind2=source.rfind(" ",ind);
        ind3=source.find(" ",ind);
        word=source.substr(ind2+1,(ind3-(ind2+1)));
        if(ind+src.length()==ind3){
            cout<<"index: "<<ind<<" word: "<<word<<endl;
        }
        ind = source.find(src,ind+1);
    }
}

    


void firstSplitCheck(string source, string src){
    int ind, ind2, ind3;
    string word;
    ind = source.find(src);
    while(ind!=-1){
        ind2=source.rfind(" ",ind);
        ind3=source.find(" ",ind);
        word=source.substr(ind2+1,(ind3-(ind2+1)));
        if(ind-1==ind2){
            cout<<"index: "<<ind<<" word: "<<word<<endl;
            
        }
        ind = source.find(src,ind+1);
    }
}


void midSplitCheck(string source, string src){
    int ind, ind2, ind3;
    string word;
    ind = source.find(src);
    while(ind!=-1){
        ind2=source.rfind(" ",ind);
        ind3=source.find(" ",ind);
        word=source.substr(ind2+1,(ind3-(ind2+1)));
        if((word.substr(0, src.length()) != src) && (word.substr(word.length() - src.length(), src.length()) != src) && (ind2 + 1 != ind) && (ind + src.length() != ind3)){
            cout<<"index: "<<ind<<" word: "<<word<<endl;
        }
        ind = source.find(src,ind+1);
    }
}


    
    
    

int main(){
    
    string source ="";
    string perm;
    string search;
    string arg;
    

        
    source = input();
    while (isAlpha(source)==false){
        source = input();
        
        
    }
    
    perm = source;
    do{
        cout<<"Enter search string: ";
        cin>>search;
        
        if (opSelect(search)==4){
            
            search = search.substr(0,search.find("**"));
            source = perm;
            allSplitCheck(source, search);
            
            
        }else if (opSelect(search)==1){
            source = perm;

            search = search.substr(0,search.find("+"));
            firstSplitCheck(source, search);
        }else if (opSelect(search)==2){
            
            source = perm;

            search = search.substr(0,search.find("."));
            lastSplitCheck(source, search);
        }else if(opSelect(search)==3){
            
            source = perm;

            search = search.substr(0,search.find("*"));
            midSplitCheck(source, search);
            
        }
            
            
        
        
        
    }while (opSelect(search)!=5);
        
        
        
    
    
    
    
    
    return 0;
}
