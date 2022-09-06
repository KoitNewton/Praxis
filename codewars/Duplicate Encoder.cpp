#include <string>
using namespace std;
std::string duplicate_encoder(const std::string& word){
  string word_in = word;
  //word_in[word.size()-1]='(';
  for(unsigned long i=0;i<=word.size()-1;i++)
    for(unsigned long j=0;j<=word.size()-1;j++){
        if(i!=j){
            if(word[i]>='A'&&word[i]<='Z'){
                if(word[i]==word[j]||word[i]==word[j]-32){
                    word_in[i] =')';
                    break;
                }
                else
                    word_in[i] ='(';

            }
            else if(word[i]>='a'&&word[i]<='z'){
                 if(word[i]==word[j]||word[i]==word[j]+32){
                    word_in[i] =')';
                    break;
                }
                else
                    word_in[i] ='(';
               
            }
            else if(word[i]==word[j]){
                    word_in[i] =')';
                    break;
                }
                else
                    word_in[i] = '(';

       }
    }
  
  return word_in;
}