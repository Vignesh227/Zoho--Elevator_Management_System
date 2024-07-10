
#include<bits/stdc++.h>
using namespace std;

class lift{
    public:
        int floor, lifetime;
        char pos = ' ';
        lift(){
            floor=0;
            lifetime=0;
        }
    void display();
    int checkfloor();
};


void lift :: display(){
    cout<<setw(2)<<floor;
}

int main(){
    int choice=0, curr, dest, life, prevmaintain=-1;
    int num;
    bool flag = true;
    vector<int> arr;

    cout<<"\n LIFT Management System \n";
    cout<<"\n Constraints : (There can be max of 20 lifts and 100 floors) \n";

    while(flag){
        cout<<"\n Enter the number of lifts : ";
        cin>>num;

        cout<<"\n Enter the lifetime (cycle) of the lifts : ";
        cin>>life;

        int currfloor[num];

        if(num >= 1 && num <= 20){
            for(int i=0; i<num; ++i){
                cout<<"\n Enter the current position of the lift L"<<i+1<<" : ";

                cin>>currfloor[i];

                if(currfloor[i] < 0 || currfloor[i] > 100){
                    cout<<"\n Enter the current floor within the range (1-100)! \n";
                    --i;
                    continue;
                }
                arr.push_back(currfloor[i]);
            }
            flag = false;

        }
        else{
            cout<<"\n Enter the number of lifts within a range (1-20)! \n";
        }
    }



    lift obj[num];

    for(int i=0; i<num; ++i){
        obj[i].floor = arr[i];
    }
    flag = true;
    cout<<"\n Current Position \n Lifts :  ";
    for(int i=0; i<num; ++i){
        cout<<"L"<<i+1<<"  ";
    }
    cout<<endl<<" Floors : ";
    for(int i=0; i<num; ++i){

        obj[i].display();
        cout<<"  ";
    }
    cout<<endl;

    while(choice != 2){
        cout<<"\n 1 -> Use lift\n 2 -> Exit";
        cout<<"\n Enter your choice : ";
        cin>>choice;

        if(choice == 2) continue;
        if(choice != 1){
            cout<<"\n Enter the choice correctly !";
            continue;
        }
        // Get curr floor
        while(flag){
            cout<<"\n Enter the current floor : ";
            cin>>curr;
            if(curr < 0 || curr > 100){
                cout<<"\n Enter the current floor correctly\n";
                continue;
            }
            flag = false;
        }
        flag = true;

        // Get dest floor
        while(flag){

            cout<<"\n Enter the destination floor : ";
            cin>>dest;

            if(dest < 0 || dest > 100){
                cout<<"\n Enter the destination floor correctly!\n";
                continue;
            }
            flag = false;
        }
        flag =true;

        vector<char> direction;
        vector<int> position;

        int min = INT_MAX, assign;
        for(int i=0; i<num; ++i){
            if(obj[i].pos == 'M') continue;
            if(min > abs(curr - obj[i].floor)){
                assign = i;
                position.clear();
                direction.clear();
                position.push_back(i);
                direction.push_back(obj[i].pos);
                min =  abs(curr - obj[i].floor);
            }
            else if(min == abs(curr - obj[i].floor)){
                direction.push_back(obj[i].pos);
                position.push_back(i);
            }
        }
        // IF more than 1 lift is closer, assign by direction
        char req ; int c=0 , more=0;
        while(c < position.size()){
            // cout<<position[c]<<" ";
            if(obj[position[c]].floor > dest && obj[position[c]].pos == '-'){
                assign = position[c];
                more++;
            }

            else if(obj[position[c]].floor < dest && obj[position[c]].pos == '+'){
                assign = position[c];
                more++;
            }
            c++;
        }

        c = 0;
        if(more > 0){
            while(c < position.size()){
                if((dest%2 == 0 && ((position[c]+1)%2 == 0)) || (dest%2 !=0 && ((position[c]+1)%2 != 0) )){
                        assign = position[c];
                }

                c++;
            }
        }


        if(obj[assign].floor > dest)
            obj[assign].pos = '-';
        else
            obj[assign].pos = '+';


        cout<<"\n    L"<<assign+1<< " has been assigned";
        obj[assign].floor = dest;
        obj[assign].lifetime++;

        if(prevmaintain != -1){
            obj[prevmaintain].lifetime = 0;
            obj[prevmaintain].floor = 0;
            obj[prevmaintain].pos = ' ';
            prevmaintain = -1;
        }
        if(obj[assign].lifetime >= life){
              obj[assign].pos = 'M';
              prevmaintain = assign;
         }

        // To display the curr pos
        cout<<"\n\n    Lifts :  ";
        for(int i=0; i<num; ++i){
            cout<<"L"<<i+1<<"("<<obj[i].pos<<")"<<"  ";
        }
        cout<<endl<<"    Floor  :    ";
        for(int i=0; i<num; ++i){

            obj[i].display();
            cout<<"     ";
        }
        cout<<endl;

    }

    cout<<"\n Thank you for using lifts !";
}
