// for(int i=0;i<N;i++)
    // {
    //     cout << A[i] << " ";
    // }
    
    long long sum=0;
    
    vector<long long> odd_v,even_v;
    for(int i=0;i<N;i++)
    {
        if(i%2==0)
        {
            even_v.push_back(A[i]);
        }
        else
        {
            odd_v.push_back(A[i]);
        }
    }
    for(int i=0;i<even_v.size();i++)
    {
        sum=sum+even_v[i];
    }
    // cout << endl << sum << endl;
    sort(odd_v.begin(),odd_v.end());
    int it=odd_v.size()-1;
    while(K--)
    {
        if(it<0)
        {
            break;
        }
        odd_v[it]=-odd_v[it];
        // cout << odd_v[it] << " ";
        it=it-1;
    }
    
    
    for(int i=0;i<odd_v.size();i++)
    {
        sum=sum-odd_v[i];
    }
    
    return sum;