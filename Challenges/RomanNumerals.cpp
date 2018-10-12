/*
    ID: 185
*/

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <math.h>


int value(char r)
{
    int res = -1;
    switch(r)
    {
        case 'I': res = 1;
        break;
        case 'V': res = 5;
        break;
        case 'X': res = 10;
        break;
        case 'L': res = 50;
        break;
        case 'C': res = 100;
        break;
        case 'D': res = 500;
        break;
        case 'M': res = 1000; 
    }
    return res;
}

int rToD(std::string &str)
{
    int res = 0;
    for(size_t i = 0; i < str.length(); ++i)
    {
        int s1 = value(str[i]);
        if(i + 1 < str.length())
        {
            int s2 = value(str[i+1]);
            if(s1 >= s2) res = res + s1;
            else 
            {
                res = res + s2 - s1;
                i++;
            }
        }
        else 
        {
            res = res + s1;
            i++;
        }
    }
    return res;
}

int main()
{
    std::string str;
    while(std::cin >> str)
    {
        if(str == "#") return 0;
        size_t pluspos = str.find("+");
        size_t eqpos = str.find("=");
        std::string part1 = str.substr(0, pluspos);
        std::string part2 = str.substr(pluspos + 1, eqpos - pluspos - 1);
        std::string part3 = str.substr(eqpos + 1);
        //std::cout << rToD(part1) << " + " << rToD(part2) << " = " << rToD(part3) << "\n";
        //if(rToD(part1) + rToD(part2) == rToD(part3)) std::cout << "Correct";
        //else std::cout << "Incorrect";

        //bool impossible = false;
        int s1 = part1.size();
        //int bigs = s1;
        int s2 = part2.size();
        //if(s2 > s1) bigs = s2;
        int s3 = part3.size();
        //if(s3 > s2) bigs = s3;
        
        //if(s1 > s3 || s2 > s3) impossible = true; //Succesffuly removes some

        //int numbers[] = {1,2,3,4,5,6,7,8,9};
        char letters[] = {'I','V','X','L','M','C','D'};
        std::set<char> leftset;
        std::set<char> rightset;
        char arr[3][9] = {0};
        int letterTable[90] = {0};

        int j = 0;
        for(auto it = part1.rbegin(); it != part1.rend(); ++it)
        {
            arr[0][j++] = *it;
            leftset.insert(*it);
        }
        j = 0;
        for(auto it = part2.rbegin(); it != part2.rend(); ++it)
        {
            arr[1][j++] = *it;
            leftset.insert(*it);
        }
        j = 0;
        for(auto it = part3.rbegin(); it != part3.rend(); ++it)
        {
            arr[2][j++] = *it;
            rightset.insert(*it);
        }

        int count = 0;
        for(int k = 0; k < 10; k++)
        {
            letterTable[ letters[(k + 7) % 7] ] = (k + 1 + 9) % 9;
            //std::cout << "l: " << letters[(k+7) % 7] << " " << letterTable[letters[(k+7)%7]] << "\n";
            //bool ok = false;

            for(int i = 0; i < 9; i++)
            {
                for(int l = 0; l < 7; l++)
                {
                    if(l != k) letterTable[ letters[(l + 7) % 7] ] = (i + l + 9) % 9;
                }
                //std::cout << "l: " << letters[(k+7) % 7] << " " << letterTable[letters[(k+7)%7]] << "\n";
                // letterTable['I'] = (i + 1 + 9) % 9;
                // letterTable['V'] = (i + 2 + 9) % 9;
                // letterTable['X'] = (i + 3 + 9) % 9;
                // letterTable['L'] = (i + 4 + 9) % 9;
                // letterTable['C'] = (i + 5 + 9) % 9;
                // letterTable['D'] = (i + 6 + 9) % 9;
                // letterTable['M'] = (i + 7 + 9) % 9;
                int l1 = 0;
                int l2 = 0;
                int r1 = 0;
                for(int j = 0; j < s1; j++)
                {
                    int x = (letterTable[arr[0][j]] + 1) * pow(10, j);
                    l1 += x;
                }
                for(int j = 0; j < s2; j++)
                {
                    int y = (letterTable[arr[1][j]] + 1) * pow(10, j);
                    l2 += y;
                }
                for(int j = 0; j < s3; j++)
                {
                    int z = (letterTable[arr[2][j]] + 1) * pow(10,j);
                    r1 += z;
                }

                if(l1 + l2 == r1) ++count;
                // int rans = l1 + l2;
                // std::string strans = std::to_string(rans);
                // bool ok = false;
                // if(strans.size() == s3)
                // {
                    
                //     for(int j = 0; i < s3; i++)
                //     {
                //         if(leftset.count(arr[2][j]))
                //         {
                //             if((letterTable[arr[2][j]] + 1) == (*(strans.rbegin() + j) - 48))
                //             {
                //                 ok = true;
                //             } 
                //             //else ok = false;
                //         }
                        
                //     }
                // }
                // if(ok) ++count;

                std::cout << l1 << " " << l2 << " " << r1 << "\n";
            }
        }


        // if(count == 1) std::cout << " valid";
        // else if(!count) std::cout << " impossible";
        // else std::cout << " ambigious";
        std::cout << count;

        // for(int i = 0; i < 3; i++)
        // {
        //     for(int j = 0; j < 9; j++)
        //     {
        //         std::cout << arr[i][j];
        //     }
        //     std::cout << "\n";
        // }





        //if(impossible) std::cout << " impossible";
        std::cout << "\n";

        // rightset.clear();
        // leftset.clear();

    }


    return 0;
}