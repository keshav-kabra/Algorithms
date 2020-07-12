#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
class MinJob
{
    static const int Id; 
    public:
    double weight, length;
    double priorityratio;
    MinJob()
    {

    }
    MinJob(double w , double l)
    {
        weight = w;
        length = l;
        priorityratio = weight/length;
        

    }
    
};
void Bubblesort(vector<MinJob> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr.size()-1;j++)
        {
            if(arr[j].priorityratio < arr[j+1].priorityratio) 
                swap(arr[j] , arr[j+1]);
            if(arr[j].priorityratio == arr[j+1].priorityratio && arr[j].weight < arr[j+1].weight)    
                swap(arr[j] ,arr[j+1]);
        }
    }

}

void readfile(vector<MinJob> &arr)
{
    bool first = true;
    double weight , length;
    string line;
    ifstream input;
    input.open("_jobs.txt");
    while(getline(input , line))
    {
        if(first) first = false;
        else
        {
            stringstream ss(line);
            ss>>weight;
            ss>>length;
            arr.push_back(MinJob(weight , length));

        }
    }

}
int main()
{
    //create arr  of objects
    long long completiontime = 0, weightedTime =0;
    vector<MinJob> arr;
    //1.call to read arr
    readfile(arr);
    for(int i=0;i<arr.size();i++)
    cout<<"priority ratio of is "<<arr[i].priorityratio<<" and its length is "<<arr[i].length<<" and weight "<<arr[i].weight<<endl;
    //sort acc to priority ratio
    Bubblesort(arr);
    cout<<"after sorting "<<endl;
    for(int i=0;i<arr.size();i++)
    {
    completiontime += arr[i].length;
    weightedTime += completiontime*arr[i].weight;
    }

    cout<<"completion time "<<weightedTime<<endl;
    return 0;
}



//  int no_of_jobs;
//      double completiontime  = 0;
//     vector<MinJob> arr;
//     cout<<"enter number of jobs "<<endl;
//     cin>>no_of_jobs;
//     for(int i=0;i<no_of_jobs;i++)
//     {
//         double weight , length;
//         cout<<"enter the value of weight and lenght for "<<i+1<< " job"<<endl;
//         cin>>weight>>length;
//         arr.push_back(MinJob(weight , length));
//     }