#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout; using std::string; using std::vector; using std::cout; using std::cin; using std::endl; using std::sort;

void adfgvxEncrypt(string plaintext, string keyword, string sorted_keyword, vector<char> &ciphertxt);
int chartoint(char let);

int main()
{
    char cont = 'n';
    vector<char>final_ct;

    do{
        final_ct.clear();
        string pt;// = "PRODUCTCIPHERS";
        cout<<"Enter the plaintext you'd like to encrypt: ";
        cin>>pt;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::transform(pt.begin(),pt.end(),pt.begin(), :: toupper);
        string kw = "DEUTSCH";
        //cout<<"Enter the keyword you'd like to use: ";
        //cin>>keyword;
        string skw = kw;
        sort(skw.begin(),skw.end());
        //cout<<endl<<keyword<<" "<<skw<<endl;

        adfgvxEncrypt(pt,kw,skw, final_ct);
        cout<<"Your encrypted message: ";
        cout<<endl;
        for (unsigned index = 0; index < final_ct.size(); ++index){
            cout<<final_ct[index];
        }
        cout<<endl<<endl;

        cout<<"Would you like to continue? (Y/N)";
        cin>>cont;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(cont == 'y' || cont == 'Y');
    cout<<"Thank you for your time. Have a lovely day."<<endl<<endl;
    return 0;
}

void adfgvxEncrypt(string plaintext, string keyword, string sorted_keyword, vector<char> &ciphertxt){
    vector<char> tenta_ct;

    vector<char> vecplt(plaintext.begin(), plaintext.end());

    char key[6][6] = {
    {'K', 'Z', 'W', 'R', '1', 'F'},
    {'9', 'B', '6', 'C', 'L', '5'},
    {'Q', '7', 'J', 'P', 'G', 'X'},
    {'E', 'V', 'Y', '3', 'A', 'N'},
    {'8', 'O', 'D', 'H', '0', '2'},
    {'U', '4', 'I', 'S', 'T', 'M'}
    };

    cout<<"Your key is: "<<endl<<endl;
    char ADFGVX[6] = {'A','D','F','G','V','X'};
    int adfgvx_vert = 0;

    //displays the key, ADFVGX and lines for readability
    for (int key_horiz = 0; key_horiz <6 ; ++key_horiz){
        if (key_horiz == 0){
            cout<<"   ";
            for (int adfgvx_horiz = 0; adfgvx_horiz < 6; ++adfgvx_horiz){
                cout<<ADFGVX[adfgvx_horiz]<<"  ";
            }
            cout<<endl<<"  -----------------"<<endl;
        }
        cout<<ADFGVX[adfgvx_vert]<<"| "<<key[key_horiz][0]<<"  ";
        ++adfgvx_vert;
        for (int key_vert = 1; key_vert < 6; ++key_vert){
            cout<<key[key_horiz][key_vert]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

    //finds each character of the plaintext in the key 2d array
    for (unsigned ptind = 0; ptind < vecplt.size(); ++ptind){
        for (int i  = 0; i < 6; ++i){
            for (int j = 0; j < 6; ++j){
                if (vecplt[ptind] == key[i][j]){
                    cout<<vecplt[ptind]<<" at: row "<<i+1<<", column "<<j+1<<" ";
                    tenta_ct.push_back(ADFGVX[i]);
                    tenta_ct.push_back(ADFGVX[j]);
                    cout<<endl;
                }
            }
        }
    }
    cout<<endl<<plaintext<<" outputs ";
    for (unsigned k = 0; k < tenta_ct.size(); ++k){
        cout<<tenta_ct[k];
    }


    //convert keyword into integer chars, order from 0 to keyword.length(), add as first row of 2d vector. Add entries into final ct by column.
    int ct_mat_rows;
    if ((tenta_ct.size())%keyword.length() == 0){
        ct_mat_rows = (tenta_ct.size())/keyword.length();
    }
    else{
        ct_mat_rows = 1+((tenta_ct.size())/keyword.length());
    }
    vector < vector <char> > ct_mat(ct_mat_rows, vector<char>(keyword.length()));

    for(int i=0;i<ct_mat_rows;++i)
    {
        for(unsigned j=0;j<keyword.length();++j)
        {

            if(tenta_ct.size()<=(7*i+j)){
                char space = ' ';
               (ct_mat[i])[j] =(space);
            }
            else{
                (ct_mat[i])[j] = tenta_ct[7*i+j];
            }
            cout<<ct_mat[i][j]<<"  ";
        }
        cout<<endl;
    }

    for (unsigned keyword_count = 0; keyword_count < keyword.length(); ++keyword_count){
        for (unsigned position = 0; position < keyword.length(); ++position){
            for(int sorted_row=0;sorted_row<ct_mat_rows;++sorted_row){
                if (sorted_keyword[keyword_count] == keyword[position]){
                    if(ct_mat[sorted_row][position] != ' '){
                        ciphertxt.push_back(ct_mat[sorted_row][position]);
                    }
                }
            }
        }
    }
    cout<<endl;
}
