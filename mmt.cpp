#include <bits/stdc++.h>
using namespace std;

//source,price,time,mode,destination
vector<pair<pair<float,float>,pair<char,int>>> adj[1000000];
unordered_map<string,int> statemappingnumber;
// unordered_map<int,string> numbermappingstate;
static int countOfState;

void addInGraph(int source,int destination,float price,float time,char mode){
    adj[source].push_back({{price,time},{mode,destination}});
}

void makeGraph(string source,string destination,float price,float time,char mode){
    int source_num,destination_num;
    if(statemappingnumber.find(source)!=statemappingnumber.end()){
        source_num = statemappingnumber[source];
    }else{
        statemappingnumber[source]=countOfState;
        countOfState+=1;
    }
    
    if(statemappingnumber.find(destination)!=statemappingnumber.end()){
        destination_num = statemappingnumber[destination];
    }else{
        statemappingnumber[destination]=countOfState;
        countOfState+=1;
    }
    // numbermappingstate[source_num]=source;
    // numbermappingstate[destination_num]=destination;
    addInGraph(source_num,destination_num,price,time,mode);
}

int minimumTimeRoute(int source,int destination){
    priority_queue<pair<int,pair<int,string>>,vector<pair<int,pair<int,string>>>,greater<pair<int,pair<int,string>>>> pq;
    pq.push({0,{source,""}});
    vector<int> vis(countOfState,0);
    
    while(!pq.empty()){
        int time = pq.top().first;
        int node = pq.top().second.first;
        string path = pq.top().second.second;
        pq.pop();
        vis[node]=1;
        // for(auto it:statemappingnumber){
        //     if(it.second==node){
        //         // cout<<" take "<<it.first<<endl;
        //         break;
        //     }
        // }
      
        if(node == destination){
            cout<<path<<endl;
            string temp_num="";
            // cout<<time<<endl;
            // for(int i=0;i<path.size();i++){
            //     if(path[i]==' '){
            //         temp_num="";
            //         continue;
            //     }else if(path[i]=='_'){
            //         int number = stoi(temp_num);
            //         cout<<number<<endl;
            //     }else if(path[i]>='A' && path[i]<='Z'){
            //         if(path[i]=='B'){
            //             cout<<"Bus"<<endl;
            //         }else if(path[i]=='F'){
            //             cout<<"Flight"<<endl;
            //         }else{
            //             cout<<"train"<<endl;
            //         }
            //     }else{
            //         temp_num+=path[i];
            //     }
            // }
            
            
            return time;
        }
        
        for(auto it:adj[node]){
            if(vis[it.second.second]==0){
                string temp = " ";
                temp+=to_string(it.second.second);
                temp+="_";
                temp+=it.second.first;
                pq.push({time+it.first.second,{it.second.second,path+temp}});
            }
        }
    }
    cout<<"no route"<<endl;
    return -1;
}

int main(){
    makeGraph("Delhi","Chandigarh",5000.0,2.0,'F');
    makeGraph("Delhi","Chandigarh",2000.0,4.0,'T');
    makeGraph("Delhi","Chandigarh",300.0,6.0,'B');
    
     makeGraph("Delhi","Patiala",1800.0,6.0,'T');
    makeGraph("Delhi","Patiala",800.0,8.0,'B');
    
     makeGraph("Delhi","Pune",6000.0,3.0,'F');
     makeGraph("Delhi","Pune",3500.0,14.0,'T');
    makeGraph("Delhi","Pune",2000.0,20.0,'B');
    
     makeGraph("Chandigarh","Delhi",4500.0,2.0,'F');
    makeGraph("Chandigarh","Delhi",1000.0,6.0,'B');
    makeGraph("Chandigarh","Delhi",2000.0,4.0,'T');
    
    
    makeGraph("Chandigarh","Patiala",400.0,1.0,'T');
    makeGraph("Chandigarh","Patiala",200.0,2.0,'B');
    
     makeGraph("Chandigarh","Pune",8000.0,4.0,'F');
    makeGraph("Chandigarh","Pune",4000.0,18.0,'T');
    makeGraph("Chandigarh","Pune",3500.0,24.0,'B');
    
     makeGraph("Patiala","Chandigarh",400.0,1.0,'T');
    makeGraph("Patiala","Chandigarh",200.0,2.0,'B');
    
     makeGraph("Patiala","Delhi",1800.0,6.0,'T');
    makeGraph("Patiala","Delhi",800.0,8.0,'B');                                makeGraph("Patiala","Pune",3800.0,20.0,'T');
    
    
    makeGraph("Pune","Delhi",6500.0,3.0,'F');
     makeGraph("Pune","Delhi",3500.0,14.0,'T');
    makeGraph("Pune","Delhi",2500.0,20.0,'B');

     makeGraph("Pune","Chandigarh",8200.0,4.0,'F');
     makeGraph("Pune","Chandigarh",3800.0,18.0,'T');
    makeGraph("Pune","Chandigarh",3200.0,24.0,'B');
     makeGraph("Pune","Patiala",3800.0,20.0,'T');
     
    
    
    
    
  
    
    for(auto it:statemappingnumber){
        cout<<"state "<<it.first<<" mapping with "<<it.second<<" state"<<it.second<<endl; 
    }
    cout<<endl<<endl;
    
   cout<<minimumTimeRoute(statemappingnumber["Delhi"],statemappingnumber["Delhi"]);
	return 0;
}
